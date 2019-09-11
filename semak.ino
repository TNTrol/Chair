#define HIM 10
#define SIZE 8
int timeCount = 0, temp = 0, pin = -1, code = 0;

void setup() {
    for(int i = 0; i < SIZE; i++)
    pinMode(i,OUTPUT);
}

void set(int a){
    if(a < 0)
        return;
    for(int i = 0; i < SIZE; i++)
        digitalWrite(i, LOW);
    digitalWrite(a % SIZE, HIGH);
} 

void loop() {
    code = analogRead(A0);
    timeCount = 2 * code;
    analogWrite(HIM, code / 4);
    if(temp >= timeCount){
        set(++pin);
        temp = 0;
    }
    temp++;
}
