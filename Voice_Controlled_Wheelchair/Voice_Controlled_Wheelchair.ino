String voice;
void setup()
{
  Serial.begin(9600); //start serial communication
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, INPUT);
}
void loop()
{
  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') 
{
      break; //Exit the loop when the # is detected after the word
}
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) 
  {
    if (voice == "*forward")
    {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW );
      digitalWrite(12, HIGH );
      digitalWrite(13, LOW );
    }
   else if (voice == "*backward")
   {
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH );
      digitalWrite(12, LOW );
      digitalWrite(13, HIGH );
   }
   else if (voice == "*right")
    {
      digitalWrite(10, LOW );
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH );
      digitalWrite(13, LOW); /*right*/
      delay (1000);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
    else if (voice == "*left")
    {
      digitalWrite(10, HIGH );
      digitalWrite(11, LOW);
      digitalWrite(12, LOW );
      digitalWrite(13, LOW); /*left*/
      delay(1000);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW); 
    }
   else if (voice == "*stop")
  {
    digitalWrite(10, LOW );
    digitalWrite(11, LOW);
    digitalWrite(12, LOW );
    digitalWrite(13, LOW);
     }
       voice = ""; //Reset the variable after initiating
    }
}
