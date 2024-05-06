#include <BleMouse.h>

BleMouse bleMouse("Syringe Controller", "Team 23", 100);

bool BTConnected = false;
bool isClicking = false;

const int buttonPin = 2;

int sleepTimer = 0;
const int sleepGoal = 28000000;
//1000000; //Should be a little over 30 seconds in real time
//20000000; //Should be a little over 10 minutes in real time (exact value for 10 min will be roughly 18,093,306)
//28000000; //Should be a little over 15 minutes in real time (exact value for 15 min will be roughly 27,258,960)

//Known: It takes roughly 99.05 seconds for 3,000,000 cycles to take place

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  pinMode(buttonPin, INPUT_PULLUP);

  bleMouse.begin();

  //Print the wakeup reason for ESP32
  //print_wakeup_reason();

  esp_deep_sleep_enable_gpio_wakeup(BIT(D0), ESP_GPIO_WAKEUP_GPIO_LOW);
  //Setting what external gpio pin can wakeup device from deep sleep (NOTE: Only works with pins D0 - D3)

  //Initialize sleep timer at 0
  sleepTimer = 0;
  
}

void enterSleep() {
  //Go to sleep now
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();
}

void loop() {
  if(bleMouse.isConnected()) {
    int clickState = digitalRead(buttonPin);

    if(!BTConnected) {
      Serial.println("BT Mouse Connected");
      BTConnected = true;
      sleepTimer = 0;
    }
    
    if(clickState == LOW && !isClicking) {
      Serial.println("Button Pressed");
      bleMouse.click(MOUSE_MIDDLE);
      isClicking = true;
      sleepTimer = 0;
      delay(100);
    }
    if(clickState == HIGH) {
      isClicking = false;
    }

    //Examples for each mouse button press
    /*
    Serial.println("Left click");
    bleMouse.click(MOUSE_LEFT);
    delay(500);

    Serial.println("Right click");
    bleMouse.click(MOUSE_RIGHT);
    delay(500);

    Serial.println("Scroll wheel click");
    bleMouse.click(MOUSE_MIDDLE);
    delay(500);

    Serial.println("Back button click");
    bleMouse.click(MOUSE_BACK);
    delay(500);

    Serial.println("Forward button click");
    bleMouse.click(MOUSE_FORWARD);
    delay(500);

    Serial.println("Click left+right mouse button at the same time");
    bleMouse.click(MOUSE_LEFT | MOUSE_RIGHT);
    delay(500);

    Serial.println("Click left+right mouse button and scroll wheel at the same time");
    bleMouse.click(MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE);
    delay(500);
    */
  }
  else {
    /*
    Serial.println("BT Mouse Not Connected");
    delay(2000);
    */
    BTConnected = false;
  }
  sleepTimer += 1;
  Serial.println(sleepTimer);
  if (sleepTimer >= sleepGoal) {
    //Enough time has elapsed without input, entering sleep mode
    enterSleep();
  }
}