#include <iostream>

void trougao( int n, int trenutna_linija )
{
  if( trenutna_linija > n )
  {
    return;
  }

  for( int i = 0; i < trenutna_linija ; i++ )
  {
    std::cout << "+";
  }

  std::cout << "\n";

  trougao( n, trenutna_linija + 1 );
}

int main( int argc, char **argv )
{
  int n = 5;

  trougao( n, 1 );

  return 0;
}
