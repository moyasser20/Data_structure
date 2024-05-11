#include <iostream>
#include <string>

using namespace std;

class Graph {
private:
    int **adj_matrix;
    string *vertex_data;
    int size;

public:
    Graph(int size) : size(size) {
        // Initialize adjacency matrix and vertex data
        adj_matrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            adj_matrix[i] = new int[size];
            // Initialize each cell of the adjacency matrix to 0
            for (int j = 0; j < size; ++j) {
                adj_matrix[i][j] = 0;
            }
        }
        vertex_data = new string[size];
    }

    ~Graph() {
        // Deallocate memory for adjacency matrix and vertex data
        for (int i = 0; i < size; ++i) {
            delete[] adj_matrix[i];
        }
        delete[] adj_matrix;
        delete[] vertex_data;
    }

    void add_edge(int u, int v, int weight) {
        // Add edge between vertices u and v with given weight
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adj_matrix[u][v] = weight;
            // For undirected graph, uncomment below line
            // adj_matrix[v][u] = weight;
        }
    }

    void add_vertex_data(int vertex, const string& data) {
        // Add data to a vertex
        if (vertex >= 0 && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    int find_min_distance(const int distances[], const bool visited[]) {
        // Initialize minimum distance and index
        int min_distance = INT_MAX;
        int min_index = -1;

        // Iterate through all vertices
        for (int i = 0; i < size; ++i) {
            // Check if the vertex has not been visited and its distance is smaller than the current minimum
            if (!visited[i] && distances[i] <= min_distance) {
                min_distance = distances[i];
                min_index = i;
            }
        }
        return min_index;
    }

    int* dijkstra(const string& start_vertex_data) {
        // Find the index of the start_vertex_data in vertex_data array
        int start_vertex = -1;
        for (int i = 0; i < size; ++i) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }
        // If start_vertex_data is not found, return nullptr
        if (start_vertex == -1) {
            cout << "Start vertex not found.\n";
            return nullptr;
        }

        // Create arrays to store distances and visited vertices
        int *distances = new int[size];
        bool *visited = new bool[size];
        // Initialize distances to all vertices as infinite and visited as false
        for (int i = 0; i < size; ++i) {
            distances[i] = INT_MAX;
            visited[i] = false;
        }
        // Distance from start_vertex to itself is 0
        distances[start_vertex] = 0;

        // Iterate through all vertices
        for (int count = 0; count < size - 1; ++count) {
            // Find the vertex with the minimum distance that has not been visited
            int u = find_min_distance(distances, visited);
            // If there is no such vertex (all vertices are visited), break the loop
            if (u == -1) {
                break;
            }
            // Mark vertex u as visited
            visited[u] = true;

            // Update distances of adjacent vertices of u
            for (int v = 0; v < size; ++v) {
                // Update distance if v is not visited, there is an edge from u to v,
                // distance to u is not infinite, and distance through u to v is shorter
                if (!visited[v] && adj_matrix[u][v] != 0 &&
                    distances[u] != INT_MAX &&
                    distances[u] + adj_matrix[u][v] < distances[v]) {
                    distances[v] = distances[u] + adj_matrix[u][v];
                }
            }
        }

        // Deallocate memory for visited array and return distances array
        delete[] visited;
        return distances;
    }

    // Getter function for vertex_data
    string* get_vertex_data() {
        return vertex_data;
    }
};

int main() {
    // Create a graph object with 7 vertices
    Graph g(7);

    // Add vertex data to the graph
    g.add_vertex_data(0, "A");
    g.add_vertex_data(1, "B");
    g.add_vertex_data(2, "C");
    g.add_vertex_data(3, "D");
    g.add_vertex_data(4, "E");
    g.add_vertex_data(5, "F");
    g.add_vertex_data(6, "G");

    // Add edges to the graph with corresponding weights
    g.add_edge(3, 0, 4);  // D -> A, weight 4
    g.add_edge(3, 4, 2);  // D -> E, weight 2
    g.add_edge(0, 2, 3);  // A -> C, weight 3
    g.add_edge(0, 4, 4);  // A -> E, weight 4
    g.add_edge(4, 2, 4);  // E -> C, weight 4
    g.add_edge(4, 6, 5);  // E -> G, weight 5
    g.add_edge(2, 5, 5);  // C -> F, weight 5
    g.add_edge(1, 2, 2);  // B -> C, weight 2
    g.add_edge(1, 5, 2);  // B -> F, weight 2
    g.add_edge(6, 5, 5);  // G -> F, weight 5

    // Perform Dijkstra's algorithm starting from vertex D
    cout << "Dijkstra's Algorithm starting from vertex D:\n";
    int *distances = g.dijkstra("D");
    if (distances) {
        // Get vertex data array
        string* vertex_data = g.get_vertex_data();
        // Print shortest distances from D to all vertices
        for (int i = 0; i < 7; ++i) {
            cout << "Shortest distance from D to " << vertex_data[i] << ": " << distances[i] << endl;
        }
        delete[] distances;
    }

    return 0;
}
