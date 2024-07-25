class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int s,int e){
        if(s>=e) 
            return;
        int mid=(s+e)/2;
        mergeSort(nums,mid+1,e);
        mergeSort(nums,s,mid);
        merge(nums,s,e);
    }
    void merge(vector<int>& nums,int s,int e)
    {
        int mid=(s+e)/2;
        int l1=mid-s+1;
        int l2=e-mid;
        vector<int> first(l1), second(l2);
        int j=s;
        for(int i=0;i<l1;i++)
            first[i]=nums[j++];
        j=mid+1;
        for(int i=0;i<l2;i++)
            second[i]=nums[j++];
        int i1=0, i2=0;
        j=s;
        while(i1<l1 && i2<l2)
        {
            if(first[i1]<second[i2]) 
                nums[j++]=first[i1++];
            else 
                nums[j++]=second[i2++];
        }
        while(i1<l1) 
            nums[j++]=first[i1++];
        while(i2<l2) 
            nums[j++]=second[i2++];
    }
};