
// NOTE:
// Replace with your own Wifi credentials and Blynk Auth Token before running

#define BLYNK_TEMPLATE_ID "TMPL3rNerJt6C" 
#define BLYNK_TEMPLATE_NAME "smart street light" 
 #define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN" 
#define BLYNK_PRINT Serial 
 
#include <WiFi.h> 
#include <BlynkSimpleEsp32.h> 
 
char ssid[] = "YOUR_WIFI_NAME"; 
char pass[] = "YOUR_WIFI_PASSWORD"; 
 
#define LDR_PIN 34 // LDR connected to anolog pin
#define PIR_PIN 27 // PIR motion sensor input5
#define LED_PIN 25 // LED output
 
int ldrValue; 
 
int pirState; 
 

 
 
bool manualMode = false; 
int manualBrightness = 0; 
 
int ldrThreshold = 1200;   // Threshold to detect day/night
 
BlynkTimer timer; 
 
// PWM setup 
#define PWM_CHANNEL 0 
#define PWM_FREQ 5000 
#define PWM_RESOLUTION 8 
 
void checkSensors() 
// Read sensor values
{ 
  ldrValue = analogRead(LDR_PIN); 
  pirState = digitalRead(PIR_PIN); 
 
  Serial.print("LDR: "); 
  Serial.print(ldrValue); 
  Serial.print("  PIR: "); 
  Serial.println(pirState); 
 
  if (!manualMode) 
  { 
    // DAY → OFF 
    if (ldrValue > ldrThreshold) 
    { 
      ledcWrite(PWM_CHANNEL, 0); 
    } 
    else 
    { 
      // NIGHT 
      if (pirState == HIGH) 
      { 
        ledcWrite(PWM_CHANNEL, 255); // FULL 
      } 
      else 
      { 
        ledcWrite(PWM_CHANNEL, 120);  // DIM (~30%) 
      } 
    }
  }
  // Send data to Blynk 
  Blynk.virtualWrite(V1, ldrValue); 
  Blynk.virtualWrite(V2, pirState); 
} 
 
// Manual mode switch 
BLYNK_WRITE(V0) 
{ 
  manualMode = param.asInt(); 
} 
 
// Brightness slider 
BLYNK_WRITE(V3) 
{ 
  manualBrightness = param.asInt(); 
 
  if (manualMode) 
  { 
    int pwmValue = map(manualBrightness, 0, 100, 0, 255); 
    ledcWrite(PWM_CHANNEL, pwmValue); 
  } 
} 
 
void setup() 
{ 
  Serial.begin(115200); 
 
  pinMode(PIR_PIN, INPUT_PULLDOWN); 
 
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION); 
  ledcAttachPin(LED_PIN, PWM_CHANNEL); 
 
  Serial.println("Connecting to WiFi..."); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
 
  timer.setInterval(1000L, checkSensors); 
} 
 
void loop() 
{ 
  Blynk.run(); 
  timer.run();
}
  
