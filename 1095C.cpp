#include <bits/stdc++.h> 

using namespace std; 

#define mp make_pair
#define pb push_back
#define mod 1000000007 // 10^9 +7 
#define vi vector<int>
#define vs vector<string>

int main()
{
    int n,k;
    cin>>n>>k;
    map<int,int>ans;
    queue<int>ms;
    for(int i=0; i<31; i++)
    {
        if(n&(1<<i))
        {
            ans[1<<i]=1;
            if(i>0) ms.push(1<<i) ;
        }
    }

    if(k<ans.size()){
        cout<<"NO";
        return 0;
    }

    int cnt=ans.size();
    while(cnt<k && !ms.empty())
    {
        int cur = ms.front();
        ms.pop();
        ans[cur]--;
        ans[cur/2]+=2;
        if(cur/2 >1)
        {
            ms.push(cur/2);
            ms.push(cur/2);
        }
        cnt++;
    }
    if(cnt <k)
    {
        cout<<"NO";
        return 0;
    }

    cout<<"YES"<<endl;
    for(auto i:ans)
    {
        for(int j=0; j<i.second ; j++)
            cout<<i.first<<" ";
    }

    return 0;
}
