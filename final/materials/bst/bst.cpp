#include<iostream>
#include<algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class BinarySearchTree {
    public:
    Node* root;

    BinarySearchTree() {
        root=NULL;
    }

    Node* insert(Node* node,int data) {
        if(node==NULL) {
            node=new Node(data);
            return node;
        }

        if(data<node->data) {
            node->left=insert(node->left,data);
        }
        else if(data>node->data) {
            node->right=insert(node->right,data);
        }

        return node;
    }

    void inOrder(Node* node) {
        if(node==NULL) {
            return;
        }

        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if(node==NULL) {
            return;
        }

        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if(node==NULL) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<" ";
    }

    Node* findMin(Node* node) {
        while(node->left!=NULL) {
            node=node->left;
        }

        return node;
    }

    Node* findMax(Node* node) {
        while(node->right!=NULL) {
            node=node->right;
        }

        return node;
    }

    Node* deleteNode(Node* node,int data) {
        if(node==NULL) {
            return node;
        }

        if(data<node->data) {
            node->left=deleteNode(node->left,data);
        }
        else if(data>node->data) {
            node->right=deleteNode(node->right,data);
        } else {
            if(node->right==NULL && node->left==NULL) {
                return NULL;
            }
            else if(node->left==NULL) {
                node=node->right;
            }
            else if(node->right==NULL) {
                node=node->left;
            } else {
                Node* tmp=findMin(node->right);
                node->data=tmp->data;
                node->right=deleteNode(node->right,tmp->data);
            }
        }

        return node;
    }

    int treeDepth(Node* node) {
        if(node==NULL) {
            return 0;
        }
        int left_trees_depths=treeDepth(node->left);
        int right_trees_depths=treeDepth(node->right);

        if(left_trees_depths>right_trees_depths) {
            return left_trees_depths+1;
        } else {
            return right_trees_depths+1;
        }
    }

    int numOfNodes(Node* node) {
        if(node==NULL) {
            return 0;
        }

        return numOfNodes(node->left)+numOfNodes(node->right)+1;
    }

    void printLeafs(Node* node) {
        if(node==NULL) {
            return;
        }

        printLeafs(node->left);
        if(node->right==NULL && node->left==NULL) {
            cout<<node->data<<" ";
        }
        printLeafs(node->right);
    }

    void printLastTree(Node* node) {
        if(node==NULL) {
            return;
        }

        printLastTree(node->left);
        if(node->left!=NULL && node->right!=NULL) {
            cout<<node->data<<" ";
        }
        printLastTree(node->right);
    }

    bool isBalanced(Node* node) {
        if(node==NULL) {
            return true;
        }

        if(abs(treeDepth(node->left)-treeDepth(node->right))<=1 && isBalanced(node->left) && isBalanced(node->right)) {
            return true;
        }

        return false;
    }
};

int main() {
    BinarySearchTree* bst=new BinarySearchTree();

    int n,t;
    cin>>n;

    while(n--) {
        cin>>t;
        bst->root=bst->insert(bst->root,t);
    }
    bst->inOrder(bst->root);


    return 0;
}