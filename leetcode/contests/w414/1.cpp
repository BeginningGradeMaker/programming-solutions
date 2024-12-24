class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        auto get = [] (int num) -> string {
            string ans = "";
            while (num != 0) {
                ans = (num & 1 ? '1' : '0') + ans;
                num >>= 1;
            }

            return ans;
        };

        string ans = "";
        while (year != 0) {
            ans = (year & 1 ? '1' : '0') + ans;
            year >>= 1;
        }
        ans += '-';
        ans += get(month);
        ans += '-';
        ans += get(day);

        return ans;
    }
};
