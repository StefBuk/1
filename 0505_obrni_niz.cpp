#include <iostream>
#include <vector>

void obrni( int *a, int n )
{
  if( n == 0 || n == 1 )
  {
    return;
  }

  int tmp = *a;
  *a = *( a + n - 1 );
  *(a + n - 1 ) = tmp;

  obrni( a + 1, n - 2 );
}

void obrni_u_novi( int *a, int *b, int n, int brojac )
{
  if( n == 0 )
  {
    return;
  }

  *( b + brojac++ ) = *( a + n - 1 );

  obrni_u_novi( a, b, n - 1, brojac );
}

int main( int argc, char **argv )
{
  int brojac = 0;

  std::vector < int > a = { 1, 2, 3, 4, 5 };
  std::vector < int > b( a.size() );

  // obrni( a.data(), a.size() );
  obrni_u_novi( a.data(), b.data(), a.size(), brojac );

  for( int x : a )
  {
    std::cout << x << " ";
  }

  std::cout << "\n";

  for( int y : b )
  {
    std::cout << y << " ";
  }

  return 0;
}
