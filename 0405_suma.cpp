#include <iostream>

int suma( int x );

int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int x = atoi( *( argv + 1 ) );

  std::cout << suma( x );

  return 0;
}

//fun

int suma( int x )
{
  if( x == 0 )
  {
    return 0;
  }

  int c   = x % 10;
  int ost = x / 10;

  return c + suma( ost );
}
