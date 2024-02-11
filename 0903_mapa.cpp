#include <iostream>
#include <unordered_map>
#include <vector>

int main ()
{
    std::unordered_map<int, int> mapa;

    mapa[10] = 20;
    mapa[12] = 24;
    mapa[5] = 10;
    mapa[1] = 2;
    mapa[100] = 200;
    mapa[1000] = 2000;
    mapa[34] = 68;

    mapa[34] = 92;

    for( const auto &entry : mapa )
    {
      std::cout << entry.first << "->" << entry.second << "\n";
    }

    return 0;
}
