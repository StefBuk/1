#include <iostream>
#include <queue>

int main ()
{
    // FIFO - First In First Out
    std::queue<int> red;

    red.push(3);
    red.push(5);
    red.push(2);
    red.push(1);
    red.push(4);
    red.push(8);
    red.push(6);

    while( !red.empty() )
    {
      std::cout << red.front() << " ";
      red.pop();
    }


    return 0;
}
