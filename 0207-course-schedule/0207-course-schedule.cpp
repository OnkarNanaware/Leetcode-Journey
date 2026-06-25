class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int neighbor : graph[node])
        {
            // If the neighbor has not been visited, visit it
            if (!visited[neighbor])
            {
                if (dfs(neighbor, graph, visited, pathVisited))
                    return true;
            }
            // If the neighbor is already in the current DFS path, cycle exists
            else if (pathVisited[neighbor])
            {
                return true;
            }
        }

        // Backtracking
        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Step 1: Build the graph
        vector<vector<int>> graph(numCourses);

        for (auto p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
        }

        // Step 2: Arrays for DFS
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        // Step 3: Check every component
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, graph, visited, pathVisited))
                    return false; // Cycle found
            }
        }

        return true; // No cycle
    }
}; 

//solve using kahn's algorithm which is usefull in the topo sort with bfs 