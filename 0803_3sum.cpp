//suma 3 broja = 0
#include <iostream>
#include <vector>
#include <algorithm>

int three_sum(const std::vector<int> &a)
{
    int n = a.size();

    int broj = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    broj++;
                }
            }
        }
    }

    return broj;
}

int three_sum_v2(std::vector<int> a) {
    std::sort(a.begin(), a.end());  //sortiranje, 2 pokazivaca

    int broj = 0;
    int n = a.size();
    int trazena_suma;

    for (int i = 0; i < n; i++) {
        trazena_suma = 0 - a[i];                    //logicno
        for (int j = i + 1, k = n - 1; j < k; )     // j = 1, k = poslednji
        {
            if ( a[j] + a[k] == trazena_suma )      //prolazis sa 2 pokaz
            {
                j++;        //levi povecas
                k--;        //desni smanjis
                broj++;     //nasao si jedan broj (ako treba mozes i da sacuvas j i k poziciju)
            }
            else if (a[j] + a[k] < trazena_suma)    //povecas levi
            {
                j++;
            }
            else {                                  //povecas desni
                k--;
            }
        }
    }

    return broj;
}

int main ()
{
    std::vector<int> a = {-8, -5, 7, 4, 1, -2, 9, -3, 2};

    std::cout << three_sum(a) << "\n";

    std::cout << three_sum_v2(a) << "\n";

    return 0;
}
