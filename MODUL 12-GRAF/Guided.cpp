#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TNode *node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node -> data << " ";
        inorder(node->right);
    }
}

void postorder(TNode *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        cout << node -> data << " ";
    }
}

int main(){
    TNode *zero = new TNode(0);
    //0
    // /\
    //NULL NULL
    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    //7
    // /\
    // 1 NULL
    seven->right = nine;
    //7
    // /\
    //19
    one->left = zero;
    //7
    // /\
    //1 9
    // /\
    // 0  NULL
    one->right = five;
    //7
    // /\
    //1 9
    // /\
    // 0 5
    nine->left = eight;
    //7
    // /\
    //1 9
    // /\ /\
    // 058  NULL
    preorder(seven);
    cout << endl;
    inorder(seven);
    cout << endl;
    postorder(seven);
    cout << endl;

    return 0;
}
