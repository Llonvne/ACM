#include "bits/stdc++.h"

using namespace std;

#define MATRIX_SIZE 5
#define INPUT_STOP (-1)
#define COMMAND_STOP ('0')
#define UNSAFE (-1)
#define INPUT_ERROR (-1)

int InputMatrix();

int InputCommand();

int OuputMatrix();

int SafeCheck(const int CheckPos[]);

int OutputPuzzleCount();

int ErrorOutput();

int commandSwitch(char commandType, int returnRouter[]);

const int upp[] = {-1, 0};
const int down[] = {1, 0};
const int Left[] = {0, -1};
const int Right[] = {0, 1};

char matrix[MATRIX_SIZE][MATRIX_SIZE];
char commandChar[1000];
int commandLen;
int blankPos[2];
int PuzzleCount = 0;

int main() {

    while (InputMatrix() != INPUT_STOP) {

        if (PuzzleCount != 0){
            printf("\n");
        }

        InputCommand();

        for (int i = 0; i < commandLen; ++i) {
            int destPos[2] = {0, 0};

            if (commandSwitch(commandChar[i], destPos) == INPUT_ERROR) {
                ErrorOutput();
                goto done;
            }
            if (SafeCheck(destPos) == UNSAFE) {
                ErrorOutput();
                goto done;
            }

            swap(matrix[blankPos[0]][blankPos[1]], matrix[destPos[0]][destPos[1]]);
            swap(blankPos[0], destPos[0]);
            swap(blankPos[1], destPos[1]);
        }

        OutputPuzzleCount();
        OuputMatrix();

        done:;
    }
}

char GetCharWithoutEnter() {
    char ReturnChar;
    do {
        ReturnChar = getchar();
        if (ReturnChar == EOF) {
            return INPUT_STOP;
        }
    } while (ReturnChar == '\n');
    return ReturnChar;
}

int InputMatrix() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            char charBuffer = GetCharWithoutEnter();

            if (charBuffer == INPUT_STOP) {
                return INPUT_STOP;
            } else if (charBuffer == ' ') {
                blankPos[0] = i;
                blankPos[1] = j;
            }

            matrix[i][j] = charBuffer;
        }
        while (getchar()!='\n'){
            ;
        }
    }
    return 0;
}

int InputCommand() {

    memset(commandChar, '\0', sizeof(commandChar));
    for (int i = 0;; ++i) {
        commandChar[i] = GetCharWithoutEnter();

        if (commandChar[i] == COMMAND_STOP) {
            commandLen = i;
            getchar();
            break;
        }
    }
    return 0;
}

int commandSwitch(char commandType, int returnRouter[]) {
    int isError = 0;
    switch (commandType) {
        case 'A':
            returnRouter[0] += upp[0];
            returnRouter[1] += upp[1];
            break;
        case 'B':
            returnRouter[0] += down[0];
            returnRouter[1] += down[1];
            break;
        case 'L':
            returnRouter[0] += Left[0];
            returnRouter[1] += Left[1];
            break;
        case 'R':
            returnRouter[0] += Right[0];
            returnRouter[1] += Right[1];
            break;
        default:
            isError = INPUT_ERROR;

    }
    returnRouter[0] += blankPos[0];
    returnRouter[1] += blankPos[1];
    return isError;
}

int OuputMatrix() {

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE - 1; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("%c\n", matrix[i][MATRIX_SIZE - 1]);
    }
    return 0;
}

int SafeCheck(const int CheckPos[]) {
    if (CheckPos[0] >= 5 || CheckPos[0] < 0) {
        return UNSAFE;
    } else if (CheckPos[1] >= 5 || CheckPos[1] < 0) {
        return UNSAFE;
    }
    return 1;
}

int OutputPuzzleCount() {
    PuzzleCount++;
    printf("Puzzle #%d:\n", PuzzleCount);
    return 0;
}

int ErrorOutput() {
    OutputPuzzleCount();
    printf("This puzzle has no final configuration.\n");
    return 0;
}