static void ledFlashBinary() {
	int i, j;
	byte state;
	for (i = 0, j = 1; i < sizeof(pins) / sizeof(pins[0]); i++, j = j * 2)
	{
    //この()は重要。ないと挙動がおかしくなる。
		state = (count & j) > 0 ? HIGH : LOW;
		digitalWrite(pins[i], state);
	}
}
