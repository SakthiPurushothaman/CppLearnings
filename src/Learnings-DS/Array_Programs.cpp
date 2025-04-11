/*
General Array programs
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
/*
Best Use Cases for unordered_set:
Removing duplicates from an array.
Checking if a value exists in a dataset.
Storing unique values without needing additional data.

Best Use Cases for unordered_map:
Counting word/number occurrences in a dataset.
Caching results (e.g., memoization in DP).
Storing relationships (e.g., adjacency list in graphs).

*/
// Two pointers mentod
void reverseArray(vector<int> &array)
{
    int n = array.size();
    int start = 0;
    int end = n - 1;

    // Swap the elements at the start and end, moving towards the center
    while (start < end)
    {
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

/////////////////   Remove Duplicates for Unsorted Array /////////////////////////////////////////

/*This works for sorted array and array with consecutive duplicate numbers
Eg: {1,2,3,3,4,5,5},{1,3,3,,4,4,2,6,6}*/
void removeDuplicates(vector<int> &array)
{
    int n = array.size();

    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (array[j] != array[i])
        {
            // First element always remains the same. The addition of elements are done from array[1] position
            j++;
            array[j] = array[i];
        }
    }
    array.resize(j + 1);
}

/////////////////   Remove Duplicates for Unsorted Array /////////////////////////////////////////
/*Tc: O(n)    SC O(n)*/

/*This works for sorted array and array with consecutive duplicate numbers
Eg: {1,2,3,3,4,5,5},{1,3,3,,4,4,2,6,6}*/

void removeDuplicatesForUnsortedArray(vector<int> &array)
{
    unordered_set<int> set;
    int j = 0;
    for (int i = 0; i < array.size(); i++)
    {
        /* The find method of unordered_set searches for the element array[i] in the set.
        If the element is found, it returns an iterator pointing to the element.
        If the element is not found, it returns an iterator equal to seen.end() (a special iterator that represents "past-the-end" of the set).
        If true, it means the element array[i] is not present in the set.*/
        if (set.find(array[i]) == set.end()) // O(n)
        {
            set.insert(array[i]);
            array[j] = array[i];
            j++;
        }
    }
    array.resize(j);
}

void findMaxandMinElement(vector<int> array)
{
    unordered_map<int, int> mapp;

    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        mapp[array[i]] += 1;
    }
    int maxFreq = INT_MIN;
    int minFreq = __INT_MAX__;
    int maxEle = 0, minEle = 0;

    for (auto it : mapp)
    {
        int element = it.first;
        int frequency = it.second;
        if (frequency > maxFreq)
        {
            maxFreq = frequency;
            maxEle = element;
        }

        if (frequency < minFreq)
        {
            minFreq = frequency;
            minEle = element;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}
void greatestandSmallestElement(vector<int> array)
{
    int max = INT_MIN;
    int min = __INT_MAX__;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    cout << "The greatest  element is: " << max << "\n";
    cout << "The lowest  element is: " << min << "\n";
}
void duplicatearray(int arr[], int n)
{
    bool found = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            if (!found || arr[i] != arr[i - 2])
            {
                cout << arr[i] << " ";
                found = true;
            }
        }
    }
    if (!found)
    {
        cout << "No duplicates";
    }
}

void duplicateArrayUnsorted(int arr[],int n)
{
    unordered_set<int> unique_array;
     unordered_set<int>duplicate_array;

vector<int> array={1,2,3,1,2};
unordered_map<int,int> mp;
for(auto i: array)
{
mp[i]=++mp[i];
mp[arr[i]]++;

}


    for(int i=0;i<n;i++)
    {
        if(unique_array.find(arr[i])!=unique_array.end())
        {
                  duplicate_array.insert(arr[i]);
                
        }
        else
        {
            unique_array.insert(arr[i]);
        }
    }
   for(auto duparr:duplicate_array)
   {
    cout<<duparr<<endl;
   }
}

void reverseArrayusinfPointer(int *arr,int size)
{
    int* start = arr;
    int* end = arr + size -1;
    
    while(start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


// Left Rotation (K = 3)
// Move the first 3 characters to the end.
// Original: "12345678"
//87654321 
// reverse(array.begin(), array.begin() + K);        // Reverse first part
// reverse(array.begin() + K, array.end());          // Reverse second part
// reverse(array.begin(), array.end());              // Reverse the entire array
// Left Rotated: "45678123"
// Right Rotation (K = 3)
// Move the last 3 characters to the front.
// Original: "12345678"
// Right Rotated: "67812345"
// reverse(array.begin(), array.begin() + (N - K));  // Reverse first N-K elements
// reverse(array.begin() + (N - K), array.end());    // Reverse last K elements
// reverse(array.begin(), array.end());              // Reverse entire array


int main()
{
       int array[] = {1,5,3,2,1,2,4,2,7,3,8,0,3,9,5,7,4,6,9,0};
    int size = sizeof(array)/sizeof(array[0]);
 //   duplicatearray(array,size);
    vector<int> arr = {4, 2, 4, 3, 2, 2, 1, 2, 7, 8, 9};

    // removeDuplicates(arr);
    // reverseArray(arr);
    // removeDuplicatesForUnsortedArray(arr);
    // findMaxandMinElement(arr);
  //  greatestandSmallestElement(arr);
    duplicateArrayUnsorted(array,size);
    // for (auto it : arr)
    // {
    //     cout << it << endl;
    // }
    return 0;
}