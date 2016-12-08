
bool sent = false;


void setup() {

  pinMode(D7, OUTPUT);

  Particle.subscribe("talktalktalk", myHandler);


}


void loop() {


      //  Particle.publish("your_unique_event_name","intact");
    int in = analogRead(A0);
    if(sent == false && in > 1000){
      sent = true;
      Particle.publish("talktalktalk","intact");
      delay(100);
    }
    else if(sent == true && in < 1000){
      sent = false;
      Particle.publish("talktalktalk","broken");
      delay(100);
    }


  }




// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data){


  if (strcmp(data,"intact")==0) {
    // if your buddy's beam is intact, then turn your board LED off
    digitalWrite(D7,HIGH);
  }
  else if (strcmp(data,"broken")==0) {
    // if your buddy's beam is broken, turn your board LED on
    digitalWrite(D7,LOW);
  }

}
