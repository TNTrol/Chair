#define HIM 10
#define START_PIN 0
#define END_PIN 8
#define READ_PIN A0

#define SIZE (END_PIN - START_PIN)

int timeCount = 0, temp = 0, pin = -1, code = -1;

void setup() {
    for(int i = START_PIN; i < END_PIN; i++)
        pinMode(i,OUTPUT);
}

void set(int a){
    for(int i = START_PIN; i < END_PIN; i++)
        digitalWrite(i, LOW);
    if(a >= 0)
        digitalWrite(a % SIZE, HIGH);
} 

void loop() {
    code = analogRead(READ_PIN);
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
