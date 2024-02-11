#include <iostream>
#include <vector>

int suma( int *a, int n )
{
  if( n == 0 )
  {
    return 0;
  }

  int suma_ostatak = suma( a + 1, n - 1 );

  return *a + suma_ostatak;
}

int main( int argc, char **argv )
{
  std::vector< int > a = { 1, 2, 3, 4, 5, 6 };

  std::cout << suma( a.data(), a.size() ) << "\n";

  return 0;
}
