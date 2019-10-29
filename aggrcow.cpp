#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    //Iterating over the test cases
    while(t--)
    {
        ll n,c;
        cin>>n>>c;                              //input the length of array and no of cows
        ll a[100009];                           //array to store the locations of sheds
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        sort(a,a+n);                            //sorting the array of locations
        ll i=1,j=1000000001,ans=0;
        
        while(i <= j)                           //while the range does not cross upper limit j
        {
            ll mid=((j+i)/2);                   //find middle element of the range

            int fi=a[0],count=1;                //first cow occupies shed a[0] and counter is increased
            
            for(int k=1;k<n;k++)                //iterate over the array to check each cow is allotted or not
            {
                if(a[k]-fi >= mid)              //if the kth cow has the "mid" distance from (k-1)th cow
                    count++,fi=a[k];            //increase allotted no of cows and set previous cow
            }
            if(count < c)                       //if all cows are not alloted
                j=mid-1;                        //decrease the upper limit to "mid-1"
            else
            {
                ans=mid;                        //the point where the function inverts itself or below
                i=mid+1;                        //or the lower limit has to be increased to "mid+1"
            }
        }
        cout<<"ans:"<<ans<<endl;
    }
    return 0;
}