//123453 3 => 1245
#include <iostream>

int ukloni( int x, int c );

int main( int argc, char **argv )
{
  if( argc != 3 )
  {
    std::cout << "Pogresan broj ulaza";
    exit( EXIT_FAILURE );
  }

  int broj  = atoi( *( argv + 1 ) );
  int cifra = atoi( *( argv + 2 ) );

  std::cout << ukloni( broj, cifra );

  return 0;
}

//fun

int ukloni( int x, int c )
{
  if( x == 0 )
  {
    // if( c == 0 )
    // {
    //   return -1;
    // }
    return 0;
  }

  int cifra = x % 10;
  int ost   = x / 10;

  int broj_bez_cifre = ukloni( ost, c );

  if( cifra == c )
  {
    return broj_bez_cifre;
  }
  else
  {
    return broj_bez_cifre * 10 + cifra;
  }

}
