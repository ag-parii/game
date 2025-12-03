#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

#define ROWS 10
#define LANES 3
#define INITIAL_LIVES 3

void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
    srand(time(0));

    // Hide cursor
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(h, &cursorInfo);

    int playAgain = 1;

    while (playAgain) {
        system("color 4F");
        PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);

        int playerPos = 1;
        int step = 0;
        int obstaclePos = rand() % LANES;
        int score = 0;
        int lives = INITIAL_LIVES;

        int gameOver = 0;

        while (!gameOver) {
            // ---- INPUT ----
            if (_kbhit()) {
                char ch = getch();
                if (ch == 27) { // Esc to quit
                    gameOver = 1;
                    playAgain = 0;
                    break;
                }
                if (ch == 75 && playerPos > 0) playerPos--; // LEFT arrow
                if (ch == 77 && playerPos < LANES-1) playerPos++; // RIGHT arrow
            }

            // ---- DRAW ----
            clear_screen_fast();
            printf("|--- --- ---|\n");

            for (int i = 0; i < ROWS; i++) {
                if (i == step) {
                    for (int lane = 0; lane < LANES; lane++) {
                        if (lane == obstaclePos) printf("|  #  ");
                        else printf("|     ");
                    }
                    printf("|\n");
                } else {
                    printf("|           |\n");
                }
            }

            // Draw player
            for (int lane = 0; lane < LANES; lane++) {
                if (lane == playerPos) printf("|  O  ");
                else printf("|     ");
            }
            printf("|\n");

            // Display score and lives
            printf("Score: %d    Lives: %d\n", score, lives);

            // ---- COLLISION ----
            if (step == ROWS-1 && playerPos == obstaclePos) {
                lives--;
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("impact.wav"), NULL, SND_ASYNC);
                if (lives <= 0) {
                    gameOver = 1;
                    break;
                }
                Sleep(500); // short pause after hit
            } else if (step == ROWS-1) {
                score++; // survived obstacle
            }

            Sleep(120);

            // Move obstacle down
            step++;
            if (step >= ROWS) {
                step = 0;
                obstaclePos = rand() % LANES;
            }
        }

        // ---- GAME OVER SCREEN ----
        clear_screen_fast();
        printf("\n====================\n");
        printf("     GAME OVER!     \n");
        printf("====================\n");
        printf("Final Score: %d\n", score);
        printf("Press 'R' to restart or ESC to quit.\n");

        char choice = 0;
        while (1) {
            if (_kbhit()) {
                choice = getch();
                if (choice == 'r' || choice == 'R') break;
                if (choice == 27) { // ESC
                    playAgain = 0;
                    break;
                }
            }
        }

        PlaySound(NULL, NULL, 0); // stop all sounds before restart or quit
    }

    return 0;
}
