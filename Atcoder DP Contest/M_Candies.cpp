#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(k+1, 0), temp(k+1, 0);
    v[0] = 1;
    for(int i=0; i<n; i++){
        int max_candies_i;
        cin>>max_candies_i;
        long long sum = 0;
        for(int j=0; j<=k; j++){
            sum += v[j];
            if(j-max_candies_i-1>=0){
                sum -= v[j-max_candies_i-1];
            }
            temp[j] = sum%1000000007;
        }
        v = temp;
    }
    cout<<v[k]<<endl;
}