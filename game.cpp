#include "game.h"

Game::Game()
{

}

int Game::getResult(){return _result;}
void Game::setResult(int newResult){_result = newResult;}

QString Game::getScore(){return _score;}
void Game::setScore(QString newScore){_score = newScore;}

void Game::sumScore(){

    std::string scoreStr;
    scoreStr.append(_score.toStdString());
    int index = 0;
    for (int i = 0; i < scoreStr.length(); i ++){
        if(scoreStr.at(i) == ' '){
            index ++;
        }
    }
    std::vector <std::string> numbers;
    numbers.resize(index + 1);

    int space = 0, k = 0;
    int spacePrev = 0;

    for( ; ; ){
        space = scoreStr.find(' ', space);
        if(space != std::string::npos){
            numbers.at(k) = scoreStr.substr(spacePrev, space - spacePrev);
            k++;
            space++;
            spacePrev = space;

        }else{
            numbers.at(k) = scoreStr.substr(spacePrev, scoreStr.length() - spacePrev);
            break;
        }
    }

    int sum = 0;
    int iter = 0;
    int tempD = 0;

    for(int i = 0; i <= index; i++){
        if(numbers.at(i) != "c" && numbers.at(i) != "d" && numbers.at(i) != "+" || numbers.at(i - 1) == "D" || numbers.at(i - 1) == "C"){
            sum += std::stoi(numbers.at(i));
            iter = i + 1;
        }else if (numbers.at(i) == "c" || numbers.at(i - 1) == "C"){
            iter --;
            if (numbers.at(i - 1) == "d" || numbers.at(i - 1) == "D" || numbers.at(i - 1) == "+"){
                sum -= tempD;
            }else{
                sum -= std::stoi(numbers.at(iter));
            }
        }else if (numbers.at(i) == "d" || numbers.at(i - 1) == "D"){
            if(numbers.at(i - 1) == "c" || numbers.at(i - 1) == "C"){
                tempD = std::stoi(numbers.at(iter - 1)) * 2;
            }else if(numbers.at(i - 1) == "d" || numbers.at(i - 1) == "D" || numbers.at(i - 1) == "+"){
                tempD *= 2;
            }else{
                tempD = std::stoi(numbers.at(i - 1)) * 2;
            }
            sum += tempD;
        }else if (numbers.at(i) == "+"){
            if(numbers.at(i - 1) == "c" || numbers.at(i - 1) == "C"){
                tempD = std::stoi(numbers.at(iter - 1)) + std::stoi(numbers.at(iter - 2));
            }else if(numbers.at(i - 1) == "d" || numbers.at(i - 1) == "D" || numbers.at(i - 1) == "+"){
                tempD = tempD + std::stoi(numbers.at(iter - 2));
            }else{
                tempD = std::stoi(numbers.at(i - 1)) + std::stoi(numbers.at(i - 2));
            }
            sum += tempD;
        }
    }
    _result = sum;
}
