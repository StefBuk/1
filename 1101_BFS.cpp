#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
  Graph(){};
  Graph( int V );

  ~Graph(){};

  void add_edge( int u, int v );
  void print_adjacency_list();
  void BFS( int u );

private:
  int V;
  std::vector< std::vector < int > > adjacency_list;
  std::vector < bool > visited;
};

//*******funkcije*******

Graph :: Graph( int V )
{
  this->V = V;
  adjacency_list.resize( V );
  visited.resize( V, false );
}

void Graph :: add_edge( int u, int v )
{
  adjacency_list[ u ].push_back( v );
  adjacency_list[ v ].push_back( u );
}

void Graph :: print_adjacency_list()
{
  for( int i = 0; i < V ; i++ )
  {
    std:: cout << i << " -> ";
    for( int x : adjacency_list[ i ] )
    {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}

void Graph :: BFS( int u ) //pocetni cvor
{
  std::queue < int > red;

  visited[ u ] = true;

  red.push( u );

  int tmp;

  while( !red.empty() )
  {
    tmp = red.front();
    red.pop();

    std::cout << tmp << " ";

    for( int v : adjacency_list[ tmp ] )
    {
      if( !visited[ v ] )
      {
        visited[ v ] = true;
        red.push( v );
      }
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
  G.BFS( 0 );

  return 0;
}
