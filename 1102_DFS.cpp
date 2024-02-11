#include <iostream>
#include <vector>

class Graph {
public:
  Graph(){};
  Graph( int V );

  ~Graph(){};

  void add_edge( int u, int v );
  void print_adjacency_list();
  void DFS( int u );

private:
  int V;
  std::vector< std::vector< int > > adjacency_list;
  std::vector < bool > visited;
};

//*********Fukcije*********

Graph :: Graph( int V )
{
  this->V = V;
  adjacency_list.resize( V );
  visited.resize( V, false );
}

void Graph :: add_edge( int v, int u )
{
  adjacency_list[ u ].push_back( v );
  adjacency_list[ v ].push_back( u );
}

void Graph :: print_adjacency_list()
{
  for( int i = 0; i < V; i++ )
  {
    std::cout << i << " -> ";

    for( int x : adjacency_list[ i ] )
    {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}

void Graph :: DFS( int u )
{
  visited[ u ] = true;

  std::cout << u << " ";

  for( int v : adjacency_list[ u ] )
  {
    if( !visited[ v ] )
    {
      DFS( v );
    }
  }
}


int main( int argc, char **argv )
{
  Graph G( 5 );

  G.add_edge( 0, 1 );
  G.add_edge( 0, 4 );
  G.add_edge( 1, 2 );
  G.add_edge( 1, 3 );
  G.add_edge( 2, 3 );

  // G.print_adjacency_list();
  G.DFS( 0 );

  return 0;
}
