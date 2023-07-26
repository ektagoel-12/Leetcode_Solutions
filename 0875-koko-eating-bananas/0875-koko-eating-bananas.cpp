class Solution {
public:
    double solve(vector<int>piles,int h)
    {
            double hrs=0;
            for(int j=0;j<piles.size();j++)
            {
                hrs+=ceil((double)piles[j]/ (double)h);
            }
            return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        // if(h==n) return piles[n-1];
        int highest=INT_MIN;
        for(int i=0;i<n;i++)
        {
            highest=max(piles[i],highest);
        }
        int low=1,high=highest;
        while(low<=high)
        {
            int mid=(low+high)/2;
            double totalhrs=solve(piles,mid);
            if(totalhrs<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};