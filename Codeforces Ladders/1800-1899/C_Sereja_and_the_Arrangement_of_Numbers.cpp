#include<bits/stdc++.h>
using namespace std;

long long calc(long long limit, long long sup)
{
	long long inf = 1;
	while(inf < sup)
	{
		long long mid((inf + sup + 1) >> 1);
        long long temp = (mid * (mid - 1) >> 1);
        if((mid&1)^1){
            temp += (mid>>1) - 1;
        }
        if(temp <= limit)
            inf = mid;
        else
            sup = mid - 1;
	}
	return inf;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin>>n>>m;
    int ans = calc(n-1, m);
    vector<int> v(m);
    for(int i=0; i<m; i++) cin>>v[i]>>v[i];
    sort(v.begin(), v.end(), greater<int>());
    long long sum = 0;
    for(int i=0; i<ans; i++){
        sum += v[i];
    }
    cout<<sum<<endl;
    return 0;
}
