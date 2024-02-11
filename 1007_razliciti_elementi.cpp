#include <iostream>
#include <vector>
#include <unordered_map>

int main ()
{
    std::vector<int> a = {1,2,4,3,5,3};

    std::unordered_map< int, int > mapa;

    int b = 3;

    for ( int i = 0; i < b; i++ )
    {
        mapa[ a[ i ] ]++;
        // 1 -> 1
        // 2 -> 1
        // 4 -> 1
    }

    std::cout << mapa.size() << " -> velicina mape A \n";

    for (int i = b; i < a.size(); i++)
    {
        mapa[ a[ i ] ]++;

        int el = a[i - b];
        std::cout << "Element: " << el << "\n";
        mapa[el]--;

        //ukoliko ga je smanjilo na 0 brise element
        if (mapa[el] == 0) {
            mapa.erase(el);
        }

        std::cout << mapa.size() << " -> velicina mape B \n";

        for( const auto &entry : mapa )
        {
          std::cout << "\n\n" << entry.first << "->" << entry.second << "\n\n";
        }


    }

    std::cout << "\n";

    for( const auto &entry : mapa )
    {
      std::cout << entry.first << "->" << entry.second << "\n";
    }


    return 0;
}
