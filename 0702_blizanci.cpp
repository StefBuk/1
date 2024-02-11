#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int blizanci( std::vector < int > a, std::vector < int > b )
{
  std::sort( a.begin(), a.end() );
  std::sort( b.begin(), b.end() );

  int i = 0, j = 0; //brojaci
  int n = a.size();
  int m = b.size();

  int min = INT_MAX;

  while( i < n && j < m ) // dok je i manje of n I j manje of m
  {
    int diff = std::abs( a[ i ] - b[ j ] );

    if( diff < min )
    {
      min = diff;
    }

    if( a[ i ] < b[ j ] )
    {
      i++;
    }
    else if( a[ i ] > b[ j ] )
    {
      j++;
    }
    else
    {
      return 0;
    }
  }

  return min;
}

int main( int argc, char **argv )
{
  int n, m;

  std::cin >> n;
  std::vector < int > a( n );

  for( int i = 0; i < n ; i++ )
  {
    std::cin >> a[ i ];
  }

  std::cin >> m;
  std::vector < int > b( m );

  for( int i = 0; i < m ; i++ )
  {
    std::cin >> b[ i ];
  }

  std::cout << blizanci( a, b );

  return 0;
}
