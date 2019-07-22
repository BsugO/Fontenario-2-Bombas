/*
 Name:		fontenario.ino
 Created:	3/14/2019 5:02:10 PM
 Author:	PTL00023-PAN006
*/
#include <Servo.h>
const int bomba_1 = 2;
const int bomba_2 = 3;
const int sensor = A1;
int ValorSensor = 0;
const int ON = 4;
int Temporizador[11] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500};
// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(bomba_1, OUTPUT);
	pinMode(bomba_2, OUTPUT);
	pinMode(ON, OUTPUT);
	pinMode(sensor, INPUT);
	Serial.begin(9600);
	Servo Dt, Esq;
	}

// the loop function runs over and over again until power down or reset
void loop() {
	ValorSensor = analogRead(sensor);
	Serial.println(ValorSensor);
	if (sensor <= 50) {
		Sequencia_1();
		delay(2000);
		Sequencia_2();
		delay(2000);
		Sequencia_3();
		delay(2000);
		Sequencia_4();
		delay(2000);
		Sequencia_5();
		Sequencia_6();
		Serial.println("pausa no sistema");
		delay(10000);
	}
	else
	{
		digitalWrite(bomba_1, LOW);
		digitalWrite(bomba_2, LOW);
	}
}
void Sequencia_1() {
	Serial.println("Seq1");
	digitalWrite(bomba_1, HIGH);
	delay(2500);
	digitalWrite(bomba_2, HIGH);
	delay(2500);
	digitalWrite(bomba_1, LOW);
	delay(800);
	digitalWrite(bomba_2, LOW);
	delay(1000);
}
void Sequencia_2() {
	Serial.println("Seq2");
	digitalWrite(bomba_1, HIGH);
	digitalWrite(bomba_2, HIGH);
	delay(3000);
	digitalWrite(bomba_1, LOW);
	digitalWrite(bomba_2, LOW);
	delay(1000);
}
void Sequencia_3() {
	Serial.println("Seq3");
	digitalWrite(bomba_1, HIGH);
	delay(3000);
	digitalWrite(bomba_2, HIGH);
	delay(3000);
	digitalWrite(bomba_1, LOW);
	delay(500);
	digitalWrite(bomba_2, LOW);
	delay(500);
}
void Sequencia_4() {
	Serial.println("Seq4");
	digitalWrite(bomba_1, HIGH);
	delay(1000);
	digitalWrite(bomba_2, HIGH);
	delay(1000);
	digitalWrite(bomba_1, LOW);
	digitalWrite(bomba_2, LOW);
	delay(2000);
}
void  Sequencia_5() {
	Serial.println("Seq5");
	for (int a = 0; a < 6; a++) {
		Serial.println(a);
		digitalWrite(bomba_1, HIGH);
		delay(2000);
		digitalWrite(bomba_1, LOW);
		digitalWrite(bomba_2, HIGH);
		delay(2000);
		digitalWrite(bomba_2, LOW);
	}
}
void  Sequencia_6() {
	Serial.println("Seq6");
	for (int a = 10; a >= 0; a--) {
		Serial.println(Temporizador[a]);
		digitalWrite(bomba_1, HIGH);
		delay(Temporizador[a]);
		digitalWrite(bomba_1, LOW);
		digitalWrite(bomba_2, HIGH);
		delay(Temporizador[a]);
		digitalWrite(bomba_2, LOW);
	}
}
