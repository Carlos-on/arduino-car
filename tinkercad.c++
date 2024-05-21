//MOTOR 1   
int velM1 = 3; //Controle de velocidade do Motor
int motor1H = 2; //Controle de acionamento do motor
int motor1L = 7; //Controle de acionamento do motor
int foto1 = 8;

//MOTOR 2
int velM2 = 3; //Controle de velocidade do Motor
int motor2H = 12; //Controle de acionamento do motor
int motor2L = 13; //Controle de acionamento do motor
int foto2 = 5;

int tmp = 300;

   
void setup()  
{  
  //Define os pinos como saida  
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
   
void loop()  
{  
  //Define a velocidade de rotacao  
  int rpm = 255;  
  digitalWrite(velM1,rpm);   
  digitalWrite(velM2,rpm);
  
  /*char kara;
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
  //Para o motor 
  //pare();  
  //frente();
  //pare();
  //re();
  //pare();
  //direita();
  //pare();
  //esquerda();
  //pare();
     
  /*void frente()
  {
  digitalWrite(motor1H, HIGH);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, HIGH);  
  digitalWrite(motor2L, LOW); 
  delay(tmp);  
  }

  void re()
  {
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, HIGH);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, HIGH); 
  delay(tmp);
  }

  void direita()
  {
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, HIGH);
  digitalWrite(motor2H, HIGH);  
  digitalWrite(motor2L, LOW); 
  delay(tmp);
  }

  void esquerda()
  {
  digitalWrite(motor1H, HIGH);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, HIGH); 
  delay(tmp);
  }

  void pare()
  {
  digitalWrite(motor1H, LOW);  
  digitalWrite(motor1L, LOW);
  digitalWrite(motor2H, LOW);  
  digitalWrite(motor2L, LOW); 
  delay(tmp);
  }*/

  float luz = digitalRead(8);
  float luz2 = digitalRead(5);
  Serial.println(luz);
  Serial.println(luz2);
  if(luz ==0 && luz2 == 0){
    digitalWrite(motor1H, HIGH);
    digitalWrite(motor2H, HIGH);
  }else if(luz2 == 0 && luz == 1){
    digitalWrite(motor1H, HIGH);
    digitalWrite(motor2H, LOW);
  }else if(luz2 == 1 && luz == 0){
    digitalWrite(motor1H, LOW);
    digitalWrite(motor2H, HIGH);
  }else if(luz == 1 && luz2 == 1){
    digitalWrite(motor1H, LOW);
    digitalWrite(motor2H, LOW);
  }
}
