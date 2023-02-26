// Print all the subsets of a vector except power set
// Time Complexity = O((2^n)*n)
    vector<int> v = {2, 3, 4};
    for (int i = 0; i < (1 << v.size()); i++)
    {
        stack<int> st;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
                st.push(v[j]);
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
