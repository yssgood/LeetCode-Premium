class Solution {
    struct Knight{
        int x, y, dist; 
    };
    vector<pair<int,int>> dir = {{-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
public:
    int minKnightMoves(int x, int y) {
        queue<Knight> q; 
        x = abs(x); 
        y = abs(y); 
        set<pair<int,int>> visited; 
        //set<string> visited; 
        q.push({0,0,0}); 
        //visited.insert("0,0"); 
        visited.insert({0,0}); 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Knight first = q.front();
                q.pop(); 
                int xx = first.x, yy = first.y, dist = first.dist; 

                if(xx == x && yy == y) return dist; 

                for(pair<int,int>& p : dir){
                    int nX = xx + p.first; 
                    int nY = yy + p.second; 

                    if(!visited.count({nX,nY}) && nX >= -1 && nY >= -1){
                        q.push({nX,nY,dist+1}); 
                        visited.insert({nX,nY}); 
                    }
                }
            }
        }
        return -1; 
    }
};