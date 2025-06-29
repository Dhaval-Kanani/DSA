
#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    long long n, s;
    cin>>n>>s;
    vector<int> a(n);
 
    for(int i=0; i<n; i++) cin>>a[i];
 
    long long l = 0, x = 0, res = LLONG_MIN;
    for(int r=0; r<n; r++){
        x += a[r];
        while(x>s){
            x -= a[l];
            l++;
        }
        res = max(res, r-l+1);
    }
    cout<<res<<endl;
    return 0;
}