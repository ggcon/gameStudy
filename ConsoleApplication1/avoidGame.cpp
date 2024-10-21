#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch() ���
#include <time.h>
#include <windows.h> // Sleep() ���

#define WIDTH 20
#define HEIGHT 10
//����� test
void setup(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            field[i][j] = ' ';
}

void draw(char field[HEIGHT][WIDTH], int playerPos, int score, int lives) {
    system("cls"); // ȭ�� �����
    printf("Score: %d  Lives: %d\n", score, lives); // ������ ��� ǥ��
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
    int lives = 3; // �ʱ� ��� ����
    srand(time(NULL));

    setup(field);

    while (lives > 0) { // ����� 0�� �� ������ �ݺ�
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' && playerPos > 0) playerPos--; // ����
            if (ch == 'd' && playerPos < WIDTH - 1) playerPos++; // ������
        }

        placeObstacle(field);
        moveObstacles(field);

        // ��ֹ��� �÷��̾� �浹 Ȯ��
        if (field[HEIGHT - 1][playerPos] == '#') {
            lives--; // ��� ����
            field[HEIGHT - 1][playerPos] = ' '; // �÷��̾� ��ġ �ʱ�ȭ
            if (lives > 0) {
                printf("Oops! You lost a life. Lives remaining: %d\n", lives);
                Sleep(1000); // ��� ���
            }
            else {
                printf("Game Over! Final Score: %d\n", score);
                break;
            }
        }
        else {
            score++; // ��ֹ��� ���� ������ ���� ����
        }

        draw(field, playerPos, score, lives); // ������ ��� ǥ��
        Sleep(200); // ���� �ӵ� ����
    }

    return 0;
}
