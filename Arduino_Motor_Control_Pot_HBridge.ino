const int pot_pin = A5;
const int enable_pin = 9;
const int motor_control_1 = 12;
const int motor_control_2 = 7;

const int motor_fwd_button = 3;
const int motor_rev_button = 4;

void setup() {
  pinMode(pot_pin, INPUT);
  pinMode(enable_pin, OUTPUT);
  pinMode(motor_fwd_button, INPUT);
  pinMode(motor_rev_button, INPUT);

  digitalWrite(enable_pin, LOW);
}

void loop() {
  int motor_speed = map(analogRead(pot_pin), 0, 1023, 0, 255);
  int direction_fwd = digitalRead(motor_fwd_button);
  int direction_rev = digitalRead(motor_rev_button);
  delay(5);


  if(direction_fwd && !direction_rev){
    digitalWrite(motor_control_1, LOW);
    digitalWrite(motor_control_2, LOW);
    delay(500);
    analogWrite(enable_pin, motor_speed);
    digitalWrite(motor_control_1, HIGH);
    digitalWrite(motor_control_2, LOW);
  }

  else if(!direction_fwd && direction_rev){
    digitalWrite(motor_control_1, LOW);
    digitalWrite(motor_control_2, LOW);
    delay(500);
    analogWrite(enable_pin, motor_speed);
    digitalWrite(motor_control_1, LOW);
    digitalWrite(motor_control_2, HIGH);
  }
}
