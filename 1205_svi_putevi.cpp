//Svi putevi koji vode do krajnjeg cvora
#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int V)
    {
        this->V = V;
        this->adjacency_list.resize( V );
        this->visited.resize( V, false );
    }

//undirected
    void add_edge( int u, int v )
    {
        adjacency_list[ u ].push_back( v );
        adjacency_list[ v ].push_back( u );
    }


    //u = ulazni cvor, v = trazeni cvor, path = vektor cvorova koji cine putanju
    void all_paths(int u, int v, std::vector< int > path)
    {
        visited[u] = true;
        path.push_back( u );//vektor path, ubacujemo prvi element

        if ( u == v ) //ako je prvi cvor zapravo i trazeni
        {
            for ( int x : path )
            {
                std::cout << x << " ";
            }

            std::cout << "\n";
            visited[v] = false;
            return ;
        }

        for ( int w : adjacency_list[ u ] )
        {
            if ( !visited[ w ] )  //ako nije bio u tom cvoru, ulazi u njega i poziva ponovo funkciju
            {
                all_paths( w, v, path );
            }
        }

        visited[ u ] = false;
    }

private:
    int V;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<bool> visited;
};


int main ()
{
    Graph G(5);

    G.add_edge(0, 1);
    G.add_edge(0, 2);
    G.add_edge(0, 3);
    G.add_edge(0, 4);
    G.add_edge(1, 2);
    G.add_edge(2, 3);
    G.add_edge(2, 4);

    G.all_paths(0, 4, {});

    return 0;
}
