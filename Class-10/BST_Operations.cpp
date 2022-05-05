/*
 * This program is to give demo about Binary Search Tree Data Structures.
 */

#include<iostream>
using namespace std;

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

/*
 * This function is to insert into the elements in BST
 * T.C :
 * S.C :
*/
TreeNode* insert(TreeNode* root, int value){
	if (root == NULL){ 
		return new TreeNode(value);
	}

	if (value < root->data){
		root->left = insert(root->left, value);
	}
	else{
		root->right = insert(root->right, value);
	}
	return root;
}

/*
 * This function is to do a inorder traversal of a Binary Search Tree
 * T.C :
 * S.C :
 */
void inorder(TreeNode* root){
	if (root == NULL)
		return ;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

/*
 *This function is to search recussively and return element found or not
 * T.C :O(Height)
 * S.C :O(Height)
 */
bool search_rec_bst(TreeNode* root, int value){
	if (root == NULL)
		return false;

	if (root->data == value){
		return true;
	}
	
	if (value < root->data){
		return search_rec_bst(root->left, value);
	}
	else{
		return search_rec_bst(root->right, value);
	}
}

/*
*This function is to search iteratively ( NO RECURSION) and return element found or not
* T.C :O(Height)
* S.C :O(1)
*/
bool search_iter_bst(TreeNode* root, int value){
	while (root != NULL){
		if (root->data == value){
			return true;
		}
		if (value < root->data)
			root = root->left;
		else
			root = root->right;
	} // end of while
	return false;
}

int get_smallest(TreeNode *root){
    while (root->left != NULL){
        root = root->left;
    }
    return root->data;
}

TreeNode *delete_node(TreeNode *root, int val){
    // Base Case
    if (root == NULL){
        return NULL;
    }

    if (root->data == val){
        // If no child is present : scrap off the branch
        if (root->left == NULL && root->right == NULL){
            return NULL;
        }
        
        //If a single child is present : just return the non child node
        if (root->left == NULL){
            return root->right;
        }
        if (root->right == NULL){
            return root->left;
        }

        //If two childs are present : Replace the node with its inorder successor and delete the inorder successor
        int inorder_successor_value = get_smallest(root->right);
        root->data = inorder_successor_value;
        root->right = delete_node(root->right, inorder_successor_value);
    }
    else if (val < root->data){
        root->left =  delete_node(root->left, val);
    }
    else{
        root->right =  delete_node(root->right, val);
    }

    return root;
}

int main(){
	cout << "Tree-1 Hard Coded" << endl;
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);
	inorder(root);
	cout << endl;
	cout << "Search-1 using Recursion" << endl;
	cout << search_rec_bst(root, 4) << endl;
	cout << search_rec_bst(root, 10) << endl;
	cout << search_rec_bst(root, 7) << endl;

	cout << "Search-2 using Iteration" << endl;
	cout << search_iter_bst(root, 4) << endl;
	cout << search_iter_bst(root, 10) << endl;
	cout << search_iter_bst(root, 7) << endl;

	cout << "Tree-2 Using Insert Function" << endl;
	root = insert(NULL, 50);
	root = insert(root, 30);
	root = insert(root, 70);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);
	inorder(root);
	cout << endl;

    cout << "Delete Operations :" << endl;
    root = delete_node(root, 20);
    inorder(root);
    cout << endl;

    root = delete_node(root, 30);
    inorder(root);
    cout << endl;

    root = delete_node(root, 50);
    inorder(root);
    cout << endl;

	system("pause");
}