#include <string>
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <climits>
#include "Board.hpp"

int main(){
    
    ariel::Board b;
    string message = "Yuval Marmer";
    
    //Simple post at 200 , 200
    b.post(200,200,ariel::Direction::Horizontal, message);
    b.post(200,200,ariel::Direction::Vertical, message);

    //Simple read at 200 200 of message length
    std::cout << b.read(200,200,ariel::Direction::Horizontal, message.length()) << std::endl;  
    std::cout << b.read(200,200,ariel::Direction::Horizontal, message.length()) << std::endl;

    //Show the board
    b.show();

    //Simple overwrite at 200,205 and 205,200
    b.post(200,205,ariel::Direction::Horizontal, message);
    b.post(205,200,ariel::Direction::Vertical, message);    

    //Simple read at 200 200 of message length
    std::cout << b.read(200,200,ariel::Direction::Horizontal, message.length()) << std::endl;  
    std::cout << b.read(200,200,ariel::Direction::Horizontal, message.length()) << std::endl;

    //Show the board
    b.show();

    
    return 0;
}
