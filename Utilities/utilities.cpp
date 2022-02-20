#include "utilities.h"

void clearScreen(){	
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

uint32_t fact(uint16_t n){
    if (n == 0 || n == 1 || n == 2) { return n; }
    uint32_t f = 1;
    for (; n > 1; n--){
        f *= n;
    }
    return f;
}