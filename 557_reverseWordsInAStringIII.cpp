class Solution
{
public:
    string reverseWords(string s)
    {
        size_t pos = 0;
        string res;
        while ((pos = s.find(" ")) != string::npos)
        {
            string word = s.substr(0, pos);
            word = reverseWord(word);
            s.erase(0, pos + 1);
            res += word + " ";
        }
        s = reverseWord(s);
        res += s;
        return res;
    }

    string reverseWord(string s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l += 1;
            r -= 1;
        }
        return s;
    }
};