int duration;
int distance;
int trig=7;
int echo=7;

int red=3;
int yellow=4;
int green=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trig, LOW);
 duration = pulseIn(echo, HIGH);
 distance = duration/58.2;
  Serial.println(distance);
  delay(500);


  if (distance <= 100 && distance >= 60){
      digitalWrite(green,HIGH);
      digitalWrite(yellow,LOW);
      digitalWrite(red,LOW);
    }else if(distance <= 59 && distance >= 30 ){
      
      digitalWrite(green,LOW);
      digitalWrite(yellow,HIGH);
      digitalWrite(red,LOW);
      } else if (distance<=29){
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(red,HIGH);
        
        }else{
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(red,LOW);
          
          
          }
}
