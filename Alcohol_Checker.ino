#define Drunk 400   // Define min value that we consider drunk
#define MQ3 0

float sensorValue;
int LED = 6;
const int trigPin = 9;
const int echoPin = 10;
long duration = 0;
int distance = 0;
int alcohol = 3;

void setup() {
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  pinMode(LED , OUTPUT);
  pinMode(alcohol, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED, LOW);
  sensorValue = analogRead(MQ3); // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  sensorValue = 402;
  if (sensorValue > Drunk) {
    // Check for vehicle ahead using ultrasonic sensor
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
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("\nDistance: ");
    Serial.println(distance);

    if(distance<70)
      digitalWrite(LED, HIGH);
  }
  
  delay(2000); // wait 2s for next reading
}