#include <iostream>

int izbaci_neparnu( int x )
{
  if( x ==  0 )
  {
    return 0;
  }

  int br = x % 10;

  int ostatak = izbaci_neparnu( x / 10 );


  // if( br % 2 )
  // {
  //   return ostatak;
  // }
  // else
  // {
  //   return ostatak * 10 + br;
  // }

  return ( br % 2 ) ? ostatak : ( ostatak * 10 + br);
}

int main( int argc, char **argv )
{
  int x;

  std::cin >> x;

  std::cout << izbaci_neparnu( x ) << "\n";

  return 0;
}
