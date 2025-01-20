// Define pins for IR sensors
#define LEFT_MOST_SENSOR_PIN 2
#define MIDDLE_LEFT_SENSOR_PIN 3
#define MIDDLE_RIGHT_SENSOR_PIN 4
#define RIGHT_MOST_SENSOR_PIN 11

// Define pins for motor control
#define ENA 5
#define IN1 7 //left forward
#define IN2 8 // left backward
#define IN3 9 // right forward 
#define IN4 10 // right backward
#define ENB 6

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

    //sensor pins as input
  pinMode(LEFT_MOST_SENSOR_PIN, INPUT);
  pinMode(MIDDLE_LEFT_SENSOR_PIN, INPUT);
  pinMode(MIDDLE_RIGHT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_MOST_SENSOR_PIN, INPUT);

  Serial.begin(9600);

}


void loop() {
int lm = digitalRead(LEFT_MOST_SENSOR_PIN);
int l = digitalRead(MIDDLE_LEFT_SENSOR_PIN);
int r = digitalRead(MIDDLE_RIGHT_SENSOR_PIN);
int rm = digitalRead(RIGHT_MOST_SENSOR_PIN);

//A part
if(lm==HIGH && l == LOW && r == LOW && rm == HIGH){  //1001
   moveForward();
}else if(lm==HIGH && l == HIGH && r == LOW && rm == HIGH){ //1101
   moveRight();
}else if(lm==HIGH && l == LOW && r == HIGH && rm == HIGH){ //1011
   moveLeft();
}

//B part
else if(lm==HIGH && l == HIGH && r == LOW && rm == LOW){  //1100
   moveForward();
}else if(lm==LOW && l == LOW && r == HIGH && rm == HIGH){ //1000
   moveForward();
}else if(lm==HIGH && l == HIGH && r == HIGH && rm == LOW){ //1110
   moveRight();
}else if(lm==HIGH && l == LOW && r == LOW && rm == LOW){ //1000
   moveLeft();
}else if(lm==LOW && l == LOW && r == LOW && rm == HIGH){ //0001
   moveRight();
}else if(lm==LOW && l == HIGH && r == HIGH && rm == HIGH){ //0111
   moveLeft();
}

// C part 
else if(lm==LOW && l == HIGH && r == HIGH && rm == LOW){ //0110
   moveForward();
}else if(lm==LOW && l == LOW && r == HIGH && rm == LOW){ //0010
   moveRight();
}else if(lm==LOW && l == HIGH && r == LOW && rm == LOW){ //0100
   moveLeft();
}else if(lm==HIGH && l == LOW && r == LOW && rm == LOW){ //1000
  moveLeft();}
  else if (lm==LOW && l == LOW && r == LOW && rm == LOW){
    stop();
  }
else{
  moveForward();
}
// 
}

const int speed = 125;

void moveForward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// Function to turn left
void moveLeft() {
  analogWrite(ENA,speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn right
void moveRight() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
