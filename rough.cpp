#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> v(n);
        for(auto &i:v){
            cin>>i;
        }
        vector<int> v1;
        for(int i=0; i<33; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(v[j]&(1ll<<i)){
                    count++;
                }
            }
            v1.push_back(count);
        }
        int gcd = v1[0];
        for(int i=0; i<33; i++){
            gcd = __gcd(gcd, v1[i]);
        }
        int factors = 0;
        for(int i=1; i<=gcd; i++){
            if(gcd%i==0){
                factors++;
            }
        }
        cout<<factors<<endl;
    }
}