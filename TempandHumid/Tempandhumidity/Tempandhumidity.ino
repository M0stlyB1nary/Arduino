/* How to use DHT-11 sensor with Arduino uno
   Temperature and humidity sensor
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com */

//Libraries
#include <dht.h>

//Constants
dht DHT;
const int dhtPin = 10; //Data pin of DHT-11 to Arduino digital pin 2

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
}

void loop()
{
  chk = DHT.read11(dhtPin); //Check data pin and read values
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
}

   
