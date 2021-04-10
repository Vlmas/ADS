#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinHeap {
    public:

    vector<int> a;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return 2*i+1;
    }

    int right(int i) {
        return 2*i+2;
    }

    int getMin() {
        return a[0];
    }

    void siftUp(int i) {
        while(i>0 && a[parent(i)]>a[i]) {
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }
    }

    void insert(int k) {
        a.push_back(k);
        int i=a.size()-1;

        siftUp(i);
    }

    void heapify(int i) {
        if(a.size()-1<left(i)) {
            return;
        }

        int j=left(i);

        if(right(i)<a.size() && a[left(i)]>a[right(i)]) {
            j=right(i);
        }
        if(a[i]>a[j]) {
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root=getMin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0) {
            heapify(0); 
        }

        return root;
    }

    void increaseValue(int i,int new_val) {
        a[i]=new_val;
        heapify(i);
    }

    void decreaseValue(int i,int new_val) {
        a[i]=new_val;

        siftUp(i);
    }

    void heapSort(int n) {
        for(int i=0;i<n;i++) {
            cout<<extractMin()<<" ";
            for(int j=0;j<a.size();j++) {
                cout<<a[j]<<" ";
            }
            cout<<"\n";
        }
    }
};

int main() {
    int n,x;
    cin>>n;

    MinHeap* heap=new MinHeap();

    for(int i=0;i<n;i++) {
        cin>>x;
        heap->insert(x);
    }

    heap->heapSort(n);

    for(int i=0;i<heap->a.size();i++) {
        cout<<heap->a[i]<<" ";
    }


    return 0;
}