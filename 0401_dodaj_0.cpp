#include <iostream>

int dodaj_0( int x )
{
  if( x == 0 )
  {
    return 0;
  }

  int c = x % 10;
  int ostatak_broja = x / 10;

  int promenjen_broj = dodaj_0( ostatak_broja );

  if( c % 2 == 0 )//paran
  {
    return ( promenjen_broj * 10 + c );
  }
  else
  {
    return ( promenjen_broj * 10 + c ) * 10;
  }
}

int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int x = atoi( *( argv + 1 ) );

  std::cout << dodaj_0( x ) << std::endl;

  return 0;
}
