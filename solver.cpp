#include <chrono>
#include <iostream>
#include <vector>

void checkBoard(std::vector<std::vector<char>>& board,  bool (&rows)[9][9], bool (&cols)[9][9], bool (&squares)[9][9]) {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      if (board[r][c] != '.') {
        int current = board[r][c] - 49;
        int sqindex = (c / 3 + ((r / 3) * 3));        
        rows[r][current] = cols[c][current] = squares[sqindex][current] = 1;
        }
      }
    }  
  return;
}

bool isValidEntry(std::vector<std::vector<char>>& board, int c, int row, int column, bool (&rows)[9][9], bool (&cols)[9][9], bool (&squares)[9][9]) {
  int sqIndex = (column / 3 + ((row / 3) * 3));
  if (rows[row][c] || cols[column][c] || squares[sqIndex][c]) {
    return false;
  } else {
    rows[row][c] = cols[column][c] = squares[sqIndex][c] = 1;
  }
  return true;
}

bool solveSudokuHelper(std::vector<std::vector<char>>& board, bool (&rows)[9][9], bool (&cols)[9][9], bool (&squares)[9][9]) { 
  for (int m = 0; m < 9; m++) {
    for (int n = 0; n < 9; n++) {
      if (board[m][n] == '.') {
        for (int c = 0; c < 9; c++) {
          if (isValidEntry(board, c, m, n, rows, cols, squares)) {
            board[m][n] = c + 49;
            if (solveSudokuHelper(board, rows, cols, squares)) {
              return true;
            } else {
              rows[m][c] = false;
              cols[n][c] = false;
              squares[(n / 3 + ((m / 3) * 3))][c] = false;
              board[m][n] = '.';
            }
          }
        }
      return false;
    }
  }
}
return true;
}

void solveSudoku(std::vector<std::vector<char>>& board) {
  bool rows[9][9] = {0};
  bool cols[9][9] = {0};
  bool squares[9][9] = {0};
  checkBoard(board, rows, cols, squares);
  solveSudokuHelper(board, rows, cols, squares);
}

  int main() {

  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  std::vector<std::vector<char>> sudoku = {
    { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
  };
  
  auto t1 = high_resolution_clock::now();
  solveSudoku(sudoku);  
  auto t2 = high_resolution_clock::now();
  for (auto vec:sudoku) {
    for (auto c:vec) {
      std::cout << c << ' ';
    }
    std::cout << '\n';
  }
  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  std::cout << ms_int.count() << "ms\n";
}
