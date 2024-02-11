#include <iostream>
#include <stack>

int main( int argc, char **argv )
{
  std::stack < int > stek;

  stek.push( 1 );
  stek.push( 2 );
  stek.push( 3 );

  while( !stek.empty() )
  {
    std::cout << stek.top() << "\n";
    stek.pop();
  }

  if( stek.empty() )
  {
    std::cout << "kraj";
  }
   return 0;
}
