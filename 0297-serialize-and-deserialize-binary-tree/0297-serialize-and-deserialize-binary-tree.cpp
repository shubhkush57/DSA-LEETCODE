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
        if(root == NULL){
            return "()";
        }
        string LeftPart = serialize(root->left);
        string RightPart = serialize(root->right);
        int leftSize = LeftPart.size();
        int rightSize = RightPart.size();
        string rootValue = to_string(root->val);
        string ans = "(";
        ans += rootValue;
        ans += "#";
        ans += to_string(leftSize)+LeftPart;
        ans += "#";
        ans += to_string(rightSize)+RightPart;
        ans += ")";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(data == "()"){
            return NULL;
        }
        string rootValue = "";
        int i = 1;
        while(data[i] != '#'){
            rootValue.push_back(data[i]);
            i++;
        }
        int rootVal = stoi(rootValue);
        TreeNode* root = new TreeNode(rootVal);
        i++;
        string LeftSize = "";
        while(data[i]!= '('){
            LeftSize.push_back(data[i]);
            i++;
        }
        int leftSize = stoi(LeftSize);
        root->left = deserialize(data.substr(i,leftSize));
        i = leftSize+i+1;
        string RightSize = "";
        while(data[i] != '('){
            RightSize.push_back(data[i]);
            i++;
        }
        int rigthSize = stoi(RightSize);
        root->right = deserialize(data.substr(i,rigthSize));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// (rootValue#LeftSize LeftPart#RightSize RightPart)

// j-i+1 = leftSize;
// j = leftSize+i-1;