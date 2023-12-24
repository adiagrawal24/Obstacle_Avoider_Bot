// Define ultrasonic sensor pins
#define trigPin1 6
#define echoPin1 7
#define trigPin2 8
#define echoPin2 9
#define trigPin3 10
#define echoPin3 11

// Variables to store the distance readings
long duration1;
int middle;
long duration2;
int left;
long duration3;
int right;

void setup() {
  // Set ultrasonic sensor pins as OUTPUT and INPUT
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // Set motor control pins as OUTPUT
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, OUTPUT);

  Serial.begin(9600); // Start serial communication for debugging
  Serial.println("Obstacle Avoider");
}

void loop() {
  // Read distance from middle ultrasonic sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  middle = duration1 * 0.034 / 2;
  Serial.print("middle: ");
  Serial.print(middle);
  Serial.println(" cm");

  // Read distance from right ultrasonic sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  right = duration2 * 0.034 / 2;
  Serial.print("right: ");
  Serial.print(right);
  Serial.println(" cm");

  // Read distance from left ultrasonic sensor
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  left = duration3 * 0.034 / 2;
  Serial.print("left: ");
  Serial.print(left);
  Serial.println(" cm");

  // Check the distances and perform corresponding actions
  if (left < 20 && right < 20) {
    Forward();
  }
  if (left < 20) {
    Forward();
  }
  if (right < 20) {
    Forward();
  }
  if (middle < 20) {
    Right();
  }
  if (left < 20 && middle < 20) {
    Right();
  }
  if (right < 20 && middle < 20) {
    Left();
  }
  if (left > 20 && middle > 20 && right > 20) {
    Forward();
  }
  if (left < 20 && middle < 20 && right < 20) {
    Right();
  }
}

// Functions to control the movement of the robot
void Forward() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(3, LOW);
}

void Backward() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(3, HIGH);
}

void Right() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(12, LOW);
  digitalWrite(3, HIGH);
}

void Left() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(3, LOW);
}

void Stop() {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(12, LOW);
  digitalWrite(3, LOW);
}
