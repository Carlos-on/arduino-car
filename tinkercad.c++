// MOTOR 1
int motor1H = 2; // Controle de acionamento do motor
int motor1L = 7; // Controle de acionamento do motor
int foto1 = 8;

// MOTOR 2
int motor2H = 12; // Controle de acionamento do motor
int motor2L = 13; // Controle de acionamento do motor
int foto2 = 5;

int tmp = 300;

void setup() {
    // Define os pinos como saida
    pinMode(velM1, OUTPUT);
    pinMode(motor1H, OUTPUT);
    pinMode(motor1L, OUTPUT);
    pinMode(velM2, OUTPUT);
    pinMode(motor2H, OUTPUT);
    pinMode(motor2L, OUTPUT);
    pinMode(foto1, INPUT);
    pinMode(foto2, INPUT);
    Serial.begin(9600);
}

// status: -1 para tras, 0 para, 1 pra frente
void setMotorStatus(int pinH, int pinL, int status) {
  digitalWrite(pinH, status > 0 ? HIGH : LOW);
  digitalWrite(pinL, status < 0 ? HIGH : LOW);
}

void frente() {
  setMotorStatus(motor1H, motor1L, 1);
  setMotorStatus(motor2H, motor2L, 1);
  delay(tmp);
}

void re() {
  setMotorStatus(motor1H, motor1L, -1);
  setMotorStatus(motor2H, motor2L, -1);
  delay(tmp);
}

void direita() {
  setMotorStatus(motor1H, motor1L, 1);
  setMotorStatus(motor2H, motor2L, -1);
  delay(tmp);
}

void esquerda() {
  setMotorStatus(motor1H, motor1L, -1);
  setMotorStatus(motor2H, motor2L, 1);
  delay(tmp);
}

void pare() {
  setMotorStatus(motor1H, motor1L, 0);
  setMotorStatus(motor2H, motor2L, 0);
  delay(tmp);
}

void loop() {
  // Define a velocidade de rotacao
  int rpm = 255;
  digitalWrite(velM1, rpm);
  digitalWrite(velM2, rpm);

/*
  char kara;
  if(Serial.available()>0){
    kara = Serial.read();
  }

  if(kara == 'w'){
    frente();
  }else if(kara == 'a'){
    esquerda();
  }else if(kara == 's'){
    re();
  }else if(kara == 'd'){
    direita();
  }else if(kara == 'e'){
    pare();
  }
 */

  int luz1 = digitalRead(foto1);
  int luz2 = digitalRead(foto2);

  Serial.println(luz1);
  Serial.println(luz2);

  if (luz1 == LOW && luz2 == LOW) {
    frente();
  } else if (luz1 == LOW && luz2 == HIGH) {
    esquerda();
  } else if (luz1 == HIGH && luz2 == LOW) {
    direita();
  } else if (luz1 == HIGH && luz2 == HIGH) {
    pare();
  }
}
