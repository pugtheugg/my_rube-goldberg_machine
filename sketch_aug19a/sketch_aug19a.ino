int buttonPin = 2;                  // defines the button
int relayPin = 3;                   // defines the relay
int relayState = HIGH;              // defines inisial relay state 
int buttonState;                    // records the current button state
int lastButtonState = LOW;          // records the last button state
long lastDebounceTime = 0;
long debounceDelay = 10;            // eliminate debounce time

void setup() {
pinMode(buttonPin, INPUT);  //defines button as imput and relay as output
pinMode(relayPin, OUTPUT);
digitalWrite(relayPin, relayState);  // configure the initial state of relay
  }

void loop() {
int reading = digitalRead(buttonPin);             //reads the value of button
// once detects change of state, record time
if (reading != lastButtonState) {
lastDebounceTime = millis();
}

// wait for 10ms to evaluate if it is the same state as last state
// if different, change the button state
// if the state of button is high(pressed), change the state of relay

if ((millis() - lastDebounceTime) > debounceDelay) {
if (reading != buttonState) {
buttonState = reading;
if (buttonState == HIGH) {
relayState = !relayState;
    }
  }
}
digitalWrite(relayPin, relayState);

//change the last state of button

lastButtonState = reading;

} 
