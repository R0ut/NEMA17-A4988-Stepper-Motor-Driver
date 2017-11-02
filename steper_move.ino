//ardiuno used pins
const int stepPin = 3;
const int dirPin = 4;

int del = 0; // delay between single mottor step
int steps = 0; //motor steps
 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  Serial.begin(463611);
  Serial.setTimeout(0);
  
  digitalWrite(8,HIGH);//ms2
  digitalWrite(9,LOW);//ms3
  digitalWrite(10,LOW);//ms1
}
void loop() {
  while(!Serial.available()); //Wait for data from PC
  del = Serial.readString().toInt(); //Sets delay recived from PC
  for(int i=0;i<=5;i++)
  {
    steps++;
    Forwards(); //Execute one step forward
  }
  
  if(steps == 8400){
    steps =0;
    delayMicroseconds(1000);
    for(int j=0;j<8400;j++){
      Backward(); //Execute one step backward
    }
  }
  Serial.println(steps); //Send data to PC through serial   
}

//Forwards step
void Forwards()
{
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(del); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(del); 
}

//Backword step
void Backward()
{
  digitalWrite(dirPin,LOW); // Enables the motor to move in a back direction
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(400); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(400); 
}

