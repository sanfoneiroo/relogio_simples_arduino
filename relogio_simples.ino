#include <LiquidCrystal.h>

// LCD Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Pinos
#define BUTTONS_PIN A0
#define PIN_LANTERNA 10

// Relógio simples
int hora = 0;
int minuto = 0;
unsigned long ultimoMillis = 0;

bool lanternaLigada = true;

String comando = "";

// ================= SETUP ======================
void setup() {
  lcd.begin(16, 2);
  pinMode(PIN_LANTERNA, OUTPUT);

  digitalWrite(PIN_LANTERNA, HIGH);

  Serial.begin(9600);
  delay(200);

  // Info CLI
  Serial.println("Relógio simples");
  Serial.println("Aperte Select para editar o relógio");
}

// ================= LOOP =======================
void loop() {
  // --- Atualiza relógio ---
  if (millis() - ultimoMillis >= 60000) {
    ultimoMillis = millis();
    minuto++;
    if (minuto >= 60) {
      minuto = 0;
      hora = (hora + 1) % 24;
    }
  }
  // --- Atualiza LCD ---
  mostrarLCD();
  
// --- Leitura botões ---
  int botao = lerBotao();
  if (botao == 0) { // Direita
    lanternaLigada = true;
    digitalWrite(PIN_LANTERNA, HIGH);
  } else if (botao == 1) { // Cima
  } else if (botao == 2) { // Baixo
  } else if (botao == 3) { // Esquerda
    lanternaLigada = false;
    digitalWrite(PIN_LANTERNA, LOW);
  } else if (botao == 4) { // Select
    ajustarRelogio();    
  }
}

// ================= FUNÇÕES ====================

// Atualiza LCD com status
void mostrarLCD() {
  lcd.setCursor(0, 0);
  if (hora < 10) lcd.print("0");
  lcd.print(hora);
  lcd.print(":");
  if (minuto < 10) lcd.print("0");
  lcd.print(minuto);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Relogio Arduino");
}

// Identifica botão
int lerBotao() {
  int leitura = analogRead(BUTTONS_PIN);
  if (leitura > 1000) return -1;
  if (leitura < 100) return 0;   // Direita
  if (leitura < 200) return 1;   // Cima
  if (leitura < 400) return 2;   // Baixo
  if (leitura < 600) return 3;   // Esquerda
  if (leitura < 800) return 4;   // Select
  return -1;
}

// Limpa buffer Serial
void limparBufferSerial() {
  while (Serial.available() > 0) Serial.read();
}

// Ajusta relógio
void ajustarRelogio() {
  Serial.println("Digite a hora no formato HHMM: ");
  limparBufferSerial();
  while (Serial.available() == 0);
  int entrada = Serial.parseInt();
  limparBufferSerial();
  hora = entrada / 100;
  minuto = entrada % 100;
  ultimoMillis = millis();
}


// Mostra hora formatada
void mostraHora(int h, int m) {
  if (h < 10) Serial.print("0");
  Serial.print(h);
  Serial.print(":");
  if (m < 10) Serial.print("0");
  Serial.print(m);
}


