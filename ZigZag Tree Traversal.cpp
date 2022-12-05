/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
*/
class BinaryTreeZigzagLevelOrderTraversal
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            flag = !flag;
            if (flag == false)
            {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};