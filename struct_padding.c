/* ============================================================================
 * C STRUCT BELLEK HİZALAMA (ALIGNMENT) VE PADDING KURALLARI (64-BİT REHBERİ)
 * ============================================================================
 *
 * 1. TEMEL KAVRAMLAR
 * ------------------
 * - S (Size / Boyut)      : sizeof(tip)  -> Değişkenin kapladığı byte sayısı.
 * - A (Alignment / Çarpan): alignof(tip) -> Başlangıç adresinin TAM BÖLÜNMESİ
 *                                           gereken sayı (2'nin kuvvetidir).
 * - O (Offset / Konum)    : offsetof(struct, alan) -> Struct başlangıcından (0)
 *                                           itibaren kaçıncı byte'ta başladığı.
 * - p (Pointer / Sayaç)   : Sıradaki ilk boş byte indeksi (başlangıçta p = 0).
 *
 * 2. TİPİK 64-BİT (x86_64 / ARM64) SİSTEM DEĞERLERİ
 * -------------------------------------------------
 * | Veri Tipi               | Boyut (S) | Çarpan (A) | Kural (O % A == 0)     |
 * |-------------------------|-----------|------------|------------------------|
 * | char                    | 1 byte    | 1          | Her adrese yerleşir    |
 * | short                   | 2 byte    | 2          | 0, 2, 4, 6, 8...       |
 * | int, float              | 4 byte    | 4          | 0, 4, 8, 12, 16...     |
 * | double, long long, ptr  | 8 byte    | 8          | 0, 8, 16, 24, 32...    |
 *
 * 3. DERLEYİCİNİN 3 KESİN ALGORİTMA KURALI
 * ----------------------------------------
 * [KURAL 1 - Sıra Korunur]:
 *   Derleyici değişkenlerin yazılış sırasını ASLA değiştirmez.
 *
 * [KURAL 2 - Alan Yerleştirme ve Ara Boşluk (Internal Padding)]:
 *   Her alan kendi çarpanına (A) tam bölünen bir offset'te başlamak zorundadır:
 *       Şart            : O % A == 0
 *       Eklenecek Pad   : pad = (A - (p % A)) % A
 *       Başlangıç Offset: O = p + pad
 *       Yeni Boş İndeks : p = O + S
 *
 * [KURAL 3 - Struct Sonu Boşluğu (Tail Padding)]:
 *   Struct'ın kendi hizalama çarpanı (A_max), içindeki en büyük A değeridir:
 *       A_max = max(A_1, A_2, ..., A_n)
 *   Struct'ın toplam boyutu (sizeof), A_max değerine tam bölünmek zorundadır
 *   (böylece struct dizisi oluşturulduğunda 2. eleman da hizalı başlar):
 *       Şart            : sizeof(struct) % A_max == 0
 *       Tail Padding    : tail_pad = (A_max - (p % A_max)) % A_max
 *       Toplam Boyut    : sizeof(struct) = p + tail_pad
 * ============================================================================
 */

#include <stdio.h>
#include <stddef.h>     // offsetof() ve size_t için
#include <stdalign.h>   // alignof() ve alignas() için (C11 ve sonrası)

/* ----------------------------------------------------------------------------
 * ÖRNEK 1: KÖTÜ SIRALAMA (24 BYTE)
 * ----------------------------------------------------------------------------
 * Bellek Haritası (Her harf 1 byte, '.' = Padding):
 * [a][.][.][.][.][.][.][.] [b][b][b][b][b][b][b][b] [c][c][c][c][d][.][.][.]
 *  0  1..7 (7B Pad)         8..15                    16..19      20 21..23 (3B Tail)
 */
struct KotuSiralama {
    char a;     // p=0  | S=1, A=1 | 0 % 1 = 0 -> pad=0 | O=0  (0)     -> yeni p=1
                // [PAD: p=1, sıradaki A=8 -> (8 - (1%8))%8 = 7 byte boşluk (1..7)]
    double b;   // p=1  | S=8, A=8 | 1 % 8 = 1 -> pad=7 | O=8  (8..15) -> yeni p=16
    int c;      // p=16 | S=4, A=4 | 16% 4 = 0 -> pad=0 | O=16 (16..19)-> yeni p=20
    char d;     // p=20 | S=1, A=1 | 20% 1 = 0 -> pad=0 | O=20 (20)    -> yeni p=21
                // [TAIL PAD: p=21, A_max=8 -> (8 - (21%8))%8 = 3 byte boşluk (21..23)]
};              // TOPLAM: 21 + 3 = 24 byte (14B veri + 10B çöp)


/* ----------------------------------------------------------------------------
 * ÖRNEK 2: İYİ SIRALAMA - BÜYÜKTEN KÜÇÜĞE (16 BYTE)
 * ----------------------------------------------------------------------------
 * Bellek Haritası:
 * [b][b][b][b][b][b][b][b] [c][c][c][c][a][d][.][.]
 *  0..7                     8..11       12 13 14..15 (2B Tail)
 */
struct IyiSiralama {
    double b;   // p=0  | S=8, A=8 | 0 % 8 = 0 -> pad=0 | O=0  (0..7)  -> yeni p=8
    int c;      // p=8  | S=4, A=4 | 8 % 4 = 0 -> pad=0 | O=8  (8..11) -> yeni p=12
    char a;     // p=12 | S=1, A=1 | 12% 1 = 0 -> pad=0 | O=12 (12)    -> yeni p=13
    char d;     // p=13 | S=1, A=1 | 13% 1 = 0 -> pad=0 | O=13 (13)    -> yeni p=14
                // [TAIL PAD: p=14, A_max=8 -> (8 - (14%8))%8 = 2 byte boşluk (14..15)]
};              // TOPLAM: 14 + 2 = 16 byte (%33 bellek tasarrufu)


/* ----------------------------------------------------------------------------
 * ÖRNEK 3: TAIL PADDING NEDEN VAR? (ARRAY / DİZİ KANITI)
 * ----------------------------------------------------------------------------
 * Eğer sizeof(struct DiziKaniti) 5 byte olsaydı, struct DiziKaniti arr[2]
 * tanımlandığında arr[1].n alanı Offset 5'e düşerdi (5 % 4 != 0 -> Hizasız!).
 * 3 byte Tail Padding sayesinde sizeof = 8 olur ve arr[1].n Offset 8'de başlar.
 */
struct DiziKaniti {
    int n;      // p=0 | S=4, A=4 | pad=0 | O=0 (0..3) -> yeni p=4
    char c;     // p=4 | S=1, A=1 | pad=0 | O=4 (4)    -> yeni p=5
                // [TAIL PAD: p=5, A_max=4 -> (4 - (5%4))%4 = 3 byte (5..7)]
};              // TOPLAM: 8 byte


/* ----------------------------------------------------------------------------
 * ÖRNEK 4: İÇ İÇE (NESTED) STRUCT KURALI
 * ----------------------------------------------------------------------------
 * KURAL: İçerdeki bir struct'ın hizalama çarpanı (A), kendi içindeki EN BÜYÜK
 * elemanın çarpanıdır (A_max). Dış struct, iç struct'ı bu A_max değerine göre hizalar.
 */
struct IcStruct {
    double x;   // S=8, A=8 -> O=0 (0..7)
    char y;     // S=1, A=1 -> O=8 (8) + 7 byte Tail Pad (9..15)
};              // sizeof(struct IcStruct) = 16, alignof(struct IcStruct) = 8

struct DisStruct {
    char baslik;         // p=0  | S=1,  A=1 | pad=0 | O=0 (0)      -> yeni p=1
                         // [PAD: p=1, IcStruct'ın A değeri 8 -> 7 byte pad (1..7)]
    struct IcStruct ic;  // p=1  | S=16, A=8 | pad=7 | O=8 (8..23)  -> yeni p=24
    int son;             // p=24 | S=4,  A=4 | pad=0 | O=24(24..27) -> yeni p=28
                         // [TAIL PAD: p=28, A_max=8 -> (8 - (28%8))%8 = 4 byte (28..31)]
};                       // TOPLAM: 32 byte


/* ----------------------------------------------------------------------------
 * ÖRNEK 5: DERLEYİCİYE MÜDAHALE (PACKED - PADDING İPTALİ)
 * ----------------------------------------------------------------------------
 * #pragma pack(push, 1) tüm A değerlerini 1'e zorlar. Padding tamamen kalkar.
 * Ağ paketleri ve donanım register'ları için kullanılır (CPU erişimi yavaşlar).
 */
#pragma pack(push, 1)
struct Sikistirilmis {
    char a;     // O=0 (1 byte)
    double b;   // O=1 (8 byte) -> Normalde 8'de başlardı, şimdi 1'de başlıyor!
    int c;      // O=9 (4 byte)
};              // TOPLAM: 13 byte (Sıfır padding)
#pragma pack(pop)


/* ============================================================================
 * DOĞRULAMA KODU (Derleyip çıktıları görmek için)
 * ============================================================================ */
int main(void) {
    printf("=== 1. KOTU SIRALAMA ===\n");
    printf("sizeof: %zu, alignof (A_max): %zu\n",
           sizeof(struct KotuSiralama), alignof(struct KotuSiralama));
    printf("Offsets -> a:%zu, b:%zu, c:%zu, d:%zu\n\n",
           offsetof(struct KotuSiralama, a), offsetof(struct KotuSiralama, b),
           offsetof(struct KotuSiralama, c), offsetof(struct KotuSiralama, d));

    printf("=== 2. IYI SIRALAMA ===\n");
    printf("sizeof: %zu, alignof (A_max): %zu\n",
           sizeof(struct IyiSiralama), alignof(struct IyiSiralama));
    printf("Offsets -> b:%zu, c:%zu, a:%zu, d:%zu\n\n",
           offsetof(struct IyiSiralama, b), offsetof(struct IyiSiralama, c),
           offsetof(struct IyiSiralama, a), offsetof(struct IyiSiralama, d));

    printf("=== 3. DIS STRUCT (NESTED) ===\n");
    printf("sizeof: %zu, alignof (A_max): %zu\n",
           sizeof(struct DisStruct), alignof(struct DisStruct));
    printf("Offsets -> baslik:%zu, ic:%zu, son:%zu\n\n",
           offsetof(struct DisStruct, baslik), offsetof(struct DisStruct, ic),
           offsetof(struct DisStruct, son));

    printf("=== 4. PACKED STRUCT ===\n");
    printf("sizeof: %zu, alignof (A_max): %zu\n",
           sizeof(struct Sikistirilmis), alignof(struct Sikistirilmis));
    printf("Offsets -> a:%zu, b:%zu, c:%zu\n",
           offsetof(struct Sikistirilmis, a), offsetof(struct Sikistirilmis, b),
           offsetof(struct Sikistirilmis, c));

    return 0;
}