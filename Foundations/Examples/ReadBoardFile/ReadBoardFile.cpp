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

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}
// TODO: Add the ReadBoardFile function here.
vector<vector<State>> ReadBoardFile(string filePath){
  vector<vector<State>> board{};
  string line;
  ifstream f1;
  f1.open(filePath);
  //ifstream myfile (path);/*another option*/
  if(f1)/*will be evaluated as false bool in case of failed filure*/
  {
    while(getline(f1,line))/*this return object from fstream but during conditions it is evaluated as bool and will be false incase of EOF*/  
    {
	 //cout<<line<<"\n";
      vector<State> row = ParseLine(line);
      board.push_back(row);
	}
  }
  return board;
  
string CellString(State s)
{
  if(s==State::kObstacle)
    return "⛰️   ";
  else
    return "0 "; 
}
}
// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
     // cout << board[i][j];
  
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}