#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

const int soilMoisturePin = A0; 
const int motorPin = 2;
const int wet = 80;
const int dry = 40;
const int balance = 60;
 
int sensorValue = 0;    
int outputValue = 0; 
int sensor;
int lastSensorValue;

char buf[20];

void showProjectTitle()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("SMART GARDENING");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  delay(1500);
}

void showStudentNumbers()
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("22.11.5032");
  lcd.setCursor(3, 1);
  lcd.print("22.11.5066");
  delay(1000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("22.11.5022");
  lcd.setCursor(3, 1);
  lcd.print("22.11.5021");
  delay(1000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("22.11.5020");
  delay(1000);
  lcd.clear();
}

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  lcd.init();
  showProjectTitle();
  showStudentNumbers();                      
  lcd.setCursor(2, 0);
  lcd.print("Soil Moisture");
  Serial.print("Soil Moisture = ");
  Serial.print(outputValue);
  Serial.println(" %");
  statusSensor ();

}


void loop()
{
  sensorValue = analogRead(soilMoisturePin);
  outputValue = map(sensorValue, 0, 1023, 100, 0);
  
  if (sensorValue != lastSensorValue)
  {
    statusSensor ();
    lastSensorValue = sensorValue;
  }

  if (outputValue >= balance)
  {    
    digitalWrite(motorPin, LOW);
  }

  delay(200);
}

void statusSensor()
{
  lcd.setCursor(2, 1);
  sprintf(buf, "%3d %%", outputValue);
  lcd.print(buf);
  
  if (outputValue > wet)
  {
    Serial.println("Status: Tanah terlalu basah");
    lcd.setCursor(8, 1);
    sprintf(buf, "Wet       ");
    lcd.print(buf);
  }
  else if (outputValue <= wet && outputValue >= dry)
  {
    Serial.println("Status: Kelembapan normal");
    lcd.setCursor(8, 1);
    sprintf(buf, "Perfect   ");
    lcd.print(buf);
  }
  else
  {
    Serial.println("Status: Tanah terlalu kering [PUMP ON]");
    digitalWrite(motorPin, HIGH);
    lcd.setCursor(8, 1);
    sprintf(buf, "Dry      ");
    lcd.print(buf);
  }
}
