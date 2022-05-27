// InvertBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <iostream>
#include <memory>
#include <queue>
#include <string>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    void swapChildren(TreeNode* aRoot)
    {
        TreeNode* temp = aRoot->left;
        aRoot->left = aRoot->right;
        aRoot->right = temp;
    }

    // 226. Invert Binary Tree (Easy)

    TreeNode* invertByQueue(TreeNode* aRoot)
    {
        std::queue<TreeNode*> myQueue;
        myQueue.push(aRoot);

        while (!myQueue.empty())
        {
            TreeNode* current = myQueue.front();
            myQueue.pop();

            swapChildren(current);

            if (current->left)
            {
                myQueue.push(current->left);
            }
            if (current->right)
            {
                myQueue.push(current->right);
            }
        }

        return aRoot;
    }

    TreeNode* invertByRecursive(TreeNode* aRoot)
    {
        swapChildren(aRoot);

        if (aRoot->left)
        {
            invertByRecursive(aRoot->left);
        }
        if (aRoot->right)
        {
            invertByRecursive(aRoot->right);
        }

        return aRoot;
    }

    void TestInvertBinaryTree()
    {
        /*************************
        Input:

             4
           /   \
          2     7
         / \   / \
        1   3 6   9
        Output:

             4
           /   \
          7     2
         / \   / \
        9   6 3   1
        *************************/


        string inputBst = "[4,2,7,1,3,6,9]";
        std::cout << "\n226. Invert Binary Tree (Easy) for: " << inputBst << endl;


        TreeNode* root = LeetCodeUtil::BuildTreeFromLevelOrderString(inputBst);

        root = invertByQueue(root);
        LeetCodeUtil::PrintTreeLevelOrder(root);

        cout << endl;

        root = invertByRecursive(root);
        LeetCodeUtil::PrintTreeLevelOrder(root);
        cout << endl;
    }
}
