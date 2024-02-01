#include <iostream>
#include <set>
#include <map>
#include <climits>
#include <functional>
#include <queue>
#include <numeric>
#include <iomanip>
#include <list>
#include <bitset>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ii pair<int, int>
#define vii(a) vector<pair<int, int> > (a)
#define read(a) for (auto &x : (a)) cin >> x;
#define print(a) for (auto x : (a)) cout << x << " "; 
#define cb1(a) __builtin_popcount(a)
#define vt vector
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
// Solution by inori224 (=^･ω･^=) ~
struct Edge{
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {};
};
ll totalWeight = 0;
vt<Edge> v;
struct dsu{
    vt<int> par;
    void init(int n){
        par.resize(n+5, 0);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }
    int find(int n){
        if (par[n] == n) return n;
        return find(par[n]);
    }
    bool isCycle(int u, int v){
        u = find(u), v = find(v);
        if (u==v) return 0;
        par[v] = u;
        return 1;
    }
} dsu;

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        v.pb({a,b,c});
    }
    sort(all(v), [](Edge &x, Edge &y){return x.w < y.w;});
    dsu.init(n);
    for (auto x : v){
        if (!dsu.isCycle(x.u, x.v)) continue;
        totalWeight += x.w;
    }
    cout << totalWeight;
}

int main(){
        solve(); 
    return 0;   
}       