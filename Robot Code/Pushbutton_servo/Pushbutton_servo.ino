 #include <Servo.h>;
 
 // pushbutton pin
 const int buttonPin = 8;

 // servo pin
 const int servoPin = 3;
 Servo servo;


//create a variable to store a counter and set it to 0
int counter = 0;
void setup()
{
  servo.attach (servoPin);
  
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);
}


void loop()
{
 // local variable to hold the pushbutton states
  int buttonState;  

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  if(counter == 0)
    servo.write (20);  // zero degrees
  else if(counter == 1)
    servo.write(90);
  else if(counter == 2)
    servo.write (150); 
  else if(counter == 3)  
    servo.write (180);
  //else reset the counter to 0 which resets thr servo to 0 degrees
  else
   counter = 0;
}
