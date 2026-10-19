class Solution {
    public int maximumWealth(int[][] accounts) {
        for(int i=0;i<accounts.length;i++)
        {
            int sum = 0;
            for(int j=0;j<accounts[0].length;j++)
            {
                sum += accounts[i][j];
            }
            accounts[i][0] = sum;
        }
        int maxi = Integer.MIN_VALUE;
        for(int i=0;i<accounts.length;i++)
        {
            maxi = Math.max(maxi,accounts[i][0]);
        }
        return maxi;
    }
}