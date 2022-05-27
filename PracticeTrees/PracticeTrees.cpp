// PracticeTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "LeetCodeUtil.h"
#include "PracticeTrees.h"

#include <iostream>

using namespace std;
using namespace Trees;

int main()
{
    std::cout << "Practices of Tree!\n";

    TestInvertBinaryTree();

    TestValidateBinarySearchTree();

    TestSymmetricTree();

    TestConvertSortedArraytoBinarySearchTree();

    BinaryTreeLevelOrderTraversal();
}
