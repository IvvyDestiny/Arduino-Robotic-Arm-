// Inclua a biblioteca do servo
#include <Servo.h>

// Pinos para os servos
const int servoPin1 = 9;
const int servoPin2 = 10;
const int servoPin3 = 11;
const int servoPin4 = 12;

// Pinos para os joysticks
const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickZPin = A2;
const int joystickWPin = A3;

// Pinos para os LEDs
const int ledPin1 = 2;
const int ledPin2 = 3;

// Intervalo para leitura dos valores dos joysticks
const int joystickRange = 1023;

// Ângulos mínimos e máximos para os servos
const int servoMinAngle = 0;
const int servoMaxAngle = 180;

// Variáveis para armazenar as posições dos servos
int servoPos1 = 90; // Posição inicial
int servoPos2 = 90; // Posição inicial
int servoPos3 = 90; // Posição inicial
int servoPos4 = 90; // Posição inicial

// Variáveis para armazenar os valores dos joysticks
int joystickXValue = 0;
int joystickYValue = 0;
int joystickZValue = 0;
int joystickWValue = 0;

// Variáveis para armazenar o estado dos LEDs
bool led1On = false;
bool led2On = false;

// Criar objetos do tipo Servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Inicializar os objetos dos servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  // Configurar os pinos dos LEDs como saída
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Ler os valores dos joysticks
  joystickXValue = analogRead(joystickXPin);
  joystickYValue = analogRead(joystickYPin);
  joystickZValue = analogRead(joystickZPin);
  joystickWValue = analogRead(joystickWPin);

  // Mapear os valores dos joysticks para a faixa de ângulos dos servos
  int mappedX = map(joystickXValue, 0, joystickRange, servoMinAngle, servoMaxAngle);
  int mappedY = map(joystickYValue, 0, joystickRange, servoMinAngle, servoMaxAngle);
  int mappedZ = map(joystickZValue, 0, joystickRange, servoMinAngle, servoMaxAngle);
  int mappedW = map(joystickWValue, 0, joystickRange, servoMinAngle, servoMaxAngle);

  // Atualizar as posições dos servos de acordo com os valores dos joysticks
  servo1.write(mappedX);
  servo2.write(mappedY);
  servo3.write(mappedZ);
  servo4.write(mappedW);

  // Verificar se o botão 1 foi pressionado
  if (digitalRead(ledPin1) == LOW)

  // Verificar se o botão 1 foi pressionado
  if (digitalRead(ledPin1) == LOW) {
    // Código a ser executado quando o botão 1 for pressionado
    // Acender o LED 1
    digitalWrite(ledPin1, HIGH);
  } else {
    // Código a ser executado quando o botão 1 não estiver pressionado
    // Apagar o LED 1
    digitalWrite(ledPin1, LOW);
  }

  // Verificar se o botão 2 foi pressionado
  if (digitalRead(ledPin2) == LOW) {
    // Código a ser executado quando o botão 2 for pressionado
    // Acender o LED 2
    digitalWrite(ledPin2, HIGH);
  } else {
    // Código a ser executado quando o botão 2 não estiver pressionado
    // Apagar o LED 2
    digitalWrite(ledPin2, LOW);
  }
}
