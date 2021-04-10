#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& v,int x) {
    int l=0;
    int r=v.size()-1;
    int m;

    while(l<=r) {
        m=(l+r)/2;
        // m=l+(r-l)/2;

        if(v[m]==x) {
            return m;
        }
        else if(v[m]>x) {
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return -1;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    cout<<binarySearch(v,m);

    return 0;
}