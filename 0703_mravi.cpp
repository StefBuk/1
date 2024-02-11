#include <iostream>
#include <vector>

int main ()
{
    int n, m;

    std::cin >> n >> m;

    std::vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
//punjenje vektora
    std::vector<int> c(n + m);
//zajednicni vektor
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        }
        else {
           c[k] = b[j];
           j++;
        }
        k++;
    } //napuni manjim elementima iz niza a i b,

    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }

    for (int x : c) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
