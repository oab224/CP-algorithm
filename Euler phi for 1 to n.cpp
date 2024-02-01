#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define vt vector

const int maxN = 2e5 + 5;
ll phi[maxN];

void _phi(){
    phi[0] = 0;
    phi[1] = 2;
    for (int i = 2; i <= maxN; i++){
        phi[i] = i;
    }
    for (int i = 2; i <= maxN; i++){
        if (phi[i] == i)
        for (int j = i; j <= maxN; j+=i)
            phi[j] -= phi[j]/i;
    }
}







