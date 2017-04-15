#include <Servo.h>

int btnPin = 3; // Кнопка запуска и зарядки

int readyPin = 5; // Датчик зарядки

int servoPin = 2; // сервопривод каретки 

int motorPin = 4; // Мотор натяжки

// состояние системы, true - готов
boolean readyCatapult = false;

Servo servo;

void setup() {

  servo.attach(servoPin);
  //Serial.begin(9600);
  pinMode(motorPin, OUTPUT); 
  digitalWrite(motorPin, LOW); 
  readyCatapult = digitalRead(readyPin);
  servo.write(138);

  delay(100);
  servo.detach();
  
}

void loop() {
  
  readyCatapult = digitalRead(readyPin); // Кнопка - катапульта заряжена или нет
  int btnGoalOneState = digitalRead(btnPin); // Кнопка запуска
  //Serial.println(readyCatapult);

  // Если нажили кнопку
  if(btnGoalOneState == 1) {
    servo.attach(servoPin);
    // если готова к высрелу
    if(readyCatapult == 1) {
      servo.write(100);
      delay(100);
      servo.detach();
    } else {
      // Заряжаем катапульту
      servo.write(138);
      while(digitalRead(readyPin) == 0) { // Крутить моторчик пока кнопка не нажмется
        digitalWrite(motorPin, HIGH);
      }
      digitalWrite(motorPin, LOW);
      servo.detach();
    }
    
  }
  
 
  


}
