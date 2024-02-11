//Kahn's algorithm for topological sorting works only on directed graphs
#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
    Graph(int V)
    {
        this->V = V;
        this->adjacency_list.resize(V);
        this->degree.resize(V, 0);
    }

    //directed graph
    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        //kada dodajes novu vezu, od U do V, dodajes je na deo liste U
        //Tada povecavas degree[ v ], jer je to stepen zavisnosti cvora
        degree[v]++;
    }

    void kahn()
    {
        std::queue<int> red;

        for (int i = 0; i < V; i++) {
            if (degree[i] == 0) {
                red.push(i);
            }
        }
        //ako cvor ne zavisi od drugih -> push

        while (!red.empty()) {
            int u = red.front();
            red.pop();//izbaci prvi ubacen u red

            std::cout << u << " ";  //stampamo element koji je prvi izasao iz reda

            for (int v : adjacency_list[u]) {
                degree[v]--;
                if (degree[v] == 0) { //ako je neki stepen zavisnosti 0 -> ubaci u red
                    red.push(v);
                }
            }//preleti po matrici veza, spusti za 1 sve stepene cvorova koji su
             //zavisili od cvora V. Ako postoji cvor V koji je stepena 0, dodaj
             //ga u red.
        }

        std::cout << "\n";
    }

private:
    int V;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> degree;
};


int main ()
{
    Graph G(7);

    G.add_edge(0, 1);
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(2, 3);
    G.add_edge(2, 4);
    G.add_edge(3, 4);
    G.add_edge(5, 1);
    G.add_edge(6, 5);
    G.add_edge(6, 3);

    G.kahn();

    return 0;
}
