#include <iostream>
#include "supports.cpp"
int main(){
    std::cout << "Welcome to hangman."<<std::endl;
    dealer dealer_a;
    dealer_a.generateSecretWord();
    dealer_a.startRound();
    std::cout << "Word of the day is " << dealer_a.getSecretWord() << "." << std::endl;
}