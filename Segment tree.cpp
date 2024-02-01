//if n is the power of 2 then there are no DUMMY value;
//else if n isn't the power of 2 then size of the segment tree arr is the smallest power of 2 greater than n
//for example if n = 6 then the size of the array should be 2*8-1; because 8 is the smallest value that power of 2 and greater than n
//value are 2*x - 1
#include <bits/stdc++.h>
using namespace std;


int query(vector<int> st, int i, int j, int l, int r, int pos){
    if (r < i || l > j) return 0;
    if (l >= i && r <= j){
        return st[pos];
    }
    int mid = (i+j)/2;
    return query(st, i, mid, l, r, pos*2+1) + query(st, mid + 1, j, l, r, pos*2+2);

}
void update(vector<int> arr, vector<int> &st, int i, int j, int pos, int idx, int value){
    if (i == j){
        st[pos] = value;
    }
    else{
        int mid = (i+j)/2;
        if (idx >= i && idx <= mid)     
            update(arr, st, i, mid, 2*pos+1, idx, value);
        else 
            update(arr, st, mid+1, j, 2*pos+2, idx, value);
            st[pos] = st[2*pos+1] + st[2*pos+2];
    }
}

void build(vector<int> arr, vector<int> &st, int i, int j, int pos){
    if (i == j)
        st[pos] = arr[i];
    else{
        int mid = (i+j)/2;
        build(arr, st, i, mid, 2*pos+1);
        build(arr, st, mid+1, j, 2*pos+2);
        st[pos] = st[2*pos + 1] + st[2*pos + 2];
    }
}

int main(){
    int n, m;
    char c;
    cin >> n >> m;
    vector<int> arr(n);
    int mxN = 2*(pow(2,ceil(log2(n)))) - 1;
    vector<int> st(mxN, 0);
    build(arr, st, 0, n-1, 0);
    for (int i = 0, x, y, l, r; i < m; i++){
        cin >> c;
        if (c == 'S') cin >> x >> y, update(arr, st, 0, n-1, 0, x-1, y);
        if (c == 'Q') cin >> l >> r, cout << query(st, 0, n-1, l-1, r-1, 0) << '\n';
    }
    for (auto x : st) cout << x << ' ';
    return 0;
}