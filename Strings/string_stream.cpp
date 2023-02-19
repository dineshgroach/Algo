#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s="BBBRWWRRRWBR";
    string token;
    stringstream ss(s);
    vector<string>v;
  // To seperate the string whenever the 'W' in the vector v
    while(getline(ss,token,'W'))
    {
        v.push_back(token);
    }
    for(auto &i:v)
    {
        cout<<i<<endl;
    }
    return 0;
}
