class Solution {
public:
int firstOcc(vector<int> arr,int n,int x)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        {
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]>x) high=mid-1;
        else {low=mid+1;}
    }
    return ans;
}
int lastOcc(vector<int> arr,int n,int x)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        {
           ans=mid;
           low=mid+1;
        }
        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int n=nums.size();
    v.push_back(firstOcc(nums,n,target));
    v.push_back(lastOcc(nums,n,target));
    return v;
    }
};