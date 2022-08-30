#include <iostream>
#include<cstring>
using namespace std;

void SUBSTRING(string S, int E_P, int E_L)
{
    int n = S.length();
    char str[n + 1];
    strcpy(str, S.c_str());

    char SUB[E_L];
    int count;
    for (count = 0;count < E_L;count++)
    {
        SUB[count] = S[E_P + count - 1];
    }
    SUB[count] = '\0';
    cout << "\n\tSUBSTRING : " << SUB;
}

string insert(string S, int E_p, string SUB)
{
    int n = S.length();
    SUB = SUB + " ";
    int ns = SUB.length();
    int total = n + ns + 1;
    char str[total];
    strcpy(str, S.c_str());
    char Sub[ns + 1];
    strcpy(Sub, SUB.c_str());

    string tep = S;

    char temp[total];
    strcpy(temp, tep.c_str());

    for (int i = E_p, j = 0;i < ns + E_p;i++, j++)
    {
        str[i] = Sub[j];
    }
    for (int i = E_p + ns, j = E_p;i < n + ns + 1;i++, j++)
    {
        str[i] = temp[j];
    }
    cout << "STRING : " << str << "\n";
    return(string(str));
}

string deleteS(string S, int pos, int len)
{
    int nm = pos + len;
    int n = S.length();
    char str[n + 1];
    strcpy(str, S.c_str());

    string tep = S;
    char temp[n + 1];
    strcpy(temp, tep.c_str());
    for (int i = 0, j = pos;j < n + 1;i++)
    {
        str[j] = temp[nm];
        nm = nm + 1;
        j = j + 1;
    }
    return (string(str));
}

int main()
{
    int n, E_POS, E_LEN, choice = 1, P, length, del_i, DS, REM, POS, ch;
    cout << "\n\t Substring operations \n";
    string S, SubS, SAM;
    cout << "\nEnter the string : ";
    getline(cin, S);
    do {
        cout << "\nOperations:\n1.substring extraction\n2.Insertion\n3.Deletion\n4.Replacement\n5.Exit\nEnter your option : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        { cout << "\n";
        cout << "Enter the position from which string is to be extracted : ";
        cin >> E_POS;
        cout << "Enter the length of the substring to extract : ";
        cin >> E_LEN;
        SUBSTRING(S, E_POS, E_LEN);
        break;}
        case 2:
        {
            cout << "\nEnter the string to be inserted : ";
            cin >> SubS;
            cout << "Enter the position from which the string is to be inserted : ";
            cin >> P;
            S = insert(S, P, SubS);
            break;}
        case 3:
        {
            cout << "\nEnter the position from which the string has to be deleted : ";
            cin >> del_i;
            cout << "Enter the length of string to be deleted : ";
            cin >> DS;
            S = deleteS(S, del_i, DS);
            cout << "\n\t STRING : " << S;
            break; }
        case 4:
        {
            cout << "\nEnter the position from which the string has to be replaced : ";
            cin >> POS;
            cout << "Enter the lenght of string to be removed : ";
            cin >> REM;
            cout << "Enter the string to be replaced : ";
            cin >> SAM;
            S = deleteS(S, POS, REM);
            S = insert(S, POS, SAM);
            break;}
        case 5:
        {
            choice = 0;
            break;
        }
        default:cout << "\nInvalid choice\n";
        }
        if (choice != 0)
        {
            cout << "\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice : ";
            cin >> choice;
        }
    } while (choice != 0);
    cout << "\n\tEND\n";
    return 0;
}