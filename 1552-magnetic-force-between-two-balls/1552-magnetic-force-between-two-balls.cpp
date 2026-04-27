class Solution {

bool ispossible(vector<int>& position, int m,int mid){

    int ballCount = 1;
    int firstB = position[0];
    for(int i=0;i<position.size();i++){
        if(abs(firstB-position[i])>=mid){
            ballCount++;
            if(ballCount == m){
                return true;
            }
            firstB = position[i];
        }
    }
    return false;
}



public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s = 0;
        // int maxi = INT_MIN;
        // for(int i=0;i<position.size();i++){
        //     maxi = max(maxi,position[i]);
        // }

        int e = position.back()-position.front();
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(ispossible(position,m,mid)){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};