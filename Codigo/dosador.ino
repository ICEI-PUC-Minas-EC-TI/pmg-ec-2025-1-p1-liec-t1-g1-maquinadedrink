#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

BluetoothSerial SerialBT;

int valorRecebido;
const int bomba1 = 26;
const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
const int potPin = 34;

const int ledR = 12;
const int ledG = 13;
const int ledB = 14;

const int limiteModoBaixo = 1700;
const int limiteModoAlto = 2300;
int contadorBaixo = 0;
int contadorAlto = 0;
const int leiturasConsecutivas = 3;

bool modoAtual = true;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("NOME_DO_GRUPO");
  Serial.println("Pronto para parear!");

  pinMode(bomba1, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, HIGH);
}

void setLedModo(bool modoComSensor) {
  if (modoComSensor) {
    // Azul
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);
  } else {
    // Vermelho
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, HIGH);
  }
}

float medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duracao = pulseIn(ECHO_PIN, HIGH, 30000);
  return duracao * 0.034 / 2;
}

void loop() {
  int leituraPot = analogRead(potPin);

  // Histerese com contagem
  if (leituraPot < limiteModoBaixo) {
    contadorBaixo++;
    contadorAlto = 0;
  } else if (leituraPot > limiteModoAlto) {
    contadorAlto++;
    contadorBaixo = 0;
  } else {
    contadorBaixo = 0;
    contadorAlto = 0;
  }

  if (contadorBaixo >= leiturasConsecutivas) {
    modoAtual = true;
  }
  if (contadorAlto >= leiturasConsecutivas) {
    modoAtual = false;
  }

  setLedModo(modoAtual);  
  float distancia = medirDistancia();

  if (SerialBT.available() > 0) {
    valorRecebido = SerialBT.parseInt();
    Serial.print("Valor recebido: ");
    Serial.println(valorRecebido);

    if (modoAtual && distancia >= 20) {
      Serial.println("Objeto muito distante, comando ignorado.");
      return;
    }

    int tempo = (valorRecebido * 1000) / 22.5;
    digitalWrite(bomba1, HIGH);
    delay(tempo);
    digitalWrite(bomba1, LOW);
  }

  delay(25);
}
