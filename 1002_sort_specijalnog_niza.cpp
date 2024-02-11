#include <iostream>
#include <vector>
#include <list>

int main( int argc, char **argv )
{
  std::vector < int > a = {2,7,1,9,-2,-5,20};

  std::list < int > red_sa_dva_kraja;

  red_sa_dva_kraja.push_back( a[ 0 ] );

  for( int i = 1; i < a.size(); i++ )
  {
    if( a[ i ] > red_sa_dva_kraja.front() )
    {
      red_sa_dva_kraja.push_back( a[ i ] );
    }
    else
    {
      red_sa_dva_kraja.push_front( a[ i ] );
    }
  }

  for( int i = 0; i < a.size() ; i++ )
  {
    a[ i ] = red_sa_dva_kraja.back();
    red_sa_dva_kraja.pop_back();
  }

  for( int x : a )
  {
    std::cout << x << " ";
  }

  return 0;
}
