class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size()-1;
        int left = 1;
        int right = piles[n];
        int ans = right;
        // Binary search
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            long totalhour =0;
            for(int i=0;i<piles.size();i++)
            {
                totalhour = totalhour +(piles[i]+mid-1)/mid;  //(a+b-1)/b or ceil(a/b)
            }
            if(totalhour<=h)
            {
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};