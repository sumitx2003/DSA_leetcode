class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()+nums2.size()==0)return 0;
        if(nums1.size()+nums2.size()==1){
            if(nums1.size()==1)return nums1[0];

            return nums2[0];
        }
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2!=0)return nums1[nums1.size()/2];

        double x=nums1[nums1.size()/2-1];
        double y=nums1[nums1.size()/2];
    
        return (x+y)/2;
    }
};