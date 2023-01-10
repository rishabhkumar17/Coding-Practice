bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;

    if (!(root->left) && !(root->right) && root->val == targetSum)
        return true;

    return (root->left && hasPathSum(root->left, targetSum - (root->val))) ||
           (root->right && hasPathSum(root->right, targetSum - (root->val)));
}