#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    char data;
    int freq;
    TreeNode *left, *right;

    TreeNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};


struct FreqCompare {
    bool operator()(const TreeNode* a, const TreeNode* b) const {
        return a->freq > b->freq;
    }
};


TreeNode* buildTree(unordered_map<char, int> &freqMap) {
    priority_queue<TreeNode*, vector<TreeNode*>, FreqCompare> nodes;

   
    for (auto &pair : freqMap) {
        nodes.push(new TreeNode(pair.first, pair.second));
    }

    while (nodes.size() > 1) {
        TreeNode *lChild = nodes.top(); nodes.pop();
        TreeNode *rChild = nodes.top(); nodes.pop();

        int combinedFreq = lChild->freq + rChild->freq;
        TreeNode *internalNode = new TreeNode('$', combinedFreq);  
        internalNode->left = lChild;
        internalNode->right = rChild;
        nodes.push(internalNode);
    }

    return nodes.top(); 
}


void generateCodes(TreeNode* root, string code) {
    if (!root) return;

    if (root->data != '$') {
        cout << root->data << ": " << code << endl;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main() {
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    string text = "A sample text for Huffman encoding.";
    unordered_map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    TreeNode* root = buildTree(freq);
    generateCodes(root, "");

    return 0;
}
