#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b){
    return a + (rand() % (b-a+1));
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int t = rand(1, 10);
    cout<<t<<endl;
    while(t--){
        int n = rand(2, 10);
        cout<<n<<endl;
        for(int i=0; i<n; i++){
            cout<<rand(1, n)<<" ";
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<<rand(1, n)<<" ";
        }
        cout<<endl;
    }
    return 0;
}