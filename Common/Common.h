#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

namespace Trees
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) {}
		TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
		TreeNode( int x, TreeNode* left, TreeNode* right ) : val( x ), left( left ), right( right ) {}		
	};

	// Function to print tree nodes in
	// InOrder fashion
	void printInOrder( TreeNode* root )
	{
		if( root != nullptr )
		{
			printInOrder( root->left );
			cout << root->val << " ";
			printInOrder( root->right );
		}
	}

	void printLevelOrder( TreeNode* root )
	{
		std::queue<TreeNode*> q;
		q.push( root );                     
												
		while( !q.empty() )
		{                     

			TreeNode* current = q.front();      
			q.pop();
			std::cout << current->val << " ";   

			if( current->left != nullptr )
			{
				q.push( current->left );
			}
			if( current->right != nullptr )
			{
				q.push( current->right );
			}
		}
		cout << endl;
	}

	void cleanUp( TreeNode* root )
	{
		if( root )
		{
			cleanUp( root->left );
			cleanUp( root->right );
		}
		delete root;
	}

	void createTree( TreeNode* node, int i, vector<string>& arr )
	{
		if( node != nullptr )
		{
			if( 2 * i + 1 < arr.size() )
			{
				if( arr[2 * i + 1] == "null" )
					node->left = nullptr;
				else
					node->left = new TreeNode( stoi( arr[2 * i + 1] ) );

				createTree( node->left, 2 * i + 1, arr );
			}


			if( 2 * i + 2 < arr.size() ) {
				if( arr[2 * i + 2] == "null" )
					node->right = nullptr;
				else
					node->right = new TreeNode( stoi( arr[2 * i + 2] ) );

				createTree( node->right, 2 * i + 2, arr );
			}
		}
	}


	TreeNode* levelOrderCreateTree( vector<string>& arr )
	{
		if( arr.size() == 0 )
			return nullptr;

		TreeNode* head = new TreeNode( stoi( arr[0] ) );
		createTree( head, 0, arr );
		return head;
	}
}