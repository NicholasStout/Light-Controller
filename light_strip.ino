
int green = 9;
int red = 6;
int blue = 5;
int r = 0;
int g = 0;
int b = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  analogWrite(red, 100);
  analogWrite(green, 100);
  analogWrite(blue, 100);

  Serial.begin(9600);
}

void set(int p,int b) {
    analogWrite(p, b);
}

void loop() {
  String s = Serial.readString();
  if (s.length() == 11) {
    r  = 255 - s.substring(0,3).toInt();
    g  = 255 - s.substring(4,7).toInt();
    b  = 255 - s.substring(8).toInt();
    Serial.println("Command Recieved");
  }
  
  set(red,r);
  set(green, g);
  set(blue, b);
}
