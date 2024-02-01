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
vt<int> g[105];
bool vis[105] = {0};
int ans = 0;
int dfs(int n){
    int v = 0;
    vis[n] = true;
    for (auto x : g[n]){
        if (!vis[x]){
            int cnt = dfs(x);
            if (cnt%2==0) ++ans;
            else v += cnt;
        }
    }
    return v+1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cout << ans;
}

int main(){
        solve(); 
    return 0;   
}       