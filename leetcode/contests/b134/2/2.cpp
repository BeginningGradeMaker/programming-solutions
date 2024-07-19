class Solution {
public:
    long long maximumPoints(vector<int>& arr, int k) {
        long long n = arr.size();
        long long ans = 0;
        sort(arr.begin(), arr.end());
        long long mn = arr[0];
        if (k < mn) return 0;
        for (int i = n-1; i >= 0; i--) {
            ans += ((long long)k / mn);
            k %= mn;
            k += arr[i];
        }

        return ans;
    }
};
