#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::
    rush(){
        string s,t;
        cin>>s>>t;
        vector<int> v[30];
        for(i=0;s[i];i++){
            int k=s[i]-'a';
            v[k].pb(i);
        }
        int cur=-1;//字符串 s 的指针
        int ans=1;
        for(i=0;t[i];i++){
            int k=t[i]-'a';
            if(v[k].size()==0){
                ans=-1;
                break;
            }
            int pos=upper_bound(v[k].begin(),v[k].end(),cur)-v[k].begin();
            if(pos==v[k].size()){
                ans++;
                pos=0;
            }
            cur=v[k][pos];
        }
        cout<<ans<<endl;
    }
    //PAUSE;
    return 0;
}