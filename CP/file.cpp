#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define int long long int

using namespace std;

signed main(){
    int q;
    cin>>q;
    while (q--) {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int b = k;
        int i=n-1,j=n-2;
        int sum=1,win=0;
        while(j>=0&&i>0){
            j=i-1;
            while(b>=0&&j>-1){
                b-=v[i]-v[j];
                j--;
            }
            if(j!=-1||(j==-1&&b<0)){
                b+=v[i]-v[j];
                j++;
            }
            if(i-j>sum){sum = i-j;win = i;}
            b+= ((v[i]-v[i-1])*(i-j));
            i--;
        }
        cout<<sum<<" "<<v[win]<<endl;
    }
    return 0;
}