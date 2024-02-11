#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    int n, s;
    std::cin >> s >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int br = 0;

    std::sort(a.begin(), a.end());//sortiranje niza

    for ( int i = 0; i < a.size() - 1; i++) //prolaz kroz niz
    {
        if ( std::binary_search( a.begin() + i + 1, a.end(), s - a[i] ) )
        {
            br++;
        }
    }

    std::cout << br << "\n";

    return 0;
}
