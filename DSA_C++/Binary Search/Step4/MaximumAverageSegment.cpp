#include <bits/stdc++.h>
using namespace std;

int n, d, start = 0, finish = 0;
vector<int> a;
bool good(double x){

    vector<double> prev_msum(n);
    vector<double> prev_sum(n);
    vector<int> idx(n);

    prev_msum[0] = a[0] - x;
    prev_sum[0] = a[0] - x;
    idx[0] = 0;

    for(int i=1; i<n; i++){
        prev_sum[i] = prev_sum[i-1] + a[i] - x;
        if(prev_msum[i-1]>prev_sum[i]){
            prev_msum[i] = prev_sum[i];
            idx[i] = i;
        } else{
            prev_msum[i] = prev_msum[i-1];
            idx[i] = idx[i-1];
        }
    }
    for(int i=n-1; i+1-d>=0; i--){
        if(i+1-d >= 0 && prev_sum[i]>=0){
            start = 0, finish = i;
            return true;
        } 
        if(prev_sum[i]>=prev_msum[i-d] && i-d>=0){
            start = idx[i-d] + 1, finish = i;
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n>>d;
    a.resize(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    double l = 0, r = 110;

    for(int i=0; i<110; i++){
        double m = l + (r - l)/2;
        if(good(m)) l = m;
        else r = m;
    }

    cout<<start+1<<" "<<finish+1<<endl;
}