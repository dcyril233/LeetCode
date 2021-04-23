#include <iostream>
#include <sstream>
#include <initializer_list>

#include <numeric>

#include <algorithm>
#include <memory>
#include <cmath>
#include <functional>
#include <optional>

#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

void quickSort(vector<int>& nums, int begin, int end) {
    if(begin >= end)
        return;
    int l = begin, r = end;
    int pivot = nums[l];
    while(l < r) {
        while(l < r && nums[r] >= nums[l])
            --r;
        nums[l] = nums[r];
        while(l < r && nums[l] <= nums[r])
            ++l;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quickSort(nums, begin, l-1);
    quickSort(nums, l+1, end);
}

void mergeSort(vector<int>& nums, int begin, int end, vector<int>& temp) {
    if(begin + 1 >= end)
        return;
    int mid = (begin + end) / 2;
    mergeSort(nums, begin, mid, temp);
    mergeSort(nums, mid, end, temp);
    int l = begin, r = mid, index = l;
    while(l < mid || r < end) {
        if(l >= mid || (r < end && nums[l] >= nums[r]))
            temp[index++] = nums[r++];
        else 
            temp[index++] = nums[l++];
    }
    for(int i = begin; i < end; ++i)
        nums[i] = temp[i];
}

void insertSort(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
            swap(nums[j], nums[j-1]);
        }
    }
}

void bubbleSort(vector<int>& nums) {
    bool swapped = false;
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = 0; j < nums.size() - i - 1; ++j) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void sellectionSort(vector<int>& nums) {
    int temp;
    for(int i = 0; i < nums.size(); ++i) {
        temp = i;
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[j] < nums[temp]) {
                temp = j;
            }
        }
        swap(nums[i], nums[temp]);
    }
}

int main() {
    cout << " 1:" << endl;
    {//quick sorting
        vector<int> nums {5, 6, 3, 9, 35};
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
        quickSort(nums, 0, nums.size()-1);
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
    }
    cout << " 2:" << endl;
    {//merge sort
        vector<int> nums {5, 6, 3, 9, 35};
        vector<int> temp(nums.size());
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
        mergeSort(nums, 0, nums.size(), temp);
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
    }
    cout << " 3:" << endl;
    {//insert sort
        vector<int> nums {5, 6, 3, 9, 35};
        vector<int> temp(nums.size());
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
        insertSort(nums);
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
    }
    cout << " 4:" << endl;
    {//bubble sort
        vector<int> nums {5, 6, 3, 9, 35};
        vector<int> temp(nums.size());
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
        bubbleSort(nums);
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
    }
    cout << " 5:" << endl;
    {//sellection sort
        vector<int> nums {5, 6, 3, 9, 35};
        vector<int> temp(nums.size());
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
        sellectionSort(nums);
        for(auto& num:nums)
            cout << num << ',';
        cout << endl;
    }
    return 0;
}