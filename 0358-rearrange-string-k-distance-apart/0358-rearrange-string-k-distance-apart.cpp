class Solution {
public:
    string rearrangeString(string s, int k) {
        map<char,int> hashMap; 

        priority_queue<pair<int,char>> pq; 

        for(int i = 0; i < s.size(); i++){
            hashMap[s[i]]++; 
        }

        for(auto& it : hashMap){
            pq.push({it.second, it.first}); 
        }

        string answer; 
        queue<pair<int,char>> wait; 

        while(answer.size() != s.size()){
            int index = answer.size(); 
            
            if(!wait.empty() && (index - wait.front().first) >= k){
                auto q = wait.front(); wait.pop(); 
                pq.push({hashMap[q.second], q.second}); 
            }

            if(pq.empty()){
                return ""; 
            }

            char currChar = pq.top().second; pq.pop(); 
            answer += currChar; 

            hashMap[currChar]--; 
            if(hashMap[currChar] > 0){
                wait.push({index, currChar}) ; 
            }
        }
        return answer; 
    }
};