#include <iostream>

int max_cifra( int x );

int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int x = atoi( *( argv + 1 ) );

  std::cout << max_cifra( x ) << std::endl;

  return 0;
}

//132
int max_cifra( int x )
{
  if( !x )
  {
    return 0;
  }

  int c = x % 10;
  int ostatak = x / 10;

  int max = max_cifra( ostatak );

  if( c > max )
  {
    return c;
  }
  else
  {
    return max;
  }
}
