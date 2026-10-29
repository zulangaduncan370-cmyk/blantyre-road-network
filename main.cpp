#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

// The graph contains 20 vertices, numbered from 1 to 20.
const int V = 20;

// Infinity represents a distance that has not yet been discovered.
const double INF = numeric_limits<double>::infinity();

// Represents an edge connecting a vertex to one of its neighbours.
struct Edge {
    int to;          // The neighbouring vertex.
    double weight;   // The distance to that neighbour in kilometres.
};

// Represents a vertex and its current tentative distance.
struct State {
    double distance;
    int vertex;

    // Allows the priority queue to compare states by distance.
    // The smallest distance is processed first.
    bool operator>(const State& other) const {
        return distance > other.distance;
    }
};

// Adds an undirected edge between vertices u and v.
// Both directions are added because the roads are assumed to be two-way.
void addEdge(vector<vector<Edge>>& graph,
             int u, int v, double weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

// Finds the shortest route from the source vertex to the destination.
void dijkstra(const vector<vector<Edge>>& graph,
              int source, int destination) {

    // Initially, every vertex is unreachable.
    vector<double> dist(V + 1, INF);

    // Stores the previous vertex on each currently shortest route.
    // -1 means that no predecessor has been assigned.
    vector<int> predecessor(V + 1, -1);

    // A min-priority queue processes the vertex with the smallest
    // tentative distance before vertices with larger distances.
    priority_queue<State, vector<State>, greater<State>> pq;

    // The distance from the source to itself is zero.
    dist[source] = 0.0;
    pq.push({0.0, source});

    // Continue while there are vertices waiting to be processed.
    while (!pq.empty()) {

        // Retrieve and remove the state with the smallest distance.
        State current = pq.top();
        pq.pop();

        double currentDistance = current.distance;
        int u = current.vertex;

        // Ignore an outdated entry if a shorter route to u
        // has already been discovered.
        if (currentDistance > dist[u]) {
            continue;
        }

        // Once the destination is removed with its current minimum
        // distance, its shortest distance has been determined.
        if (u == destination) {
            break;
        }

        // Examine every neighbour connected to the current vertex u.
        for (const Edge& edge : graph[u]) {
            int v = edge.to;

            // Calculate the distance to v through the current vertex u.
            double newDistance = dist[u] + edge.weight;

            // If this route is shorter, update the best-known distance.
            if (newDistance < dist[v]) {
                dist[v] = newDistance;

                // Record u as the predecessor of v so the route
                predecessor[v] = u;

                // Add the improved distance to the priority queue.
                pq.push({newDistance, v});
            }
        }
    }

    // If the destination still has infinite distance, no route exists.
    if (dist[destination] == INF) {
        cout << "No route exists between these locations.\n";
        return;
    }

    // Reconstruct the route by following predecessors backwards,
    // starting from the destination until the source is reached.
    vector<int> path;

    for (int current = destination;
         current != -1;
         current = predecessor[current]) {
        path.push_back(current);
    }

    // The path was collected from destination to source.
    // Reverse it to display the route from source to destination.
    reverse(path.begin(), path.end());

    // Maps vertex numbers to their corresponding location names.
    const vector<string> names = {
        "",
        "Limbe Market",
        "NACIT",
        "Chichiri Mall",
        "Kwik-Fit Chitawira",
        "Chipiku Plus Chitawira",
        "Stereo Kamba",
        "Blantyre Baptist Academy",
        "Sana Cash n Carry Ginnery Corner",
        "Mwai Wathu Hospital",
        "Mibawa Bus Stop",
        "Mudi River-Bridge",
        "Victoria Gardens",
        "Njamba Freedom Park",
        "Soche Technical College",
        "St. Columba CCAP",
        "St. Pius Church",
        "Zingwangwa Market",
        "Stella Marris",
        "Total Energies Chikwawa Road Service Station",
        "St. Montfort Catholic Parish"
    };

    // Display distances to two decimal places.
    cout << fixed << setprecision(2);

    cout << "\nShortest distance: "
         << dist[destination] << " km\n";

    // Display the numerical sequence of vertices in the shortest route.
    cout << "Shortest path: ";

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];

        // Print an arrow between vertices, but not after the last one.
        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }

    // Display the same route using the actual location names.
    cout << "\nRoute by location: ";

    for (size_t i = 0; i < path.size(); i++) {
        cout << names[path[i]];

        // Separate location names with arrows.
        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }

    cout << '\n';
}

int main() {

    // Create an adjacency list for the 20 vertices.
    // The extra position allows vertices to be indexed from 1 to 20.
    vector<vector<Edge>> graph(V + 1);

    // Add the undirected roads and their distances in kilometres.
    addEdge(graph, 1, 2, 2.0);
    addEdge(graph, 2, 3, 1.9);
    addEdge(graph, 3, 8, 0.9);
    addEdge(graph, 3, 9, 3.9);
    addEdge(graph, 8, 10, 2.2);
    addEdge(graph, 9, 10, 2.5);
    addEdge(graph, 10, 11, 3.3);
    addEdge(graph, 11, 12, 5.3);
    addEdge(graph, 12, 20, 0.8);
    addEdge(graph, 11, 20, 6.6);
    addEdge(graph, 19, 20, 1.4);
    addEdge(graph, 18, 19, 1.4);
    addEdge(graph, 17, 18, 2.6);
    addEdge(graph, 16, 17, 1.1);
    addEdge(graph, 15, 16, 1.5);
    addEdge(graph, 13, 15, 0.95);
    addEdge(graph, 14, 15, 2.3);
    addEdge(graph, 1, 14, 1.6);
    addEdge(graph, 1, 4, 3.0);
    addEdge(graph, 3, 4, 1.1);
    addEdge(graph, 4, 5, 0.8);
    addEdge(graph, 4, 13, 0.3);
    addEdge(graph, 5, 6, 1.4);
    addEdge(graph, 6, 7, 3.6);
    addEdge(graph, 7, 20, 1.9);
    addEdge(graph, 6, 16, 1.3);
    addEdge(graph, 8, 20, 2.5);

    // Display the source and destination of the search.
    cout << "Dijkstra's Shortest-Path Algorithm\n";
    cout << "Source: 1 (Limbe Market)\n";
    cout << "Destination: 20 (St. Montfort Catholic Parish)\n";

    // Execute Dijkstra's algorithm for the selected route.
    dijkstra(graph, 1, 20);

    return 0;
}
