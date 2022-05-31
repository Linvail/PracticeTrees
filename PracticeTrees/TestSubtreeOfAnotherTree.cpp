#include "PracticeTrees.h"
#include "LeetCodeUtil.h"

#include <stack>

namespace Trees
{
    using namespace std;
    using namespace LeetCodeUtil;

    #define RECURSIVE 0

    #if( RECURSIVE )

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true;
        if (( p && !q ) || ( !p && q ) || ( p->val != q->val )) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    #else

    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
        {
            // both null.
            return true;
        }
        else if (!root || !subRoot)
        {
            // one is null, another is not.
            return false;
        }

        // Do inorder traversal.
        TreeNode* p = root;
        TreeNode* q = subRoot;
        stack<TreeNode*> nodeStack;
        while (p || q || !nodeStack.empty())
        {
            if (p && q)
            {
                nodeStack.push(p);
                nodeStack.push(q);

                p = p->left;
                q = q->left;
            }
            else if(!p && !q)
            {
                q = nodeStack.top();
                nodeStack.pop();
                p = nodeStack.top();
                nodeStack.pop();
                if (!p || !q || p->val != q->val)
                {
                    return false;
                }

                p = p->right;
                q = q->right;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
    #endif

    // 572. Subtree of Another Tree
    // We need to check whether two trees are identical.
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
        {
            // both null.
            return true;
        }
        else if (!root || !subRoot)
        {
            // one is null, another is not.
            return false;
        }

        if (isSameTree(root, subRoot))
        {
            return true;
        }

        bool result = false;
        if (root->left)
        {
            result = isSubtree(root->left, subRoot);
        }
        if (root->right)
        {
            result = result || isSubtree(root->right, subRoot);
        }

        return result;
    }

    void TestSubtreeOfAnotherTree()
    {
        cout << "\n572. Subtree of Another Tree" << endl;
        // Input: root = [3,4,5,1,2], subRoot = [4,1,2]
        // Output: true
        // Input: root = [1,2,3], subRoot = [1,2]
        // Output: false
        // root = [1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2], subRoot = [1,null,1,null,1,null,1,null,1,null,1,2]
        // Output: true
        // root = [3,6,5,4,null,null,null,1,2], subRoot = [4, 1, 2]
        // Output: true
        //TreeNode* root = BuildTreeFromLevelOrderString("[1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]");
        //TreeNode* subRoot = BuildTreeFromLevelOrderString("[1,null,1,null,1,null,1,null,1,null,1,2]");
        TreeNode* root = BuildTreeFromLevelOrderString("[3,4,5,1,2]");
        TreeNode* subRoot = BuildTreeFromLevelOrderString("[4,1,2]");

        cout << "Result: " << isSubtree(root, subRoot) << endl;
    }
}