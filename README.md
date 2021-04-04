# Пожароизвестителна система с ардуино уно 🚒

Това е система създадена с помощта на платформата Tinkercad и е предназначена да известява потребителите при пожар.

# Използвани компоненти ⚙️

|Елемент|Брой|
|---|---|
|Arduino Uno R3|1|
|Бутон за натискане|2|
|Сензор за дим|1|
|1000 Ω резистор|8|
|Зелен светлодиод|1|
|Жълт светлодиод|1|
|Оранжев светлодиод|1|
|Червен светлодиод|1|
|Пиезо|1|
|Кабели|~20|

# Електрическа схема 🔌
![image](https://user-images.githubusercontent.com/75749242/113511869-b3c47200-956a-11eb-8364-68524723e025.png)

# Описание на системата 📔
Сензорът за дим постоянно изпраща на микроконтролера стойностите, които регистрира. При по-високи стойности микроконролера изпраща сигнали към светлинния индикатор съответно да включи или изключи дадена лампа спрямо стойностите на сензора за дима и включва звукова аларма, която известява всички, че има пожар.
Ако системата не долавя дим, но все пак има пожар, тя може да бъде задействана ръчно от съответния бутон.
Систената също може да бъде изключена от бутон, само ако сензора на дима не отчита високи стойности на дим.

# Сорс код 💻
```c++
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
  int gas = analogRead(GAS_PIN);
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
  delay(200);
}
```

# Прокет
https://www.tinkercad.com/things/5XuQvOjJWsq-stunning-wluff-kasi
