// STL used to create the unique permutation of a string or a vector, working is shown below

    string s;
    cin >> s;
// If want to avoid duplicate permutations then sort it
    sort(s.begin(), s.end());
    vector<string> ans;
    string chk = s;
    ans.push_back(chk);
    while (true)
    {
        next_permutation(s.begin(), s.end());
        if (chk == s)
        {
            break;
        }
        else
        {
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << endl;
    }
