/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> inMap;

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& postIdx) {
        // Base case:
        if(inStart > inEnd) return nullptr;

        // Current Root element postorder ke aakhri se uthao
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Transfer array mein root ka idx
        int inIdx = inMap[rootVal];

        // Imp: Pehle right, phir left(Kyunki, postorder peeche se scan ho raha hain)
        root->right = build(inorder, inIdx+1, inEnd, postorder, postIdx);
        root->left = build(inorder, inStart, inIdx-1, postorder, postIdx);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inMap.clear();
        int n=inorder.size();
        for(int i=0; i<n; i++){
            inMap[inorder[i]] = i;
        }
        int postIdx = n-1;
        return build(inorder, 0, n-1, postorder, postIdx);
    }
};