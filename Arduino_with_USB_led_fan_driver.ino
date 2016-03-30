/*******************************************************
LED/Fan driver 

this is simply an opto isolator that allows the Arduino to 
drive heavy loads like high brightness LEDs or a fan
safely.

A single capacitance touch switch is used to turn the load on and off
the first touch switches the load ON
the second touch turns it OFF

Connections:
Capacitance touch switch:
Vcc to Arduino 5 volts, 
Gnd to Arduino Gnd, 
Output to Digital pin 4

USB LED/Fan driver:
Vcc to suitable 5 volt external power source, 
Gnd to Arduino Gnd, 
Signal to digital pin 3

*******************************************************/
int USBdriverPin = 3;
int brightness = 0;
int fadeAmount = 5;
int capSwitch = 4;
int brightnessMax = 10; // maximum value is 255
int brightnessMin = 0;  // minimum value is 0
boolean pressButton;
# define LED 13 // onboard LED

/*******************************************************/
void setup(){
Serial.begin(9600); // debug if required
pinMode(USBdriverPin, OUTPUT);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW); // turn on board LED off
pinMode(capSwitch, INPUT_PULLUP); // pull input HIGH
}
/*******************************************************/
void loop (){
// turn switch ON on first touch
// OFF on second press
  delay(200); // helps stop false triggering
  if ((digitalRead(capSwitch) == HIGH)) {
    digitalWrite(LED, HIGH); // turn LED ON to show button press
    if (brightness == brightnessMax) brightness = brightnessMin;
    else brightness = brightnessMax;
    analogWrite(USBdriverPin, brightness);
    // wait here until the cap switch is no longer touched
    while (digitalRead(capSwitch) == HIGH){
    // wait for switch to be released
    }
    digitalWrite(LED, LOW); // turn LED OFF as button now released
  }
}
/*******************************************************/
