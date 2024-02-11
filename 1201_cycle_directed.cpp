// directed graph
#include <iostream>
#include <vector>

class Graph{
public:
  Graph(){};
  Graph( int V );

  ~Graph(){};

  void add_edge( int u, int v );
  bool detect_cycle( int u );

private:
  int V;
  std::vector < std::vector < int > > adjacency_list;
  std::vector < bool > visited;

};

//********Metode********

Graph :: Graph( int V )
{
  this->V = V;
  this->adjacency_list.resize( V );
  this->visited.resize( V, false );
}

void Graph :: add_edge( int u, int v )
{
  adjacency_list[ u ].push_back( v );
}

bool Graph :: detect_cycle( int u )
{
  visited[ u ] = true;

  for( int v : adjacency_list[ u ] )
  {
    if( visited[ v ] )
    {
      return true;
    }

    if( detect_cycle( v ) )
    {
      return true;
    }
  }

  visited[ u ] = false;
  return false;
}


int main( int argc, char **argv )
{
  Graph G( 4 );

  G.add_edge( 0, 1 );
  G.add_edge( 1, 2 );
  G.add_edge( 2, 0 );

  std::cout << std::boolalpha << G.detect_cycle( 0 ) << "\n";

  return 0;
}
