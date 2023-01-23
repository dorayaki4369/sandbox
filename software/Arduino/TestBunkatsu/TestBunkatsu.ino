int pins[3] = {10,11,12};
int count = 0;

void setup()
{
	Serial.begin(9600);
	for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
		pinMode(pins[i], OUTPUT);
	}
	Serial.println("Hello");
}

void loop(){
	count++;
	Serial.println(count);
	Serial.println("bit1  :");
	Serial.println(count & 1);
	Serial.println("bit10 :");
	Serial.println(count & 2);
	Serial.println("bit100:");
	Serial.println(count & 4);
	ledFlashBinary();
	delay(1000);
	count = count >= 8 ? 0 : count;
}

