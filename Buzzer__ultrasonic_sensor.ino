// defines pins numbers
const int trigPin = 3;
const int echoPin = 2;
const int buzzer = 5;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 15){
 digitalWrite(buzzer, HIGH);
 delay(1000);
//  tone(buzzer, 1000); // tone() is the main function to use with a buzzer, it takes 2 or 3 parameteres (buzzer pin, sound frequency, duration)
//  delay(100);
  tone(buzzer, 1000); // You can also use noTone() to stop the sound it takes 1 parametere which is the buzzer pin
  delay(100);
  //digitalWrite(buzzer, LOW);
  //delay(100);

  digitalWrite(ledPin, HIGH);
  delay(1000);
}
else{
  digitalWrite(buzzer, LOW);
  delay(100);
  noTone(buzzer);
  delay(1000);
    
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
