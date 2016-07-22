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

void setup() {                
  pinMode(winding1_A, OUTPUT);
  pinMode(winding1_A_, OUTPUT);
  pinMode(winding2_B, OUTPUT);
  pinMode(winding2_B_, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {    
  Serial.print("slow down = ");
  Serial.print(slow_down);
  Serial.print(" | ");
  Serial.print("speed = ");
  Serial.print(rota_speed);
  Serial.print(" | ");
  Serial.print("full step = ");
  Serial.println(full_step);
  
  if(full_step == 200){
    digitalWrite(led, HIGH);      
    if(slow_down) rota_speed+=1;
    else rota_speed-=1;    
  }else if (full_step == 400){
    digitalWrite(led, LOW);      
    full_step = 0;
    if(slow_down) rota_speed+=1;
    else rota_speed-=1;    
  } 

  if(rota_speed == 2) slow_down = true;
  if(rota_speed == 10) slow_down = false;
  
  digitalWrite(winding1_A, HIGH);
  digitalWrite(winding1_A_, LOW);
  digitalWrite(winding2_B, HIGH);
  digitalWrite(winding2_B_, LOW);
  ++full_step;
  delay(rota_speed);
  digitalWrite(winding1_A, LOW);
  digitalWrite(winding1_A_, HIGH);
  digitalWrite(winding2_B, HIGH);
  digitalWrite(winding2_B_, LOW);
  ++full_step;
  delay(rota_speed);
  digitalWrite(winding1_A, LOW);
  digitalWrite(winding1_A_, HIGH);
  digitalWrite(winding2_B, LOW);
  digitalWrite(winding2_B_, HIGH);
  ++full_step;
  delay(rota_speed);
  digitalWrite(winding1_A, HIGH);
  digitalWrite(winding1_A_, LOW);
  digitalWrite(winding2_B, LOW);
  digitalWrite(winding2_B_, HIGH);
  ++full_step;
  delay(rota_speed);  
}
