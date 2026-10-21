#!/bin/bash

# Klasördeki tüm .c dosyalarını bul ve döngüye sok
for file in *.c; do
    # Eğer klasörde hiç .c dosyası yoksa hata vermesini önle
    [ -e "$file" ] || continue

    # Uzantıyı kaldırarak çalıştırılabilir dosya adını belirle (örneğin: main.c -> main)
    output="${file%.c}"

    echo "Derleniyor: $file -> $output"
    
    # gcc ile derle (-Wall ve -Wextra eklemek olası hataları görmek için faydalıdır)
    gcc "$file" -o "$output"

    # Derlemenin başarılı olup olmadığını kontrol et
    if [ $? -eq 0 ]; then
        echo "[BAŞARILI] $output oluşturuldu."
    else
        echo "[HATA] $file derlenirken sorun oluştu!"
    fi
    echo "----------------------------------------"
done

echo "Tüm işlemler tamamlandı."