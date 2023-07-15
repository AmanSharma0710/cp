#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            count++;
        }
    }
    int ans = 0;
    for(int i=0; i<count; i++){
        ans+= a[i]!=0;
    }
    cout<<ans<<endl;
    return 0;
}