class Solution {
private:
    bool ispossible(vector<int>& weights, int days,int capacity)
    {
        int day=1;
        int currentcapacity = 0;
        for(auto it:weights)
        {
            if(currentcapacity+it > capacity)
            {
                day++;
                currentcapacity = it;
            }
            else
            {
                currentcapacity += it;
            }
        }
        return day<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int result = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(ispossible(weights,days,mid))
            {
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};