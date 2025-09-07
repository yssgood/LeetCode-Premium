class Solution {
public:
    vector<pair<int,int>> dir = {{-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0) return 0; 
        queue<vector<int>> q; 
        x = abs(x); //amount of moves we make to 5 5 and -5 -5 are same
        y = abs(y); 
        q.push({0,0,0}); 
        set<pair<int,int>> set; 
        set.insert({0,0}); //because this is about checking the position, we use set 
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> v = q.front(); 
                q.pop(); 

                int xx = v[0], yy = v[1], dist = v[2]; 

                // if(xx == x && yy == y){
                //     return dist; 
                // }


                for(pair<int,int>& p : dir){
                    int nX = xx + p.first;
                    int nY = yy + p.second; 

                    if(!set.count({nX,nY}) && nX >= -2 && nY >= -2){
                        if(nX == x && nY == y){
                            return dist + 1;  
                        }
                        q.push({nX,nY,dist+1});  
                        set.insert({nX,nY}); 
                    }
                }
            }
        }

        return -1; 
    }
};