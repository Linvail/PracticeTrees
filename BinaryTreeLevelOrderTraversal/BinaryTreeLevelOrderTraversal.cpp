// BinaryTreeLevelOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\Common\Common.h"

using namespace std;
using namespace Trees;

class Solution
{
public:
    static vector<vector<int>> levelOrder( TreeNode* root )
    {
        vector<vector<int>> result;

        std::queue<TreeNode*> q;
        if( root )
        {
            q.push( root );
            q.push( nullptr );

            result.emplace_back();
        }

        while( !q.empty() )
        {
            TreeNode* current = q.front();
            q.pop();

            if( current == nullptr )
            {
                continue;
            }

            result.back().push_back( current->val );
           
            if( current->left != nullptr )
            {
                q.push( current->left );
            }
            if( current->right != nullptr )
            {
                q.push( current->right );
            }

            // Check next item in queue.
            if( q.front() == nullptr )
            {
                q.pop();

                if( q.size() > 0 )
                {
                    result.emplace_back();
                }

                q.push( nullptr );
            }
        }

        return result;
    }

    static vector<vector<int>> levelOrder2( TreeNode* root )
    {
        vector<vector<int>> result;

        if( !root )
        {
            return result;
        }

        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() )
        {
            int size = q.size();
            vector<int>v;
            for( int i = 0; i < size; i++ )
            {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back( temp->val );

                if( temp->left )
                {
                    q.push( temp->left );
                }
                if( temp->right )
                {
                    q.push( temp->right );
                }

            }
            result.push_back( v );
        }

        return result;
    }
};

int main()
{
    vector<string> arr = { "3", "9", "20", "null", "null", "15", "7" };
    //vector<string> arr = { "1", "2", "3", "4", "5" };
    //vector<string> arr = { "1", "2" };
    TreeNode* node = levelOrderCreateTree( arr );

    Solution::levelOrder2( node );
}

