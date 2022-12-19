#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    // read input
    std::ifstream inputFile;
    inputFile.open("input.txt");
    std::string line;
    int score = 0;
    int score2 = 0;

    // while not "/n", add total to the current spot in the vector
    while(std::getline(inputFile, line)) {
        if (line.find("X") != std::string::npos) {
            score += 1;
            if (line.find("A") != std::string::npos) {
                score2 += 3;
                score += 3;
            }
            if (line.find("B") != std::string::npos) {
                score2 += 1;
            }
            if (line.find("C") != std::string::npos) {
                score2 += 2;
                score += 6;
            }
        }
        if (line.find("Y") != std::string::npos) {
            score += 2;
            score2 += 3;
            if (line.find("C") != std::string::npos) {
                score2 += 3;
            }
            if (line.find("B") != std::string::npos) {
                score += 3;
                score2 += 2;
            }
            if (line.find("A") != std::string::npos) {
                score += 6;
                score2 += 1;
            }
        }
        if (line.find("Z") != std::string::npos) {
            score += 3;
            score2 += 6;
            if (line.find("C") != std::string::npos) {
                score += 3;
                score2 += 1;
            }
            if (line.find("B") != std::string::npos) {
                score += 6;
                score2 += 3;
            }
            if (line.find("A") != std::string::npos) {
                score2 += 2;
            }
        }
    }

    cout << "Score: " << score << endl;
    cout << "SCore 2: " << score2 << endl;
    return 0;
}