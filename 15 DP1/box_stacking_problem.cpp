#include<bits/stdc++.h>

using namespace std ;
bool small(vector<int> b1,vector<int> b2)
{
    if(b1[0]<b2[0] and b1[1]<b2[1] and b1[2]<b2[2])
    {
        return true; 
    }
    return false;
}
bool comp(vector<int> b1,vector<int> b2)
{
    return b1[2]<b2[2];
}
int solve(vector<vector<int>> &v,int n)
{
    
    sort(v.begin(),v.end(),comp);
    vector<int> dp(n,0);
    for(int i = 0;i<n;i++){
        dp[i] = v[i][0];
    }
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<i; j++)
        {
            if(small(v[j],v[i]))
            {

                int current = v[i][2];
                if(dp[j]+current >dp[i])
                {
                    dp[i] = dp[j]+current;
                }
            }
        }
    }
    return *max_element(dp.begin(),dp.end());

    
}
int main()
{
    vector<vector<int>> v = {{2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}};
    int n = v.size();
    int k = solve(v,n);
    cout<<k<<endl;
   
    

}