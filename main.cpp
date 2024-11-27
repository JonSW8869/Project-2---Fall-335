#include <iostream>
#include "FileTrie.hpp"
#include "FileAVL.hpp"

int main()
{
    FileAVL tree;
    File hello = File("hello", "content");
    File bye = File("bye", "sadness");
    File cry = File("cry", "haha");
    File help = File("help", "idk");
    File please = File("please", "maybe");
    File *f1;
    File *f2;
    File *f3;
    File *f4;
    File *f5;
    f1 = &hello;
    f2 = &bye;
    f3 = &cry;
    f4 = &help;
    f5 = &please;
    tree.insert(f1);
    tree.insert(f2);
    tree.insert(f3);
    tree.insert(f4);
    tree.insert(f5);
    tree.displayInOrder();
    std::cout << std::endl;
    tree.displayLevelOrder();
}