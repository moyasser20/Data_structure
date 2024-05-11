#include <iostream>
#include <string>
#include <cstring> // for memset

using namespace std;

class Graph {
private:
    int **adj_matrix;
    string *vertex_data;
    int size;

public:
    Graph(int size) : size(size) {
        adj_matrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            adj_matrix[i] = new int[size];
            memset(adj_matrix[i], 0, size * sizeof(int)); // Initializing with 0
        }
        vertex_data = new string[size];
    }

    void add_edge(int u, int v) {
        if (0 <= u && u < size && 0 <= v && v < size) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }
    }

    void add_vertex_data(int vertex, string data) {
        if (0 <= vertex && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    void print_graph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\nVertex Data:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Vertex " << i << ": " << vertex_data[i] << endl;
        }
    }

    void dfs_util(int v, bool visited[]) {
        visited[v] = true;
        cout << vertex_data[v] << " ";

        for (int i = 0; i < size; ++i) {
            if (adj_matrix[v][i] == 1 && !visited[i]) {
                dfs_util(i, visited);
            }
        }
    }

    void dfs(string start_vertex_data) {
        bool *visited = new bool[size];
        memset(visited, false, size * sizeof(bool));

        int start_vertex = 0;
        for (int i = 0; i < size; ++i) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }

        dfs_util(start_vertex, visited);

        delete[] visited;
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
    Graph g(7);

    g.add_vertex_data(0, "A");
    g.add_vertex_data(1, "B");
    g.add_vertex_data(2, "C");
    g.add_vertex_data(3, "D");
    g.add_vertex_data(4, "E");
    g.add_vertex_data(5, "F");
    g.add_vertex_data(6, "G");

    g.add_edge(3, 0);  // D - A
    g.add_edge(0, 2);  // A - C
    g.add_edge(0, 3);  // A - D
    g.add_edge(0, 4);  // A - E
    g.add_edge(4, 2);  // E - C
    g.add_edge(2, 5);  // C - F
    g.add_edge(2, 1);  // C - B
    g.add_edge(2, 6);  // C - G
    g.add_edge(1, 5);  // B - F

    g.print_graph();

    cout << "\nDepth First Search starting from vertex D:" << endl;
    g.dfs("D");

    return 0;
}
