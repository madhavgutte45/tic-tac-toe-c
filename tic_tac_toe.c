#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
        }
    }
    return 1;
}

int main() {
    int player = 1;
    int choice;
    char mark;

    while (1) {
        displayBoard();

        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d [%c], enter position (1-9): ",
               player, mark);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        if (checkWin()) {
            displayBoard();
            printf("Player %d [%c] wins!\n", player, mark);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
