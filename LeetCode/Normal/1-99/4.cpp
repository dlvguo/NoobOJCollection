#include <iostream>
#include <cstring>
using namespace std;

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
   if(nums1Size+nums2Size==1)
        return nums1Size?nums1[0]:nums2[0];

    int num1index = 0, num2index = 0, pointindex = (nums1Size + nums2Size) / 2, temp = 0, num = 0;
    double mid = 0.0;
    while (num1index < nums1Size || num2index < nums2Size)
    {

        if (num1index < nums1Size)
        {
            temp = nums1[num1index];
        }
        if (num2index < nums2Size &&((temp > nums2[num2index])||num1index==nums1Size))
        {
            temp = nums2[num2index];
            num2index++;
        }
        else
        {
            num1index++;
        }
        
        num++;
        if (num == pointindex)
        {
            mid = (nums1Size+nums2Size) % 2 ? 0 : temp;
        }
        if (num == (pointindex + 1))
        {
            mid=mid==0?temp:(mid+temp)/2;
            break;
        }
    }
    return mid;
}