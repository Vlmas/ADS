#include<iostream>

using namespace std;

template<typename T>
struct Node {
    Node<T>* next;
    T _data;

    Node(T _data) {
        this->_data=_data;
    }
}; 

template<typename T>
class Queue {
    private:
    Node<T>* _front;
    Node<T>* _back;
    int _sz;

    public:
    Queue() {
        _front=NULL;
        _back=NULL;
        _sz=0;
    }

    void push(T _data) {
        Node<T>* node=new Node<T>(_data);

        if(_front==NULL) {
            _front=node;
            _back=node;
        } else {
            _back->next=node;
            _back=node;
        }
        _sz++;
    } 

    void pop() {
        if(this->_front!=NULL) {
            Node<T>* tmp=_front;
            _front=_front->next;

            if(_front==NULL) {
                _back=NULL;
            }

            delete tmp;
            _sz--;
        }
    }

    T front() {
        return this->_front->_data;
    }

    int size() {
        return this->_sz;
    }

    bool empty() {
        return (this->_sz==0);
    }
};

int main() {}