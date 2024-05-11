#include <iostream>
#include <string>

using namespace std;

class Graph {
private:
    int **adj_matrix; //used to create a 2D array for thr adacnecy matrix
    string *vertex_data; //Store data associated with each vertex
    int size;

public:
    Graph(int size) : size(size) {
        adj_matrix = new int*[size]; //allocate memory for the adjacency matrix
        for (int i = 0; i < size; i++) {
            adj_matrix[i] = new int[size];
            for (int j = 0; j < size; j++) {
                adj_matrix[i][j] = 0;
            }
        }
        vertex_data = new string[size];
    }

    void add_edge(int u, int v) {
        if (0 <= u && u < size && 0 <= v && v < size) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }
    }

    void add_data(int vertex, string data) {
        if (0 <= vertex && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    void print_graph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\nVertex Data:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Node " << i << ": " << vertex_data[i] << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < size; i++)
        {
            delete[] adj_matrix[i];
        }
        delete[] adj_matrix;
        delete[] vertex_data;
    }
};

int main() {
    Graph g(4);
    g.add_data(0, "A");
    g.add_data(1, "B");
    g.add_data(2, "C");
    g.add_data(3, "D");
    g.add_edge(0, 1);  // A - B
    g.add_edge(0, 2);  // A - C
    g.add_edge(0, 3);  // A - D
    g.add_edge(1, 2);  // B - C

    g.print_graph();

    return 0;
}
