// 5
// 1 2 4 4 4 -> 1 1 3 3 4
//Dva broja za redom su parna -> prvi se smanjuje za 1
#include <iostream>
#include <vector>

void f( int *a, int n )
{
  if( n == 1 )
  {
    return;
  }

  if( a[ 0 ] % 2 == 0 && a[ 1 ] % 2 == 0 )
  {
    a[ 0 ]--;
    // a[ 0 ] = a[ 0 ] - 1;
  }
  f( a + 1, n - 1 );

}

int main( int argc, char **argv )
{
  int n;
  std::cin >> n;

  std::vector < int > a( n );

  for( int i = 0; i < n ; i++ )
  {
    std::cin >> a[ i ];
  }

  f( a.data(), a.size() );

  for( int x : a )
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  return 0;
}
