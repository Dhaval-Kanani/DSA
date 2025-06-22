#include <bits/stdc++.h>
using namespace std;



int main(){
    int m, n;
    cin>>m>>n;

    vector<int> a(m), b(n);
    for(int i=0; i<m; i++) cin>>a[i];

    for(int j=0; j<n; j++) cin>>b[j];

    vector<int> c(m+n);
    
    int i = 0, j = 0, k = 0;
    while(i<m or j<n){
        if(j==n || (i<m and a[i]<b[j])){
           c[k++] = a[i++];
        } else c[k++] = b[j++];
    }
    for(auto x: c)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}