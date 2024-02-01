/* #include <iostream>
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
#define read(a) for (auto &x : (a)) cin >> x;
#define print(a) for (auto x : (a)) cout << x << " "; 
#define cb1(a) __builtin_popcount(a)
#define vt vector
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define vii(a) vector<pair<int, int> > (a)
using namespace std;
const int mxN = 1e3+1;
int shop[mxN];
vii(v)[2*mxN];
const int oo = 1e9;
int d[mxN][(1<<10)+1];
void solve(){
   
    int n, m, k; 
    cin >> m >> m >> k;
    for (int i = 1, a, b; i <= n; i++){
        cin >> a;
        while(a--){
           cin >> b;
           b--;
           shop[i] |= (1 << b);
        }
   }
    for (int i = 0, a, b, w; i < m; i++){
        cin >> a >> b >> w;
        v[a].pb(mp(b, w));
        v[b].pb(mp(a, w));
    }
    for (int i = 0; i < mxN; i++)
        for (int j = 0; j < (1<<10)+1; j++)
            d[i][j] = oo;
    d[1][shop[1]] = 0;
    q.push(mp())
       priority_queue<ii, vt<ii>, greater<ii> > q;
    
}

int main(){
        solve(); 
    return 0;   
}        */