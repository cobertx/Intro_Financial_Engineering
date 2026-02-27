#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cout << "Arrow Debreu One Period Market Model" << std::endl;
    vector<vector<double>> U = {
        {2, 1, 1},
        {0, 3, 2},
        {0, 0, 4}
    };
    return 0;
}