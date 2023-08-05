// Recursive Solution
   void po(TreeNode *root,vector<int>&ans)
    {
        if(root==NULL) return;
        po(root->left,ans);
        po(root->right,ans);
        ans.push_back(root->val);
    }
  vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        po(root,ans);
        return ans;
    }

// Iterative Solution using 2 Stack
vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int>postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            auto curr =st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left!=NULL)
            {
                st1.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                st1.push(curr->right);
            }
        }
        while (!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }

// Iterative Solution using Single Stack
vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
            return postorder;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr!=NULL or !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while (!st.empty() and temp==st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                    
                }
                else
                {
                    curr=temp;
                }
            }
        }
        return postorder;
    }
