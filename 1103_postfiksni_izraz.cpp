//Bez razmaka
// 2 3 + 5 * < = > (2 + 3) * 5
// 2 7 - 6 9 + * < = > (2 - 7) * (6 + 9)

#include <iostream>
#include <stack>

int main ()
{
    std::stack<int> stek;

    std::string izraz;

    std::cin >> izraz;

    for (char c : izraz) {
        if (c == '+') {
            int op1 = stek.top();
            stek.pop();

            int op2 = stek.top();
            stek.pop();

            stek.push(op1 + op2);
        }
        else if (c == '-') {
            int op2 = stek.top();
            stek.pop();

            int op1 = stek.top();
            stek.pop();

            stek.push(op1 - op2);

            // op1 = stek.top();
            // stek.pop();

            // op2 = stek.top();
            // stek.pop();

            // stek.push(op2 - op1);
        }
        else if (c == '*') {
            int op1 = stek.top();
            stek.pop();

            int op2 = stek.top();
            stek.pop();

            stek.push(op1 * op2);
        }
        else if (c == '/') {
            int op2 = stek.top();
            stek.pop();

            int op1 = stek.top();
            stek.pop();

            if (op2 == 0) {
                std::cerr << "Deljenje 0!\n";
                exit(1);
            }
            stek.push(op1 / op2);
        }
        else {
           stek.push(c - '0'); //123,dmjgf345 => 123 std::stoi, std::atoi
        }
    }

    std::cout << stek.top() << "\n";

    return 0;
}
