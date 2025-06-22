#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<double>> a;
bool good(double t){
    bool check = true;
    double l = INT_MIN, r = INT_MAX;

    for(int i=0; i<n; i++){
        l = max(l, (a[i][0] - t*a[i][1]));
        r = min(r, (a[i][0] + t*a[i][1]));
    }

    return l<=r;
}

int main(){

    cin>>n;
    a.resize(n, vector<double>(2));
    
    for(int i=0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
    }

    double l = 0, r = 1e10;

    for(int i=0; i<100; i++){
        double m = l + (r - l)/2;
        if(good(m)) r = m;
        else l = m;
    }

    cout<<setprecision(15)<<r<<"\n";
    return 0;
}