#define HIM 10
int timeCount = 0, temp = 0, pin = -1, code = 0;

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
    code = analogRead(A0);
    timeCount = 2 * code;
    analogWrite(HIM, code / 4);
    if(temp >= timeCount){
        pin += (pin + 1 ) % HIM == 0 ? 2 : 1;
        set(pin);
        temp = 0;
    }
    temp++;
}
