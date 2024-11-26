#include "FileAVL.hpp"
#include "File.hpp"
#include "FileTrie.hpp"

// ALL YOUR CODE SHOULD BE IN THIS FILE. NO MODIFICATIONS SHOULD BE MADE TO FILEAVL / FILE CLASSES
// You are permitted to make helper functions (and most likely will need to)
// You must declare them "inline" | declare & implement them at the top of this file, before query()
// Below query(), implement and document all methods declared in FileTrie.hpp

// two approaches
/*
1. add all the nodes into a vector and then sort it by file size
2. then push the query vector with the given sizes

1.Search for all node given a vertain key and return the node
2. Call the function for min > max
*/

// avl tree traversal
// Node *nodeTraverse(Node *&root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     nodeTraverse(root->left_);
// }

// std::vector<File *> allNodes(Node *&root)
// {
//     std::vector<File *> result = {};
//     if ()
// }

/**
 * @brief Retrieves all files in the FileAVL whose file sizes are within [min, max]
 *
 * @param min The min value of the file size query range.
 * @param max The max value of the file size query range.
 * @return std::vector<File*> storing pointers to all files in the tree within the given range.
 * @note If the query interval is in descending order (ie. the given parameters min >= max),
        the interval from [max, min] is searched (since max >= min)
 */
std::vector<File *> FileAVL::query(size_t min, size_t max)
{
    std::vector<File *> result = {};
    // root_
    //  Your code here.

    return result;
}

// FileTrie implementation

void FileTrie::addFile(File *f)
{
    // convert to lowercase
}

std::unordered_set<File *> FileTrie::getFilesWithPrefix(const std::string &prefix) const
{
    // convert to lowercase
    std::unordered_set<File *> stub = {};
    return stub;
}

FileTrie::~FileTrie()
{
}