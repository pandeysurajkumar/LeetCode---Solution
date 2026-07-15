class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2)
            return 0;

        vector<bool> checklist(n, true);

        checklist[0] = false;
        checklist[1] = false;

        for(int i = 2; i * i < n; i++)
        {
            if(checklist[i])
            {
                for(int j = i * i; j < n; j += i)
                {
                    checklist[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++)
        {
            if(checklist[i])
                count++;
        }

        return count;
    }
};