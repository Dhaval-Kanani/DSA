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
        int l = -1, r = n; //This is use to define what should be print on the edge cases. l or l+1 or r or r+1.
        while(l+1 < r){
            int m = (l + r)/2;
            if(a[m]< num){ // This condition < or <= should define till which point our search goes. For closest to the left we want to 
                           //search maximum idx at which value not geater than the one. So we have to use <= for equal terms. Similarly 
                           //viceversa we have to use < only as for equal values we assigning m idx to r.
                l = m;
            } else r = m;
        }
        cout<<r+1<<"\n";
    }
 
    return 0;
}