📏 Ultrasonic Distance Measurement using Arduino (HC-SR04)

This project demonstrates how to measure distance using ultrasonic sound waves with an HC-SR04 sensor and display the result on the Serial Monitor.

🧠 Working Principle

The HC-SR04 ultrasonic sensor measures distance by sending out a short ultrasonic pulse from the Trigger (TRIG) pin and waiting for its echo to return to the Echo (ECHO) pin.

The time taken for the echo to return is directly proportional to the distance between the sensor and the object.

The Arduino calculates the distance using:

Distance (cm)
=
Time (µs)
×
0.0171
1
Distance (cm)=
1
Time (µs)×0.0171
	​

🧩 Components Required
Component	Quantity
Arduino UNO	1
HC-SR04 Ultrasonic Sensor	1
Jumper Wires	4
Breadboard	1
USB Cable	1
⚡ Circuit Connections
HC-SR04 Pin	Arduino Pin
VCC	5V
GND	GND
TRIG	D7
ECHO	D6

The sensor emits 40 kHz sound waves and listens for reflections.
Distance range: 2 cm to 400 cm (with ~3 mm accuracy).

💻 Arduino Code
```c
const int Echopin = 6;
const int Trigpin = 7;

unsigned int Duration, Distance;
void setup()
{
  pinMode(Echopin, INPUT);
  pinMode(Trigpin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(Trigpin, LOW);
}

void loop()
{
  digitalWrite(Trigpin, HIGH);
  _delay_ms(10);
  digitalWrite(Trigpin, LOW);

  Duration = pulseIn(Echopin, HIGH);
  Distance = (0.0171 * Duration);

  Serial.print(Distance);
  Serial.println(" cm");
  _delay_ms(100);
}
```
📟 Output Example

Serial Monitor Output:

12 cm
11 cm
10 cm
9 cm
8 cm


As an object moves closer to the sensor, the measured distance decreases accordingly.

🧩 Code Explanation

Trigger Pulse: Arduino sends a 10 µs HIGH pulse to the Trig pin.

Echo Detection: The Echo pin stays HIGH for the duration of the pulse’s round trip.

Time Measurement: pulseIn() measures that HIGH time in microseconds.

Distance Calculation: Distance = Duration × 0.0171 (speed of sound ÷ 2).

Result Display: Distance is printed to the Serial Monitor in centimeters.

🛠️ Applications

Object detection and avoidance (Robotics)

Parking assistant systems

Level monitoring (water or tank levels)

Proximity-based automation

⚙️ Notes

Avoid objects that absorb sound (like soft cloth) — they can reduce accuracy.

For stable readings, use a delay of 100–200 ms between measurements.

Replace _delay_ms() with delay() if you’re using standard Arduino syntax (since _delay_ms() comes from AVR C).
