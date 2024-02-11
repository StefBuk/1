#include <iostream>
#include <queue>

int main ()
{
    std::queue<int> red;

    int n;
    int m;

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        red.push(i);  //ubaci 0 do n-1 brojeva
    }

    while (red.size() > 1)  // dok je veci od 1
    {
        for (int i = 0; i < m - 1; i++) //m-2 puta se zavrti red
        {
            red.push(red.front());
            red.pop();  //poslednji ide na prvo mesto
        }
        red.pop();  //pop
    }

    std::cout << red.front() << "\n";

    return 0;
}
