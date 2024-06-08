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

// Fungsi untuk menampilkan child nodes dari suatu node
void showChildren(const Graph& graph, int node) {
    cout << "Child nodes of " << node << ": ";
    for (const Edge& edge : graph[node]) {
        cout << edge.second << " ";
    }
    cout << endl;
}

// Fungsi untuk menampilkan descendant nodes dari suatu node menggunakan DFS
void showDescendants(const Graph& graph, int node) {
    vector<bool> visited(graph.size(), false);
    vector<int> descendants;
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const Edge& edge : graph[current]) {
            int v = edge.second;
            if (!visited[v]) {
                descendants.push_back(v);
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "Descendant nodes of " << node << ": ";
    for (int desc : descendants) {
        cout << desc << " ";
    }
    cout << endl;
}

int main() {
    int jumlahKota_22102003, jumlahJalan_22102003;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahKota_22102003;
    cout << "Masukkan jumlah jalan yang menghubungkan kota: ";
    cin >> jumlahJalan_22102003;

    Graph graph(jumlahKota_22102003);

    cout << "Masukkan data jalan (kota1 kota2 jarak):" << endl;
    for (int i = 0; i < jumlahJalan_22102003; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Hitung jarak terpendek dari satu kota ke kota lainnya\n";
        cout << "2. Tampilkan child nodes dari suatu kota\n";
        cout << "3. Tampilkan descendant nodes dari suatu kota\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            int start_22102003, end_22102003;
            cout << "Masukkan kota awal: ";
            cin >> start_22102003;
            cout << "Masukkan kota tujuan: ";
            cin >> end_22102003;

            vector<int> distance = dijkstra(graph, start_22102003);

            if (distance[end_22102003] == INF) {
                cout << "Tidak ada jalur yang menghubungkan kota " << start_22102003 << " dan kota " << end_22102003 << "." << endl;
            } else {
                cout << "Jarak terpendek dari kota " << start_22102003 << " ke kota " << end_22102003 << " adalah " << distance[end_22102003] << endl;
            }
        } else if (pilihan == 2) {
            int node;
            cout << "Masukkan kota: ";
            cin >> node;
            showChildren(graph, node);
        } else if (pilihan == 3) {
            int node;
            cout << "Masukkan kota: ";
            cin >> node;
            showDescendants(graph, node);
        } else if (pilihan == 4) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
