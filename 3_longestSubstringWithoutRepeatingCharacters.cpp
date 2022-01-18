class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> chars;
        int l = 0, r = 1;

        chars.insert(s[l]);
        int len = chars.size();

        if (s.length() == 0)
            return 0;
        while (r < s.length())
        {

            if (chars.find(s[r]) == chars.end())
            {
                chars.insert(s[r]);
                len = chars.size() > len ? chars.size() : len;
                r += 1;
            }
            else
            { // remove all char before duplicated char
                while (s[l] != s[r])
                {
                    chars.erase(s[l]);
                    l += 1;
                }
                chars.erase(s[l]);
                l += 1;
            }
        }
        return len;
    }
};