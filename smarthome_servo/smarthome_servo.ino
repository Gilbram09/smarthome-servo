
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> //file untuk modul wifi
#include <BlynkSimpleEsp8266.h> //file untuk blynk
#include <Servo.h> // library untuk servo


char auth[] = "Gw9Fs5tqyO9knwq80J9lxn-UUhVoEu74"; //char yang dikirim oleh blynk
char ssid[] = "WiFi";
char pass[] = "apaandahh";

// definisi fungsi servo menjadi gerak_servo
Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
} // fungsi blynk untuk mengatur nilai servo dengan pin virtual v1 yg ada di aplikasi blynk

void setup()
{
  // Debug console
  Serial.begin(9600);// memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token wifi dan pwnya

  gerak_servo.attach(2); //setting pin gpio 2 ke server , D4 = 2
}

void loop()
{
  Blynk.run(); //memulai blynk
}
