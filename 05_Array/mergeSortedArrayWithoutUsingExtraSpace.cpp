#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        int arr3[n + m];
        int left = 0;
        int right = 0;
        int index = 0;

        while (left < n && right < m)
        {
            if (a[left] <= b[right])
            {
                arr3[index] = a[left];
                left++;
                index++;
            }
            else
            {
                arr3[index] = b[right];
                right++;
                index++;
            }
        }

        while (left < n)
        {
            arr3[index++] = a[left++];
        }
        while (right < m)
        {
            arr3[index++] == b[right++];
        }

        for (int i = 0; i < n + m; i++)
        {
            if (i < n)
                a[i] = arr3[i];
            else
                b[i - n] = arr3[i];
        }
    }
};

int main()
{
}