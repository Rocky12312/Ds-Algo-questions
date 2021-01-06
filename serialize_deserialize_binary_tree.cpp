class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "NULL";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            TreeNode*p = q.front();
            q.pop();
            if(p == NULL){
                s = s+ "NULL,";
            }
            else{
                s = s+to_string(p->val) + ",";
                q.push(p->left);
                q.push(p->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //Here what we have is an string in which values are separated by commas
        stringstream ss(data);
        string value;
        if(data == "NULL"){
            return NULL;
        }
        queue<string> values;
        queue<TreeNode*> tree_nodes;
        TreeNode* root; 
        //We will get a queue with values
        while(getline(ss, value, ',')){
            values.push(value);
        }
        //stoi(string to integer)
        //Creating root as the value in root will be the first value of queue(or say the string)
        root = new TreeNode(stoi(values.front()));
        values.pop();
        tree_nodes.push(root);
        while(values.empty() == false){
            string left = values.front();
            values.pop();
            TreeNode* curr = tree_nodes.front();
            tree_nodes.pop();
            if(left != "NULL"){
                curr->left = new TreeNode(stoi(left));
                tree_nodes.push(curr->left);
            }
            if(values.empty() == false){
                string right = values.front();
                values.pop();
                if(right != "NULL"){
                    curr->right = new TreeNode(stoi(right));
                    tree_nodes.push(curr->right);
                }
            }
        }
        
        return root;
    }
};

