#include <bits/stdc++.h>
#include <wchar.h>
using namespace std;

vector< set< wchar_t > > alphabets(10);
string lang[10] = {"be", "de", "en", "fr", "hy", "it", "ka", "ru", "sv", "uk"};

void fillAlphabet()
{
    for (int i = 0;i < alphabets.size();i++)
    {
        string path = "mosh2019/txts/" + lang[i] + ".txt";
        wifstream fin(path);
        wchar_t a;
        while (fin >> a)
            alphabets[i].insert(a);
    }
}

signed main()
{
    fillAlphabet();
    set< wchar_t > l;

    wifstream fin("mosh2019/C1/4.txt");

    wchar_t a;
    fin >> a >> a >> a;

    vector< bool > poss(10, 1);


    while (fin >> a)
    {
        vector< int > iAlpha(poss.size(), 0);
        for (int i = 0;i < iAlpha.size();i++)
        {
            iAlpha[i] = alphabets[i].count(a);
        }
        bool letter = 0;
        for (int i = 0;i < iAlpha.size();i++)
        {
            if (iAlpha[i] != 0)
                letter = 1;
        }
        if (letter)
        {
            for (int i = 0;i < iAlpha.size();i++)
            {
                if (iAlpha[i] == 0)
                    poss[i] = 0;
            }
        }
    }
    for (int i = 0;i < poss.size();i++)
        if (poss[i])
            cout << lang[i];
    return 0;
}
