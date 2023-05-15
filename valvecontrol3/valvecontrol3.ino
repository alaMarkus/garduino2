char input;
unsigned long hourInMs = 3600000;
unsigned long actualInterval = 24*hourInMs;
unsigned long timeUntilFirstRun = 10000;
unsigned long intervalAfterFirstRun = actualInterval;

unsigned long interval=timeUntilFirstRun;


unsigned long opentime1 = 6000;

unsigned long opentime2 = 6000 + opentime1;

unsigned long opentime3 = 6000 + opentime2;

unsigned long opentime4 = 6000 + opentime3;

// Tracks the time since last event fired
unsigned long previousMillis=0;
unsigned long timer;
unsigned long timer2 = 0;

unsigned long totalMillis;
unsigned long measuredInterval;
unsigned long remainingMillis;
unsigned long seconds;
unsigned long minutes;
unsigned long hours;
unsigned long days;

void setup() {
  pinMode(25,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  digitalWrite(25,LOW);
  digitalWrite(24,LOW);
  digitalWrite(26,LOW);
  digitalWrite(28,LOW);
  digitalWrite(30,LOW);
  digitalWrite(31,LOW);
  Serial.begin(115200);
}

void loop() {
 if(true){
    unsigned long currentMillis = millis();
    // How much time has passed, accounting for rollover with subtraction!
    if ((unsigned long)(currentMillis - previousMillis) >= interval && (currentMillis - previousMillis) <= interval + opentime1 && digitalRead(25) != HIGH) {
      // It's time to do something!
      measuredInterval = millis()-timer2;
      remainingMillis = measuredInterval % 1000;
      seconds = measuredInterval / 1000;
      minutes = seconds / 60;
      hours = minutes / 60;

      seconds = seconds % 60;
      minutes = minutes % 60;
      hours = hours % 24;

      Serial.print("Watering sequence ran last ");
      Serial.print(hours); Serial.print(" hours ");
      Serial.print(minutes); Serial.print(" minutes ");
      Serial.print(seconds); Serial.print(" seconds and ");
      Serial.print(remainingMillis); Serial.println(" milliseconds ago");
      Serial.print("which is "); Serial.print(measuredInterval); Serial.println(" milliseconds in total");

      totalMillis = millis();
      remainingMillis = totalMillis % 1000;
      seconds = totalMillis / 1000;
      minutes = seconds / 60;
      hours = minutes / 60;
      days = hours / 24;

      seconds = seconds % 60;
      minutes = minutes % 60;
      hours = hours % 24;

      Serial.print("System has been running ");
      Serial.print(days); Serial.print(" days ");
      Serial.print(hours); Serial.print(" hours ");
      Serial.print(minutes); Serial.print(" minutes ");
      Serial.print(seconds); Serial.print(" seconds and ");
      Serial.print(remainingMillis); Serial.println(" milliseconds ago");
      Serial.print("which is "); Serial.print(totalMillis); Serial.println(" milliseconds in total");


      timer = millis();
      digitalWrite(25, HIGH);
      delay(10);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      Serial.println("valve 1 open");
    }
    if ((unsigned long)(currentMillis - previousMillis) >= (interval + opentime1) && (currentMillis - previousMillis) <= (interval + opentime2) && digitalRead(24) != HIGH) {
      digitalWrite(25, LOW);
      Serial.println("valve 1 closed");
      Serial.println(millis()-timer);
      timer = millis();
      delay(10);
      digitalWrite(24,HIGH);
      Serial.println("valve 2 open");
    }
    if ((unsigned long)(currentMillis - previousMillis) >= (interval + opentime2) && (currentMillis - previousMillis) <= (interval + opentime3) && digitalRead(26) != HIGH) {
      digitalWrite(24, LOW);
      Serial.println("valve 2 closed");
      Serial.println(millis()-timer);
      timer = millis();
      delay(10);
      digitalWrite(26,HIGH);
      Serial.println("valve 3 open");
    }
    if ((unsigned long)(currentMillis - previousMillis) >= (interval + opentime3) && (currentMillis - previousMillis) <= (interval + opentime4) && digitalRead(28) != HIGH) {
      digitalWrite(26, LOW);
      Serial.println("valve 3 closed");
      Serial.println(millis()-timer);
      timer = millis();
      delay(10);
      digitalWrite(28,HIGH);
      Serial.println("valve 4 open");
    }
    if ((unsigned long)(currentMillis - previousMillis) >= (interval + opentime4)){
      digitalWrite(28, LOW);
      Serial.println("valve 4 closed");
      Serial.println(millis()-timer);
      timer = millis();
      delay(10);
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      previousMillis = currentMillis;

      if(interval == intervalAfterFirstRun){
        interval = actualInterval;
        Serial.println("changed interval to ");Serial.println(interval);

      }
      
      if(interval == timeUntilFirstRun){
        interval=intervalAfterFirstRun;
        Serial.println("changed interval to ");Serial.println(interval);
      }

      timer2 = millis();
    }
  }



////////////////////////////////////  
    //Serial.println(millis());
    if(Serial.available()){
    input = Serial.read();
    Serial.print("You typed: " );
    Serial.println(input);
    if (input == 't'){
      digitalWrite(25,HIGH);
      delay(10);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      timer = millis();
    }
    if (input == 'g'){
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      delay(10);
      digitalWrite(25,LOW);
      Serial.print("valve 1 was open: ");
      Serial.println(millis()-timer);
      timer = 0;
    }
    if (input == 'y'){
      digitalWrite(24,HIGH);
      delay(10);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      timer = millis();
    }
    if (input == 'h'){
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      delay(10);
      digitalWrite(24,LOW);
      Serial.print("valve 2 was open: ");
      Serial.println(millis()-timer);
      timer = 0;
    }
    if (input == 'u'){
      digitalWrite(26,HIGH);
      delay(10);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      timer = millis();
    }
    if (input == 'j'){
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      delay(10);
      digitalWrite(26,LOW);
      Serial.print("valve 3 was open: ");
      Serial.println(millis()-timer);
      timer = 0;
    }
    if (input == 'i'){
      digitalWrite(28,HIGH);
      delay(10);
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      timer = millis();
    }
    if (input == 'k'){
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      delay(10);
      digitalWrite(28,LOW);
      Serial.print("valve 4 was open: ");
      Serial.println(millis()-timer);
      timer = 0;
    }
    if (input == 'o'){
      //
    }
    if (input == 'l'){
      //digitalWrite(30,LOW);
    }
    if (digitalRead(25)==LOW &&
        digitalRead(24)==LOW &&
        digitalRead(26)==LOW &&
        digitalRead(28)==LOW)
        {
         digitalWrite(30,LOW);
         digitalWrite(31,LOW); 
        }
  }
}
