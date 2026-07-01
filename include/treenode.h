#pragma once

template<typename T>
struct TreeNode
{
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(const T& value):data(value),left(nullptr),right(nullptr),parent(nullptr)
    {}
};