#include <string>
#include <iostream>
#include <vector>
using namespace std;

//My variant is 34, but amount of variants in Lab 6 - 30, that`s why I did 4-th variant

struct TNode
{
    float val;
    TNode* left, * right;
};

class Tree {
    TNode* root;
    void insert(float a, TNode*& prev);
public:
    Tree() :root(nullptr) {}
    TNode* getRoot() const;
    void printTree(const TNode* node, int level);
    friend void input(Tree& h);
    friend ostream& operator<<(ostream& os, Tree h);
};

void findNegative(int & negative_amount, TNode* tmp);

void findPositive(int& positive_amount, TNode* tmp);