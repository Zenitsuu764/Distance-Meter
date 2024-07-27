#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);


#define echoPin 2
#define trigPin 3

long duration;
			
int distance;

int red = 9;
int green = 10;
	

void setup()
{
  	lcd.begin(16,2);
	Serial.begin(9600);
  	pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);
	pinMode(trigPin,OUTPUT);
			
	pinMode(echoPin, INPUT);

	Serial.begin(9600); 
					 
	lcd.print("Distance measurement"); 
	delay(1000);
}

void loop()
{
  
  
  	
	digitalWrite(trigPin, LOW);
	delay(2);
	digitalWrite(trigPin, HIGH);
	delay(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2;
  	
  	
  	if(distance > 5 && distance < 300)
    {
    
  	digitalWrite(red,LOW);
    digitalWrite(green,HIGH);  
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");

	lcd.clear();
    lcd.blink();
	lcd.setCursor(0, 0);
		
	lcd.print("Distance:");
	lcd.setCursor(0,1);
				
	lcd.print(distance);
	lcd.setCursor(4, 1);
	lcd.print("cm");

	delay(1000);
    }
    
    
    else if(distance < 5) 
    {
      digitalWrite(red, HIGH);
      digitalWrite(green,LOW);
      lcd.clear();
      lcd.print("TOO SHORT");
      delay(1000);   
    }
      else
      {
        digitalWrite(red, HIGH);
        digitalWrite(green,LOW);
      	lcd.clear();
        lcd.print("TOO LONG");
        delay(1000);
      }  
    
  
   
}
