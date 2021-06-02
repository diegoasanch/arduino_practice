/** Fills the received values array with HIGH or LOW corresponding
 * to the 7-segment display states [DP, A-G]
 */
void getDisplaySegments(int num, int values[]) {

    clearValues(values, 8);

    if (num >= 0 && num <= 0xF) {
        if (num == 0 || num == 2 || num == 3 || (num >= 5 && num <= 0xA) || num == 0xC || num >= 0xE)
            values[1] = HIGH; // A
        if (num <= 4 || (num >= 7 && num <= 0xA) || num == 0xD)
            values[2] = HIGH; // B
        if (num == 0 || num == 1 || (num >= 3 && num <= 0xB) || num == 0xD)
            values[3] = HIGH; // C
        if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || (num >= 0xB && num <= 0xE))
            values[4] = HIGH; // D
        if (num == 0 || num == 2 || num == 6 || num == 8 || num >= 0xA)
            values[5] = HIGH; // E
        if (num == 0 || (num >= 4 && num <= 6) || (num >= 8 && num <= 0xC )|| num >= 0xE)
            values[6] = HIGH; // F
        if ((num >= 2 && num <= 6 ) || (num >= 8 && num <= 0xB) || num >= 0xD)
            values[7] = HIGH; // G
    }
    else {
        if (num == -1)
            values[0] = HIGH; // DP
    }
}

void clearValues(int values[], int length) {
    for (int i = 0; i < length; i++)
        values[i] = LOW;
}

byte valuesToByte(int values[8]) {
    byte result = 0;

    for (int i = 0; i < 8; i++) {
        if (values[i])
            bitSet(result, 7-i);
    }
    return result;
}
