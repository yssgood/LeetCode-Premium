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
        //<string,int> pair -> q 
        //if (diff(..) -> true) q.push(next string)
        //map<string,bool> mp -> mp[next string] = true  
        //bfs  ->  if curr string == endGene -> return dist 
        map<string, bool> hashMap; 
        queue<pair<string,int>> q; 
        q.push({startGene,0}); 
        
        for(string& s : bank) hashMap[s] = true; 
        if(hashMap[endGene] == false) return -1; 

        hashMap.clear(); 
        hashMap[startGene] = true; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                pair<string,int> p = q.front();
                q.pop(); 

                string curr = p.first; 
                int dist = p.second; 

                if(curr == endGene){
                    return dist; 
                }

                for(string& s : bank){
                    if(!hashMap[s] && findDiff(curr,s)){
                        hashMap[s] = true; 
                        q.push({s, dist + 1}); 
                    }
                }
            }
        }

        return -1; 
        
    }
};