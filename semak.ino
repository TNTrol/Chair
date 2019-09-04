
int timeCount = 0, temp = 0, pin = -1;

void setup() {
    for(int i = 0; i < 12; i++)
    pinMode(i,OUTPUT);
}

void set(int a){
    if(a > 0)
        return;
    for(int i = 0; i < 13; i++)
        digitalWrite(i, LOW);
    digitalWrite(a % 13, HIGH);
} 

void loop() {
    timeCount = 2 * analogRead(A0);
    if(temp >= timeCount){
        pin++;
        set(pin);
        temp = 0;
    }
    temp++;
}
