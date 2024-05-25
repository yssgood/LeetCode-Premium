class Solution {
public:
    struct Node{
        int x,y, dist; 
    };

    struct Compare{
        bool operator()(Node& a, Node& b){
            return a.dist > b.dist; 
        }
    };

    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), INT_MAX)); 
        priority_queue<Node, vector<Node>, Compare> pq; 
        pq.push({0,0,0}); 
        visited[0][0] = 0; 

        while(!pq.empty()){
            int size = pq.size(); 
            for(int i = 0; i < size; i++){
                Node node = pq.top(); 
                pq.pop(); 


                int x = node.x, y = node.y, dist = node.dist; 

                if(x == heights.size()-1 && y == heights[0].size()-1){
                    return dist; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= heights.size() || nY >= heights[0].size()) continue; 

                    int new_dist = max(dist, abs(heights[nX][nY] - heights[x][y])); 

                    if(visited[nX][nY] > new_dist){
                        visited[nX][nY] = new_dist; 
                        pq.push({nX,nY,new_dist}); 
                    }
                }
            }
        }
        return -1; 
    }
};