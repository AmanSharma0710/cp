#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> A(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin>>A[i][0]>>A[i][1];
    }
    sort(A.begin(), A.end());
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        vector<int> B = {x, y};
        cout<<binary_search(A.begin(), A.end(), B)<<endl;
    }
    return 0;
}