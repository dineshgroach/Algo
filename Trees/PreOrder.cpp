// Recursive Solution
    void po(TreeNode *root,vector<int>&ans)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        po(root->left,ans);
        po(root->right,ans);
    };
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        po(root,ans);
        return ans;
    }

// Iterative Solution
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int>preorder;
        stack<TreeNode*>st;
        if(root == NULL) return preorder;
        st.push(root);
        while (!st.empty())
        {
            auto curr=st.top();
            st.pop();
            preorder.push_back(curr->val);
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }
            if(curr->left!=NULL)
            {
                st.push(curr->left);
            }
        }
        return preorder;
    }
