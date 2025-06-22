#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector<long long> a;

bool good(long long minsum){
    long long cnt = 0, sum = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>minsum) return false;
        sum = 0;
        while(i<n && sum + a[i]<=minsum) {sum+=a[i]; i++;}
        cnt++;
        i = i-1;
    }
    return cnt<=k;

    // long long sum = 0;
    // int cnt = 0;
    // for(long long i=0; i<n; i++){
    //     if(n-i==k-cnt-1){
    //         sum = a[i]; cnt += 1;
    //     } else{
    //         sum += a[i];
    //     }
        
    //     if(a[i]>minsum) return false;
    //     if(sum>minsum){
    //         if(i==n-1) return false;
    //         sum = a[i];
    //         cnt +=1;
    //     }
    //     if(i==n-1) cnt+=1;
    // }
    // return k>=cnt;
}

int main(){
    cin>>n>>k;
    a.resize(n);

    for(long long i=0; i<n; i++){
        cin>>a[i];
    }

    long long l = 0, r = 1e15;

    while(l+1<r){
        long long m = l + (r - l)/2;
        if(good(m)) r = m;
        else l = m;
    }

    cout<<r<<endl;
}