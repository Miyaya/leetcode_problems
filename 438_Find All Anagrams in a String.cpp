class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> indexs;

        if (s.size() == 0)
            return indexs;

        int pMap[26] = {0};
        int pTotal = 0;

        for (int i = 0; i < p.size(); i++)
        {
            pMap[p[i] - 'a'] += 1;
            pTotal += 1;
        }

        int l = 0, r = 0;
        for (int l = 0; l < s.size(); l++)
        {
            int r = l, pT = pTotal;
            int pM[26];
            memcpy(pM, pMap, 26 * sizeof(int));

            while (r < s.size() && --pM[s[r] - 'a'] >= 0)
            {
                pT -= 1;
                if (pT == 0)
                {
                    indexs.push_back(l);
                }
                r += 1;
            }
        }

        return indexs;
    }
};