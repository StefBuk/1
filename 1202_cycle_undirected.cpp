#include <iostream>
#include <vector>

class Graph{
public:
  Graph(){};
  Graph( int V );

  ~Graph(){};

  void add_edge( int u, int v );
  void print_adjecency_list();
  bool detect_cycle( int u, int parent );

private:
  int V;
  std::vector < std::vector< int > > adjacency_list;
  std::vector < bool > visited;
};

//******Methods*******

Graph :: Graph( int V )
{
  this->V = V;
  this->adjacency_list.resize( V );
  this->visited.resize( V, false );
}

void Graph :: add_edge( int u, int v )
{
  adjacency_list[ u ].push_back( v );
  adjacency_list[ v ].push_back( u );
}

void Graph :: print_adjecency_list()
{
  for( int i = 0; i < adjacency_list.size() ; i++ )
  {
    std::cout << i << " -> ";
    for( int x : adjacency_list[ i ] )
    {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}
//ukoliko se vrati da

//Poenta je da se udje prvo u petlju 2 nekoliko puta, pa na kraju u petlju 1 i tada se zavrsi program
//Ukoliko se na kraju ne udje u petlju 1, a visited[ v ] je true, vraca se false
bool Graph :: detect_cycle( int u, int parent )
{
  visited[ u ] = true;  //prvi je visited

//Ako je prvi cvor 0, pogledaj sve cvorove vezane za nulti
  for( int v : adjacency_list[ u ] )
  {
    //1
    if( visited[ v ] && v != parent ) //ako je vec bio u tom cvoru i nije roditelj
    {
      return true;  //vrati da ima kruga
    }

//Ako pokazivac nije bio u povezanom cvoru( v ), udji u taj cvor, ispitaj njega i stavi da je roditelj cvor U
    if( !visited[ v ] ) //2
    {
      if( detect_cycle( v, u ) ) // rekurzija, ulazi se u novi cvor, a roditelj je trenutni
      {
        return true;  //ukoliko se veze nekoliko true-a, i dodje do toga da su svi visited -> vraca se true iz petlje
      }
    }
  }
  return false;
}


int main( int argc, char **argv )
{
  Graph G( 5 );

  G.add_edge( 0, 1 );
  G.add_edge( 1, 2 );
  G.add_edge( 0, 2 );

  G.print_adjecency_list();

  std::cout << "\n";

  std::cout << std::boolalpha << G.detect_cycle( 0, -1 ) << "\n";

  return 0;
}
