#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

string reverseString(string &str)
{
    int n = str.length();
    string revstring;
    for (int i = n - 1; i >= 0; i--)
    {
        revstring += str[i];
    }
    return revstring;
    // for(int i =0;i<n/2;i++)
    // {
    //     std::swap(str[i],str[n-i-1]);
    // }
}

string revSentence(const string &str)
{
    stringstream ss(str);
    string revword;
    string word;

    while (ss >> word)
    {
        revword = word + " " + revword;
    }

    return revword;
}

// Program to reverse word in a string Eg:olleH dlrow
// TC: o(n) SC:O(n)
string revWordInSentence(const string &str)
{
    stringstream ss(str);
    string revword;
    string word;
    while (ss >> word)
    {
        int i = 0;
        int j = word.length() - 1;

        while (i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }

        if (!revword.empty())
        {
            revword += " ";
        }
        revword += word;
    }
    return revword;
}

void countFrequency(const string &str)
{
    unordered_map<string, int> mapp;
    stringstream ss(str);
    string word;
    while (ss >> word)

    {
        mapp[word]++;
    }

    for (auto ch : mapp)
    {
        cout << ch.first << " " << "appears" << ch.second << " " << "times" << endl;
    }
}

string removeDelimiters(const string &str)
{
    string result;
    for (auto ch : str)
    {
        if (isalnum(ch))
        {
            result += ch;
        }
    }
    return result;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<pair<string,int>> checkAnagram(vector<string> str)
{
    unordered_map<string,vector<string>> mapp;
    
    
    for(auto word: str)
    {
     string str1 = word;
      sort(str1.begin(),str1.end());
      mapp[str1].push_back(word);
      
    }
    

    for(auto i : mapp)
    {
       for(auto j : i.second)
       {
            cout<<j<<endl;
       }
        
    }
         
    return result;
}


int main()
{
	vector<string> strs =  {"eat","tea","tan","ate","nat","bat","bet"};
	 checkAnagram(strs);
// 	for(auto i:result )
// 	{
// 	    cout<<i.first<<endl;
// 	}

	                         return 0;
}
bool IsPalindrome(const string &str)
{
    int i = 0;
    int j = str.length() - 1;
    bool res;

    while (i < j)
    {
        if (!isalnum(str[i]))
        {
            i++;
            continue;
        }
        if (!isalnum(str[j]))
        {
            j--;
            continue;
        }
        if (tolower(str[i]) != tolower(str[j]))
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int convertToInteger(const string &str)
{
    int value, result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            continue;
        }

        value = str[i] - '0';
        result = result * 10 + value;
    }

    return result;
}

int countDuplicates(string& str1,string & str2)
{
    unordered_set<char> str3;
    int count=0;

    for(auto ch : str2)
    {
        str3.insert(ch);`
    }
 
    for(auto ch: str1)
    {
        if(str3.find(ch)!=str3.end())
        {
             count++;
        }
    }
    return count;
}

string removeDuplicates(string &str1)
{
   unordered_set<char> set;
   string str2;

   for(auto ch:str1)
   {
    if(set.find(ch)==set.end())
    {
           str2+=ch;
           set.insert(ch);
    }
   } 
   return str2;
}

int main() {
    std::string str = "1223324325346";
    int carry = 1; // Start with +1

    // Iterate from the last digit to the first
    for (int i = str.size() - 1; i >= 0 && carry > 0; --i) {
        int digit = str[i] - '0';  // Convert char to int
        digit += carry;           // Add the carry
        carry = digit / 10;       // Update carry for the next digit
        str[i] = (digit % 10) + '0'; // Store the result back as a char
    }

    // If there's still a carry, prepend '1' to the string
    if (carry > 0) {
        str.insert(str.begin(), '1');
    }

    std::cout << "Updated string: " << str << std::endl;

    return 0;
}
int main()
{
   // string str = "1asllr234sdfdsf5";

    // string str1 = revWordInSentence(str);

    // string str1 = reverseString(str);
    // string str1 = revSentence(str);
    // countFrequency(str);
    // string str1 =  removeDelimiters(str);
    // cout << str1 << endl;
    // bool result = IsPalindrome(str);
    // if (result)
    // {
    //     cout << "It is paindrome" << endl;
    // }
    // else
    // {
    //     cout << "It is not a palindrome" << endl;
    // }
   // int value = convertToInteger(str);
    //cout << value << endl;
    string str1 = "aabcddekll12@";
    string str2 = "bb2211@5";
    int count = countDuplicates(str1, str2);
        cout << count << endl;
       string str3 = removeDuplicates(str1);
        cout << str3 << endl;

    return 0;
}