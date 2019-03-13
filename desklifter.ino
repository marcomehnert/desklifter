#include <Arduino.h>
long upperBound, lowerBound;
double actualPosition;
int triggerPin = 2; /* D4 = GPIO2 */
int echoPin = 0; /* D3  = GPIO0 */
int relayUpPin = 12; /* D6 = GPIO12 */
int relayDownPin = 13; /* D7 = GPIO13 */
int switchUpPin = 15; /* D8 = GPI15  */
int switchDownPin = 14; /* D5 = GPI14 */

double getDistance() {
  double duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); delayMicroseconds(30);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 340 / (2 * 10000);
  return distance;
}
void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(relayUpPin, OUTPUT);
  pinMode(relayDownPin, OUTPUT);

  pinMode(switchUpPin, INPUT);
  pinMode(switchDownPin, INPUT);

  upperBound = 10;
  lowerBound = 6;
  digitalWrite(relayDownPin, HIGH);
  digitalWrite(relayUpPin, HIGH);
  digitalWrite(triggerPin, LOW);

  Serial.begin(74880);
  Serial.println(String(getDistance()));

}


void loop()
{
    digitalWrite(relayDownPin, (digitalRead(switchDownPin)== HIGH) ? LOW : HIGH);
    digitalWrite(relayUpPin, (digitalRead(switchUpPin)== HIGH) ? LOW : HIGH);
    Serial.println(String(getDistance()));
}
