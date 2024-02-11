#include <iostream>
#include <unordered_set>

int main ()
{
    std::unordered_set<int> skup;

    skup.insert(3);
    skup.insert(2);
    skup.insert(5);
    skup.insert(7);
    skup.insert(3);
    skup.insert(4);
    skup.insert(4);
    skup.insert(2);

    //PRETRAGA, BITNO
    if (skup.find(2) != skup.end()) {
        std::cout << "Postoji!\n";
    }
    else {
        std::cout << "Ne postoji!\n";
    }

    for (int x : skup) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
