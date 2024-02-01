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
int total = 0;
struct Edge{
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {};
};
vt<Edge> v;
int par[3005]; 
int find(int n){
    if (par[n] == n) return n;
    return find(par[n]);
}
bool cycle(int u, int v){
    int a = find(u), b = find(v);
    if (a==b) return false;
    par[b] = a;
    return true;
}
void solve(){
   int n, m; cin >> n >> m;
   for (int i = 0, a, b, c; i < m; i++){
       cin >> a >> b >> c;
        v.pb({a,b,c});
   }
    for (int i = 1; i <=n ; i++)
    par[i] = i;
    sort(all(v),[](Edge &a, Edge &b){return a.w < b.w;});
    for (auto x : v){
        if (!cycle(x.u, x.v)) continue;
        total += x.w;
    }
    cout << total;
}

int main(){
        solve(); 
    return 0;   
}       