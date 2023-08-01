class Solution {
public:
    bool dfs(int src , vector<bool>&visited,  vector<bool>&dfsvisited, vector<vector<int>>&graph,vector<bool>&cycle){
        visited[src]=true;
        dfsvisited[src]=true;
        vector<int> v = graph[src];
        for(auto i : v){
            if(visited[i]==false){
                if(dfs(i , visited, dfsvisited, graph,cycle)){
                    cycle[src]=true;
                    return cycle[src];
                }
            }else if(visited[i]==true && dfsvisited[i]==true){
                cycle[src]=true;
                return cycle[src];
            }
        }
        dfsvisited[src]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<bool>visited(graph.size(),false);
        vector<bool>dfsvisited(graph.size(),false);
        vector<bool>cycle(graph.size(),false);
        for(int i =0 ;i<graph.size();i++){
            if(visited[i]==false){
                dfs(i,visited,dfsvisited,graph,cycle);
            }
        }
        for(int i =0 ; i<cycle.size();i++){
            if(cycle[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
