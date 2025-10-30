const int Echopin = 6;
const int Trigpin = 7;

unsigned int Duration, Distance;
void setup()
{
  pinMode(Echopin,INPUT);
  pinMode(Trigpin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(Trigpin,LOW);
}

void loop()
{
  digitalWrite(Trigpin,HIGH);
  _delay_ms(10);
  digitalWrite(Trigpin,LOW);

  Duration = pulseIn(Echopin,HIGH);
  Distance = (0.0171 * Duration);

  Serial.print(Distance);
  Serial.println(" cm");
  _delay_ms(100);
}
