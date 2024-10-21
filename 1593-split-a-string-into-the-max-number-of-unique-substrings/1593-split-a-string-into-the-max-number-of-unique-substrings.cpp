class Solution {
public:
    int answer = 0;
    map<string,int> hashMap;  
    void dfs(string& s, vector<string>& container, int index){
        if(index >= s.length()){
            //cout << tmp << endl; 
            answer = max(answer, (int)container.size()); 
            return;  
        }

        for(int i = index; i < s.length(); i++){
            string tmp = s.substr(index, i - index + 1); 
            if(hashMap.count(tmp)) continue; 
            container.push_back(tmp); 
            hashMap[tmp]++; 
            dfs(s, container, i + 1);
            container.pop_back(); 
            hashMap.erase(tmp); 
        }
    }
    int maxUniqueSplit(string s) {
        vector<string> container; 
        string tmp = ""; 
        dfs(s,container,0);
        return answer; 
    }
};