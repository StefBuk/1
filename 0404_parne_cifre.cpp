//Izbroj parne cifre u broju
//PAZITI NA PREKORACENJE INT
#include <iostream>

int broj_parnih( int x );

int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int x;
  x = atoi( *( argv + 1 ) );

  std::cout << broj_parnih( x ) << "\n";

  return 0;
}


int broj_parnih( int x )
{
  if( x == 0 )
  {
    return 0;
  }

  int n   = x % 10;
  int ost = x / 10;

  int bp = broj_parnih( ost );

  if( n % 2 == 0 )
  {
    return 1 + bp;
  }
  else
  {
    return 0 + bp;
  }
}
