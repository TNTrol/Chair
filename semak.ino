#define HIM 10
#define SIZE 8
int timeCount = 0, temp = 0, pin = -1, code = -1;

void setup() {
    for(int i = 0; i < SIZE; i++)
        pinMode(i,OUTPUT);
}

void set(int a){
    for(int i = 0; i < SIZE; i++)
        digitalWrite(i, LOW);
    if(a >= 0)
        digitalWrite(a % SIZE, HIGH);
} 

void loop() {
    code = analogRead(A0);
    timeCount = code;
    analogWrite(HIM, code / 4);
    if(code > 50){
        if(temp >= timeCount){
            set(++pin);
            temp = 0;
        }
        temp++;
    }else{
     set(-1);   
    }
}
