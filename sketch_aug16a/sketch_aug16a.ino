#include <IRremote.h>

// Define pins
const int RECV_PIN = 11;
const int ledPin2 = 12;
 

// Remote control's buttons
const unsigned long Button_Power = 0xFD00FF;

// Define varables 
boolean ledState = LOW;
boolean ledState2 = HIGH;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(ledPin2,OUTPUT);  
              
  digitalWrite(ledPin2, ledState);
  }
//}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

//if (when the signal is decoded) it is case power button then the pin motorPin recives power to power the motor 

    switch (results.value){
      case Button_Power:
        ledState = !ledState;
        digitalWrite(ledPin2, ledState);  
     }
  }
}
 /*       ledState = !ledState;
        digitalWrite(ledPin2, ledState);
        }
}





/*          break;
      }

    irrecv.resume();
  }
}*/
