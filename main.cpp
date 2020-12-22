#include <Arduino.h>
#include <math.h>
#define MOTOR_PWM_RIGHT_PIN 3
#define MOTOR_DIR1_RIGHT 2
#define MOTOR_DIR2_RIGHT 4

void silnik(float value ,int pwm_pin ,int dir_1_pin ,int dir_2_pin )// value-moc silnika wartość (od -1 do 1)  znak w zależniści od kierunku
{
  if(value>1 || value<-1)//sprawdzanie czy wartośc mieści się w przedziale od -1 do 1
    return;

  int moc=int (abs(value*255));//konwersja z % na przedział 0-255
  
  pinMode(pwm_pin,OUTPUT);// pwm pin ustaw wyjście

  if(value>=0)//jesli wartośc >=0 to obróć silnik w prawo ,w przeciwnym razie w lewo
  {
    digitalWrite(dir_1_pin,HIGH);//zmiana stanu logicznego na pinie
    digitalWrite(dir_2_pin,LOW);//zmiana stanu logicznego na pinie
  }
  else
  {
    digitalWrite(dir_1_pin,LOW);// zmiana stanu logicznego na pinie
    digitalWrite(dir_2_pin,HIGH);// zmiana syanu logicznego na pinie
  }
  analogWrite(pwm_pin,moc);
}
 
void setup()
{
  pinMode(MOTOR_PWM_RIGHT_PIN,OUTPUT);// ustawienie "MOTOR_PWM_RIGHT_PIN" jako wyjście
  pinMode(MOTOR_DIR1_RIGHT,OUTPUT);//  ustawienie "MOTOR_DIR1_RIGHT,OUTPUT" jako wyjście
  pinMode(MOTOR_DIR2_RIGHT,OUTPUT);//  ustawienie "MOTOR_DIR2_RIGHT,OUTPUT" jako wyjście
}
void loop() 
{
  //float moc=0.0f;  //255=100%     191-75%    127-50%   63-25%    0-0% 
  
  for( int i=0;i<5;i++)
  {
    silnik(0.1f*(i+1),MOTOR_PWM_RIGHT_PIN ,MOTOR_DIR1_RIGHT ,MOTOR_DIR2_RIGHT);
    delay(2000);
    silnik(-0.1f*(i+1),MOTOR_PWM_RIGHT_PIN ,MOTOR_DIR1_RIGHT ,MOTOR_DIR2_RIGHT);
    delay(2000);
  }  
    silnik(0.0f,MOTOR_PWM_RIGHT_PIN ,MOTOR_DIR1_RIGHT ,MOTOR_DIR2_RIGHT);
    while(1);  
}
//test line
//test line 2
