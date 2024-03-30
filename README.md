# posttest4-praktikum-iot-unmul

## Kelompok 4 IOT C 2022 
1. Aprisa Idma Mutiara (2209106001)
2. Narupa Rangga Goroguta (2209106004)
3. Juniver Veronika Lili (2209106013)

 ## Kontrol dan Monitor Lampu dan Suhu dengan Menggunakan Telegram
 **Deskripsi :** 
1. Terdapat n LED yang hanya bisa di nyala matikan oleh masing masing anggota
2. Terdapat 1 LED yang dapat di nyala matikan seluruh anggota
3. DHT dapat menampilkan status suhu dan kelembapan saat di minta seluruh anggota
4. Terdapat jawaban peringatan jika anggota A mencoba menyala matikan LED anggota
   
**Cara kerja alat :** 
Pada proyek ini, terdapat 4 led. Dimana setiap orang hanya memiliki akses untuk 1 led nya sendiri dan 1 led untuk bersama (on/off). Jika Anggota lain ingin mencoba mengakses lampu milik anggota lainnya, maka akan muncul pemberitahuan bahwa dia tidak memiliki akses ke lampu tersebut. Untuk led bersama bisa diakses oleh semua anggota tanpa terkecuali. Jika ingin menampilkan suhu bisa memilih menu pada suhu. 

**Pembagian tugas :**
1. Aprisa Idma Mutiara : membuat struktur kodingan 
2. Narupa Rangga Goroguta : membuat rangkaian our schematic
3. Juniver Veronika Lili : membuat rangkaian board schematic
   
**Komponen yang Digunakan**
1. Kabel jumper
2. LED
3. Resistor
4. Breadboard
5. ESP8266
6. Kabel MicroUSB
7. Sensor DHT11

**Board Schematic :**
![Gambar WhatsApp 2024-03-30 pukul 13 51 54_10539a79](https://github.com/aprisamutiara/posttest4-praktikum-iot-unmul/assets/123526722/51a2875b-360c-4e8d-b025-c08bf5a155de)

**Our Schematic :**
![Gambar WhatsApp 2024-03-30 pukul 13 47 47_3bd95002](https://github.com/aprisamutiara/posttest4-praktikum-iot-unmul/assets/123526722/688f5ce8-d76e-474e-9bd0-06b093a99029)
