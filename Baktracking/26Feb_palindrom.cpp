// https://leetcode.com/problems/palindrome-partitioning/
#include<vector>
#include<string>
using namespace std;

class Solution
{
private:
    void func(int index, string s, vector<string> &ds, vector<vector<string>> &ans)
    {
        int n = s.size();
        if (index == n)
            {
                ans.push_back(ds);
                return;
            }
        for (int i = index; i < n; ++i)
        {
            if (isPalindrome(s, index, i))
            {
                ds.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        func(0, s, ds, ans);
        return ans;
    }
};