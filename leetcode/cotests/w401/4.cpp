class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        ranges::sort(rewardValues);
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int val : rewardValues) {
            int shift = f.size() - val;
            f |= f << shift >> shift << val;
        }
        for (int i = rewardValues.back() * 2 - 1; i >= 0; i--) {
            if (f.test(i)) {
                return i;
            }
        }

        return 0;
    }
};
