#include<iostream>
#include<vector>
using namespace std;

/*
* Given Inorder + Preorder Traversal.
* Construct Binary Tree.
* Print Post Order Traversal
* Complexity : O(N2) since 
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
void inorder(TreeNode* root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if (root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

TreeNode* construct_bt_util(vector<int>& inorder, vector<int>& preorder, int in_start, int in_end, int& pre_index){
    // Base Condition
    if (in_start > in_end){
        return NULL;
    }

    // First Construct the Root Node
    TreeNode *root = new TreeNode(preorder[pre_index]);
    pre_index++;

    // Now search for the root node in Inorder Vector and get the index.
    int index = in_start;
    for (int i = in_start; i <= in_end; ++i){
        if (inorder[i] == root->data){
            index = i;
            break;
        }
    }

    // Now subdivide the problem into further.
    root->left = construct_bt_util(inorder, preorder, in_start, index - 1, pre_index);
    root->right = construct_bt_util(inorder, preorder, index + 1, in_end, pre_index);
    
	return root;
}

TreeNode* construct_bt(vector<int> inorder, vector<int> preorder){
    int pre_index = 0;
    return construct_bt_util(inorder, preorder, 0, inorder.size() - 1, pre_index);
}



int main()
{
    TreeNode *root = construct_bt({ 3, 1, 4, 0, 5, 2 }, { 0, 1, 3, 4, 2, 5 });

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;

    system("pause");
    return 0;
}

/* Home Work
 *1. Make the solution as O(N) by implementing the hashing instead of searching using for loop
 *2. Do one more solutin using post order traversal too.
*/
