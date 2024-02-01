#include <iostream>
#include <set>
#include <map>
#include <functional>
#include <iomanip>
#include <climits>
#include <queue>
#include <bitset>
#include <numeric>
#include <list>
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
int d[105] = {0};
int g[105];
bool vis[105] = {0};

bool valid(int n){
    if (n < 1 || n > 100 || vis[n]) return false;
    return true;
}
void solve(){
    memset(vis,0, sizeof(vis));
    memset(d, 0, sizeof(d));
    int n, m; cin >> n;
    for (int i = 1; i <= 100; i++) g[i] = i;
    for (int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        g[a] = b;
    }
    cin >> m;
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        g[a] = b;
    }
    queue<int> q;
    q.push(1);
    while(q.size()){
        int current = q.front();
        q.pop();
        vis[current] = 1;
        for (int i = 1; i <= 6; i++){
            int next = g[current + i];
            if (valid(next)){
                q.push(next);
                vis[next] = 1;
                d[next] = d[current] + 1;
            }
        }
    }
    cout << (vis[100] ? d[100] : -1);
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while (t--) 
        solve(); 
    return 0;   
}   