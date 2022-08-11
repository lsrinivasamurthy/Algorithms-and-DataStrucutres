#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int linear_path_sum(TreeNode *root, int &result){
    if (root == NULL){
        return 0;
    }
    int left_sum = linear_path_sum(root->left, result);
    int right_sum = linear_path_sum(root->right, result);

    result = max(result, max(0, left_sum) + max(0, right_sum) + root->data);

    return max({ root->data,
        left_sum + root->data,
        right_sum + root->data });
}

int max_path_sum(TreeNode *root){
    int result = INT_MIN;
    linear_path_sum(root, result);
    return result;
}
 
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << max_path_sum(root)<<endl;

    root = new TreeNode(-10);
    root->left = new TreeNode(-20);
    root->right = new TreeNode(-30);
    cout << max_path_sum(root)<<endl;

    system("pause");
    return 0;
}