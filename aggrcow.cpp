/*
https://www.spoj.com/problems/AGGRCOW/

AGGRCOW - Aggressive cows
#binary-search

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls,
such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?

Input
-----
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
------
For each test case output one integer: the largest minimum distance.
*/


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

/*
Example:

Input
-----
1
5 3
1
2
8
4
9

Output
------
3
*/
