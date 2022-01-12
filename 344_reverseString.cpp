class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        vector<char>::iterator left = s.begin();
        vector<char>::iterator right = s.end() - 1;

        while (left < right)
        {
            char tmp = *left;
            *left = *right;
            *right = tmp;

            left += 1;
            right -= 1;
        }
    }
};