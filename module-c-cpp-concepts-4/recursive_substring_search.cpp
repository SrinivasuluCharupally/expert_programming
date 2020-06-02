// Recursive function to do substring search

// source : https://www.geeksforgeeks.org/recursive-function-to-do-substring-search/

// Recursive C++ program to find if a given pattern is 
// present in a text
#include<iostream>
using namespace std;
 
bool exactMatch(char *text, char *pat)
{
    if (*text == '\0' && *pat != '\0')
        return false;
 
    // Else If last character of pattern reaches
    if (*pat == '\0')
        return true;
 
    if (*text == *pat)
        return exactMatch(text + 1, pat + 1);
 
    return false;
}
 
// This function returns true if 'text' contain 'pat'
bool contains(char *text, char *pat)
{
    // If last character of text reaches
    if (*text == '\0')
        return false;
 
    // If current characts of pat and text match
    if (*text == *pat)
        return exactMatch(text, pat);
 
    // If current characts of pat and tex don't match
    return contains(text + 1, pat);
}
 
// Driver program to test above function
int main()
{
    cout << contains("geeksforgeeks", "geeks") << endl;
    cout << contains("geeksforgeeks", "geeksquiz") << endl;
    cout << contains("geeksquizgeeks", "quiz") << endl;
    return 0;
}
