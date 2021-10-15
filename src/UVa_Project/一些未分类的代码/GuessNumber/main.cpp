#include <iostream>
#include <stdlib.h>
int main() {
    int guess,secret = int(rand()) % 100 + 1;
    std::cout << "Now Guessing >>>   ";
    while(std::cin >> guess){
        if (guess == secret){
            std::cout << "You win!";
            break;
        }else if(guess > secret){
            std::cout << "Too large";
        }else {
            std::cout << "Too small";
        }
        std::cout << std::endl << "Guessing again >>>   ";
    }
}
