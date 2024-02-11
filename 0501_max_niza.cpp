#include <iostream>
#include <vector>

int max( int *v, int n )
{
  if( n == 1 )
  {
    return *v;
  }

  int max_vrednost = max( v + 1, n );  //rekurzija

  return std::max( *v, max_vrednost );
}

int main( int argc, char **argv )
{
  std::vector<int> v = {12,1,2,7,6,3,92};

  std::cout << max( v.data(), v.size() ) << "\n";

  return 0;
}
