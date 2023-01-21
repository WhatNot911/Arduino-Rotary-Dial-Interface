// Rotary phone dial interface v1.0.0

/*
Old rotary phone dials may (colour may vary) have this wiring setup:
Green - common wire shared between both terminals. Goes to ground
Brown - used to indicate whether a digit is being put in (e.g. when the dial is engaged)
White - used to count which digit user is trying to put in by opening the circuit N ammount of times

Logic:
When the dial is engaged (e.g. when brown wire circuit is CLOSED) - count how many times white terminal OPENS
*/

int digit = 0;

int pinBrown = 2;
int pinWhite = 3;
int pinDigit = 12;

bool dialStatus;
bool digitStatus;

void setup() {
  //start serial connection
  Serial.begin(9600);
  pinMode(pinBrown, INPUT_PULLUP);  // Brown wire goes to DIGITAL 2
  pinMode(pinWhite, INPUT_PULLUP);  // White wire goes to DIGITAL 3

  pinMode(pinDigit, OUTPUT);     // DIGITAL 12 will be used with an LED to indicate that a digit is being put in
  pinMode(LED_BUILTIN, OUTPUT);  // Debug LED will indicate if dial is engaged
}

void loop() {
  // Read whether the dial is being engaged or not

  // Brown wire is connected to ground. When dial is not engaged (e.g. circuit between wires is opened) - it will read HIGH.
  bool dialEngaged = digitalRead(pinBrown) == HIGH ? false : true;

  // TRIGGER: Dial status change
  if (dialStatus != dialEngaged) {
    dialStatus = dialEngaged;
    if (dialStatus == true) {
      // 💡 Light up the LED to indicate that the dial is being engaged
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      // Turn off lights and reset digit counter
      digitalWrite(LED_BUILTIN, LOW);
      // 🖥️ THIS IS MAIN OUTPUT FORMAT RIGHT NOW
      // Print out the value of the digit being put in
      // Maybe use some analog output divided by 9 increments if needed?
      Serial.println(digit);
      // Reset the counter
      digit = 0;
    };
  };

  // TRIGGER: Digit counter
  if (dialStatus == true) {
    // White wire is also connected to ground.
    // By default the circuit is closed, so we need to count how many times it opens when dial is engaged
    bool digitCount = digitalRead(pinWhite) == HIGH ? true : false;
    if (digitStatus != digitCount) {
      digitStatus = digitCount;
      if (digitStatus == true) {
        // 💡 Light up the LED to indicate that a digit has just been counted
        digitalWrite(pinDigit, HIGH);
        // Increment the value of digit being put in
        digit++;
      } else {
        // Lights off otherwise
        digitalWrite(pinDigit, LOW);
      };
    };
  };

  // Digital read shenanigans...
  delay(1);
};
