class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> hashMap; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({value,timestamp}); 
    }
    
    string get(string key, int timestamp) {
        if(!hashMap.count(key)) return ""; 
        //vector<pair<string,int>> lst = hashMap[key];
        const auto& lst = hashMap[key]; // Reference, no copy! 
        int left = 0, right = lst.size()-1; 
        while(left <= right){
            int mid = left + (right - left) / 2; 

            int curr = lst[mid].second; 

            if(curr <= timestamp){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }
        return left - 1 < 0 ? "" : lst[left-1].first; 
    }
};
