class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //my logic work like
        //take k  use dfs bfs find neighbors directly connected 
        //then check any outside method calling them and again 
        //check if calling print all the methos else only non suspecious 
        //by removing the safely ehat we asked.....

       // 1. Build adjacency list for graph representation
        vector<vector<int>> graph(n);
        for (const auto& edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        // 2. BFS to find all suspicious method
        unordered_set<int> suspicious;
        queue<int> q;

        q.push(k);
        suspicious.insert(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : graph[curr]) {
                if (!suspicious.count(neighbor)) {
                    suspicious.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        // 3. Check if any node OUTSIDE suspicious group invokes a node INSIDE
        bool can_remove = true;
        for (const auto& edge : invocations) {
            int u = edge[0], v = edge[1];
            if (!suspicious.count(u) && suspicious.count(v)) {
                can_remove = false; // Outside node invokes a suspicious method
                break;
            }
        }

        // 4. Construct the answer
        vector<int> result;
        if (!can_remove) {
            // Cannot remove suspicious methods, return all methods
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        } else {
            // Return only the non-suspicious methods
            for (int i = 0; i < n; ++i) {
                if (!suspicious.count(i)) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};