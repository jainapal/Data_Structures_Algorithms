vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        stack<int> st;
        vector<int> vis(n, 0);
        st.push(0);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(vis[node] == 0){
                vis[node] = 1;
                ans.push_back(node);
            }
            
            //visit from right to left so that leftmost node popped out first
            for(int i = adj[node].size() - 1; i >= 0; i--){
                if(vis[adj[node][i]] == 0) st.push(adj[node][i]);
            }
        }
        return ans;
        
    }
    TC = O(V + E), SC = O(V)
-------------------------------------------------------------------------------------------------
RECURSIVE APPROACH
void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& vis){
        vis[node] = 1;
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                DFS(adj[node][i], adj, ans, vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, 0);
        vector<int> ans;
        DFS(0, adj, ans, vis);
        return ans;
    }