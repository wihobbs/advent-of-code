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
    std::vector<int> elves;
    std::string line;
    int a = 0;

    // while not "/n", add total to the current spot in the vector
    while(std::getline(inputFile, line)) {
        if (line != "") {
            // cout << line << endl;
            a += std::stoi(line);
        } else {
            elves.push_back(a);
            a = 0;
        }
    }

    // you could make this compute in O(n) time but I'm too lazy for that
    sort(elves.begin(), elves.end()); // O(n(log n))
    int max = elves[elves.size()-1];
    int maxThree = elves[elves.size()-1] + elves[elves.size()-2] + elves[elves.size()-3];

    cout << "Top elf: " << max << endl;
    cout << "Top three elves: " << maxThree << endl;
    return 0;
}