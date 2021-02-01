// UVa1660 Cable TV Network
// 陈锋
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define _zero(D) memset((D), 0, sizeof(D))
#define _init(D, v) memset((D), (v), sizeof(D))
#define _ri1(x) scanf("%d", &(x))
#define _ri2(x, y) scanf("%d%d", &(x), &(y))
#define _ri3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define _ri4(a, b, c, d) scanf("%d%d%d%d", &(a), &(b), &(c), &(d))
typedef long long LL;
struct Edge {
  int from, to, cap, flow;
};
bool operator<(const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

template <int MAXSIZE, int INF>
struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;  // 边数的两倍
  vector<int> G[MAXSIZE];  // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[MAXSIZE];  // BFS使用
  int d[MAXSIZE];     // 从起点到i的距离
  int cur[MAXSIZE];   // 当前弧指针

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for (int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (const auto& ei : G[x]) {
        auto e = edges[ei];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < (int)G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }

  vector<int> Mincut() {  // call this after maxflow
    vector<int> ans;
    for (int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if (vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }
};

const int MAXN = 50 + 2, INF = 0x7f7f7f7f;
int N, M, G[MAXN][MAXN];
Dinic<MAXN * 2 + 2, INF> D;
vector<Edge> Es;
int solve() {
  if (N == 0) return 0;
  if (N == 1) return 1;
  int ans = N;
  _for(i, 0, N) _for(j, 0, N) if (i != j) {
    D.init(2 * N + 2);
    _for(u, 0, N) D.AddEdge(u, u + N, 1);
    for (const auto& e : Es)
      D.AddEdge(e.from + N, e.to, INF), D.AddEdge(e.to + N, e.from, INF);
    ans = min(ans, D.Maxflow(i + N, j));
  }
  return ans;
}

int main() {
  while (_ri2(N, M) == 2) {
    Edge e;
    Es.clear();
    _for(i, 0, M) {
      scanf(" (%d,%d)", &(e.from), &(e.to));
      Es.push_back(e);
    }
    int ans = solve();
    printf("%d\n", ans);
  }
  return 0;
}
// 20223820	1660 Cable TV Network Accepted C++11	0.100 2017-10-22 12:45:02