void getDisplaySegments(int num, int values[]) {

    clearValues(values, 7);

    if (num >= 0 && num <= 0xF) {
        if (num == 0 || num == 2 || num == 3 || (num >= 5 && num <= 0xA) || num == 0xC || num >= 0xE)
            values[0] = HIGH; // A
        if (num <= 4 || (num >= 7 && num <= 0xA) || num == 0xD)
            values[1] = HIGH; // B
        if (num == 0 || num == 1 || (num >= 3 && num <= 0xB) || num == 0xD)
            values[2] = HIGH; // C
        if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || (num >= 0xB && num <= 0xE))
            values[3] = HIGH; // D
        if (num == 0 || num == 2 || num == 6 || num == 8 || num >= 0xA)
            values[4] = HIGH; // E
        if (num == 0 || (num >= 4 && num <= 6) || (num >= 8 && num <= 0xC )|| num >= 0xE)
            values[5] = HIGH; // F
        if ((num >= 2 && num <= 6 ) || (num >= 8 && num <= 0xB) || num >= 0xD)
            values[6] = HIGH; // G
    }
    else {
        if (num == -1)
            values[1] = HIGH; // B
    }
}

void clearValues(int values[], int length) {
    for (int i = 0; i < length; i++)
        values[i] = LOW;
}

void printValue(int pins[7], int segments[7]) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(pins[i], segments[i]);
    }
}
