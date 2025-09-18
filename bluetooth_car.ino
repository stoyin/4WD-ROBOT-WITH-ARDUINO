
#include<Servo.h>
#include <SoftwareSerial.h>



#define Ena 3
#define Enb 6

#define IN_1 4
#define IN_2 5
#define IN_3 7
#define IN_4 8

SoftwareSerial BTSerial(10, 11);//tx 10, rx 11
//Servo myServo;
char cmd;

void forward()
  {

   digitalWrite(IN_1,HIGH);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,HIGH);
   digitalWrite(IN_4,LOW);
   delay(1000);
  }

  void backward()
  {
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,HIGH);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,HIGH);
   delay(1000);
  }


    void right()
  {

   digitalWrite(IN_1,HIGH);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,HIGH);
   delay(1000);
  }


    void left()
  {
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,HIGH);
   digitalWrite(IN_3,HIGH);
   digitalWrite(IN_4,LOW);
   delay(1000);
  }

  void stoped()
  {
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,LOW);
   
  }


void setup() {
  // put your setup code here, to run once:

  Serial.begin(38400);
  //myServo.attach(8);
  BTSerial.begin(38400);

  pinMode( Ena,OUTPUT);
  pinMode( Enb,OUTPUT);
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);

  analogWrite(Ena, 200);
  analogWrite(Enb, 200);

}

void loop() {
  // put your main code here, to run repeatedly:
      if(BTSerial.available() >0){
       cmd =BTSerial.read();
       switch(cmd){
          case 'F':
            //myServo.write(180);
            //Serial.println("F command");
            
            right();
            break;
          case 'B':
            //myServo.write(90);
            //Serial.println("B command");
            
            left();
            break;
          case 'R':
            forward();
            break;

          case 'L':
            backward();
            break;
          
          default:
            stoped();

        }
      }

}
