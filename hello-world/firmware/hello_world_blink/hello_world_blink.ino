// Hello World: blink the LED while the button is held.
//
// Wiring (see hello-world.kicad_sch):
//   D2  -> push button -> GND   (uses the internal pull-up, so pressed = LOW)
//   D9  -> 220 ohm resistor -> LED anode, LED cathode -> GND

const int BUTTON_PIN = 2;
const int LED_PIN = 9;
const unsigned long BLINK_MS = 250;

unsigned long lastToggle = 0;
bool ledOn = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool pressed = digitalRead(BUTTON_PIN) == LOW;

  if (!pressed) {
    ledOn = false;
    digitalWrite(LED_PIN, LOW);
    return;
  }

  if (millis() - lastToggle >= BLINK_MS) {
    lastToggle = millis();
    ledOn = !ledOn;
    digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
  }
}
