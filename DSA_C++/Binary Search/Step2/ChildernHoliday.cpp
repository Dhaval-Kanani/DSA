#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> a;
vector<int> ans;
bool good(int T){

    int sum = 0;

    for(int i=0; i<n; i++){
        int cnt = 0;
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];
        
        int reminder = T%(t*z + y);
        
        if(reminder>t*z) reminder = t*z;
        cnt = floor(T/(t*z + y))*z + floor(reminder/t);
        sum += cnt;
        ans[i] = cnt;
    }

    return sum>=m;
}


int main() {
    ios::sync_with_stdio(false);

    cin>>m>>n;
    a.resize(n, vector<int>(3));
    ans.resize(n);

    for(int i=0; i<n; i++){
        cin>>a[i][0];
        cin>>a[i][1];
        cin>>a[i][2];
    }
    
     if(m == 0) {
        cout << 0 << endl;
        for(int i=0; i<n; i++) {
            cout << "0 ";
        }
        return 0;
    }

    int l = 0, r = 1e7;
 
    while(l+1<r){
        int mid = (l + r)/2;
        if(good(mid)) r = mid;
        else l = mid;
    }

    cout<<r<<"\n";
    
    int T = r;
    // int time = r;
    // for(int i=0; i<n; i++) {
    //     int ballon = time/(a[i][0]*a[i][1] + a[i][1]);
    //     int rem = time - ballon * (a[i][0]*a[i][1] + a[i][1]);
    //     ballon *= a[i][1];
    //     if(rem >= a[i][0]) {
    //         if(rem/a[i][0] > a[i][1]) {
    //             ballon += a[i][1];
    //         }
    //         else ballon += (rem/a[i][0]);
    //     }
    //     ans[i] = ballon;
    // }
    
    for(int i=0; i<n; i++){
        long long cnt = 0;
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];
        
        int reminder = T%(t*z + y);
        
        if(reminder>t*z) reminder = t*z;
        cnt = floor(T/(t*z + y))*z + floor(reminder/t);
        ans[i] = cnt;
    }
    
    // int blown = 0;
    // for(int i=0; i<n; i++) {
    //     if(blown + ans[i] > m) {
    //         if(m > 0) {
    //             cout << m-blown << " ";
    //             m = 0;
    //         }
    //         else cout << "0 ";
    //     }
    //     else cout << ans[i] << " ";
    //     blown += ans[i];
    // }
    // cout << "\n";
    
    for(int i=0; i<n; i++){
        
        if(m==0) {
            cout<<"0 "; continue;
        }
        if(ans[i]<=m) {
            cout<<ans[i]<<" ";
            m -= ans[i];
        } else {
            cout<<m<<" ";
            m = 0;
        }
    }
    
    return 0;
}