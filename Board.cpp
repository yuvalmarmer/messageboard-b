#include "Board.hpp"
#include <string>
#include "Direction.hpp"
#include <climits>


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
	
	//Check if in row and cols are in the allocated board
	if(d==Direction::Horizontal){	 //Horizontal

		//Changing the left column that was posting
		if(leftColPost>column){
			leftColPost=column;
		}
		//Changing the right column that was posting
		if(rightColPost<column+message.length()){
			rightColPost=column+message.length();
		}

		//Resizing the board if needed
		if(message.length() + column >= cols){
			resize(0,message.length()+column-cols+1);

		}
		if(row >= rows){
			resize(row-rows+1,0);
		}
		//Posting the message
		for(size_t i=0;i<message.length();++i){
				board->at(row).at(column+i) = message[i];
		}
	}
	else if(d==Direction::Vertical ){ 	//Vertical
		//Changing the top row that was posting
		if(topRowPost>row){
			topRowPost=row;
		}
		//Changing the bottom row that was posting
		if(bottRowPost<row+message.length()){
			bottRowPost=row+message.length();
		}
		//Resizing the board if needed
		if(message.length() + row >= rows){
			resize(message.length()+row-rows+1,0);
		}
		if(column >= cols){
			resize(0,column-cols+1);
		}
		//Posting the message
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

	//If top row didnt change at all then all vertical
	if (topRowPost==UINT_MAX){
		topRowPost = 0;
		bottRowPost=board->size();
	}
	//If left column didnt change at all then all horizontal
	if (leftColPost==UINT_MAX){
		leftColPost = 0;
		rightColPost=board->at(0).length();
	}

	for(size_t i = topRowPost;i < bottRowPost; ++i){
		for (size_t j = leftColPost; j < rightColPost;++j){
			std::cout << board->at(i)[j];
		}
		std::cout << std::endl;
	}

}


void Board::resize(unsigned int add_rows, unsigned int add_cols){

	//Adding new rows
	for(int i=0;i<add_rows;++i){
		string column;
		board->resize(board->size()+1);
		for(int j =0;j<cols;++j){
			column.push_back('_');
		}
		board->push_back(column);
	}
	//Adding new cols
	for(unsigned int i=0;i<rows;++i){
		string row = board->at(i);
		board->resize(board->size()+1);
		for(int j =0;j<add_cols;++j){
			row.push_back('_');
		}
		board->at(i)=row;
	}

	rows = add_rows + rows;
	cols = add_cols + cols;
}