#include "Board.hpp"
#include <string>
#include "Direction.hpp"

using namespace ariel;
using namespace std;

Board::Board(){
	// Initi the board with fix sizes (rows, cols)
	board = new vector<string>;
	for(int i=0;i<rows;++i){
		string column;
		for(int j =0;j<cols;++j){
			column.push_back('_');
		}
		board->push_back(column);
	}

}
Board::~Board(){
	
}


void Board::post(unsigned int row, unsigned int column, Direction d, std::string message){
	
}
std::string Board::read(unsigned int row, unsigned int column, Direction d , int length){
	string str = "";
	//Check if in row and cols are in the allocated board
	if(row+length<rows && column+length<cols){ 
		if(d==Direction::Horizontal){	
			for(int i=0;i<length;++i){
				str += board[row].at(i);
			}
		}
		else{ //Vertical
			for(int i=0;i<length;++i){
				str += board[i].at(column);
			}
		}
	}
	return str;
}

void Board::show(){
}