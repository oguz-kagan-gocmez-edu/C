import re
import requests
from pathlib import Path
from urllib.parse import urljoin, urlparse, unquote
from bs4 import BeautifulSoup

BASE = "https://ocw.mit.edu"
COURSE = (
    "/courses/6-087-practical-programming-in-c-january-iap-2010/"
)
START = BASE + COURSE + "download/"

ROOT = Path(__file__).parent / "MIT_OCW_C_Resources"
ROOT.mkdir(parents=True, exist_ok=True)

session = requests.Session()
session.headers["User-Agent"] = "Mozilla/5.0"

# Kategorilerin ana sayfaları
pages = [
    START,
    BASE + COURSE + "resources/problem-sets/",
    BASE + COURSE + "resources/problem-set-solutions/",
    BASE + COURSE + "resources/lecture-notes/",
    BASE + COURSE + "resources/laboratory-assignments/",
]

visited = set()
pdfs = set()

while pages:
    page_url = pages.pop(0)

    if page_url in visited:
        continue
    visited.add(page_url)

    try:
        response = session.get(page_url, timeout=30)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"Page error: {page_url}: {e}")
        continue

    soup = BeautifulSoup(response.text, "html.parser")

    for a in soup.find_all("a", href=True):
        href = urljoin(page_url, a["href"])
        parsed = urlparse(href)
        path = unquote(parsed.path)
        label = a.get_text(" ", strip=True).lower()

        if parsed.netloc not in ("ocw.mit.edu", "www.ocw.mit.edu"):
            continue

        # PDF dosyalarını bul
        if path.lower().endswith(".pdf"):
            pdfs.add((href, path))
            continue

        # İlgili kaynak sayfalarını tara
        if path.startswith(COURSE + "resources/"):
            if href not in visited:
                pages.append(href)

print(f"Found {len(pdfs)} PDF files.")

for url, path in sorted(pdfs):
    # PDF adına göre alt klasör oluştur
    if "/resources/problem-set-solutions/" in path:
        category = "Problem_Set_Solutions"
    elif "/resources/problem-set-" in path:
        category = "Problem_Sets"
    elif "/resources/lecture-" in path or "/resources/lecture-notes/" in path:
        category = "Lecture_Notes"
    elif "/resources/laboratory-" in path or "/resources/lab-" in path:
        category = "Labs"
    else:
        category = "Other"

    folder = ROOT / category
    folder.mkdir(parents=True, exist_ok=True)

    filename = Path(path).name
    if not filename:
        continue

    output = folder / filename

    if output.exists() and output.stat().st_size > 0:
        print(f"Already exists: {filename}")
        continue

    try:
        r = session.get(url, timeout=60)
        r.raise_for_status()

        if not r.content.startswith(b"%PDF-"):
            print(f"Not a PDF, skipped: {filename}")
            continue

        output.write_bytes(r.content)
        print(f"Downloaded: {category}/{filename}")

    except requests.RequestException as e:
        print(f"Download failed: {filename}: {e}")

print(f"\nDone. Files saved in:\n{ROOT}")
