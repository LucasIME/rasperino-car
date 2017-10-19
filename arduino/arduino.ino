// left motor
int IN1 = 2 ;
int IN2 = 3 ;
 
// right motor
int IN3 = 4 ;
int IN4 = 5 ;

// initialize
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}

void leftWheelForward() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void leftWheelStop() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH); 
}

void leftWheelBackward() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}

void rightWheelForward() {
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void rightWheelStop() {
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH); 
}

void rightWheelBackward() {
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
}

void forward() {
  rightWheelForward();
  leftWheelForward();
}

void halt() {
  rightWheelStop();
  leftWheelStop();
}

void backward() {
  rightWheelBackward();
  leftWheelBackward();
}

void turnLeft() {
  rightWheelForward();
}

void spinLeft() {
  rightWheelForward();
  leftWheelBackward();
}

void turnRight() {
  leftWheelForward();
}

void spinRight() {
  rightWheelBackward();
  leftWheelForward();
}

void process_command() {
  if (Serial.available()) {
    int command = Serial.read();

    if (command == 'w') {
      forward();
      return;
    }
    if (command == 'h') {
      halt();
      return;
    }
    if (command == 's') {
      backward();
      return;
    }
    if (command == 'q') {
      turnLeft();
    }
    if (command == 'e') {
      turnRight();
    }
    if (command == 'a') {
      spinLeft();
    }
    if (command == 'd') {
      spinRight();
    }
  }
}


int interval = 10;
int skip = 0;

void loop(){
  bool led_turn = (skip++ % 10 == 0);
  
  if (led_turn) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  delay(interval);
  process_command();
  delay(interval);
  
  if (led_turn) {
    digitalWrite(LED_BUILTIN, LOW);
  }
}


