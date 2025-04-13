int pwm1 = 10;

int pwm2 = 11;

int ign1 = 12;

int ign2 = 9;

int check1 = 0;

int check2 = 0;

int ign_time = 3000;

void setup() {

  Serial.begin(9600);

  pinMode(pwm1, INPUT);

  pinMode(pwm2, INPUT);

  pinMode(ign1, OUTPUT);

  pinMode(ign2, OUTPUT);

  digitalWrite(ign1,HIGH);
  digitalWrite(ign2,HIGH);

}

void loop() {

   digitalWrite(ign1,HIGH);
   digitalWrite(ign2,HIGH);

   unsigned long pwmValue1 = pulseIn(pwm1, HIGH);
   unsigned long pwmValue2 = pulseIn(pwm2, HIGH);

  Serial.println(pwmValue1);
  Serial.println(pwmValue2);

  int time01 = millis();
if(time01 > 1000){
  if(pwmValue1>1990){

    int time11 = millis();

    digitalWrite(ign1, LOW);

    while(check1==0){

      int time21 = millis();

      if((time21-time11)>ign_time){

        digitalWrite(ign1,HIGH);

        check1 = 1;



      }

    }

  }
  
if(pwmValue2>1990){

    int time12 = millis();

    digitalWrite(ign2, LOW);

    while(check2==0){

      int time22 = millis();

      if((time22-time12)>ign_time){

        digitalWrite(ign2,HIGH);

        check2 = 1;



      }

    }

  }

}
}