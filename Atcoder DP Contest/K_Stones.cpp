#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> dp;
int main(){
    int n, k;
    cin>>n>>k;
    a.resize(n);
    dp.assign(k+1, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 
    for(int i=1; i<=k; i++){
        bool win = false;
        for(int j=0; j<n; j++){
            if(i-a[j]<0) continue;
            if(dp[i-a[j]]==0){
                win = true;
            }
        }
        if(win) dp[i] = 1;
        else dp[i] = 0;
    }
    cout<<(dp[k]?"First":"Second")<<endl;
    return 0;
}