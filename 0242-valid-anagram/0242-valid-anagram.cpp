class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case
        if(s.size()!=t.size()) return false;

        unordered_map<char,int> st;
        // add the fiq
        for(auto it:s){
            st[it]++;
        }
        // remove the frq
        for(auto it:t){
            st[it]--;
        }
        // if prest check
        for(auto it:st){
            if(it.second!=0) return false;
        }
        return true;
    }
};