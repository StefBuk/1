//5
// 1 2 3 1 -2

#include <iostream>
#include <vector>

void f( int *a, int n )
{
  if( n == 2 )
  {
    return;
  }

  bool ind = false;

  if( a[ 0 ] + a[ 2 ] == a[ 1 ] )
  {
    ind = true;
  }

  std::cout << "\n";
  std::cout << "0 -> " << a[ 0 ] << "\n" << "1 -> " << a[ 1 ] << "\n" << "2 -> " << a[ 2 ] << "\n";
  std::cout << "\n";

  f( a + 1, n - 1 );

  if( ind == true )
  {
    a[ 1 ] = 0;
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

  f( a.data(), a.size() );

  std::cout << "Zbir suseda jednak broju -> postavljamo na nulu \n";

  for( int x : a )
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  return 0;
}
