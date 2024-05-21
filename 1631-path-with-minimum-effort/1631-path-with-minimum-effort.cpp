class Solution {
public:
    struct Node{
        int x, y, dist; 
    };
    struct compare{
        bool operator()(Node& a, Node &b){
            return a.dist > b.dist; 
        }
    };
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<Node, vector<Node>, compare> pq; 
        bool visited[101][101]; 
        memset(visited,false,sizeof(visited)); 
        pq.push({0,0,0});  
        visited[0][0] = true;  
        while(!pq.empty()){
            int size = pq.size(); 

            for(int i = 0; i < size; i++){
                Node node = pq.top();
                pq.pop(); 

                int x = node.x, y = node.y, dist = node.dist; 
                //cout << x << ' ' << y << ' ' << dist << endl; 

                if(x == heights.size()-1 && y == heights[0].size()-1){
                    return dist; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 
                    
                    if(nX < 0 || nY < 0 || nX >= heights.size() || nY >= heights[0].size() || visited[nX][nY]) continue; 

                    int nDist = abs(heights[nX][nY] - heights[x][y]); 
                    //visited[nX][nY] = true; 
                    pq.push({nX,nY,max(dist,nDist)}); 
                }
                visited[x][y] = true; 
                
            }
        }

        return -1; 
    }
};