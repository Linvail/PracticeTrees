// SymmetricTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <iostream>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    // 101. Symmetric Tree (Easy)
    class Solution101
    {
    public:
        static bool isSymmetric(TreeNode* root)
        {
            if (!root)
            {
                return true;
            }

            return isMirror(root->left, root->right);
        }

        static bool isMirror(TreeNode* aLeft, TreeNode* aRight)
        {
            if (!aLeft && !aRight)
            {
                return true;
            }

            return aLeft && aRight && aLeft->val == aRight->val && isMirror(aLeft->left, aRight->right) && isMirror(aLeft->right, aRight->left);
        }
    };

    void TestSymmetricTree()
    {
        cout << "\n101. Symmetric Tree (Easy)\n";

        vector<string> arr = { "1", "2", "2", "3", "4", "4", "3" };
        TreeNode* node = LeetCodeUtil::BuildTreeFromLevelOrderStringVector(arr);

        std::cout << "SymmetricTree: " << Solution101::isSymmetric(node) << endl;

        LeetCodeUtil::DeleteTree(node);
    }

}