#include <iostream>
#include <stack>
#include <vector>

int main ()
{
    std::vector<int> a = {7, 5, 2, 4, 3, 1, 6, 9};
    std::stack<int> s;

    std::vector<int> result;

    result.push_back(-1);
    s.push(a[0]);

    for ( int i = 1; i < a.size(); i++ )
    {
      std::cout << "S -> " << s.top() << "\n";
        while ( !s.empty() && s.top() < a[ i ] )
        {                                           // F && _ => F
            s.pop();                                // T || _ => T
        }

        if (s.empty()) {
            result.push_back(-1);
        }
        else {
            result.push_back(s.top());
        }

        s.push(a[i]);
    }

    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
