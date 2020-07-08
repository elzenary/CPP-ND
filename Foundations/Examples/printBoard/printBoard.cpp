#include iostream
#include vector
using stdcout;
using stdvector;

void PrintBoard(const vectorvectorint board) {
  for (int i = 0; i  board.size(); i++) {
    for (int j = 0; j  board[i].size(); j++) {
      cout  board[i][j];
    }
    cout  n;
  }
}

int main() {
  vectorvectorint board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};
  PrintBoard(board);
}