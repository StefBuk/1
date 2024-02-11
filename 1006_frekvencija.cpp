#include <iostream>
#include <vector>
#include <unordered_map>

int main ()
{
    std::vector<std::string> reci = {"danas", "je",
    "lep", "dan", "lep", "danas", "dan", "jabuka"};

    std::unordered_map < std::string, int > frekvencija;

    for( std::string rec : reci )
    {
      frekvencija[ rec ] += 1;
    }

    for( const auto &entry : frekvencija )  //adresa od entry, sa adresom, pa pristupas normala entry.first
    {
      std::cout << entry.first << " -> " << entry.second << "\n";
    }

    return 0;
}
