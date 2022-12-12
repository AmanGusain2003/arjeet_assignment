const int buttonPin1 = 4;
void setup(){
    pinMode(buttonPin1,INPUT);
    Serial.begin(9600);
    Serial.println("Begin!");
}
void loop(){
    int buttonstate = digitalRead(buttonPin1);
    Serial.println(buttonstate);
    delay(40);
}