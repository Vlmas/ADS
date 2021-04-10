#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void quickSort(vector<int>& v,int l,int r) {
    int i=l;
    int j=r;
    int p=v[(l+r)/2];

    while(i<j) {
        while(v[i]<p) {
            i++;
        }
        while(v[j]>p) {
            j--;
        }

        if(i<=j) {
            swap(v[i++],v[j--]);
        }
    }

    if(l<j) {
        quickSort(v,l,j);
    }
    if(i<r) {
        quickSort(v,i,r);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    quickSort(v,0,v.size()-1);

    for(auto& i : v) {
        cout<<i<<" ";
    }


    return 0;
}