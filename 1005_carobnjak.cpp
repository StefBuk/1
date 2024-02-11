#include <iostream>
#include <vector>
#include <queue>

int main ()
{
    std::vector<int> a = {2,4,6,8,10};

    std::priority_queue<int, std::vector<int>, std::less<int>> heap;

//ubacuje vektor u min heap
    for (int x : a) {
        heap.push(x);
    }

    int t = 5, suma = 0;

    while (t)
    {
        int max = heap.top(); //maks mi je prvi element
        suma += max;          //dodajemo sumi
        // std::cout << "elem: " << heap.top() << " \n";
        heap.pop();           //popujemo
        heap.push(max / 2);   //ubacujemo pola sume
        t--;                  //i tako 5 puta
        // std::cout << "SUMA: " << suma << "\n";
    }

    while( !heap.empty() )
    {
      std::cout << heap.top() << " ";
      heap.pop();
    }

    return 0;
}
