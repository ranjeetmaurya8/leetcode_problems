class Solution {
public:

    bool iscycleDFS(int src, vector<bool> &vis,
                    vector<bool> &recpath,
                    vector<vector<int>> &edges) {

        vis[src] = true;
        recpath[src] = true;

        for(int v : edges[src]) {

            if(!vis[v]) {

                if(iscycleDFS(v, vis, recpath, edges)) {
                    return true;
                }
            }
            else if(recpath[v]) {
                return true;
            }
        }

        recpath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>> &edges) {

        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);

        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        edges = adj;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                if(iscycleDFS(i, vis, recpath, edges)) {
                    return false;
                }
            }
        }

        return true;
    }
};