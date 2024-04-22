//veriables
int right=4;
int left=7;
int sensor1;
int sensor2;
int option=0;

void setup() {
  // put your setup code here, to run once:
pinMode(right, INPUT);
pinMode(left, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //reading the right and left line sensor
  sensor1=digitalRead(right);
  sensor2=digitalRead(left);

  //checking for option to determine action
  option=check_option(sensor1, sensor2);
  
  switch(option){
    case 1:
      Serial.println(" STOP ");
      break;
    

    case 2:
      Serial.println(" turn right ");
      break;

    case 3:
      Serial.println(" turn left ");
      break;

    case 4:
      Serial.println(" straiht ");
      break;
    
  }
  //printing out option
  Serial.print(sensor1);
  Serial.print(" , ");
  Serial.print(sensor2);
  Serial.print(" , ");
  Serial.println(option);
  delay(1000);
  
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
