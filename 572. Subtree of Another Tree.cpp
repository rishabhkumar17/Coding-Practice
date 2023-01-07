class Solution
{
private:
    vector<TreeNode *> nodes;
    int getDepth(TreeNode *root, int d)
    {
        if (!root)
            return -1;

        int depth = max(getDepth(root->left, d), getDepth(root->right, d)) + 1;

        if (depth == d)
            nodes.push_back(root);

        return depth;
    }

    bool isIdentical(TreeNode *root, TreeNode *subRoot)
    {
        if (!root || !subRoot)
            return root == subRoot;

        return (root->val == subRoot->val) &&
               isIdentical(root->left, subRoot->left) &&
               isIdentical(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;

        getDepth(root, getDepth(subRoot, -1));

        for (TreeNode *n : nodes)
        {
            if (isIdentical(n, subRoot))
            {
                return true;
            }
        }
        return false;
    }
};