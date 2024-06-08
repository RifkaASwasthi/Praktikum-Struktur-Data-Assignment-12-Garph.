# <h1 align="center">Laporan Praktikum Modul Graf</h1>
<p align="center">  Rifka Annisa Swasthi</p>

## Dasar Teori
Graph adalah struktur data umum yang susunan datanya tidak berdekatan satu sama lain, graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling ketrikatan. simpul graph disebut verteks (V) dan sisi yang menghubungkan desebut edga (E). pasangna (x,y) disebut edge yang menyatakan bahwa simpul x terhubung ke simpul y. 

Komponen Teori graph [1]

Simpul adalah elemen dasar yang merepresentasikan objek atau entitas tertentu dalam konteks masalah, sisi adalah hubungan atu koneksi yang ketika terjadi suatu rangkaian atau lintasan untuk menghubungakan satu simpul ke simpul yang lain, ketika lintasan berawal dan berakhir di ttik  yang sama dinamakan siklus graf berarah memiliki arah dan sebaliknya. drajat yaitu jumlah sisi yang terhubung sengan simpul tertentu, graf berbobot adalah graf yang memiliki bobot, graf sederhana adalah graf tak berarah tanpa sisi, graf terhubung adalah graf tek berarah di mana setiap simpul dapat dijangkau, kompunen terhubung adlah kemompok simpul salam graf yang saling terhubung, graf beraturan adalah graf dimana setiap simpul memiliki drajat yang sama. 

Jenis-jenis graph,

1. Undirected graph, yaitu simpul terhubung dengan edge dan sifatnya dua arah.

2. Directed graph, simpulnya terhubung dengan edge yang hanya bisa melakukan jelajah satu arah pada simpul.

3. Weighted graph, graph yang cabangnya diberi bobot

4. Unweighted graph, tidak mempunyai bobot dan hanya mementingkan apakah dua node saling terhubung atau tidak

Karakteristik graph

1. jarak maksimum dari sebuah simpul ke simpul ke semua liannya dianggap eksentrisitas dari simpul tersebut

2. titik yang memiliki eksentrisitas minimum dianggap sebagai titik pusat dari graph

3. nilai eksentrisitas minimum dari semua simpul dianggap sebagai jari-jari dari graph terhubung.

Fungsi dan kegunaan graph [1]

1. digunakan untuk merepresentasikan aliran komputasi

2. digunakan untuk pemodelan grafik

3. dipakai pada sistem operasi alokasi sumber daya

4. google maps menggunakan graph untuk menemukan rute terpendek

5. graph digunakan dalam jaringan komputer unutuk aplikasi peer to peer



## Guided 

### 1.

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")"; 
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Kode di atas digunakan untuk menampilkan graf yang dimanaa setiap kota akan ditampilkan bersama semua kota yang terhubung beserta jaraknya. di awal kita mendeklarasikan array string simpul 7yang artinya nanti terdapat 7 nama kota yang ditampilkan, kemudian utnuk penulisan jarak menggunakan int bussur 7 7 busur i j jika tidak bernilai 0 berarti ada jalur langsung dari kota i ke kota j. untuk menampulkan graph menggunakan void tampil graph for untuk loop sertiap baris kota asal, cout untuk menampilkan sete 15 kolom karakter for kedua untk loop setiap kolom kota tujuan if busur baris kolom tidak sama dengan 0 maka cout menamipilkan nama kota tujuan, cout pindah ke baris berikutnya setelah menam[ilakn semua tujuan dari kota asal tersebut. main untuk mengeksekusi program, memanggil tampilgraph untuk menampilkan graph dan retun 0 program dijalankan selesai tampa error. 

### 2. 

```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TNode *node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node -> data << " ";
        inorder(node->right);
    }
}

void postorder(TNode *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        cout << node -> data << " ";
    }
}

int main(){
    TNode *zero = new TNode(0);
    //0
    // /\
    //NULL NULL
    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    //7
    // /\
    // 1 NULL
    seven->right = nine;
    //7
    // /\
    //19
    one->left = zero;
    //7
    // /\
    //1 9
    // /\
    // 0  NULL
    one->right = five;
    //7
    // /\
    //1 9
    // /\
    // 0 5
    nine->left = eight;
    //7
    // /\
    //1 9
    // /\ /\
    // 058  NULL
    preorder(seven);
    cout << endl;
    inorder(seven);
    cout << endl;
    postorder(seven);
    cout << endl;

    return 0;
}

```
mendefinisikan node kedalam binary tree dengan tiga anggota int data untuk menyimpan data Tnode left untuk pointer ke anak kirir dan sebaliknya, definidikan Tnode int value utnuk menginisiasi node dengan nilai value pointer left and right diinisiasi Null. Viod preorder jika kode tidak null cetak data node lalu rekrusi ke anak kiri dan kanan, void inorder jika node tidak null rekrusi ke anak kiri cetak data node lalu rekrusi ke anak kanan, void postorder jika node tidak Null rekrusi ke anak kiri rekrusi ke anak kanan lalu cetak node. main utun mengeksekusi program dengan memanggil fungsi preorder seven inorderseven dan postorderseven untuk menampilkan binary tree yang terbentuk.

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
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

```
#### Output:
pertama kita mendefinisikan type pair dan typevektor dan konstanta inf sebagi nilai maksimum int, void addedge untuk menambahkan edge ke graph. fungsi dijkstra, voktor int untuk menghitung jarak terpendek dari node start ke semua node, loop sampai priority queue kosong. main meminta user untk jumlah kota dan membuat graf dengan ukuran jumlah kota_2311110040 dan meminta input user dari setiap jalan lalu menambahkan edge ke graf, menghitung jarak terpendek dari kota awal kesemua kota menggunakan fungsi dijkstra, dan tampilkan. contoh memaasukkan jumlah kota 5 dan jumlah jalan yang menghubungkan kota 6 data jalan masukkan kota tujuan 3 , output jarak terpendek dari kota 0 ke kota 3 adalah 12. 



#### Full code Screenshot:
![Screenshot 2024-06-09 011202](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-12-Garph./assets/162097297/c1d8ce1b-16c2-457b-b539-2c39421b59c7)
### Output
![Screenshot 2024-06-09 011510](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-12-Garph./assets/162097297/0ccd667d-be54-4e73-8c38-19e6964e184d)

### 2.Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
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

```
#### Output:
![Screenshot 2024-06-09 013423](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-12-Garph./assets/162097297/1c8301c0-f770-48ed-bcca-ed26554ee9e6)


Pertama kita mendefinisikan sebuah edge sebagai pasangan nilai biaya dan tujuan dan mendefinisikan graf sebagi vektor dari vektor edge, const untuk mendefinisikan inf sebagi nialai makasimum int, void add utnuk menambahkan edge ke graf yaitu menambahkan edge dari u ke v daengan biaya w dan karena graf tidak berarah tambahkan juga edge dari u ke v daengn biaya yang sama. fungsi dijkstra untuk menghitung jark terpendek dari node start ke semua node menggunakan algoritma dijkstra, fungsi showchildren menampilkan node anak dari node yang diberikan dan fungsi showdesd=cendants untuk menampilkan semua node keturunan dari node yang diberikan menggunaakn DFS. 

#### Full code Screenshot:
![Screenshot 2024-06-09 013222](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-12-Garph./assets/162097297/e9febe44-03a7-4065-8912-a59aa61e7fd1)



## Kesimpulan
Graph adalah struktur data umum yang susunan datanya tidak berdekatan satu sama lain, graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling ketrikatan. simpul graph disebut verteks (V) dan sisi yang menghubungkan desebut edga (E). pasangna (x,y) disebut edge yang menyatakan bahwa simpul x terhubung ke simpul y. 


Simpul adalah elemen dasar yang merepresentasikan objek atau entitas tertentu dalam konteks masalah, sisi adalah hubungan atu koneksi yang ketika terjadi suatu rangkaian atau lintasan untuk menghubungakan satu simpul ke simpul yang lain, ketika lintasan berawal dan berakhir di ttik  yang sama dinamakan siklus graf berarah memiliki arah dan sebaliknya. drajat yaitu jumlah sisi yang terhubung sengan simpul tertentu, graf berbobot adalah graf yang memiliki bobot, graf sederhana adalah graf tak berarah tanpa sisi, graf terhubung adalah graf tek berarah di mana setiap simpul dapat dijangkau, kompunen terhubung adlah kemompok simpul salam graf yang saling terhubung, graf beraturan adalah graf dimana setiap simpul memiliki drajat yang sama. 
Jenis-jenis graph: Undirected graph, Directed graph,Weighted graph,Unweighted graph

## Referensi
[1]LamanIT, 2023. Teori Graf: Pengertian, Sejarah, Konsep, Komponen dan Contoh, [Artikel], LamanIT.

[2]Trivusi. 2022, Struktur Data Graph: Pengertian, Jenis, dan Kegunaannya,[Artikel] trivusi.web.id.

