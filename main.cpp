#include <iostream>
#include "FileTrie.hpp"
#include "FileAVL.hpp"
int main()
{
    FileTrie fileTrie;
    FileAVL tree;

    // Create sample files
    File *file1 = new File("example.txt", "This is example 1", nullptr);
    File *file2 = new File("exam.doc", "This is example 2", nullptr);
    File *file3 = new File("testfile.txt", "This is test file", nullptr);
    File *file4 = new File("example2.txt", "Another example file", nullptr);
    File *file5 = new File("ExAmple3.txt", "Case insensitive test", nullptr);

    // tree.insert(file1);
    // tree.insert(file2);
    // tree.insert(file3);
    // tree.insert(file4);
    // tree.insert(file5);
    // tree.displayInOrder();

    // Add files to the trie
    fileTrie.addFile(file1);
    fileTrie.addFile(file2);
    fileTrie.addFile(file3);
    fileTrie.addFile(file4);
    fileTrie.addFile(file5);

    // // Test case 1: Prefix "exa"
    std::cout << "Files with prefix 'exa':\n";
    auto filesWithExa = fileTrie.getFilesWithPrefix("exa");
    // for (const auto &file : filesWithExa)
    // {
    //     std::cout << file->getName() << "\n";
    // }

    // // // Test case 2: Prefix "ExAm"
    // std::cout << "\nFiles with prefix 'ExAm':\n";
    // auto filesWithExam = fileTrie.getFilesWithPrefix("ExAm");
    // for (const auto &file : filesWithExam)
    // {
    //     std::cout << file->getName() << "\n";
    // }

    // // // Test case 3: Prefix "test"
    // std::cout << "\nFiles with prefix 'test':\n";
    // auto filesWithTest = fileTrie.getFilesWithPrefix("test");
    // for (const auto &file : filesWithTest)
    // {
    //     std::cout << file->getName() << "\n";
    // }

    // // // Test case 4: Prefix "noMatch"
    // std::cout << "\nFiles with prefix 'noMatch':\n";
    // auto filesWithNoMatch = fileTrie.getFilesWithPrefix("noMatch");
    // if (filesWithNoMatch.empty())
    // {
    //     std::cout << "No files found.\n";
    // }

    return 0;
}
// FileAVL tree;
// File hello = File("hello", "content");
// File bye = File("bye", "sadness");
// File cry = File("cry", "haha");
// File help = File("help", "idk");
// File please = File("please", "maybe");
// File *f1;
// File *f2;
// File *f3;
// File *f4;
// File *f5;
// f1 = &hello;
// f2 = &bye;
// f3 = &cry;
// f4 = &help;
// f5 = &please;
// tree.insert(f1);
// tree.insert(f2);
// tree.insert(f3);
// tree.insert(f4);
// tree.insert(f5);
// tree.displayInOrder();
// std::cout << std::endl;
// tree.displayLevelOrder();
