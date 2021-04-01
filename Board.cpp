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
	delete board;
}


void Board::post(unsigned int row, unsigned int column, Direction d, std::string message){
	

	if(leftColPost>column){
		leftColPost=column;
	}
	if(rightColPost<column+message.length()){
		rightColPost=column+message.length();
	}


	if(topRowPost>row){
		topRowPost=row;
	}

	if(bottRowPost<row+message.length()){
		bottRowPost=row+message.length();
	}
	//Check if in row and cols are in the allocated board
	if(d==Direction::Horizontal){	 //Horizontal

		if(message.length() + column >= cols){
			resize(0,message.length()+column-cols+1);

		}
		if(row >= rows){
			resize(row-rows+1,0);
		}
		for(size_t i=0;i<message.length();++i){
				board->at(row).at(column+i) = message[i];
		}
	}
	else if(d==Direction::Vertical ){ 	//Vertical



		if(message.length() + row >= rows){
			resize(message.length()+row-rows+1,0);
		}
		if(column >= cols){
			resize(0,column-cols+1);
		}
		
		for(size_t i=0;i<message.length();++i){
				board->at(row+i).at(column) = message[i];
		}
	}

	
}
std::string Board::read(unsigned int row, unsigned int column, Direction d , unsigned int length){
	string str;

	//Check if in row and cols are in the allocated board
	if(d==Direction::Horizontal){	 //Horizontal
		if(column<cols ){
			if(column+length < cols){
				for(size_t i=0;i<length;++i){
					str.push_back(board->at(row).at(column+i));
				}
			}
			else{
				for(size_t i=0;i<(cols-column);++i){
					str += board->at(row).at(column+i);
				}
				for(size_t i=0;i<(column+length-cols);++i){
					str += "_";
				}
			}
		}
		else{
				for(size_t i=0;i<length;++i){
					str += "_";
				}
		}
	}
	else if(d==Direction::Vertical ){ 	//Vertical
		if(row<rows){
			if( row+length<rows){
				for(size_t i=0;i<length;++i){
					str += board->at(row+i).at(column);
				}
			}
			else{
				for(size_t i=0;i<(rows-row);++i){
					str += board->at(row+i).at(column);
				}
				for(size_t i=0;i<(row+length-rows);++i){
					str += "_";
				}
			}
		}
		
		else{
			for(size_t i=0;i<length;++i){
					str += "_";
			}
		}
	}
	return str;
}

void Board::show(){

	for(size_t i=0;i<board->size(); ++i){
		std::cout << board->at(i) << endl;
	}
	std::cout << "TOP : " << topRowPost << ", BOTT : " << bottRowPost << std::endl;
	std::cout << "LEFT : " << leftColPost << ", RIGHT : " << rightColPost << std::endl;
}


void Board::resize(unsigned int add_rows, unsigned int add_cols){

	//Adding new rows
	for(int i=0;i<add_rows;++i){
		string column;
		for(int j =0;j<cols;++j){
			column.push_back('_');
		}
		board->push_back(column);
	}
	//Adding new cols
	for(unsigned int i=0;i<rows;++i){
		string row = board->at(i);
		for(int j =0;j<add_cols;++j){
			row.push_back('_');
		}
		board->at(i)=row;
	}

	rows = add_rows + rows;
	cols = add_cols + cols;
}