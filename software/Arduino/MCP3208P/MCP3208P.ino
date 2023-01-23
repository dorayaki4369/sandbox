int readADC(int adcNum, int clockPin, int mosiPin, int misoPin, int csPin);

int clockPin = 13;
int mosiPin = 16;
int misoPin = 17;
int csPin = 9;

void setup()
{
	Serial.begin(9600);
	pinMode(csPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(mosiPin, OUTPUT);
	pinMode(misoPin, INPUT);
}

void loop()
{
	int inputVal0 = readADC(0, clockPin, mosiPin, misoPin, csPin);
	Serial.print("Val = ");
	Serial.println(inputVal0);
	delay(200);
}

int readADC(int chNum, int clockPin, int mosiPin, int misoPin, int csPin)
{
	if (chNum > 7 && chNum < 0)	return -1;

	digitalWrite(csPin, HIGH);
	digitalWrite(clockPin, LOW);
	digitalWrite(csPin, LOW);

	byte commandOut = chNum;
	commandOut |= 0x18;
	commandOut << 3;

	for (int i = 0; i <= 5; i++)
	{
		if (commandOut & 0x80)
		{
			digitalWrite(mosiPin, HIGH);
		}
		else
		{
			digitalWrite(mosiPin, LOW);
		}
		commandOut << 1;
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
	}

	byte adcOut = 0;

	for (int i = 0; i <= 12; i++)
	{
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
		adcOut << 1;
		if (i > 0 && digitalRead(misoPin) == HIGH) adcOut |= HIGH;
	}
	digitalWrite(csPin, HIGH);

	return adcOut;
}