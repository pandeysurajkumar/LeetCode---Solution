// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         if(n<=0) return 1;
//        int result=0;
//        int i =0;
//        while(n!=0){
//         int bit = n & 1;
//         if(bit != 1){
//             result = (1 * pow(2,i)) + result;
//             i++;
//             n = n>>1;
//         }else{
//             i++;
//             n=n>>1;
//         }
//        }
//        return result; 
//     }
// };



class Solution {
public:
    int bitwiseComplement(int n) {
        if(n<=0)return 1;
        int mass=0;
        int m = n;
        while(m!=0){
            mass = (mass<<1)|1;
            m = m>>1;
        }
        int res = (~n)& mass;
        return res;

    }
};