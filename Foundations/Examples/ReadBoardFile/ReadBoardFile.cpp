#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::string;
using std::vector;
using std::ifstream;

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(string filePath)
{
  string line;
  ifstream f1;
  f1.open(filePath);
  if(f1.is_open()==true)
  {
    while(getline(f1,line))
   cout<<line<<"\n"; 
  }
  
  
}
// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // TODO: Call the ReadBoardFile function here.
  ReadBoardFile("1.board");
  // Leave the following line commented out.
  //PrintBoard(board);
}