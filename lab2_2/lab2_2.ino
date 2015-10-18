int state = 0;
int old_t=0;
int delay_t=100;
int ledPin = 13;
int button = 7;
void setup() {
  // put your setup code here, to run once:
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    pinMode(button, INPUT); 

    Serial.begin(9600);
    Serial.print("Hello, this message is from Arduino Uno");
    
    state = LOW;
    old_t=millis();
}

void loop() {
    int new_t=millis();
    if(new_t-old_t>=delay_t){
        switch (state){
            case (LOW):
                state = HIGH;
                digitalWrite(ledPin, state);
                old_t=new_t;
            break;
            case (HIGH):
                state = LOW;
                digitalWrite(ledPin, state);
                old_t=new_t;
            break;
        }
    }
    if(digitalRead(button)){
        delay_t = delay_t + 50;
        delay_t = delay_t % 1000;
    }
}
