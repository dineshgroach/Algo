// To get all three traversal in single scan using stack
// TC - O(n)
// Sc - O(n)
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
	vector<vector<int>>ans(3);
	stack<pair<TreeNode*,int>>s;
	s.push({root,1});
	while (!s.empty())
	{
		auto curr = s.top();
		s.pop();
		// Pre Order
		if(curr.second==1)
		{
			ans[0].push_back(curr.first->data);
			curr.second++;
			s.push(curr);
			if(curr.first->left!=NULL)
			{
				s.push({curr.first->left,1});
			}
		}
		// In Order
		else if(curr.second == 2)
		{
			ans[1].push_back(curr.first->data);
			curr.second++;
			s.push(curr);
			if(curr.first->right!=NULL)
			{
				s.push({curr.first->right,1});
			}
		}
		// Post Order
		else
		{
			ans[2].push_back(curr.first->data);
		}
	}
	return ans;
}
