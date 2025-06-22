#include <bits/stdc++.h>
using namespace std;



int main(){
    int m, n;
    cin>>m>>n;

    vector<int> a(m), b(n);
    for(int i=0; i<m; i++) cin>>a[i];

    for(int j=0; j<n; j++) cin>>b[j];

    long long res = 0;
    
    int i = 0, j = 0;
    while(i<m and j<n){
        if(a[i]==a[j]){
            res++, i++;
        }else if(a[i]<a[j]){
            i++;
        } else j++;
    }
    cout<<res<<endl;
}