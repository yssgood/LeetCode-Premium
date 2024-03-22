class Solution {
public:

    bool dfs(vector<vector<int>>& edges, int curr, int destination, vector<bool>& backtrackState, vector<bool>& hasBeenProcessed){

        if(edges[curr].empty()){

            return destination == curr;

        }

        for(int & i : edges[curr]){

                if(hasBeenProcessed[curr]) continue;

                if(backtrackState[i] == true) return false;

                backtrackState[i] = true;
                if(dfs(edges, i, destination, backtrackState, hasBeenProcessed) == false) return false;
                backtrackState[i] = false;
            
        }

        hasBeenProcessed[curr] = 1;
        return true;
    }


    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adjacencyList(n, vector<int>{});

        for(auto & i : edges) adjacencyList[i[0]].push_back(i[1]);

        vector<bool> backtrackState(n, 0);
        vector<bool> hasBeenProcessed(n, 0);

        return dfs(adjacencyList, source, destination, backtrackState, hasBeenProcessed);

    }
};