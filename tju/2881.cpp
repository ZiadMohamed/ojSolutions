#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,i;cin>>t;long long ans=0;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)cin.ignore(21,' '),cin>>arr[i];
        sort(arr,arr+n);ans=0;
        for(i=0;i<n;i++)ans+=abs(arr[i]-(i+1));
        cout<<ans<<'\n';
    }
    return 0;
}
