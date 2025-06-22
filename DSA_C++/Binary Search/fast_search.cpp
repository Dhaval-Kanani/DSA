#include <bits/stdc++.h>
using namespace std;

int closest_to_left(int num, vector<int>& a){
    int l = -1, r = a.size();
    while(l+1<r){
        int m = (l+r)/2;

        if(a[m]<num){
            l = m;
        } else r = m;
    }
    return l+1;
}

int closest_to_right(int num, vector<int>& a){
    int l = -1, r = a.size();
    while(l+1<r){
        int m = (l+r)/2;

        if(a[m]<=num){
            l = m;
        } else r = m;
    }
    return r+1;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    // for(auto x:a)cout<<x<<" "; cout<<"\n";

    cin>>k;

    for(int i=0; i<k; i++){
        int l,r;
        cin>>l>>r;

        int left = closest_to_left(l, a);
        int right = closest_to_right(r, a);

        // cout<<left<<" "<<right<<"\n";
        
        int count = right - left -1;
        // if(a[right-1]==r) count++;
        // if(a[left-1]==l) count++;
        cout<<count<<"\n";
    }

    return 0;
}