#include <bits/stdc++.h>
using namespace std;
 
long long w, h, n;
bool good(long long x){
    return (x/w)*(x/h)>=n;
}
 
 
int main() {
    ios::sync_with_stdio(false);
 
    cin>>w>>h>>n;
 
    long long l = 0, r = 1;
    while(!good(r)) r*=2;
 
    while(l+1<r){
        long long m = (l + r)/2;
        if(good(m)) r = m;
        else l = m;
    }
    cout<<r<<"\n";
    return 0;
}