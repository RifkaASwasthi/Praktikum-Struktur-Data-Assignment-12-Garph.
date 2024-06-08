#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

// Definisi graf sebagai adjacency list
typedef pair<int, int> Edge; // pair (cost, destination)
typedef vector<vector<Edge>> Graph;

const int INF = numeric_limits<int>::max();

// Fungsi untuk menambahkan edge ke graf
void addEdge(Graph& graph, int u, int v, int w) {
    graph[u].push_back({w, v});
    graph[v].push_back({w, u}); // Untuk graf tidak berarah
}

// Fungsi untuk menghitung jarak terpendek menggunakan algoritma Dijkstra
vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) continue;

        for (const Edge& edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int jumlahKota_2311110040, jumlahJalan_2311110040;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahKota_2311110040;
    cout << "Masukkan jumlah jalan yang menghubungkan kota: ";
    cin >> jumlahJalan_2311110040;

    Graph graph(jumlahKota_2311110040);

    cout << "Masukkan data jalan (kota1 kota2 jarak):" << endl;
    for (int i = 0; i < jumlahJalan_2311110040; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    int start_2311110040, end_2311110040;
    cout << "Masukkan kota awal: ";
    cin >> start_2311110040;
    cout << "Masukkan kota tujuan: ";
    cin >> end_2311110040;

    vector<int> distance = dijkstra(graph, start_2311110040);

    if (distance[end_2311110040] == INF) {
        cout << "Tidak ada jalur yang menghubungkan kota " << start_2311110040 << " dan kota " << end_2311110040 << "." << endl;
    } else {
        cout << "Jarak terpendek dari kota " << start_2311110040 << " ke kota " << end_2311110040 << " adalah " << distance[end_2311110040] << endl;
    }

    return 0;
}
