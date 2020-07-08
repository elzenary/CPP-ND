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
  if(f1)/*will be evaluated as false bool in case of failed filure*/
  {
    while(getline(f1,line))/*this return object from fstream but during conditions it is evaluated as bool and will be false incase of EOF*/  
    { cout<<line<<"\n"; }
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