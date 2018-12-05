int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  int xStab = (xPosition + 4)/ 5;
  int yStab = (yPosition + 2)/ 5;
  Serial.print("X: ");
  Serial.print(xStab);
  Serial.print(" | Y: ");
  Serial.print(yStab);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100); // add some delay between reads

  if (xStab == 0){ 
     Serial.println("UP");
    } else if (xStab == 205) {
     Serial.println("DOWN");
    } else if (yStab == 0){ 
     Serial.println("RIGHT");
    } else if (yStab == 205) {
     Serial.println("LEFT");
    } 

}
