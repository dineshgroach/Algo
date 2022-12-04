// In case of a vector if number on inputs (n) is given then input and output can be performed by

int n;
    cin>>n;
    vector<int>v(n);
    for(auto&str:v)
    {
        cin>>str;
    }
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
