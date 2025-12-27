#include <bits/stdc++.h>
using namespace std;

/*
 Word Search
 Given a 2D board of characters and a word, return true if the word exists.
 The word can be constructed from sequentially adjacent cells
 (horizontally or vertically). Each cell may be used only once.
*/

bool dfs(vector<vector<char>>& board, string& word,
         int i, int j, int idx) {
    if (idx == (int)word.size()) return true;
    if (i < 0 || j < 0 || i >= (int)board.size() ||
        j >= (int)board[0].size() ||
        board[i][j] != word[idx])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    bool found =
        dfs(board, word, i + 1, j, idx + 1) ||
        dfs(board, word, i - 1, j, idx + 1) ||
        dfs(board, word, i, j + 1, idx + 1) ||
        dfs(board, word, i, j - 1, idx + 1);

    board[i][j] = temp; // restore
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    string word;
    cin >> word;

    cout << (exist(board, word) ? "true" : "false") << "\n";
    return 0;
}
