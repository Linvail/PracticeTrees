// ConvertSortedArraytoBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <iostream>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    // 108. Convert Sorted Array to Binary Search Tree (Easy)
    class Solution108
    {
    public:
        static TreeNode* sortedArrayToBST(vector<int>& nums)
        {
            const int length = nums.size();
            if (length < 1)
            {
                return nullptr;
            }

            return buildTree(nums, 0, length - 1);
        }

        inline static TreeNode* buildTree(const vector<int>& nums, int aStart, int aEnd)
        {
            // If length is even, get the 2nd.
            int middle = ( aStart + aEnd ) / 2;

            TreeNode* newNode = new TreeNode(nums[middle]);

            if (aStart <= middle - 1)
            {
                TreeNode* nodeLeft = buildTree(nums, aStart, middle - 1);
                newNode->left = nodeLeft;
            }

            if (middle + 1 <= aEnd)
            {
                TreeNode* nodeRight = buildTree(nums, middle + 1, aEnd);
                newNode->right = nodeRight;
            }

            return newNode;
        }

    };

    void TestConvertSortedArraytoBinarySearchTree()
    {
        cout << "\n108. Convert Sorted Array to Binary Search Tree (Easy) from: ";
        vector<int> arr = { -10, -3, 0, 5, 9 };
        LeetCodeUtil::PrintVector(arr);
        cout << endl;

        TreeNode* node = Solution108::sortedArrayToBST(arr);

        LeetCodeUtil::PrintTreeLevelOrder(node);
        LeetCodeUtil::DeleteTree(node);
    }

}
