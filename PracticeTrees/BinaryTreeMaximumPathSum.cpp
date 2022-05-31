#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <iostream>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    class Solution124
    {
    public:
        int maxPathSum_helper(TreeNode* root, int& maxPath)
        {
            if (!root)
            {
                return 0;
            }

            // The path of left/right might be negative. If they are, we shouldn't
            // consider them. They won't affect the maxPath and we should add them
            // in the returning value because we are allowed to return root only.
            int maxPathLeft = max(0, maxPathSum_helper(root->left, maxPath));
            int maxPathRight = max(0, maxPathSum_helper(root->right, maxPath));

            maxPath = max(maxPath, maxPathLeft + root->val + maxPathRight);

            return maxPathLeft > maxPathRight ? root->val + maxPathLeft : root->val + maxPathRight;
        }

        int maxPathSum(TreeNode* root)
        {
            // This is a hard question.
            // We still need to do recursion from root down to leaf but the
            // difficult part is what to do when we returning back.
            // During the recursion, we must track the max path all the way.
            // We must consider:
            // a. max path of left subtree + root's value + max path right subtree.
            // b. But when returning to parent, the max path must choose the greater
            //    one from left/right.
            int maxPath = INT_MIN;

            maxPathSum_helper(root, maxPath);

            return maxPath;
        }
    };

    void TestBinaryTreeMaximumPathSum()
    {
        // 124. Binary Tree Maximum Path Sum (Hard)
        // Input: root = [-10,9,20,null,null,15,7]
        // Output: 42
        //
        //            -10
        //            /  \
        //           /    \
        //          9      20
        //                 / \
        //                /   \
        //               15    7
        //
        // Input: root = [1,2,3]
        // Output: 6
        // Input: root = [2,-1]
        // Output: 2

        Solution124 sol124;
        TreeNode* root = BuildTreeFromLevelOrderString("[2,-1]");
        cout << "\nResult of Binary Tree Maximum Path Sum: " << sol124.maxPathSum(root) << endl;
    }
}