#include <iostream>
#include <stack>
#include <vector>

int main ()
{
    std::vector<char> zagrade = {'(','(',')',')',')'};

    std::stack<char> stek;

    for (char zagrada : zagrade) {
        if (zagrada == '(') {
            stek.push(zagrada);
        } else {
            if (stek.empty()) {
                std::cout << "NE\n";
                return 0;
            }
            else {
                stek.pop();
            }
        }
    }

    if (stek.empty()) {
        std::cout << "DA\n";
    }
    else {
        std::cout << "NE\n";
    }
}
