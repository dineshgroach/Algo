// Recursive Solution
    void io(TreeNode *root,vector<int>&ans)
    {
        if(root==NULL) return;
        io(root->left,ans);
        ans.push_back(root->val);
        io(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        io(root,ans);
        return ans;
    }
// Iterative Solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(root==NULL) return inorder;
        stack<TreeNode*>st;
        TreeNode* Node = root;
        while (true)
        {
            if(Node!=NULL)
            {
                st.push(Node);
                Node=Node->left;
            }
            else
            {
                if(st.empty()) break;
                Node = st.top();
                st.pop();
                inorder.push_back(Node->val);
                Node = Node->right;
            }
        }
        return inorder;
    }
