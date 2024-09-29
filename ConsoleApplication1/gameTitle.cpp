#include <iostream>
#include <conio.h>   // _kbhit(), _getch() 사용
#include <windows.h> // Sleep() 사용

using namespace std;

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

// Creeper 얼굴을 출력하는 함수
void printFace(int offset) {
    for (int i = 0; i < 14; i++) { // 14줄의 얼굴을 출력
        for (int j = 0; j < offset; j++) {
            cout << " "; // 좌우로 이동시키기 위한 공백 추가
        }
        cout << face[i] << endl; // Creeper 얼굴의 한 줄 출력
    }
}

void clearScreen() {
    system("cls"); // 화면을 지우는 함수 (Windows 환경에서만 사용 가능)
}

int main() {
    int offset = 0;
    int direction = 1; // 1이면 오른쪽으로 이동, -1이면 왼쪽으로 이동
    bool running = true;

    while (running) {
        if (_kbhit()) {  // 키 입력이 있는지 확인
            char key = _getch();  // 키 입력 받기
            if (key == 'q') {
                running = false;  // q 입력 시 게임 종료
            }
            else if (key == 's') {
                clearScreen();
                cout << "게임이 없다" << endl;  // s 입력 시 3초 후 문구 출력
                Sleep(3000);
                clearScreen();
            }
        }

        clearScreen();
        printFace(offset);  // Creeper 얼굴 출력

        offset += direction; // 좌우 이동
        if (offset == 10 || offset == 0) {  // 일정 범위에서 방향 전환
            direction = -direction;
        }

        Sleep(100);  // 애니메이션 속도 조절
    }

    return 0;
}
