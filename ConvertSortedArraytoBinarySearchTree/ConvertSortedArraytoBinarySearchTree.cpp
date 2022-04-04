// ConvertSortedArraytoBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\Common\Common.h"

using namespace std;
using namespace Trees;

class Solution
{
public:
    static TreeNode* sortedArrayToBST( vector<int>& nums )
    {
        const int length = nums.size();
        if( length < 1 )
        {
            return nullptr;
        }

        return buildTree( nums, 0, length - 1 );        
    }

    inline static TreeNode* buildTree( const vector<int>& nums, int aStart, int aEnd )
    {
        // If length is even, get the 2nd.
        int middle = ( aStart + aEnd ) / 2;

        TreeNode* newNode = new TreeNode( nums[middle] );

        if( aStart <= middle - 1 )
        {
            TreeNode* nodeLeft = buildTree( nums, aStart, middle - 1 );
            newNode->left = nodeLeft;
        }

        if( middle + 1 <= aEnd )
        {
            TreeNode* nodeRight = buildTree( nums, middle + 1, aEnd );
            newNode->right = nodeRight;
        }               

        return newNode;
    }

};

int main()
{
    vector<int> arr = { -10, -3, 0, 5, 9 };

    TreeNode* node = Solution::sortedArrayToBST( arr );

    std::cout << "ConvertSortedArraytoBinarySearchTree\n";

    printLevelOrder( node );

    cleanUp( node );
}

