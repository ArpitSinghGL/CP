#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solution(int t)
{
    ll n , m;
    cin >> n >> m;

    vector <string> words;

    ll count = 0 , numOfChar = 0;

    for(int i = 0 ; i < n ; i++)
    {
        string word;
        cin >> word;

        words.push_back(word);
    }
    for(auto word : words)
    {
        if(numOfChar + word.length() <= m)
        {
            count++;
            numOfChar += word.size();
        }
        else
        {
            break;
        }
    }
    cout << count << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solution(t);
    }

    return 0;
}