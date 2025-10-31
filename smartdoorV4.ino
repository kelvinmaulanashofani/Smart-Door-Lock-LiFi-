// Deklarasi pin komponen
#define Solenoid 12
#define ldr 8
int Buzzer = 4;
int GreenLed = 6;
int RedLed = 7;

// Variabel untuk menyimpan bitstream dari cahaya
String polaPassword = "";

void setup() {
  Serial.begin(9600);

  pinMode(ldr, INPUT_PULLUP);        // LDR membaca cahaya
  pinMode(Solenoid, OUTPUT);         // Kunci pintu
  pinMode(GreenLed, OUTPUT);         // Indikator terbuka
  pinMode(RedLed, OUTPUT);           // Indikator terkunci
  pinMode(Buzzer, OUTPUT);           // Buzzer

  // Status awal: pintu terkunci
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, LOW);
  digitalWrite(Solenoid, LOW);
}

void OpenDoor() {
  digitalWrite(Solenoid, HIGH);   // Aktifkan solenoid (buka kunci)
  tone(Buzzer, 500);              // Buzzer menyala
  digitalWrite(RedLed, LOW);      // Matikan indikator terkunci
  digitalWrite(GreenLed, HIGH);   // Nyalakan indikator terbuka

  delay(2000);                    // Biarkan pintu terbuka 2 detik

  digitalWrite(Solenoid, LOW);    // Kunci kembali
  noTone(Buzzer);                 // Matikan buzzer
  digitalWrite(RedLed, HIGH);     // Tampilkan indikator terkunci
  digitalWrite(GreenLed, LOW);    // Matikan indikator terbuka
}

void loop() {
  // Tunggu cahaya masuk dari flashlight
  if (digitalRead(ldr) == LOW) {
    Serial.println("Cahaya terdeteksi - menunggu start bit...");

    // Deteksi start bit: cahaya nyala minimal 500ms
    int durasiStart = 0;
    while (digitalRead(ldr) == LOW) {
      delay(10);
      durasiStart += 10;
      if (durasiStart > 1000) break;  // Batas atas (jika terlalu lama)
    }

    // Rentang valid start bit (sekitar 500 ms)
    if (durasiStart >= 400 && durasiStart <= 600) {
      Serial.println("Start bit valid, mulai membaca pola...");

      polaPassword = "";
      delay(100); // jeda pendek setelah start bit

      // Baca 4 bit, 1 bit per 200ms
      for (int i = 0; i < 4; i++) {
        int bitVal = (digitalRead(ldr) == LOW) ? 1 : 0;  // Cahaya terang = 1, gelap = 0
        polaPassword += String(bitVal);
        Serial.print("Bit ke-"); Serial.print(i); Serial.print(": ");
        Serial.println(bitVal);
        delay(200);  // Jeda antar bit
      }

      Serial.print("Pola diterima: ");
      Serial.println(polaPassword);

      // Verifikasi pola
      if (polaPassword == "0001") {
        Serial.println("Pola cocok: AKSES USER 1");
        OpenDoor();
      } else if (polaPassword == "1010") {
        Serial.println("Pola cocok: AKSES USER 2");
        OpenDoor();
      } else {
        Serial.println("Pola tidak dikenali. Akses ditolak.");
      }

      polaPassword = "";
      delay(500); // jeda sebelum membaca pola baru

    } else {
      Serial.println("Start bit tidak valid. Abaikan.");
    }
  }
}
