#include <iostream>
#include <vector>

void f( int *a, int n, int suma_prethodnih )
{
  if( n == 0 )
  {
    return;
  }

  f( a + 1, n - 1, suma_prethodnih + a[ 0 ] );

//??
  if( a[ 0 ] > suma_prethodnih )
  {
    a[ 0 ] = 0;
  }
}

int main( int argc, char **argv )
{
  int n;
  std::cin >> n;

  std::vector < int > a( n );

  for( int i = 0; i < n; i++ )
  {
    std::cin >> a[ i ];
  }

  f( a.data(), a.size(), 0 );

  for( int x : a )
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return 0;
}
