#include <iostream>
#include <vector>

class Graph{
public:
  Graph(){};
  Graph( int V );

  ~Graph(){};

  void add_edge( int u, int v );
  void DFS( int u );
  int number_of_components();

private:
  int V;
  std::vector < std::vector < int > > adjecency_list;
  std::vector < bool > visited;
};

//*********Methods*********

Graph :: Graph( int V )
{
  this->V = V;
  adjecency_list.resize( V );
  visited.resize( V, false );
}

void Graph :: add_edge( int u, int v )
{
  adjecency_list[ u ].push_back( v );
  adjecency_list[ v ].push_back( u );
}

void Graph :: DFS( int u )
{
  visited[ u ] = true;

  for( int v : adjecency_list[ u ] )
  {
    if( !visited[ v ] )
    {
      std::cout << u << " ";
      std::cout << v << "\n";
      DFS( v );
    }
  }
}
//Prolazice kroz vektor adjecency_list[ u ], u matrici adjecency_list,
//pa ukoliko nije cvor obidjen, pozvace ponovo metodu i oznacice ga kao
//visited


//Pronalazi komponente koje nisu obidjene od strane drugih cvorova
int Graph :: number_of_components()
{
  int num = 0;

  for( int i = 0; i < V ; i++ )
  {
    if( !visited[ i ] )
    {
      DFS( i );
      num++;
    }
  }
  return num;
}




int main( int argc, char **argv )
{
  Graph G( 10 );

  G.add_edge( 0, 1 );
  G.add_edge( 0, 2 );
  G.add_edge( 1, 2 );
  G.add_edge( 2, 3 );
  G.add_edge( 4, 5 );
  G.add_edge( 4, 6 );
  G.add_edge( 5, 6 );
  G.add_edge( 8, 9 );

  std::cout << G.number_of_components() << "\n";
  return 0;
}
