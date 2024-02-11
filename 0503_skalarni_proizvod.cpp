#include <iostream>
#include <vector>

int skalarni_proizvod( int *a, int *b, int n )
{
  if( n == 0 )
  {
    return 0;
  }

  int proizvod_ostatka_niza = skalarni_proizvod( a + 1, b + 1, n - 1 );

  return proizvod_ostatka_niza + a[ 0 ] * b[ 0 ];
}

int main( int argc, char **argv )
{
  std::vector < int > a = { 1, 2, 3, 2 };
  std::vector < int > b = { 1, 7, 4, 6 };

  std::cout << skalarni_proizvod( a.data(), b.data(), a.size() ) << "\n";

  return 0;
}
