#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n;
    cin >> k;
    vector <int > v;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    int count = 0;
    for(int i=0,j=i+1;i<v.size()-1;i++,j++) {
        if(v[i] + v[j] >= k) count++;
    }
    if(count != 0) cout << n-count-1 << endl;
    else cout << n <<endl;
}