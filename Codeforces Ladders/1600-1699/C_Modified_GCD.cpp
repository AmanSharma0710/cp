#include<bits/stdc++.h>
using namespace std;



int main(){
    int a, b;
    cin>>a>>b;
    int n = gcd(a, b);
    vector<int> factors;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            factors.push_back(i);
            if(i*i!=n) factors.push_back(n/i);
        }
    }
    sort(factors.begin(), factors.end());
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        int index = upper_bound(factors.begin(), factors.end(), r) - factors.begin();
        if(index==0) cout<<-1<<endl;
        else{
            if(factors[index-1]>=l) cout<<factors[index-1]<<endl;
            else cout<<-1<<endl;
        }
    }
}