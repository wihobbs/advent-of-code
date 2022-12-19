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
    std::string line2;
    int score = 0;
    int score2 = 0;

    // while not "/n", add total to the current spot in the vector
    while(std::getline(inputFile, line)) {
        std::string range1 = line.substr(0, (line.find(",")));
        std::string range2 = line.substr((1+line.find(",")), line.size()-1);
        int range1_lower_bound = stoi(range1.substr(0, range1.find("-")));
        int range1_upper_bound = stoi(range1.substr((1+range1.find("-")), range1.size()-1));
        int range2_lower_bound = stoi(range2.substr(0, (range2.find("-"))));
        int range2_upper_bound = stoi(range2.substr((1+range2.find("-")), range2.size()-1));
        if ((range2_lower_bound <= range1_lower_bound && range1_lower_bound <= range2_upper_bound) || (range2_lower_bound <= range1_upper_bound && range1_upper_bound <= range2_upper_bound)) {
            score++;
        } else if ((range1_lower_bound <= range2_lower_bound && range2_lower_bound <= range1_upper_bound) || (range1_lower_bound <= range2_upper_bound && range2_upper_bound <= range1_upper_bound)) {
            score++;
        }
        cout << range1_lower_bound << " " << range1_upper_bound << " " << range2_lower_bound << " " << range2_upper_bound << endl;
    }

    cout << "Score: " << score << endl;
    cout << "Score 2: " << score2 << endl;
    return 0;
}
