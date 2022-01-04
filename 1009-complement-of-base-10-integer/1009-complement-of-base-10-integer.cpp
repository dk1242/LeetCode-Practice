class Solution {
public:
    int bitwiseComplement(int num) {
        long long n;
        if(num==0)
            return 1;
        n=log2(num);
        // cout<<n<<"\n";
        // n=n<<1;
        // n=n-1;
        long long n2=pow(2, n+1)-1;
        // cout<<n2<<"\n";
        return num^n2;
    }
};