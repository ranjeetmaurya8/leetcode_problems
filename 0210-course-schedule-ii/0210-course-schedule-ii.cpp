class Solution {
public:

    // Cycle Detection using DFS
    bool iscycledfs(int curr, vector<bool>& vis,
                    vector<bool>& recpath,
                    vector<vector<int>>& edges) {

        vis[curr] = true;
        recpath[curr] = true;

        for (int i = 0; i < edges.size(); i++) {

            // LeetCode 210:
            // [course, prerequisite]
            // prerequisite -> course

            int u = edges[i][1];
            int v = edges[i][0];

            if (u == curr) {

                if (!vis[v]) {

                    if (iscycledfs(v, vis, recpath, edges)) {
                        return true;
                    }

                }
                else if (recpath[v]) {
                    return true;
                }
            }
        }

        recpath[curr] = false;
        return false;
    }


    // Topological Sort using DFS
    void toposort(int src, vector<bool>& vis,
                  stack<int>& s,
                  vector<vector<int>>& edges) {

        vis[src] = true;

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][1];
            int v = edges[i][0];

            if (u == src) {

                if (!vis[v]) {
                    toposort(v, vis, s, edges);
                }
            }
        }

        // Push after all neighbours are processed
        s.push(src);
    }


    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);

        vector<int> ans;


        // Step 1: Check Cycle
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                if (iscycledfs(i, vis, recpath, edges)) {
                    return ans;
                }
            }
        }


        // Step 2: Topological Sort
        vis.assign(n, false);

        stack<int> s;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                toposort(i, vis, s, edges);
            }
        }


        // Step 3: Stack -> Answer
        while (!s.empty()) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};