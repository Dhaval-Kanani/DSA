#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<k; i++){
        int num;
        cin>>num;
        int l = -1, r = n;
        while(l+1 < r){
            int m = (l + r)/2;
            if(a[m]<=num){
                l = m;
            } else r = m;
        }
        cout<<l+1<<"\n";
    }

    return 0;
}