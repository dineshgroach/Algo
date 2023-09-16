// Prims algo to find the total weight of MST ( Data Structure used in Set , can use priority Queue as Well)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // weight and node
        set<pair<int,int>>st;
        st.insert({0,0});
        vector<bool>vis(V,false);
        int sum = 0;
        while(!st.empty())
        {
            auto it = *st.begin();
            int node = it.second;
            int wt = it.first;
            st.erase(it);
            // checking node and adding weight
            if(vis[node]==true) continue;
            vis[node]=true;
            sum += wt;
            for(auto i:adj[node])
            {
                int adjnode = i[0];
                int adjwt = i[1];
                if(!vis[adjnode])
                {
                    st.insert({adjwt,adjnode});
                }
            }
        }
        return sum;
    }

/* If we want the edges also than in inital configuration add pair<int,pair<int,int>> such 1) weight 2) Destination 3) parent
these modification can result in finding edges as well just make sure pass in inital edges as {0{0,-1}} and dont add edge 
when the parent or destination include -1 */
