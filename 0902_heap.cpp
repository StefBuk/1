#include <iostream>
#include <queue>

// Funkcijski objekat
struct comparator {
    bool operator()(int x, int y) {
        return x < y;
    }
};

int main ()
{
    std::priority_queue<int, std::vector<int>, comparator> heap;

    heap.push(3);
    heap.push(4);
    heap.push(2);
    heap.push(1);
    heap.push(6);
    heap.push(7);
    heap.push(9);
    heap.push(12);

    while (!heap.empty()) {
        std::cout << heap.top() << "\n";
        heap.pop();
    }

    return 0;
}
