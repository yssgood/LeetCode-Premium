class Solution {
public:
    bool findDiff(string& a, string& b){
        int cnt = 0; 
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]) cnt++; 

            if(cnt > 1) return false; 
        }
        return true; 
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,bool> visited; 
        for(string& s : bank) visited[s] = false; 

        int answer = -1; 
        queue<pair<string,int>> q; 
        q.push({startGene, 0}); 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                pair<string,int> p = q.front();
                q.pop(); 

                string s = p.first; 
                int dist = p.second; 

                if(s == endGene){
                    return dist; 
                }

                for(string& next : bank){
                    if(visited[next]) continue; 

                    if(findDiff(s, next)){
                        visited[next] = true; 
                        q.push({next, dist+1}); 
                    }
                }
            }
        }



        return answer; 
    }
};