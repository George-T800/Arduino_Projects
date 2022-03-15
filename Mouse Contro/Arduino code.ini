void setup() {
  Serial.begin(9600);
  pinMode(9,INPUT);     // SW pin
  digitalWrite(9,HIGH);

}

void loop() {
  int z=0,xpos=0,ypos=0;
  int x=analogRead(A0);
  int y=analogRead(A1);
  int sensitivity=80;    // you can adjust the sensitivity based on your comfort
  if(x>=550)                     // when moved up 
  xpos=map(x,550,1023,0,sensitivity); 
  if(x<=450)                   // when moved down
  xpos=map(x,450,0,0,-sensitivity);   
  if(y>=550)                    // when moved right
  ypos=map(y,550,1023,0,sensitivity);  
  if(y<=450)                  // when moved left
  ypos=map(y,450,0,0,-sensitivity); 
  if(digitalRead(9)==LOW)   // when SW is pressed 
  z=1;
  else
  z=0;
  if(xpos!=0 or ypos!=0 or z==1) // prints only when the joystick is moved or pressed
  {
  Serial.print(xpos);    // print the data and separating by ":"
  Serial.print(":");
  Serial.print(ypos);
  Serial.print(":");
  Serial.println(z);
  }
  delay(100);         // for normal operation
}
