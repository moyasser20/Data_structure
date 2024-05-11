#include <iostream>
#include <string>

using namespace std;

class Graph {
private:
    int **adj_matrix;
    string *vertex_data;
    int size;

public:
    Graph(int size) : size(size)
    {
        adj_matrix = new int*[size];
        for (int i = 0; i < size; i++)
        {
            adj_matrix[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                adj_matrix[i][j] = 0; // Initializing with 0
            }
        }
        vertex_data = new string[size];
    }

    void add_edge(int u, int v, int weight)
    {
        if (0 <= u && u < size && 0 <= v && v < size)
        {

            adj_matrix[u][v] = weight;
            adj_matrix[v][u] = weight;
        }
    }

    void add_vertex_data(int vertex, string data)
    {
        if (0 <= vertex && vertex < size)
        {
            vertex_data[vertex] = data;
        }
    }

    void print_graph()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << (adj_matrix[i][j] != 0 ? adj_matrix[i][j] : 0) << " ";
            }
            cout << endl;
        }
        cout << "\nVertex Data:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Vertex " << i << ": " << vertex_data[i] << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < size; ++i) {
            delete[] adj_matrix[i];
        }
        delete[] adj_matrix;
        delete[] vertex_data;
    }
};

int main() {
    Graph g(4);
    g.add_vertex_data(0, "A");
    g.add_vertex_data(1, "B");
    g.add_vertex_data(2, "C");
    g.add_vertex_data(3, "D");
    g.add_edge(0, 1, 3);  // A -> B with weight 3
    g.add_edge(0, 2, 2);  // A -> C with weight 2
    g.add_edge(3, 0, 4);  // D -> A with weight 4
    g.add_edge(2, 1, 1);  // C -> B with weight 1

    g.print_graph();

    return 0;
}
