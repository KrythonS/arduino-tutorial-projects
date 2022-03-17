const int out_pin_red = 11;
const int out_pin_blue = 10;
const int out_pin_green = 9;

const int analog_red = A0;
const int analog_green = A1;
const int analog_blue = A2;

int red_sensor_value = 0;
int green_sensor_value = 0;
int blue_sensor_value = 0;

int red_output = 0;
int blue_output = 0;
int green_output = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(out_pin_red, OUTPUT);
  pinMode(out_pin_blue, OUTPUT);
  pinMode(out_pin_green, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  red_sensor_value = analogRead(analog_red);
  delay(5);

  green_sensor_value = analogRead(analog_green);
  delay(5);

  blue_sensor_value = analogRead(analog_blue);
  delay(5);

  Serial.print("Raw sensor values \nred: ");
  Serial.println(red_sensor_value);
  
  Serial.print("green: ");
  Serial.println(green_sensor_value);

  Serial.print("blue: ");
  Serial.println(blue_sensor_value);

  red_output = red_sensor_value / 4;
  green_output = green_sensor_value / 4;
  blue_output = blue_sensor_value / 4;

  Serial.print("Mapped sensor values \nred: ");
  Serial.println(red_output);
  
  Serial.print("green: ");
  Serial.println(green_output);

  Serial.print("blue: ");
  Serial.println(blue_output);

  analogWrite(out_pin_red, 255);
  analogWrite(out_pin_blue, 255);
  analogWrite(out_pin_green, 255);
}
