#include <vector>
#include <string>
using namespace std;

void helper(string digits, vector<string> &adj, vector<string> &ans, string &s, int index)
{
    if (index == digits.length())
    {
        ans.push_back(s);
        return;
    }
    char ch = digits[index];
    int c = ch - '0';
    string str = adj[c];
    for (int j = 0; j < str.length(); j++)
    {
        s += str[j];
        helper(digits, adj, ans, s, index + 1);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{

    if (digits.length() == 0)
        return {};
    vector<string> ans;
    string s = "";
    vector<string> adj = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(digits, adj, ans, s, 0);
    return ans;
}