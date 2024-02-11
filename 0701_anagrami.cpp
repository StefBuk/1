#include <iostream>
#include <algorithm>

int main( int argc, char **argv )
{
  std::string s1, s2;

  std::cin >> s1 >> s2;

  std::sort( s1.begin(), s1.end() );
  std::sort( s2.begin(), s2.end() );

  if( s1 == s2 )
  {
    std::cout << "DA";
  }
  else
  {
    std::cout << "NE";
  }
  
  return 0;
}
