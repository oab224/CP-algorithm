#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
int x, y, d;

int gcd(ll a, ll b, int &x, int &y){
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a/b*y1;
  return d;
} 

int main(){
  ll a, b;
  cin >> a >> b;
  cout << x << ' ' << y << ' ' << gcd(a, b, x, y);
} 