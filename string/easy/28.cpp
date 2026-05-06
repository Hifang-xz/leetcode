class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h = haystack.size();
        int n = needle.size();
        if (n == 0)
            return 0;
        for (int i = 0; i <= h - n; ++i)
        {
            if (haystack[i] == needle[0])
            {
                bool ok = true;
                for (int j = 0; j < n; ++j)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};