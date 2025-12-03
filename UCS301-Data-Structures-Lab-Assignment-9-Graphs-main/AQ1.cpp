#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <numeric>
#include <functional>
#include <tuple>
#include <utility>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max() / 4;


vector<int> BFS(const vector<vector<int>>& adj, int s) {
    int n = (int)adj.size();
    vector<int> vis(n, 0), order;
    queue<int> q;
    vis[s] = 1; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (!vis[v]) { vis[v] = 1; q.push(v); }
    }
    return order;
}


void dfsRec(int u, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : adj[u]) if (!vis[v]) dfsRec(v, adj, vis, order);
}

vector<int> DFS(const vector<vector<int>>& adj, int s) {
    int n = (int)adj.size();
    vector<int> vis(n, 0), order;
    dfsRec(s, adj, vis, order);
    return order;
}


struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0): n(n), p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

struct Edge { int u,v; ll w; };


pair<ll, vector<Edge>> Kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){ return a.w < b.w; });
    DSU dsu(n);
    vector<Edge> mst;
    ll total = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            total += e.w;
            if ((int)mst.size() == n-1) break;
        }
    }
    return {total, mst};
}


pair<ll, vector<Edge>> Prim(int n, const vector<vector<pair<int,ll>>>& adj) {
    vector<char> vis(n, 0);
    using T = tuple<ll,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<Edge> mst;
    ll total = 0;
    pq.emplace(0LL, 0, -1);
    while (!pq.empty() && (int)mst.size() < n-1) {
        auto [w, u, from] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (from != -1) { mst.push_back({from, u, w}); total += w; }
        for (auto &pr : adj[u]) {
            int v = pr.first; ll wt = pr.second;
            if (!vis[v]) pq.emplace(wt, v, u);
        }
    }
    return {total, mst};
}

pair<vector<ll>, vector<int>> Dijkstra(int n, const vector<vector<pair<int,ll>>>& adj, int src) {
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);
    dist[src] = 0;
    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &pr : adj[u]) {
            int v = pr.first; ll w = pr.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    return {dist, parent};
}

void printOrder(const vector<int>& ord) {
    for (size_t i = 0; i < ord.size(); ++i) {
        if (i) cout << ' ';
        cout << (ord[i] + 1);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<Edge> edges;
    vector<vector<pair<int,ll>>> adj;

    // Input format (if provided): n m
    // then m lines: u v w
    if (cin >> n >> m) {
        edges.reserve(m);
        adj.assign(n, {});
        for (int i = 0; i < m; ++i) {
            int u, v; ll w; cin >> u >> v >> w; // assume 1-based input
            --u; --v;
            edges.push_back({u, v, w});
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    } else {
        // No input detected: create a sample weighted graph
        cerr << "No graph input detected; using sample graph.\n";
        n = 6;
        edges = {
            {0,1,7},{0,2,9},{0,5,14},{1,2,10},{1,3,15},{2,3,11},{2,5,2},{3,4,6},{4,5,9}
        };
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
        m = (int)edges.size();
    }

    vector<vector<int>> unweighted(n);
    for (auto &e : edges) {
        unweighted[e.u].push_back(e.v);
        unweighted[e.v].push_back(e.u);
    }
    for (int i = 0; i < n; ++i) sort(unweighted[i].begin(), unweighted[i].end());

    cout << "BFS order starting at node 1: ";
    auto bfsOrder = BFS(unweighted, 0);
    printOrder(bfsOrder);

    cout << "DFS order starting at node 1: ";
    auto dfsOrder = DFS(unweighted, 0);
    printOrder(dfsOrder);

    // Kruskal
    auto [kWeight, kMst] = Kruskal(n, edges);
    cout << "Kruskal MST total weight: " << kWeight << "\n";
    cout << "Kruskal MST edges (u v w):\n";
    for (auto &e : kMst) cout << e.u+1 << ' ' << e.v+1 << ' ' << e.w << '\n';

    // Prim
    auto [pWeight, pMst] = Prim(n, adj);
    cout << "Prim MST total weight: " << pWeight << "\n";
    cout << "Prim MST edges (u v w):\n";
    for (auto &e : pMst) cout << e.u+1 << ' ' << e.v+1 << ' ' << e.w << '\n';

    // Dijkstra from node 1
    auto [dist, parent] = Dijkstra(n, adj, 0);
    cout << "Dijkstra distances from node 1:\n";
    for (int i = 0; i < n; ++i) {
        cout << "node " << i+1 << ": ";
        if (dist[i] >= INF/2) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
