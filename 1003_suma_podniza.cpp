#include <iostream>
#include <vector>
#include <unordered_map>

int main ()
{
    std::vector<int> a = {1, 2, 3, 5, 1, -1, 1, 5, 3, 2};
    std::unordered_map<int, int> prefiksne_sume;

    prefiksne_sume[a[0]] = 1; //prvi elem

    int suma = 0, brojac = 0;

    int s = 11; //trazimo sumu podniza = 11

    for (int i = 0; i < a.size(); i++) {
        suma += a[i]; //1,3,6,11,12,11,12,17,20,22

        //ako je suma 12, a mi trazimo 11, trazimo da li ima negde broj -1 sa find( 11 - 12 )
        if (prefiksne_sume.find(suma - s) != prefiksne_sume.end())
        {
            brojac += prefiksne_sume[ suma - s ];
        }

        prefiksne_sume[suma]++;
    }

    std::cout << brojac << "\n";

    return 0;
}
