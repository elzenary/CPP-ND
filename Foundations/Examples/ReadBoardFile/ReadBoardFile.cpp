#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;


vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}
// TODO: Add the ReadBoardFile function here.
vector<vector<int>> ReadBoardFile(string filePath){
  vector<vector<int>> board{};
  string line;
  ifstream f1;
  f1.open(filePath);
  if(f1)/*will be evaluated as false bool in case of failed filure*/
  {
    while(getline(f1,line))/*this return object from fstream but during conditions it is evaluated as bool and will be false incase of EOF*/  
    {
	 //cout<<line<<"\n";
      vector<int> row = ParseLine(line);
      board.push_back(row);
	}
  }
  return board;
  
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
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}