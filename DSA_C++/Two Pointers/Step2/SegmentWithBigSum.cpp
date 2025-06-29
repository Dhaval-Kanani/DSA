#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    long long n, s;
    cin>>n>>s;
    vector<int> a(n);
 
    for(int i=0; i<n; i++) cin>>a[i];
 
    long long l = 0, x = 0, res = LLONG_MAX;
    for(int r=0; r<n; r++){
        x += a[r];
        while(x - a[l]>=s){
            x -= a[l];
            l++;
        }
        if(x>=s)
            res = min(res, r-l+1);
    }
    if(res!=LLONG_MAX)
        cout<<res<<endl;
    else cout<<-1<<endl;
    return 0;
}