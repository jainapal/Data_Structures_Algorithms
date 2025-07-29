    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> colors(n, 0);

        return func(0, m, n, colors, adj);
    }

    bool func(int node, int m, int n, vector<int>& colors, vector<int> adj[]){
        if(n == node) return true; //all nodes are coloured
        //try all colors from 1 to m
        for(int i = 1; i <= m; i++){
            if(safe(i, node, colors, adj)){
                colors[node] = i;
                if(func(node+1, m, n, colors, adj)) return true;
                colors[node] = 0; //color doesn't lead to solution
            }
        }
        return false;
    }

    bool safe(int col, int node, vector<int>& colors, vector<int> adj[]){
        for(int i = 0; i < adj[node].size(); i++){
            if(colors[adj[node][i]] == col) return false;
        }
        return true;
    }

    TC = O(M ^ N), SC = O(N)