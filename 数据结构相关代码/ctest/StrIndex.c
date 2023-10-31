#define MAXLEN 40

typedef struct
{
    char ch[MAXLEN];
    int len;
} SString; // 定长顺序串

int StrIndex(SString s, int pos, SString t)
{
    int i, j, start; // 下标从0开始
    if (t.len == 0)
        return 0;
    start = pos - 1;
    i = start;
    j = 0;
    while (i < s.len && j < t.len)
    {
        if (s.ch[i] == t.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return (j >= t.len) ? (i - j) : -1;
}
