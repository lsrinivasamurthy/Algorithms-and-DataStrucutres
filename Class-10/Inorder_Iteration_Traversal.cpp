#include<iostream>
#include<stack>
using namespace std;

/* 
 *Recusrison is nothing but a stack of calls.
 *Here we are not supposed to use Recursion, so use the data structure iteratively. so that the reason we use Stack.
 * T.C : O(N)
 * S.C : O(N)
*/
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void push_left(TreeNode* current, stack<TreeNode*>& s){
    while (current != NULL){
        s.push(current);
        current = current->left;
    }
}

void inorder_iterative(TreeNode* root){
    stack<TreeNode*> s;
    
    // Initialize the inorder traversal on the root node
    push_left(root,s);

    while (!s.empty()){
        TreeNode* current = s.top();
        s.pop();
        cout << current->data << " ";
        // Now Traverse towards Right half 
        push_left(current->right, s);
    }
    cout << endl;
}

void inorder_recursion(TreeNode* root){
    if (root == NULL){
        return;
    }
    
    inorder_recursion(root->left);
    cout << root->data << " ";
    inorder_recursion(root->right);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Inorder Traversal using Recursion : " << endl;
    inorder_recursion(root);
    cout << endl;

    cout << "Inorder Traversal using Iteration : " << endl;
    inorder_iterative(root);
    cout << endl;

    system("pause");
    return 0;
}

/*
 *Home Work :
 *Iterative Post Order
 *Iterative In Order
*/