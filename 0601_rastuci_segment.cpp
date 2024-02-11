#include <iostream>
#include <vector>

int broj_rastucih_v1( const std::vector < int > &a )
{
  int n = a.size();
  int broj = 0;

  for( int i = 0; i < n ; i++ )
  {
    for( int j = i + 1; j < n ; j++ )
    {
      bool rastuci = true;

      for( int k = i; k < j ; k++ )
      {
        if ( a[ k ] >= a[ k + 1 ] )
        {
          rastuci = false;
          break;
        }
      }

      if( rastuci )
      {
        broj++;
      }
    }
  }

  return broj;
}

int broj_rastucih_v2( std::vector< int > &a )
{
  int n = a.size();
  int broj = 0;

  for( int i = 0; i < n; )
  {
    for( int j = i + 1; j < n ; j++ )
    {
      if( a[ j ] >= a[ j + 1 ] )
      {
        int broj_elemenata = j - i + 1;
        broj += broj_elemenata * ( broj_elemenata - 1 ) / 2;
        i = j + 1;
        break;
        std::cout << "I: " << i << " J: " << j << "\n";
      }
    }
  }
  return broj;
}


int main( int argc, char **argv )
{
  std::vector < int > a = { 1, 3, 4, -2, 10 };

  std::cout << broj_rastucih_v1( a ) << "\n";
  std::cout << broj_rastucih_v2( a ) << "\n";

  return 0;
}
