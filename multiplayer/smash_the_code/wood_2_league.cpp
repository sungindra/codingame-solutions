#include <cstdbool>
#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_ROW = 12;
const int MAX_COLUMN = 6;

const int FIVE_STAR = 0x3f3f3f3f; //skull
const int HALF_SCORE_ADDED = 5;
const int FULL_SCORE_ADDED = 10;

const char EMPTY = '.';
const char SKULL = '0';

int argmax(const int numbers[], const int length) {
    return distance(numbers, max_element(numbers, numbers + length));
}

bool is_in_map(int row, int column) {
    if(row < 0 || row >= MAX_ROW) return false;
    if(column < 0 || column >= MAX_COLUMN) return false;

    return true;
}

int left_score(const char board[MAX_ROW][MAX_COLUMN], const pair<char, char>& input_color, const int& column) {
    int score = 0;

    int row = 0;
    for(; row < MAX_ROW; row++) {
        if(!is_in_map(row + 1, column)) break;
        if(board[row + 1][column] != EMPTY) break;
    }
    score -= (MAX_ROW - row);
    if(row < 2) return score - FULL_SCORE_ADDED;

    //check bottom block
    if(is_in_map(row, column - 1) && board[row][column - 1] == input_color.second) score += HALF_SCORE_ADDED;

    //check upper block
    if(is_in_map(row - 1, column - 1) && board[row - 1][column - 1] == input_color.first) score += HALF_SCORE_ADDED;

    fprintf(stderr, "right score: %d\n", score);
    return score;
}

int right_score(const char board[MAX_ROW][MAX_COLUMN], const pair<char, char>& input_color, const int& column) {
    int score = 0;

    int row = 0;
    for(; row < MAX_ROW; row++) {
        if(!is_in_map(row + 1, column)) break;
        if(board[row + 1][column] != EMPTY) break;
    }
    score -= (MAX_ROW - row);
    if(row < 2) return score - FULL_SCORE_ADDED;

    //check bottom block
    if(is_in_map(row, column + 1) && board[row][column + 1] == input_color.second) score += HALF_SCORE_ADDED;

    //check upper block
    if(is_in_map(row - 1, column + 1) && board[row - 1][column + 1] == input_color.second) score += HALF_SCORE_ADDED;

    fprintf(stderr, "left score: %d\n", score);
    return score;
}

int bottom_score(const char board[MAX_ROW][MAX_COLUMN], const pair<char, char>& input_color, const int& column) {
    int score = 0;

    int row = 0;
    for(; row < MAX_ROW; row++) {
        if(!is_in_map(row + 1, column)) break;
        if(board[row + 1][column] != EMPTY) break;
    }
    score -= (MAX_ROW - row);
    if(row < 2) return score - FULL_SCORE_ADDED;
    if(!is_in_map(row + 1, column)) return score - HALF_SCORE_ADDED;

    if(is_in_map(row + 1, column) && board[row + 1][column] != EMPTY) {
        if(board[row + 1][column] == input_color.second) score += FULL_SCORE_ADDED;
    }

    return score;
}

int evaluate(const char board[MAX_ROW][MAX_COLUMN], const pair<char, char>& input_color, const int& column) {
    int score = 0;

    score += left_score(board, input_color, column);
    score += bottom_score(board, input_color, column);
    score += right_score(board, input_color, column);

    return score;
}

int main() {

    // game loop
    while (true) {
        pair<char, char> input_color;
        char color_A, color_B;
        cin >> color_A >> color_B; cin.ignore();
        input_color = make_pair(color_A, color_B);

        for (int i = 0; i < 7; i++) {
            char _; // color of the first block
            cin >> _ >> _; cin.ignore();
        }
        int score1;
        cin >> score1; cin.ignore();
        char board[MAX_ROW][MAX_COLUMN];
        for (int i = 0; i < MAX_ROW; i++) {
            string row; // One line of the map ('.' = empty, '0' = skull block, '1' to '5' = colored block)
            cin >> row; cin.ignore();
            for(int j = 0; j < MAX_COLUMN; j++) {
                board[i][j] = row[j];
                cerr << board[i][j] << ' ';
            }
            fprintf(stderr, "\n");
        }
        int score2;
        cin >> score2; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row;
            cin >> row; cin.ignore();
        }

        int scores[MAX_COLUMN];
        for(int c = 0; c < MAX_COLUMN; c++) {
            scores[c] = evaluate(board, input_color, c);
            fprintf(stderr, "%d ", scores[c]);
        }
        fprintf(stderr, "\n");

        cout << argmax(scores, MAX_COLUMN) << endl; // "x": the column in which to drop your blocks
    }
}