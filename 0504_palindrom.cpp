#include <iostream>
#include <vector>

bool palindrom( int *a, int n )
{
  //Krajnji uslov
  if( n == 0 || n == 1 )
  {
    return true;
  }
  //Rekurzija
  bool ostatak = palindrom( a + 1, n - 2 ); // n - 2 jer se odbija jedan na pocetku, jedan na kraju

  //Uslov rekurzija, ukoliko je vec false bio neki prethodni clan
  if( ostatak == false )
  {
    return false;
  }

  //Provera da li je clan jednak sa poslednjim
  if( a[ 0 ] != a[ n - 1 ] )
  {
    return false;
  }

  return true;
}

int main( int argc, char **argv )
{
  std::vector < int > v = { 1, 2, 3, 3, 2, 1 };

  std::cout << std::boolalpha << palindrom( v.data(), v.size() ) << "\n";

  return 0;
}
