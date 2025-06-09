#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class GenerateDataType {
private:
    class Tree {
    private:
        TreeNode* buildTree(string& data) {
            if (data.empty()) return nullptr;
            if (data[0] == '[') {
                data.erase(0, 1);
                data.pop_back();
            }
            vector<string> nodes;
            stringstream ss(data);
            string token;
            while (getline(ss, token, ',')) {
                nodes.push_back(token);
            }
            if (nodes[0] == "null") return nullptr;
            TreeNode* root = new TreeNode(stoi(nodes[0]));
            queue<TreeNode*> q;
            q.push(root);
            int i = 1;
            while (!q.empty() && i < nodes.size()) {
                TreeNode* current = q.front();
                q.pop();
                if (i < nodes.size() && nodes[i] != "null") {
                    current->left = new TreeNode(stoi(nodes[i]));
                    q.push(current->left);
                }
                i++;
                if (i < nodes.size() && nodes[i] != "null") {
                    current->right = new TreeNode(stoi(nodes[i]));
                    q.push(current->right);
                }
                i++;
            }

            return root;
        }
        void printTree(TreeNode* root) {
            if (!root) return;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* current = q.front();
                    q.pop();

                    if (current) {
                        cout << current->val << " ";
                        q.push(current->left);
                        q.push(current->right);
                    }
                    else {
                        cout << "null ";
                    }
                }
                cout << endl;
            }
        }
        TreeNode* builtTree;
    public:
        void build() {
            string rawInput;
            cin >> rawInput;
            builtTree = buildTree(rawInput);
        }
        void build(string& rawInput) {
            builtTree = buildTree(rawInput);
        }
        TreeNode* builtTreeRoot() {
            return builtTree;
        }
        void print() {
            printTree(builtTree);
        }
    };
public:
    Tree tree;
    
};
