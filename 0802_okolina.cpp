#include <iostream>
#include <vector>
#include <algorithm>

void okolina(std::vector<int> a, int d)
{
    std::sort(a.begin(), a.end());
    //-6 -4 1 3 4 9 12

    int l = 0, r = 0; //levi desni pokazivac
    int n = a.size(); //velicina vektora
    int max = 0;      //maks
    int el;           //element

    for (int i = 0; i < n; i++)
    {
        while ( a[i] - a[l] > d )
        {
            l++;
        }

        while (r < n && a[r] - a[i] <= d) {
            r++;
        }

        if (r - l > max) {
            max = r - l;
            el = a[i];
        }
    }

    std::cout << el << " " << max << "\n";
}

int main ()
{
    std::vector<int> a = {4, -6, 3, 12, 1, -4, 9};

    okolina( a, 4 );

    return 0;
}
