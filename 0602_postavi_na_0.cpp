#include <iostream>
#include <vector>

void postavi( int *a, int n, int x )
{
  if( n == 1 )
  {
    return;
  }

  bool indikator = false;

  if( a[ 0 ] + a[ 1 ] == x )  //ako je zbir trenutnog i narednog = x
  {
    indikator = true;
  }

  postavi( a + 1, n - 1, x );

  //BITNO
  if( indikator == true ) //postavi ih na nulu, ali tek nakon sto si odredio sve koje treba da postavis
  {
    a[ 0 ] = 0;
    a[ 1 ] = 0;
  }

}

int main( int argc, char **argv )
{
  int x, n;
  std::cin >> x >> n;

  std::vector < int > a( n );

  for( int i = 0; i < n; i++ )
  {
    std::cin >> a[ i ];
  }

  postavi( a.data(), a.size(), x );

  for( int x : a )
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  return 0;
}
