int Ena= 11;
int Enb=3;

int IN_1=10;
int IN_2=8;
int IN_3=6;
int IN_4=5;

float dist;
float duration;
float distance;
int trig=7;
int echo=2;


void setup() {
  // put your setup code here, to run once:
   pinMode(trig, OUTPUT);
   pinMode(echo,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(Ena, 150);
  analogWrite(Enb, 150);
  dist = get_distance();

  if (dist<=10){
    stoped();
    
  }else{
    
    forward();
    backward();
    
    }
}


float get_distance(){
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trig, LOW);
 duration = pulseIn(echo, HIGH);
 distance = duration/58.2;
 Serial.println(distance);
 //delay(500);
 return distance;
  
}
void forward(){

   digitalWrite(IN_1,HIGH);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,HIGH);
   //digitalWrite(13,HIGH);
  delay(3000);
}

void backward(){
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,HIGH);
   digitalWrite(IN_3,HIGH);
   digitalWrite(IN_4,LOW);
   //digitalWrite(13,LOW);
   delay(3000);
  }

  void stoped(){
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,LOW);
    
  }
