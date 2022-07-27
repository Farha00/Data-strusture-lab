#include<iostream>
#include<cstring>
using namespace std;
int pattern_matching(char string[], int str_length, char pattern[], int pat_length)
{
    int k = 0;
    int max = str_length - pat_length + 1;
    while (k <= max)
    {
        int c = 0;
        for (int i = 0; i < pat_length; i++)
        {
            if (pattern[i] != string[k + i])
            {
                i = pat_length;
            }
            else
            {
                c++;
            }
        }
        if (c == pat_length)
        {
            return k;
        }
        k++;
    }
    return -1;
}
int main()
{
    char str[30];
    char pat[30];
    int tlen, plen, x;
    int ch = 1;
    cout << "\tWELCOME\t" << endl;
    do {
        cout << "Enter a string : ";
        cin >> str;
        cout << "Enter pattern : ";
        cin >> pat;
        tlen = strlen(str);
        plen = strlen(pat);
        //positions 1,2,3........
        cout << "\n";
        x = pattern_matching(str, tlen, pat, plen) + 1;
        if (x == 0)
        {
            cout << "Pattern not found" << endl;
        }
        else
        {
            cout << "Pattern is present at position " << x << endl;
        }
        cout << "\n";
        cout << "Do you want to continue?" << endl;
        cout << "1:Yes\n2:No\nEnter your choice: ";
        cin >> ch;
        cout << "\n";
    } while (ch != 2);
    return 0;
}
