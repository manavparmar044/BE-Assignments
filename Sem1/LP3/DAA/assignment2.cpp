#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct HuffmanNode{
    char data;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int frequency){
        left = nullptr;
        right = nullptr;

        this->data = data;
        this->frequency = frequency;
    }
};

struct Compare{
    bool operator()(HuffmanNode *left,HuffmanNode *right){
        return left->frequency > right->frequency;
    }
};

void printCodes(HuffmanNode *root, string code,unordered_map<char,string> mpp){
    if(!root){
        return;
    }

    if (!root->left && !root->right) {
        mpp[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    printCodes(root->left,code+"0", mpp);
    printCodes(root->right,code+"1", mpp);
}