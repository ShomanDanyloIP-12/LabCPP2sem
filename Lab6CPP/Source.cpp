#include <iostream>
#include "Tree.h"
using namespace std;

//My variant is 34, but amount of variants in Lab 6 - 30, that`s why I did 4-th variant

int main() {
    Tree tree = Tree();
    input(tree);
    cout << "Tree:\n";
    cout << tree;
    int negatives = 0, positives = 0;
    findNegative(negatives, tree.getRoot());
    cout << "\nNegative amount: " << negatives;
    findPositive(positives, tree.getRoot());
    cout << "\nPositive amount: " << positives;
    return 0;
}