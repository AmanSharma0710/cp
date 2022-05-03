#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int blocks = 1;
        int len;
        cin >> len;
        if (len == 0)
        {
            cout << "RAMADHIR" << endl;
            return 0;
        }

        string str;
        cin >> str;
        char initial = str[0];
        for (int i = 1; i < len; i++)
        {
            if (str[i] == initial)
            {
                continue;
            }
            else
            {
                initial = str[i];
                blocks++;
            }
        }
        if (blocks % 2 == 0)
        {
            cout << "RAMADHIR" << endl;
        }
        else
        {
            cout << "SAHID" << endl;
        }
    }

    return 0;
}