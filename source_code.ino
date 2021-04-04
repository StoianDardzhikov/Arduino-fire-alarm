const int GAS_PIN = A0;

const int GREEN_LED_PIN = 13;
const int YELLOW_LED_PIN = 12;
const int ORANGE_LED_PIN = 11;
const int RED_LED_PIN = 10;

const int PIEZO_PIN = 6;

const int START_BUTTON_PIN = 7;

const int END_BUTTON_PIN = 5;

bool buttonPressed = false;

void setup()
{
  pinMode(GREEN_LED_PIN,OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(ORANGE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(START_BUTTON_PIN, INPUT);
  pinMode(END_BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int gas = analogRead(GAS_PIN);//85 360
  gas = map(gas, 85,360, 0, 100);
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(YELLOW_LED_PIN, gas >= 30 ? HIGH:LOW);
  digitalWrite(ORANGE_LED_PIN, gas >= 50 ? HIGH:LOW);
  digitalWrite(RED_LED_PIN, gas >= 80 ? HIGH:LOW);
  if (gas >= 50 || buttonPressed) {
  	tone(PIEZO_PIN,1000,100);
    if (digitalRead(END_BUTTON_PIN) == 1) buttonPressed = false;
  }
  if (digitalRead(START_BUTTON_PIN) == 1) buttonPressed = true;
  delay(200); // Wait for 100 millisecond(s)
}