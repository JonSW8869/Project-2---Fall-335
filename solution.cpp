#include "FileAVL.hpp"
#include "File.hpp"
#include "FileTrie.hpp"

// ALL YOUR CODE SHOULD BE IN THIS FILE. NO MODIFICATIONS SHOULD BE MADE TO FILEAVL / FILE CLASSES
// You are permitted to make helper functions (and most likely will need to)
// You must declare them "inline" | declare & implement them at the top of this file, before query()
// Below query(), implement and document all methods declared in FileTrie.hpp

void queryHelper(Node *node, size_t min, size_t max, std::vector<File *> &result)
{
    if (!node)
        return;

    size_t currentSize = node->files_.front()->getSize();

    // Traverse left subtree if the minimum range is less than the current size
    if (min < currentSize)
    {
        queryHelper(node->left_, min, max, result);
    }

    // Add files in the current node if they fall within the range
    if (min <= currentSize && currentSize <= max)
    {
        result.insert(result.end(), node->files_.begin(), node->files_.end());
    }

    // Traverse right subtree if the maximum range is greater than the current size
    if (max > currentSize)
    {
        queryHelper(node->right_, min, max, result);
    }
}
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
    // search the tree and push the nodes that have a size inbetween min and max into the vector
    std::vector<File *> result = {};
    if (min > max)
    {
        std::swap(min, max);
    }
    queryHelper(root_, min, max, result);
    //  Your code here.

    return result;
}

// FileTrie implementation

void FileTrie::addFile(File *f)
{
    // convert to lowercase
    // FileTrieNode *ptr = head;
    // std::transform(f->getName().begin(), f->getName().end(), f->getName().begin(), ::towlower);
    // for (char c : f->getName())
    // {
    // }
}

std::unordered_set<File *> FileTrie::getFilesWithPrefix(const std::string &prefix) const
{
    // convert to lowercase
    std::unordered_set<File *> stub;
    return stub;
}

FileTrie::~FileTrie()
{
}