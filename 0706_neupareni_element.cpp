#include <iostream>
#include <vector>
#include <algorithm>

int neupareni_element(std::vector<int> a)
{
    std::sort(a.begin(), a.end());

    int n = a.size();
    for (int i = 0; i < n - 1; i += 2)
    {
        //uporedjujes sa sledecim elementom.
        //ukoliko se ne pokalpa - nasli smo uljeza
        if (a[i] != a[i + 1]) {
            return a[i];
        }
    }

    return a[n - 1];
}


int main ()
{
    std::vector<int> a = {3,4,2,1,4,2,3};//1 2 2 3 3 4 4 ->

    std::cout << neupareni_element(a) << "\n";

    return 0;
}
