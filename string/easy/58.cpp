class Solution
{
public:
    int countSegments(string s)
    {
        int a = s.size();
        int q = 0;
        for (int i = 0; i < a; ++i)
        {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            {
                ++q;
            }
        }
        return q;
    }
};