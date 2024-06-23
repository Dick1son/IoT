#define NUM_BLINK 5

void setup()
{
  Serial.begin(9600);
  
  pinMode(8, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void trafficLights (){
  bool ledState = 0;
  delay(500);
  
  for(int i = 0; i < NUM_BLINK; i++){
    digitalWrite(4, ledState);
    delay(300);
    ledState = !ledState;
  }
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  
  digitalWrite(5, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(6, HIGH);
  delay(2000);
  
  ledState = 0;
  for(int i = 0; i < NUM_BLINK; i++){
    digitalWrite(6, ledState);
    delay(300);
    ledState = !ledState;
  }
  
  digitalWrite(5, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
}

bool flag = false;
void loop()
{
  bool btnState = !digitalRead(8);
    
  if (btnState && !flag) {
    flag = true;
    trafficLights();
  }
  
  if (!btnState && flag)
    flag = false;  
}