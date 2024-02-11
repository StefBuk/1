#include <iostream>

int fib( int x );


int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int x = atoi( *( argv + 1 ) );

  int rez = fib( x );
  std::cout << "Rezultat je " << rez << std::endl;

  return 0;
}


int fib( int x )
{
  if( x == 1 || x == 2 )
  {
    return 1;
  }

  return fib( x - 1 ) * fib( x - 2 );
}
