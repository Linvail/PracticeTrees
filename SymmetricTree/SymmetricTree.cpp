// SymmetricTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "..\Common\Common.h"

using namespace std;
using namespace Trees;

class Solution
{
public:
    static bool isSymmetric( TreeNode* root )
    {
        if( !root )
        {
            return true;
        }

        return isMirror( root->left, root->right );
    }

    static bool isMirror( TreeNode* aLeft, TreeNode* aRight )
    {
        if( !aLeft && !aRight )
        {
            return true;
        }

        return aLeft && aRight && aLeft->val == aRight->val && isMirror( aLeft->left, aRight->right ) && isMirror( aLeft->right, aRight->left );
    }
};


int main()
{
    vector<string> arr = { "1", "2", "2", "3", "4", "4", "3" };
    TreeNode* node = levelOrderCreateTree( arr );

    std::cout << "SymmetricTree: " << Solution::isSymmetric( node ) << endl;
}
