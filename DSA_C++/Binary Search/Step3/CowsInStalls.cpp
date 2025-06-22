#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> stalls;

bool good(int d){

    int cnt = 1;
    for(int i=0; i<n; i++){
        int j = i+1;
        while(j<n && stalls[j] - stalls[i] < d) j++;
        if(j==n) break;
        cnt += 1;
        i = j-1;
    }
    return cnt>=k;
    // int dist = 0, cnt = 1, prev = 0;
    // for(int i=1; i<n; i++){
    //     dist = stalls[i] - stalls[prev];
    //     if(n-i==k-cnt){
    //         if(stalls[i] - stalls[prev]<d) return false;
    //         prev = i;
    //         cnt+=1;
    //     } else if(dist>=d){
    //         prev = i;
    //         cnt +=1;
    //     }
    //     if(i==n-1 and dist<d) return false; 
    // }
    // return true;
}

int main(){
    cin>>n>>k;
    stalls.resize(n);

    for(int i=0; i<n; i++){
        cin>>stalls[i];
    }

    int l = 0, r = 1e9;

    while(l+1<r){
        int m = l + (r-l)/2;
        if(good(m)) l = m;
        else r = m;
    }

    cout<<l<<endl;
}