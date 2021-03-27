#include <string>
#include "Direction.hpp"
#include <iostream>
#include <vector>

using namespace std;
namespace ariel {
    class Board{

        public :
			Board();
			~Board();
			void post(int row, int column, Direction d, std::string message);
			std::string read(int row, int column, Direction d, int length);
			void show();
		private:
			int rows = 10;
			int cols = 10;
			vector<string> *board;
 	};
}