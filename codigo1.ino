
// Definição dos pinos
const int sensorUmidade = A0;  // Pino analógico onde o sensor está conectado
const int motorPin = 8;        // Pino digital que controla o motor
const int limiarSeco = 500;    // Valor limite para considerar o solo seco (ajuste conforme necessário)

void setup() {
  pinMode(sensorUmidade, INPUT); // Configura o sensor como entrada
  pinMode(motorPin, OUTPUT);     // Configura o pino do motor como saída
  digitalWrite(motorPin, LOW);   // Garante que o motor esteja desligado no início
  
  Serial.begin(9600);           // Inicia a comunicação serial para depuração
}

void loop() {
  int leituraUmidade = analogRead(sensorUmidade); // Lê o valor do sensor
  Serial.print("Valor do sensor de umidade: ");
  Serial.println(leituraUmidade); // Mostra o valor no monitor serial

  if (leituraUmidade > limiarSeco) {
    // Solo está seco: liga o motor
    Serial.println("Solo seco - Motor LIGADO");
    digitalWrite(motorPin, HIGH); // Liga o motor
  } else {
    // Solo está úmido: desliga o motor
    Serial.println("Solo úmido - Motor DESLIGADO");
    digitalWrite(motorPin, LOW); // Desliga o motor
  }

  delay(2000); // Aguarda 2 segundos antes de fazer a próxima leitura
}
