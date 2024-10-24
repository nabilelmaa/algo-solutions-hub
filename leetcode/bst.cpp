#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BST
{
public:
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            if (val > root->val)
            {
                root->right = insert(root->right, val);
            }
        }
        return root;
    }

    bool search(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (val == root->val)
        {
            return true;
        }

        if (val < root->val)
        {
            return search(root->left, val);
        }
        else
        {
            return search(root->right, val);
        }
    }
};

int main()
{
    BST tree;
    TreeNode *root = nullptr;

    root = tree.insert(root, 1);
    root = tree.insert(root, 2);
    root = tree.insert(root, 3);
    root = tree.insert(root, 4);
    root = tree.insert(root, 5);

    if (tree.search(root, 9))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "NOT Found!" << endl;
    }

    return 0;
}