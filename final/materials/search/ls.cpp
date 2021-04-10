#include<iostream>
#include<vector>

using namespace std;

void linearSearch(vector<int>& v,int m) {
    for(int i=0;i<v.size();i++) {
        if(v[i]==m) {
            cout<<"Found match at position "<<i+1;
            exit(0);
        }
    }
    cout<<"No such element..";
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    linearSearch(v,m);

    return 0;
}