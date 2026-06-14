#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public: 
    int countStudents(vector<int> &arr, int pages) {
        int n = arr.size(); //size of array.
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                //add pages to current student
                pagesStudent += arr[i];
            }
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
/*
    TC : O(N * (sum(arr[])-max(arr[])+1)) SC : O(1)
*/

    int bruteforce(vector<int>& arr, int n, int m) {
        //book allocation impossible:
        if (m > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        for (int pages = low; pages <= high; pages++) {
            if (countStudents(arr, pages) == m) {
                return pages;
            }
        }
        return low;
    }

    int optimal(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
}; 

int main(){
    Solution o; 
    vector<int> arr = {25,46,28,49,24}; 
    int student = 4; 
    cout << "Ans : " << o.bruteforce(arr,arr.size(),student) << endl; 
    cout << "Ans : " << o.optimal(arr,arr.size(),student) << endl;

}