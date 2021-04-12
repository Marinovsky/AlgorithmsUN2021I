#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(Node tree[], int i) {
  if(i==-1){
    return true;
  }else{
     bool a,b,c,d;
    // Check the left subtree of the node i
     a=IsBinarySearchTree(tree, tree[i].left);
     // Check if the node i is bigger than the bigger node of his left subtree
     if(tree[i].left!=-1){
        // If the node i has a left child
        if(tree[tree[i].left].right==-1){
            // If the right node of the left node doesn't exist
            b=((tree[tree[i].left].key)<(tree[i].key));
        }else{
            // If the right node of the left node exist
            b=(tree[tree[tree[i].left].right].key)<tree[i].key;
        }
     }else{
        // If the node i doesn't have a left node
        b=true;
     }
     // Check the right subtree of the node i
     c=IsBinarySearchTree(tree, tree[i].right);
     // Check if i is less than the less node of the right subtree
     if(tree[i].right!=-1){
        // If the node i has a right child
        if(tree[tree[i].right].left==-1){
            // If the left node of the right child of the node i doesn't exist
            d=(tree[tree[i].right].key)>=(tree[i].key);
        }else{
            // If the left node of the right child of the node i exist
            d=(tree[tree[tree[i].right].left].key)>=(tree[i].key);
        }
     }else{
         // If the node i doesn't have a right child
        d=true;
     }
     return ((a&&b)&&(c&&d));
  }
}

int main() {
 unsigned int nodes;
 cin >> nodes;
 if(nodes==0){
    cout<<"CORRECT"<<endl;
    return 0;
 }
 Node tree[nodes];
  for (unsigned int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree[i]=(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree, 0)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

