#include "Tree.h"

//My variant is 34, but amount of variants in Lab 6 - 30, that`s why I did 4-th variant

void input(Tree& mytree)
{
    bool correct_input, flag = true;
    string tmp;
    cout << "Enter values for tree nodes. To finish entering - type 'end' \n";
    while (flag)
    {
        cin >> tmp;
        correct_input = tmp.find_first_not_of("0123456789.-") == string::npos;
        if (!correct_input) {
            flag = false;
            break;
        }
        mytree.insert(stof(tmp), mytree.root);
    }
}


ostream& operator<<(ostream& flow, Tree mytree) {
    mytree.printTree(mytree.root, 0);
    return flow;
}


void Tree::printTree(const TNode* node, int level)
{
    if (node != nullptr) {
        printTree(node->left, level + 1);
        for (int i = 0; i < level; ++i) {
            cout << "\t";
        }
        cout << "  " << node->val << "\n";
        printTree(node->right, level + 1);
    }
}

void findNegative(int & negative_amount, TNode* tmp) {
    if (tmp->val < 0)
        negative_amount++;
    if (tmp->left != nullptr)
        findNegative(negative_amount, tmp->left);
    if (tmp->right != nullptr)
        findNegative(negative_amount, tmp->right);
}

void findPositive(int& positive_amount, TNode* tmp) {
    if (tmp->val > 0)
        positive_amount++;
    if (tmp->left != nullptr)
        findPositive(positive_amount, tmp->left);
    if (tmp->right != nullptr)
        findPositive(positive_amount, tmp->right);
}

TNode* Tree::getRoot() const {
    return root;
}

void Tree::insert(float a, TNode*& previous) {
    auto current = new TNode;
    current->val = a;
    current->left = nullptr;
    current->right = nullptr;
    if (previous == nullptr)
        previous = current;
    else if (current->val < previous->val)
        insert(a, previous->left);
    else
        insert(a, previous->right);
}