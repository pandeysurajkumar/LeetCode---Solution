class Solution {
    public int xorOperation(int n, int start) {
        int i = 0;
        int result = 0;
        while(n>0)
        {
            int num = start + 2 * i;
            result ^= num;
            i++;
            n--;
        }
        return result;
    }
}