/*
 * PROGRAM INI PROGRAM YANG DIBUAT BEDASARKAN UJI KOMPONEN
 * PROGRAM SENSOR ULTRASONIK HC-SR04 DENGAN ARDUINO
 * 
 * Fungsi: Mengukur jarak objek menggunakan sensor ultrasonik dan menampilkan hasilnya
 * Komponen:
 * - Sensor HC-SR04
 * - Board Arduino
 * 
 * Koneksi Pin:
 * - VCC sensor ke 5V Arduino
 * - GND sensor ke GND Arduino
 * - Trig ke pin 9 Arduino
 * - Echo ke pin 10 Arduino
 */

// DEKLARASI PIN
const int trigPin = 5;   // Pin Trig terhubung ke pin digital 9 (output)
const int echoPin = 6;  // Pin Echo terhubung ke pin digital 10 (input)

void setup() {
  /* 
   * FUNGSI SETUP - Dijalankan sekali saat program mulai
   */
  
  // Inisialisasi Serial Monitor dengan baud rate 9600
  Serial.begin(9600);
  
  // Mengatur mode pin:
  pinMode(trigPin, OUTPUT);  // Set trigPin sebagai OUTPUT untuk mengirim sinyal
  pinMode(echoPin, INPUT);   // Set echoPin sebagai INPUT untuk menerima sinyal
}

void loop() {
  /*
   * FUNGSI LOOP - Dijalankan berulang-ulang
   */
  
  // 1. MENGIRIM SINYAL ULTRASONIK
  digitalWrite(trigPin, LOW);        // Pastikan sinyal awal LOW
  delayMicroseconds(2);              // Tunggu 2 mikrodetik
  digitalWrite(trigPin, HIGH);       // Kirim sinyal HIGH (trigger)
  delayMicroseconds(10);             // Pertahankan selama 10μs
  digitalWrite(trigPin, LOW);        // Kembalikan ke LOW
  
  // 2. MENERIMA PANTULAN SINYAL
  // pulseIn() mengukur waktu dari HIGH sampai LOW dalam mikrodetik
  long duration = pulseIn(echoPin, HIGH);
  
  // 3. MENGHITUNG JARAK
  // Rumus: (waktu × kecepatan suara) / 2
  // Kecepatan suara 340 m/s = 0.034 cm/μs
  // Dibagi 2 karena sinyal bolak-balik (ke objek dan kembali)
  int distance = duration * 0.034 / 2;
  
  // 4. MENAMPILKAN HASIL KE SERIAL MONITOR
  Serial.print("Jarak: ");      // Tampilkan teks "Jarak: "
  Serial.print(distance);       // Tampilkan nilai jarak
  Serial.println(" cm");        // Tampilkan satuan cm dan pindah baris
  
  // 5. JEDA SEBELUM PENGUKURAN BERIKUTNYA
  delay(500);  // Tunggu 500ms (0.5 detik) sebelum ukur lagi
}

/*
 * CATATAN TAMBAHAN:
 * - Sensor memiliki jangkauan efektif 2cm - 400cm
 * - Akurasi ±3mm
 * - Sudut pengukuran sekitar 15 derajat
 * - Untuk hasil lebih stabil, bisa ditambahkan filter atau pengukuran rata-rata
 * - Pastikan tidak ada objek terlalu dekat (<2cm) saat pengukuran
 */
