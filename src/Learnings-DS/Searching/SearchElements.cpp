#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int> vec, int num)
{
    bool isFound = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == num)
        {
            isFound = true;
            cout << "Element found at " << i << " th position" << endl;
            return isFound;
        }
    }
    return isFound;
}

bool binarysearch(vector<int> vec, int num)
{
    bool isFound = false;
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (high + low) / 2;
        if (vec[mid] == num)
        {
            cout << "element found" << endl;
            return true;
        }
        else if (vec[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

void insertElement(vector<int> &vec,int num)
{
    /* using lower_bound*/
    // auto it = std::lower_bound(vec.begin(),vec.end(),num);
    // vec.insert(it,num);
   
    /* using binary search*/
    int low =0; int high = vec.size()-1;
    while(low<=high)
    {
        int mid = low +(high - low)/2;
        if(num>vec[mid])
        {
                low = mid + 1;
        }
        else if(num<vec[mid])
        {
            high = mid -1;
        }

    }

    vec.insert(vec.begin() + low,num);

}
int main()
{
    vector<int> arr = {1, 2, 4, 6, 2, 3, 5,9};
  //  bool val = linearSearch(arr, 9);
    vector<int> arrray = {1, 2, 3, 5, 6, 7};
  //  bool value = binarysearch(arrray, 4);
    insertElement(arrray,4);
    for(auto it: arrray)
    {
        cout<<it<<endl;
    }

    // if (!val)
    //     cout << "Element not found" << endl;
        
    // if (!value)
    //     cout << "Element not found" << endl;
    return 0;
}