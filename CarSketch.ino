#define IN1  7   //K1、K2 motor direction
#define IN2  8     //K1、K2 motor direction
#define IN3  9    //K3、K4 motor direction
#define IN4  10   //K3、K4 motor direction
#define ENA  5    // Needs to be a PWM pin to be able to control motor speed ENA
#define ENB  6    // Needs to be a PWM pin to be able to control motor speed ENA
/*motor control*/
void go_back()  //motor rotate clockwise -->robot go ahead
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4,LOW);
}
void go_ahead() //motor rotate counterclockwise -->robot go back
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,HIGH); 
}
void go_stop() //motor brake -->robot stop
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4,LOW); 
}
void turn_right(int t)  //left motor rotate clockwise and right motor rotate counterclockwise -->robot turn right
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(t);
}
void turn_left(int t) //left motor rotate counterclockwise and right motor rotate clockwise -->robot turn left
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(t);
}
/*set motor speed */
void set_motorspeed(int lspeed,int rspeed) //change motor speed
{
  analogWrite(ENA,lspeed);//lspeed:0-255
  analogWrite(ENB,rspeed);//rspeed:0-255   
}
void setup() {
  /******L298N******/
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(ENA, OUTPUT);  
  pinMode(ENB, OUTPUT);

  set_motorspeed(125,125);

  // Step 1: Move forward 6 ft
  
  ForwardSixFeet();
  go_stop();
  delay(100);
  
  // Step 2: Turn right 90 degrees
  turn_right(310);

  delay(100);
  
  // Step 3: Drive backward 6 ft
  go_back();
  delay(3100);

  go_stop();
  delay(100);

  // Step 4: Turn right 90 degrees
  turn_right(310);
  go_stop();
  delay(100);
  
  // Step 5: Drive forward 6 ft
  ForwardSixFeet();

/*
  // Step 6: Turn right 135 degrees
  turn_right(500);
*/

  //turn_right(990);


  // Stop
  go_stop();
}

void ForwardSixFeet()
{
  go_ahead();
  delay(3100);
}

void loop() {
  
}
