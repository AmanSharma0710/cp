#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <priority_queue>

using namespace std;

namespace testinfra {

class Minwin
{
public:
  bool test()
  {
    int w, insz, expsz;
    cin >> w;
    cin >> insz;

    vector<int> in, exp;
    in.reserve(insz);
    for(int i = 0; i < insz; i ++) {
      in.push_back(0);
      cin >> in[i];
    }

    cin >> expsz;
    exp.reserve(expsz);
    for(int i = 0; i < expsz; i ++) {
      exp.push_back(0);
      cin >> exp[i];
    }

    vector<int> r = this->minWindow(in, w);
    if (r.size() != exp.size()) {
      return false;
    }
    for(int i = 0; i < r.size(); i ++) {
      if (r.at(i) != exp.at(i)) {
        return false;
      }
    }
    return true;
  }

  vector<int> minWindow(vector<int> const& a, int w) {
		priority_queue<int, vector<int>, greater<int>> pq;
        multiset<int> s;
        vector<int> res;
        int n = a.size();
        for(int i=0; i<w; i++){
            pq.push(a[i]);
        }
        res.push_back(pq.top());
        for(int i=w; i<n; i++){
            pq.push(a[i]);
            s.insert(a[i-w]);
            while(s.find(pq.top()) != s.end()){
                s.erase(s.find(pq.top()));
                pq.pop();
            }
            res.push_back(pq.top());
        }
        return res;
  }
};

}

using namespace testinfra;

int
main(int argc, char** argv)
{
  Minwin s;
  cout << boolalpha << s.test() << endl;
}