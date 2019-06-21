#include <Servo.h>
Servo myservo[3];
float plateR=45;
float outR;
float oblique=M_PI/18; //30 degree
float plateFoot_r;
float plateFoot_h[3];
float val[3];
float count=0;
float speedd=0.02;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo[0].attach(9);
  myservo[1].attach(10);
  myservo[2].attach(11);

  for(int i=0;i<3;i++){
    myservo[i].write(90);
  }
}

void loop() {
  count++;
  outR=plateR/cos(oblique);

//  plateFoot_r=plateR*(2*sq(cos(oblique))-1)/cos(oblique);
  plateFoot_r=180;
  for(int i=0;i<3;i++){
    
    plateFoot_h[i]=sin(oblique)
    *sqrt(sq(outR*cos(count*speedd)-plateFoot_r*cos(M_PI_2+i*(2*M_PI/3)))
    +sq(outR*sin(count*speedd)-plateFoot_r*sin(M_PI_2+i*(2*M_PI/3))));
    myservo[i].write(plateFoot_h[i]);
//    myservo[i].write(180);
//    println(plateFoot_h[i]);
  }
//myservo[0].write(90+90*sin(count*0.01));
Serial.print("m1  ");
Serial.println(plateFoot_h[0]);
Serial.print("m2  ");
Serial.println(plateFoot_h[1]);
Serial.print("m3  ");
Serial.println(plateFoot_h[2]);
//myservo[0].write(plateFoot_h[0]);
  delay(30);

}
