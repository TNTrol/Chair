#define COUNT_PINS 8
#define START_PIN 2
#define END_PIN 12
#define COUNT_LEVELS 5
#define DELAY 50
#define VOLUME 12
#define DEBUG

int arr[COUNT_LEVELS][2];
int level = 0, err = 0;

int calculate() {
  int a = 0;
  for (int i = START_PIN; i < END_PIN; i++) {
    if (!digitalRead(i)) {
      a++;
    }
  }
  return a;
}

//функция разряда тока
void discharge() {
  for(int i = 0; i < err; i++){
    #ifdef DEBUG
    Serial.print("TZZZZZZ");
    #endif
  }
  #ifdef DEBUG
  Serial.println("");
  #endif
}

//хорошая концовка)
void good_final() {
  #ifdef DEBUG
  Serial.print("WINNER");
  #endif
}

//плохая концовка(
void bad_final() {
  #ifdef DEBUG
  Serial.print("LOSER");
  #endif
}

//переход на следующий уровень
void next_level() {
  level++;
  #ifdef DEBUG
  Serial.print("LEVEL=");
  Serial.println(level);
  #endif
  if(level >= COUNT_LEVELS)
    return;
  for(int i = 0; i < 2; i++){
    if(!digitalRead(arr[level][i])) 
      for(int *p_arr = arr[0]; p_arr < arr[0] + level * 2; p_arr++){
        if(digitalRead(*p_arr)){
          arr[level][i] = *p_arr;
          break;
        }
      }
  }
}

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
  int *p_arr = arr[0];
  for (int i = START_PIN; i < END_PIN; i++, p_arr++) {
    (*p_arr) = i;
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  while(level < COUNT_LEVELS){
    int c = calculate();
    if(level >= c ){
      delay(DELAY);
      continue;
    }
    #ifdef DEBUG
    Serial.print(level);
    Serial.print(" LEVEL == ");
    Serial.println(c);
    #endif
    if(c - level == 1){    
      if(digitalRead(arr[level][0])){
        err++;
        #ifdef DEBUG
        Serial.println("ERROR !=");
        #endif
        discharge();
      }
      next_level();
    }else{
      #ifdef DEBUG
      Serial.println("ERROR > 1");
      #endif
      err += (c - level);
      level += (c - level) / 2;      
      discharge();
    }

    if(level >= COUNT_LEVELS && err <= COUNT_LEVELS){
      good_final();
      break;
    }
    if(err > COUNT_LEVELS){
      bad_final();
      level = COUNT_LEVELS;
    }
  }
}
