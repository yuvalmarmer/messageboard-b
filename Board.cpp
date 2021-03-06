#include "Board.hpp"
#include <string>
#include "Direction.hpp"
#include <climits>


using namespace ariel;
using namespace std;

Board::Board(){
	// Init the board with fix sizes (rows=10, cols=10)
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

void Board::postVerticaly(unsigned int row, unsigned int column, Direction d, std::string message)
{
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
			//Checking if empty then init the row
			if(board->at(row+i) == ""){
				initRow(row+i);
			}
			board->at(row+i).at(column) = message[i];
	}
}
void Board::postHorizontaly(unsigned int row, unsigned int column, Direction d, std::string message)
{
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
	if(board->at(row) == ""){
		initRow(row);
	}
	for(size_t i=0;i<message.length();++i){
		board->at(row).at(column+i) = message[i];
	}
}
void Board::post(unsigned int row, unsigned int column, Direction d, std::string message){
	
	//Check if in row and cols are in the allocated board
	if(d==Direction::Horizontal){	 //Horizontal

		postHorizontaly(row,column,d,message);
	
	}
	else if(d==Direction::Vertical ){ 	//Vertical
	
		postVerticaly(row,column,d,message);
	
	}

	
}
std::string Board::readHorizontal(unsigned int row, unsigned int column, Direction d , unsigned int length){
	string str;
	//Check if in row and cols are in the allocated board
	if(column<cols ){
		if(column+length < cols){
			for(size_t i=0;i<length;++i){
				//Checking if it a empty row
				if(board->at(row) != ""){
					str.push_back(board->at(row).at(column+i));
				}
				else{
					str.push_back('_');
				}
			}
		}
		else{
			for(size_t i=0;i<(cols-column);++i){
				//Checking if it a empty row
				if(board->at(row) != ""){
					str += board->at(row).at(column+i);
				}
				else{
					str += "_";
				}
			}
			// Adding all extra chars
			for(size_t i=0;i<(column+length-cols);++i){
				str += "_";
			}
		}
	}
	else{
			//Return string of '_' 
			for(size_t i=0;i<length;++i){
				str += "_";
			}
	}

	return str;
}

std::string Board::readVerticaly(unsigned int row, unsigned int column, Direction d , unsigned int length)
{
	string str;
	//Check if in row and cols are in the allocated board
	if(row<rows){
		if( row+length<rows){
			for(size_t i=0;i<length;++i){
				//Checking if it a empty row
				if(board->at(row+i) != ""){
					str += board->at(row+i).at(column);
				}
				else{
					str += "_";
				}
			}
		}
		else{
			for(size_t i=0;i<(rows-row);++i){
				//Checking if it a empty row
				if(board->at(row+i) != ""){
					str += board->at(row+i).at(column);
				}
				else{
					str += "_";
				}
			}
			// Adding all extra chars
			for(size_t i=0;i<(row+length-rows);++i){
				str += "_";
			}
		}
	}
	
	else{
		//Return string of '_' 
		for(size_t i=0;i<length;++i){
				str += "_";
		}
	}

	return str;
}




std::string Board::read(unsigned int row, unsigned int column, Direction d , unsigned int length){
	string str;

	//Horizontal
	if(d==Direction::Horizontal){	 
		str = readHorizontal(row,column,d,length);
	}
	//Vertical
	else if(d==Direction::Vertical){ 
		str = readVerticaly(row,column,d,length);
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

	//Adding new empty rows 
	board->resize(rows+add_rows);
	//Adding new cols
	for(unsigned int i=0;i<rows;++i){
		if(board->at(i) != ""){
			string row = board->at(i);
			for(int j =0;j<add_cols;++j){
				row.push_back('_');
			}
			board->at(i)=row;
		}
	}

	rows = add_rows + rows;
	cols = add_cols + cols;
}


void Board::initRow(unsigned int row){
	//Initizilte the rows 
	string newRow;
	for(int i=0;i<cols;++i){
		newRow.push_back('_');
	}
	board->at(row) = newRow;
}