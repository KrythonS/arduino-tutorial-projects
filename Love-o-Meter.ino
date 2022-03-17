const int analogPin = A0;
bool calibrated = false;
float baseTemp = 0.0;
float totalTemp = 0.0;
float count = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pin = 2; pin < 5; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  Serial.println("Calibrating base temperature...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(analogPin);
  float sensorVolt = (sensorValue / 1024.0) * 5.0;
  float sensorTemp = (sensorVolt - 0.5) * 100;

  if (!calibrated) {
    count += 1;
    totalTemp += sensorTemp;
    baseTemp = totalTemp/count;

    if (count == 10) {
      calibrated = true;
      Serial.print("Base Temperature: ");
      Serial.println(baseTemp);
    }
  }
  else {
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    Serial.print("Sensor Voltage: ");
    Serial.println(sensorVolt, 10);
    Serial.print("Sensor Temp: ");
    Serial.println(sensorTemp, 10);
  
    if (sensorTemp < baseTemp+2) {
      for (int pin = 2; pin < 5; pin++) {
        digitalWrite(pin, LOW);
      }
    }
    else if (sensorTemp >= baseTemp+2 && sensorTemp < baseTemp+4) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);  
    }
     else if (sensorTemp >= baseTemp+4 && sensorTemp < baseTemp+6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);  
    }
     else if (sensorTemp >= baseTemp+6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);  
    }
  }
  delay(1000);
}
