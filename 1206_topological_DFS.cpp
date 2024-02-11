//Topologijski iscitava sve 
#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    Graph(int V)
    {
        this->V = V;
        this->adjacency_list.resize(V);
        this->visited.resize(V, false);
        this->degrees.resize(V, 0);
    }

    void add_edge(int u, int v)
    {
        //dodaj novi kraj na vektor pocetaka putanja, a zatim povecak
        //stepen zavisnosti
        adjacency_list[u].push_back(v);
        degrees[v]++;
    }

    void DFS(int u)
    {
        visited[u] = true;

        for (int v : adjacency_list[u]) {
            if (!visited[v]) {
                DFS(v);   //depth first search -> ide u dubinu, do kraja.
            }
        }

        //kad stigne do samog kraja, on ubaci vrednost u stek.
        //Na kraju, poslednja vrednost do koje se stiglo, nalazi se na sketu najdublje
        s.push(u);
    }

    void topological_sort()
    {
      //Svaki cvor kome je stepen zavisnosti = 0, krece se od njega i na stek se ubacuju vrednosti
        for (int i = 0; i <  V; i++) {
            //pretrazuje dfs samo za cvorove koji nemaju stepene zavisnosti
            //i stavlja ih na stek
            if (degrees[i] == 0) {
                DFS(i);
            }
        }

        //citanje i ispisivanje sa steka
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }

        std::cout << "\n";
    }

private:
    int V;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<bool> visited;
    std::vector<int> degrees;
    std::stack<int> s;
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

    G.topological_sort();

    return 0;
}
