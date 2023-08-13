#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, l, k, x = 0, row, col, count = 0, res = 0;
    char ch[6][6] = {'B', 'B', 'M', 'B', 'B', 'B',
                     'C', 'B', 'A', 'B', 'B', 'B',
                     'I', 'B', 'G', 'B', 'B', 'B',
                     'G', 'B', 'I', 'B', 'B', 'B',
                     'A', 'B', 'C', 'B', 'B', 'B',
                     'M', 'C', 'I', 'G', 'A', 'M'};

    string s;
    cin >> s;

    l = s.length();

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            k = 0;
            x = 0;
            count = 0;
            if (ch[i][j] == s[x] && x < l)
            // while (k < l)
            {
                x++;
                row = i;
                col = j;
                while (k < l - 1)
                // if (ch[row][col] == s[x] && x < l)
                {
                    k++;

                    if (ch[row][col - 1] == s[x])
                    {
                        col--;
                        count++;
                        x++;
                    }
                    if (ch[row - 1][col] == s[x])
                    {
                        row--;
                        count++;
                        x++;
                    }
                    if (ch[row][col + 1] == s[x])
                    {
                        col++;
                        count++;
                        x++;
                    }
                    if (ch[row + 1][col] == s[x])
                    {
                        row++;
                        count++;
                        x++;
                    }
                }
                // k++;
                // cout<< count<<" ";
                // printf("%d ",count);
            }
            // printf("\n");
            // cout<< count<<" ";
            if (count == l - 1)
                res++;
        }
        // printf("\n");
    }
    printf("%d", res);
    return 0;
}