#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    long long n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> check(1e5+100, 0);
 
    for(int i=0; i<n; i++) cin>>a[i];
 
    long long l = 0, res = 0;
    int count = 0;
    for(int r=0; r<n; r++){
        if(check[a[r]]==0) count++;
        check[a[r]]++;
        while(count>k){
            check[a[l]]--;
            if(check[a[l]]==0) count--;
            l++;
        }
        if(count<=k)
            res += r-l+1;
    }
    cout<<res<<endl;
    return 0;
}