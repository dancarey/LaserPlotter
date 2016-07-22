//step motor excitation
// full step; direction = TBD
// black, red -> red, green -> green, blue -> blue, black; repeat
// A, B -> B, A_ -> A_, B_ -> B_, A; repeat

// step motor wiring
//yellow = winding 1 center tap
//green = winding 2 center tap
int winding1_A = 9;  //black wire
int winding1_A_ = 10;  //green wire
int winding2_B = 5;  //red wire
int winding2_B_ = 6;  //blue wire
int rota_speed = 2;  //rotation speed

boolean slow_down = true;

int full_step = 0; //full_step count
int led = 13;

int laser = 23; // laser drive pin
int laser_pwm_val = 125;

void setup() {                
  pinMode(winding1_A, OUTPUT);
  pinMode(winding1_A_, OUTPUT);
  pinMode(winding2_B, OUTPUT);
  pinMode(winding2_B_, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  pinMode(laser, OUTPUT);
//  Serial.begin(9600);
}

void loop() {    
  analogWrite(laser, laser_pwm_val);
}
