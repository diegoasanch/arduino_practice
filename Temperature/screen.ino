/** Returns a byte with the bits corresponding to the 7-segment display
 * states [DP, A-G]
 */
byte getDisplaySegments(int num) {

    byte result = 0;

    if (num >= 0 && num <= 0xF) {
        if (num == 0 || num == 2 || num == 3 || (num >= 5 && num <= 0xA) || num == 0xC || num >= 0xE)
            bitSet(result, 0); // A
        if ((num >= 0 && num <= 4) || (num >= 7 && num <= 0xA) || num == 0xD)
            bitSet(result, 1); // B
        if (num == 0 || num == 1 || (num >= 3 && num <= 0xB) || num == 0xD)
            bitSet(result, 2); // C
        if (num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9 || (num >= 0xB && num <= 0xE))
            bitSet(result, 3); // D
        if (num == 0 || num == 2 || num == 6 || num == 8 || num >= 0xA)
            bitSet(result, 4); // E
        if (num == 0 || (num >= 4 && num <= 6) || (num >= 8 && num <= 0xC )|| num >= 0xE)
            bitSet(result, 5); // F
        if ((num >= 2 && num <= 6 ) || (num >= 8 && num <= 0xB) || num >= 0xD)
            bitSet(result, 6); // G
    }
    else if (num < 0 && num >= -4) {
        if (num == -1) // DP
            bitSet(result, 7);
        if (num == -2) { // Degree
            bitSet(result, 0); // A
            bitSet(result, 1); // B
            bitSet(result, 5); // F
            bitSet(result, 6); // G
        }
        if (num == -3) { // %
            bitSet(result, 2); // C
            bitSet(result, 5); // F
        }
    }
    return result;
}

