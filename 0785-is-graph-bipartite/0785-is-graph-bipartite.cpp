class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //wkt there are only 2 color then graph is bipartite 
       int n=graph.size();
        vector<int>color(n,-1);//all unvisited initially
        for(int i=0;i<n;i++)
        {
            if(color[i]!=-1)
               continue;

            queue<int>q;
            q.push(i);
            color[i]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int nb:graph[node])//accessing the neighbour node 
                {
                    if(color[nb]==-1)//means it is unvisited 
                    {
                      color[nb]=1-color[node];
                      //next node check kro
                      q.push(nb);
                    }
                    else if(color[nb]==color[node])
                    {
                        return false;   
                    }
                }

            }
        }

    return true;}
};