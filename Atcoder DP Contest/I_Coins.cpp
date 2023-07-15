#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    vector<double> v(n+1, 0), temp(n+1, 0);
    v[0] = 1;
    for(int i=0; i<n; i++){
        double heads = p[i], tails = 1-p[i];
        temp[0] = v[0]*tails;
        for(int j=1; j<=n; j++){
            temp[j] = v[j]*tails + v[j-1]*heads;
        }
        v = temp;
    }
    double ans = 0;
    for(int i=n/2+1; i<=n; i++){
        ans += v[i];
    }
    cout<< setprecision(10);
    cout<<ans<<endl;
    return 0;
}