// ValidateBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <iostream>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    // 98. Validate Binary Search Tree (Medium)
    class Solution98
    {
    public:

        Solution98() : lastNode(nullptr) {}

        TreeNode* lastNode;

        //! traverse in order.
        bool isValidBST(TreeNode* root)
        {
            if (!root)
            {
                return true;
            }

            // We know that we can get a sort list if we traverse the tree by 'in-order'.
            if (!isValidBST(root->left))
            {
                return false;
            }

            if (nullptr != lastNode && lastNode->val >= root->val)
            {
                return false;
            }

            lastNode = root;

            if (!isValidBST(root->right))
            {
                return false;
            }

            return true;
        }

        //! min-max approach.
        bool isValidBST_v2(TreeNode* root)
        {
            if (!root)
            {
                return true;
            }

            return isValidBST_minMax(root, static_cast<long long>( INT_MIN ) - 1, static_cast<long long>( INT_MAX ) + 1);
        }

        bool isValidBST_minMax(TreeNode* root, long long aMin, long long aMax)
        {
            bool valid = root->left == nullptr;
            if (root->left)
            {
                valid = root->left->val < root->val&& root->left->val < aMax&& root->left->val > aMin&&
                    isValidBST_minMax(root->left, aMin, root->val);
            }
            if (valid && root->right)
            {
                valid = root->right->val > root->val && root->right->val < aMax&& root->right->val > aMin &&
                    isValidBST_minMax(root->right, root->val, aMax);
            }

            return valid;
        }
    };

    void TestValidateBinarySearchTree()
    {
        cout << "\n98. Validate Binary Search Tree (Medium) for: ";

        vector<string> arr = { "2","1","3","null","4","null","7" };
        //vector<string> arr = { "5", "1", "4", "null", "null", "3", "6" };
        //vector<string> arr = { "5", "4", "6", "null", "null", "3", "7" };
        //vector<string> arr = { "2", "1", "3" };
        //vector<string> arr = { "-2147483648", "null", "2147483647" };
        //vector<string> arr = { "0", "-1" };

        TreeNode* node = LeetCodeUtil::BuildTreeFromLevelOrderStringVector(arr);
        LeetCodeUtil::PrintTreeLevelOrder(node);

        Solution98 sol98;

        cout << "Result: " << sol98.isValidBST_v2(node) << endl;
        LeetCodeUtil::DeleteTree(node);
    }
}

