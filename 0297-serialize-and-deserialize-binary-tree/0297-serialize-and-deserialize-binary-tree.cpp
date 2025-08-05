/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "()";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string ans = "(";
        ans += to_string(root->val);
        ans += "#";
        ans += to_string(left.size())+left;
        ans += "#";
        ans += to_string(right.size())+right;
        ans += ")";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "()")return NULL;
        int i = 1;
        while(data[i] != '#'){
            i++;
        }
        int rootVal = stoi(data.substr(1,i));
        TreeNode* ans = new TreeNode(rootVal);
        
        int j = i+1;
        while(data[i] != '('){
            i++;
        }
        int leftPartSize = stoi(data.substr(j,i-j));
       ans->left = deserialize(data.substr(i,leftPartSize));
        i = i+leftPartSize;
        j = i+1;
        while(data[i] != '('){
            i++;
        }
        int rightPartSize = stoi(data.substr(j,i-j));
        ans->right = deserialize(data.substr(i,rightPartSize));
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));