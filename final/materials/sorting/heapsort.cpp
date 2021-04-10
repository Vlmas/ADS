#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return (2*i+1);
}

int right(int i) {
    return (2*i+2);
}

void siftDown(vector<int>& a,int n,int i) {
    int j=i;

    if(left(i)<n && a[left(i)]>a[i]) {
        j=left(i);
    }
    if(right(i)<n && a[right(i)]>a[j]) {
        j=right(i);
    }

    if(j!=i) {
        swap(a[i],a[j]);
        siftDown(a,n,j);
    }
}

void heapSort(vector<int>& a) {
    for(int i=(a.size()/2)-1;i>=0;i--) {
        siftDown(a,a.size(),i);
    }

    for(int i=a.size()-1;i>0;i--) {
        swap(a[0],a[i]);
        siftDown(a,i,0);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    heapSort(v);

    for(auto &i : v) {
        cout<<i<<" ";
    }


    return 0;
}