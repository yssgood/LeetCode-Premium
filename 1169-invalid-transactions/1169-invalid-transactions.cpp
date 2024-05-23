class Solution {
public:
    struct Info{
        string original, name; 
        int time, amount; 
        string city; 
    };
    vector<string> convert(string& s){
        stringstream ss(s); 
        string token; 
        vector<string> res; 

        while(getline(ss,token,',')){
            res.push_back(token); 
        }
        return res; 
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> answer; 
        vector<Info> infos; 
        for(string& s : transactions){
            vector<string> v = convert(s); 
            infos.push_back({s,v[0],stoi(v[1]),stoi(v[2]),v[3]}); 
        }

        for(int i = 0; i < infos.size(); i++){
            Info first = infos[i]; 
            bool flag = false; 
            if(first.amount > 1000){
                answer.push_back(first.original); 
                continue; 
            }
            
            for(int j = 0; j < infos.size(); j++){
                Info next = infos[j]; 
                if(i == j) continue; 
                if((first.name == next.name && first.city != next.city) && abs(first.time - next.time) <= 60){
                    flag = true; 
                    //answer.push_back(next.original);
                    break; 
                }
            }

            if(flag) answer.push_back(first.original); 
        }

        return answer; 
    }
};