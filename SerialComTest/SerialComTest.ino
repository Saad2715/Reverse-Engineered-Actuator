String data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial.available()) {
    ; // wait for serial to connect
  }
  //Serial.println("Serial connected!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    data = Serial.readString();
    if (!data.equals("")){
      // Serial.println("Data received!");
      // Serial.println(data);
      if (data.equals("start")){
        int x = 0, y = 0, val[50];
        // while(x <= 50){
        for (int i = 0; i < 50 ; i++){
          val[i] = (x, y);
          // Serial.print("x = ");
          // Serial.print(x);
          // Serial.print(", y = ");
          Serial.println(val[i]);

          x += 1;
          y = pow(y, 2) - 5;

          delay(500);
        }
      }
    }
  }
}
