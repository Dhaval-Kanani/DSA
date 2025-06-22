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
        if(a[i]==b[j]){
            long long counti = i, countj = j;
            while(counti<m and a[counti]==b[j]) counti++;
            while(countj<n and b[countj]==a[i]) countj++;
            res += (counti-i)*(countj - j);
            i = counti, j = countj;    
        }else if(a[i]<b[j]){
            i++;
        } else j++;
    }
    cout<<res<<endl;
}