//veriables
int right=4;
int left=7;
int sensor1;
int sensor2;
int option=0;


int Ena= 11;
int Enb=3;

int IN_1=10;
int IN_2=9;
int IN_3=6;
int IN_4=5;


void setup() {
  // put your setup code here, to run once:
  pinMode(right, INPUT);
  pinMode(left, INPUT);


  pinMode(Ena,OUTPUT);
  pinMode(Enb,OUTPUT);
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(Ena, 150);
  analogWrite(Enb, 150);
   //reading the right and left line sensor
  sensor1=digitalRead(right);
  sensor2=digitalRead(left);

  //checking for option to determine action
  option=check_option(sensor1, sensor2);
  
  switch(option){
    case 4:
      Serial.println(" STOP ");
      Stop();
      break;
    

    case 2:
      Serial.println(" turn right ");
      
      Left();
      break;

    case 3:
      Serial.println(" turn left ");
      Right();    
      break;

    case 1:
      Serial.println(" straiht ");
      forward();
      break;
    
  }
  //printing out option
  Serial.print(sensor1);
  Serial.print(" , ");
  Serial.print(sensor2);
  Serial.print(" , ");
  Serial.println(option);
  //delay(1000);
  
}


int check_option(int a, int b){
  int check;
  if (a == 0 && b==0){
    check=1;
    //Serial.println(" stop ");
  }else if(a == 1 && b==0){
    check=2;  
    //Serial.println(" turn right ");
  }else if(a == 0 && b==1){
    check=3;  
    //Serial.println(" turn left ");
  }else if(a == 1 && b==1){
    check=4;  
    //Serial.println(" straight ");
  }

  return check;
}


void forward(){
   digitalWrite(IN_1,HIGH);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,HIGH);
}


void backward(){
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,HIGH);
   digitalWrite(IN_3,HIGH);
   digitalWrite(IN_4,LOW);
   
}



void Right(){
   digitalWrite(IN_1,HIGH);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,HIGH);
   digitalWrite(IN_4,LOW);
   delay(2);
   //Stop();
}


void Left(){
    digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,HIGH);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,HIGH);
   delay(2);
   //Stop();
}

void Stop(){
   digitalWrite(IN_1,LOW);
   digitalWrite(IN_2,LOW);
   digitalWrite(IN_3,LOW);
   digitalWrite(IN_4,LOW);
}
