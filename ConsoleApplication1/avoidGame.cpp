#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch() 사용
#include <time.h>
#include <windows.h> // Sleep() 사용

#define WIDTH 20
#define HEIGHT 10
//깃허브 test
void setup(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            field[i][j] = ' ';
}

void draw(char field[HEIGHT][WIDTH], int playerPos, int score, int lives) {
    system("cls"); // 화면 지우기
    printf("Score: %d  Lives: %d\n", score, lives); // 점수와 목숨 표시
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1 && j == playerPos)
                printf("P");
            else
                printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

void placeObstacle(char field[HEIGHT][WIDTH]) {
    int obstaclePos = rand() % WIDTH;
    field[0][obstaclePos] = '#';
}

void moveObstacles(char field[HEIGHT][WIDTH]) {
    for (int i = HEIGHT - 1; i > 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = field[i - 1][j];
        }
    }
    for (int j = 0; j < WIDTH; j++) {
        field[0][j] = ' ';
    }
}

int main() {
    char field[HEIGHT][WIDTH];
    int playerPos = WIDTH / 2;
    int score = 0;
    int lives = 3; // 초기 목숨 설정
    srand(time(NULL));

    setup(field);

    while (lives > 0) { // 목숨이 0이 될 때까지 반복
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' && playerPos > 0) playerPos--; // 왼쪽
            if (ch == 'd' && playerPos < WIDTH - 1) playerPos++; // 오른쪽
        }

        placeObstacle(field);
        moveObstacles(field);

        // 장애물과 플레이어 충돌 확인
        if (field[HEIGHT - 1][playerPos] == '#') {
            lives--; // 목숨 감소
            field[HEIGHT - 1][playerPos] = ' '; // 플레이어 위치 초기화
            if (lives > 0) {
                printf("Oops! You lost a life. Lives remaining: %d\n", lives);
                Sleep(1000); // 잠시 대기
            }
            else {
                printf("Game Over! Final Score: %d\n", score);
                break;
            }
        }
        else {
            score++; // 장애물을 피할 때마다 점수 증가
        }

        draw(field, playerPos, score, lives); // 점수와 목숨 표시
        Sleep(200); // 게임 속도 조절
    }

    return 0;
}
