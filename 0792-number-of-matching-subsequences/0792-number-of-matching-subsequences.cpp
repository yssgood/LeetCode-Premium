class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        int cnt=0;
        for (int i=0; i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        for (int i=0; i<words.size(); i++){
            string word= words[i];
            int curr=-1; bool flg=1;
            for (int j=0; j<word.size(); j++){
                char ch= word[j];
                if (mp.find(ch)==mp.end()){flg=0;break;}
                if(upper_bound(mp[ch].begin(),mp[ch].end(),curr)==mp[ch].end()){flg=0;break;}
                curr= mp[ch][upper_bound(mp[ch].begin(),mp[ch].end(),curr)-mp[ch].begin()];
            }
            if (flg)cnt++;
        }
        return cnt;
    }
};