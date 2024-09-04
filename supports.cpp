#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>

class dealer{
    public:
        dealer();
        ~dealer();
        void generateSecretWord();
        std::string getSecretWord();
        bool startRound();
        void drawHangManStage(int stage);
        bool checkGuessedLetter(char letter);
        std::string updateGuess(std::string currentGuess, char letter);
        bool validateGuess(std::string currentGuess);

    private:
        std::string secret_word;
        int verbose_level = 2;
        int attempt_max = 5;

};

dealer::dealer(){
}

dealer::~dealer(){
}

void dealer::generateSecretWord(){
    std::string word_temp;
    if(verbose_level<=1){
        std::cout << "Generating a new random secret word" << std::endl;
    }

    std::ifstream inFile("words.txt");

    if(!inFile){
        throw std::runtime_error("Unable to open file");
    } else {
        std::getline(inFile, word_temp);
        
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        int distr_i = std::rand()%(std::stoi(word_temp));
        
        for (int i =0; i<=distr_i; ++i){
            if(std::getline(inFile, word_temp)){
            }
        }
    }

    secret_word = word_temp;
}

std::string dealer::getSecretWord(){
    return secret_word;
}

bool dealer::startRound(){
    std::string current_guess = "";
    for (int i = 1; i<=secret_word.size();i++){
        if(std::isspace(secret_word[i-1])){
            current_guess += " ";
        } else{
            current_guess += "-";
        }
    }

    int strikes = 0;
    int count = 0;
    std::string guess_char = "";
    std::cout<<"\n\n\n\n\n\n\n"<<std::endl;
    std::string guessed_characters = "";
    std::string clear_text = "Guess the letter: ";
    while (true){
        // std::cout<<"\033[7A";
        std::cout<<"\n\n\n"<<std::endl;
        drawHangManStage(strikes);
        std::cout<<"Word: "<<current_guess<<"\tAttempts left: "<<attempt_max-strikes<<"\tEliminated: "<<guessed_characters<<std::endl;
        
        if (attempt_max > strikes){
            for (int i = 0; i<clear_text.size();i++){
                std::cout<<" ";
            }

            std::cout << "\rGuess the letter: ";
            std::cin >> guess_char;
            clear_text = "Guess the letter: "+guess_char;

            if (guess_char.size()==1){
                guessed_characters+= " "+guess_char;
                if(checkGuessedLetter(guess_char[0])){
                    current_guess = updateGuess(current_guess, guess_char[0]);
                    if(validateGuess(current_guess)){
                        std::cout<<"You win\n"<<std::endl;
                        break;
                    }
                } else{
                    strikes++;
                }
            }
        } else{
            std::cout<<"You lose"<<"\n"<<std::endl;
            break;
        }
    }
}

void dealer::drawHangManStage(int stage){
    switch (stage){
        case (0):
            std::cout<<"-----\n|\n|\n|\n|"<<std::endl;
            break;
        case (1):
            std::cout<<"-----\n|   O\n|\n|\n|\n"<<std::endl;
            break;
        case (2):
            std::cout<<"-----\n|   O\n|   |\n|\n|\n"<<std::endl;
            break;
        case (3):
            std::cout<<"-----\n|   O\n|  /|\n|\n|\n"<<std::endl;
            break;
        case (4):
            std::cout<<"-----\n|   O\n|  /|\\\n|  /\n|\n|"<<std::endl;
            break;
        case (5):
            std::cout<<"-----\n|   O\n|  /|\\\n|  / \\\n|\n|"<<std::endl;
            break;
    }
}

bool dealer::checkGuessedLetter(char letter){
    for (int i = 0; i<secret_word.size(); i++){
        if (letter==secret_word[i]){
            return true;
        }
    }
    return false;
}

std::string dealer::updateGuess(std::string currentGuess, char letter){
    for (int i = 0; i<currentGuess.size();i++){
        if (secret_word[i]==letter){
            currentGuess[i] = letter;
        }
    }

    return currentGuess;
}

bool dealer::validateGuess(std::string currentGuess){
    for(int i = 0; i<currentGuess.size(); i++){
        if(currentGuess[i] == '-'){
            return false;
        }
    }
    return true;
}