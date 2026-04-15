class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int front = INT_MAX;
        int back = INT_MAX;
        int n = words.size();
        for(int i= 0;i<n;i++){
            if(words[(startIndex+i)%n] ==target){
                front = i;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(words[(startIndex-i+n)%n] ==target){
                back = i;
                break;
            }
        }
        int ans = min(front,back);
        return ans == INT_MAX ? -1 : ans;
    }
};