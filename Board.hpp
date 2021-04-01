#include <string>
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
namespace ariel {
    class Board{

        public :
			Board();
			~Board();
			void post(unsigned int row, unsigned int column, Direction d, std::string message);
			std::string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
			void show();
		
		private:
		    unsigned int rows = 10;
			unsigned int cols = 10;
			unsigned int topRowPost = UINT_MAX;
			unsigned int bottRowPost = 0;
			unsigned int leftColPost = UINT_MAX;
			unsigned int rightColPost = 0;
			
			vector<string> *board;
			void resize(unsigned int add_rows, unsigned int add_cols);
 	};
}