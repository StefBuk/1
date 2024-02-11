// Dva pokazivaca
// Imam niz povrsina vodenih.
#include <iostream>
#include <vector>
#include <climits>

int max_povrsina(std::vector<int> a)
{
    int i = 0, j = a.size() - 1;
    int max = INT_MIN;

    while (i < j)
    {
        //Dokle god se nisu preklopili pokazivaci
        int tp = std::min( a[ i ], a[ j ] ) * ( j - i ); // min_visina * sirina

        if (tp > max) {
            max = tp;
            // std::cout << "i: " << i << " j: " << j << " tp: " << max << "\n";
            // std::cout << "a[i]: " << a[i] << " a[j]: " << a[j] << "\n";
            // std::cout << "\n";
        }

        if (a[i] < a[j]) {
            i++;
        }
        else {
            j--;
        }
    }

    return max;
}

int main ()
{
    int n;

    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << max_povrsina(a) << "\n";

    return 0;
}
