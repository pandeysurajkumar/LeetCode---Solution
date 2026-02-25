// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) {
//             return false; // Negative numbers and zero are not powers of two
//         }
//         while (n % 2 == 0) {
//             n /= 2;
//         }
//         return n == 1;    
//     }
// };


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        return (n & (n-1)) == 0;
    }
};