
# 🔐 Smart Door Lock with Smartphone Flashlight Login (Arduino-Based)

Proyek ini mengembangkan **sistem keamanan ruangan pribadi** berbasis **Arduino** dengan metode autentikasi menggunakan **flashlight smartphone** sebagai media login. Sistem memanfaatkan **sensor cahaya (LDR)** untuk membaca pola cahaya dari flashlight yang kemudian diproses oleh **mikrokontroler Arduino** guna mengaktifkan **solenoid door lock** secara otomatis.  
Pendekatan ini menghadirkan solusi **praktis, inovatif, dan tanpa koneksi internet** untuk meningkatkan keamanan akses ruangan.

---

## 🚀 Fitur Utama
- Login menggunakan **flashlight smartphone**  
- Tidak memerlukan **koneksi internet (offline mode)**  
- Sistem berbasis **Arduino Nano** dan **sensor LDR**  
- Menggunakan **solenoid lock** sebagai aktuator kunci otomatis  
- Indikator status menggunakan **LED** dan **buzzer**  
- Aplikasi Android dibuat dengan **Kodular.io** menggunakan komunikasi cahaya (**Li-Fi**)  

---

## 🧠 Cara Kerja Singkat
Sistem bekerja dengan mendeteksi pola cahaya dari flashlight smartphone yang dikirim melalui aplikasi **VLight**.  
Arduino memproses pola tersebut dan memverifikasi kecocokan dengan pola yang tersimpan:

- Jika **valid** → pintu terbuka, LED hijau dan buzzer aktif  
- Jika **invalid** → akses ditolak, LED merah menyala  

---

## 🧩 Komponen yang Digunakan
| Komponen | Fungsi |
|-----------|---------|
| Arduino Nano R3 | Mikrokontroler utama |
| LDR Module | Sensor cahaya |
| Solenoid Door Lock | Aktuator pengunci pintu |
| IRF730 MOSFET | Penguat dan kontrol daya |
| Buzzer | Notifikasi audio |
| LED Hijau & Merah | Indikator status sistem |
| Power Supply 12V | Sumber daya utama |
| Kodular App | Aplikasi Android untuk autentikasi |

---

## 🧷 Pin Mapping Arduino

| No | Komponen | Pin Arduino | Keterangan |
|----|------------|--------------|-------------|
| 1 | LDR Module (DO) | D8 | Input sensor cahaya |
| 2 | LED Hijau | D6 | Indikator pintu terbuka |
| 3 | LED Merah | D7 | Indikator sistem siaga / pintu tertutup |
| 4 | Buzzer | D4 | Notifikasi suara |
| 5 | MOSFET (Gate) | D12 | Kontrol solenoid |
| 6 | Solenoid Door Lock | VIN / 12V | Aktuator pengunci pintu |
| 7 | Power Supply | VIN & GND | Tegangan utama sistem |

---

## 🛠️ Instalasi & Penggunaan

### 1. Perangkat Keras
1. Rakit semua komponen sesuai skematik perancangan.  
2. Pastikan sensor LDR menghadap ke flashlight smartphone.  
3. Upload kode program ke Arduino melalui **Arduino IDE**.

### 2. Perangkat Lunak
1. Buka proyek aplikasi di **Kodular.io**.  
2. Export dan install aplikasi `VLight.apk` ke smartphone.  
3. Masukkan password, arahkan flashlight ke sensor LDR.  
4. Sistem akan membuka atau menolak akses sesuai pola cahaya.

---

## ⚙️ Teknologi yang Digunakan
- **Arduino IDE** – Pemrograman mikrokontroler  
- **Kodular.io** – Pembuatan aplikasi Android  
- **Li-Fi Communication** – Komunikasi berbasis cahaya  

---

## 👨‍💻 Pengembang
**Kelvin Maulana Shofani**  
Program Studi Teknik Komputer  
Jurusan Teknologi Informasi – Politeknik Negeri Jember (2025)
