#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int length = longestCommonSubstr(s1, s2);
    cout << "Length of Longest Common Substring: " << length << endl;

    return 0;
}
