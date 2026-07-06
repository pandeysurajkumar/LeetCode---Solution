class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int num : nums)
        {
            freq[num]++;
        }

        // Min Heap
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Step 2: Keep only top k frequencies
        for (auto it : freq)
        {
            pq.push({it.second, it.first}); // {frequency, number}

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: Store answer
        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};