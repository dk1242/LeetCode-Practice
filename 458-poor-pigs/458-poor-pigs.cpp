class Solution {
public:
    int poorPigs(int buckets, int mins1, int mins2) {
        int rounds=mins2/mins1 +1;
        return ceil(log(buckets)/log(rounds));
    }
};