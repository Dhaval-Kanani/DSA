#include <bits/stdc++.h>
using namespace std;

long long n, x, y;
bool good(long long t){

    if(t<min(x,y)) return false;

    t -= min(x, y);
    return floor(t/x) + floor(t/y) >= n-1;
}


int main() {
    ios::sync_with_stdio(false);

    cin>>n>>x>>y;

    long long l = 0, r = 1e10;
 
    while(l+1<r){
        long long m = (l + r)/2;
        if(good(m)) r = m;
        else l = m;
    }

    cout<<r<<"\n";
    return 0;
}