#include <iostream>
#include <queue>

int main( int argc, char **argv )
{
  std::priority_queue < int, std::vector < int > > heap;

  std::vector < int > a = {1,4,56,7,8,54,4,5};

  for( int x : a )
  {
    heap.push( x );
  }

  int i = 0;

  while( !heap.empty() )
  {
    a[ i ] = heap.top();
    heap.pop();
    i++;
  }

  for( int x : a )
  {
    std::cout << x << " ";
  }

  return 0;
}
