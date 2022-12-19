#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;

char common(std::string str1, std::string str2) {
    for (int i=0; i < str1.size(); ++i) {
        if (str2.find(str1[i]) != std::string::npos) {
            return str1[i];
        }
    }
}

char common(std::string str1, std::string str2, std::string str3) {
    for (int i=0; i < str1.size(); ++i) {
        if (str2.find(str1[i]) != std::string::npos) {
            if(str3.find(str1[i]) != std::string::npos) {
                return str1[i];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // read input
    std::ifstream inputFile;
    inputFile.open("input.txt");
    std::string line;
    std::string line2;
    std::string line3;
    int score = 0;
    int score2 = 0;

    // while not "/n", add total to the current spot in the vector
    while(std::getline(inputFile, line)) {
        std::getline(inputFile, line2);
        std::getline(inputFile, line3);
        char a = common(line, line2, line3);
        if (a >= 65 && a <= 90) {
            score += (a - 38);
        }
        if (a >= 97 && a <= 122) {
            score += (a - 96);
        }
        // cout << a << endl;
        // cout << score << endl;

    }

    cout << "Score: " << score << endl;
    cout << "SCore 2: " << score2 << endl;
    return 0;
}

