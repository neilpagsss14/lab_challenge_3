#define r 27
#define g 12
#define y 13
#define p 15

int freq = 5000;
int reso = 8;
int inp = 10; 

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(p, INPUT);
  pinMode(14, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  Serial.begin(9600);

  ledcSetup(0, freq, reso);
  ledcSetup(1, freq, reso);
  ledcSetup(2, freq, reso);

  ledcAttachPin(r, 0);
  ledcAttachPin(g, 1);
  ledcAttachPin(y, 2);
}

void loop() {
  int poten = analogRead(p);

  int touchRed[inp];
  int touchGreen[inp];
  int touchYellow[inp];
  
  for (int i = 0; i < inp; i++) {
    touchRed[i] = touchRead(14);
    touchGreen[i] = touchRead(32);
    touchYellow[i] = touchRead(33);
  }
  
  int touchInputGreen = 0;
  int touchInputRed = 0;
  int touchInputYellow = 0;
  for (int i = 0; i < inp; i++) {
    touchInputGreen += touchGreen[i];
    touchInputRed += touchRed[i];
    touchInputYellow += touchYellow[i];
  }
  touchInputGreen /= inp;
  touchInputRed /= inp;
  touchInputYellow /= inp;

  int lumi = map(poten, 0, 4095, 0, 255);
  
      if(touchInputRed<=30){
      ledcWrite(0, lumi);
    }else{
      ledcWrite(0, 0);
    }
    
  if(touchInputGreen<=30){
      ledcWrite(1, lumi);
    }else{
      ledcWrite(1, 0);
    }
    
    if(touchInputYellow<=30){
      ledcWrite(2, lumi);
    }else{
      ledcWrite(2, 0);
    }
}