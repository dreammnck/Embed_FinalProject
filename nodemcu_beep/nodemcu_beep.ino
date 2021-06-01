

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "V_qxM13RYNapjhVwWrtoxnMRHfRZ7Gt4";
char mess;
int dist;
int leftspace;
bool check = false;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NamNing_2.4G";
char pass[] = "Namning927";
WidgetLCD LCD(V0);

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(D1,OUTPUT);
  pinMode(D3,INPUT);

  Blynk.begin(auth, ssid, pass);
   LCD.clear();
}

void loop()
{
  Blynk.run();
    delay(100);

  if(Serial.available() > 0) {
     //Serial.print("X");
    dist = Serial.parseInt();
    Serial.print("DIST");
    Serial.print(dist);
    Serial.println();

    //LCD.print(0,0,dist);
    leftspace = 150-dist;
    if (leftspace <0){

      leftspace = 0;
    }
        Serial.print("Leftspace");
    Serial.print(leftspace);
    Serial.println();
    
    if (dist < 150){
      LCD.print(0,0,"TOO CLOSE!");
    }
    else{
      LCD.clear();
    }
    if(digitalRead(D3) == LOW) {
      check = false;
      
      
      }
     if(digitalRead(D3) == HIGH) {
      check = true;
      }
    if(!check) {
      if(dist < 150) {
        digitalWrite(D1,LOW);
        }
       else {
        digitalWrite(D1,HIGH);
        }
      }
    

    Blynk.virtualWrite(V10,leftspace);
    
   /* if (mess == 'b') {
      LCD.print(0,0,"TOO CLOSE!");
    }
    if (mess== 'X'){
      LCD.clear();
    }*/

    //Serial.println("X");
    }
}
