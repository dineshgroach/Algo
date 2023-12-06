// This code is used to calculate the average waiting time
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++)
    {
        v.push_back({arrivalTime[i],burstTime[i]});
    }
    sort(begin(v),end(v));
    int i = 0, wt = 0, curr = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>>pq;
    while(i < n)
    {
        if(pq.empty())
        {
            curr = max(curr, v[i].first);
            pq.push({v[i].second,v[i].first});
            i++;
        }
        else if(v[i].first < curr)
        {
            pq.push({v[i].second,v[i].first});
            i++;
        }
        else
        {
            auto node = pq.top();
            pq.pop();
            wt += curr - node.second;
            curr += node.first;
        }
    }
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        wt += curr - node.second;
        curr += node.first;
    }
    return (1.0)*wt/n;
}
