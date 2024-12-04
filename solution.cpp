
#include "FileAVL.hpp"
#include "File.hpp"
#include "FileTrie.hpp"

// ALL YOUR CODE SHOULD BE IN THIS FILE. NO MODIFICATIONS SHOULD BE MADE TO FILEAVL / FILE CLASSES
// You are permitted to make helper functions (and most likely will need to)
// You must declare them "inline" | declare & implement them at the top of this file, before query()
// Below query(), implement and document all methods declared in FileTrie.hpp

inline void queryHelper(Node *node, size_t min, size_t max, std::vector<File *> &result)
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
    std::vector<File *> result = {};
    if (min > max)
    {
        std::swap(min, max);
    }
    queryHelper(root_, min, max, result);
    return result;
}

// FileTrie implementation

FileTrie::FileTrie() {}

/*
// the trie tree is composed of a map <char c, FileTreeNode*>.
// Each node contains a set.

 To add a file,

First: we add the fileName into head's matching set
Then we start iterating through fileName and check the iterator's next

We add the fileName into matching;
When the itrerator reachs a point where inside ptr->next.find(c) == ptr->next.end() [the c key is not found inside next]
        then we create a new FileTreeNode with matching only having that file and next's only key is the last char in fileName


SUDOCODE:
string name = f.getName() -> lowercased;
FileTreeNode* ptr = head;
ptr.matching.insert(f);
for(char c : name)
{
    if(key not found in next)
        create new node
    else (key is found in next)
    {

        ptr->next.insert(std::makepair(c, ptr))
    }
    ptr->matching.insert(f);
    ptr = ptr->next[c]
}
*/

void FileTrie::addFile(File *f)
{
    // convert to lowercase
    std::string filename = f->getName();
    std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    if (!head)
    {
        head = new FileTrieNode();
    }
    FileTrieNode *ptr = head;
    for (char c : filename)
    {
        if (ptr->next.find(c) == ptr->next.end())
        {
            ptr->next.insert(std::make_pair(c, new FileTrieNode()));
        }
        ptr->matching.insert(f);
        ptr = ptr->next[c];
    }
}

/*
    Traverse the map until we have we have the node = next[last char of prefix, node->matching]
    we then collect that ptr->matching and return it.

    No need to traverse whole tree since each parent matching contains all the children's matching
*/

std::unordered_set<File *> FileTrie::getFilesWithPrefix(const std::string &prefix) const
{
    std::unordered_set<File *> result = {};
    std::string pre = prefix;
    std::transform(pre.begin(), pre.end(), pre.begin(), ::tolower);
    FileTrieNode *ptr = head;

    // Checks if head is empty, if so, return a blank
    if (!ptr)
    {
        return result;
    }
    for (char c : pre)
    {
        // if c is not found in the tree, then the prefix doesn't exist so we return a blank
        if (ptr->next.find(c) == ptr->next.end())
        {
            return result;
        }
        ptr = ptr->next[c];
    }
    // Insert the ptr's matching into the result
    if (ptr)
        result.insert(ptr->matching.begin(), ptr->matching.end());

    return result;
}
FileTrie::~FileTrie() {}
