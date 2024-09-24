#include <stdio.h>
#include <windows.h>

void gotoXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void setColor(int colorCode) {
    printf("\033[38;5;%dm", colorCode);
}


void printCreeperFace() {
    const char* face[] = {
        "###############################",
        "###############################",
        "###############################",
        "###        #########        ###",
        "###        #########        ###",
        "###        #########        ###",
        "#############     #############",
        "#############     #############",
        "#########             #########",
        "#########             #########",
        "#########             #########",
        "#########    #####    #########",
        "#########    #####    #########",
        "###############################",
    };

    int x = 10, y = 1;
    setColor(2);
    for (int i = 0; i < 15; i++) {
        gotoXY(x, y + i);
        printf("%s", face[i]);
    }
    setColor(7);
    printf("\n");
}

int main() {
    printCreeperFace();
    return 0;
}