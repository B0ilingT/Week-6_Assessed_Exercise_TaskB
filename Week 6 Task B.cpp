// Week 6 Task B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void DNAreplace(string S, string L, string R, string Y,string X)
{
    int LengthS = S.length(); // gets the length of every string
    int LengthL = L.length();
    int LengthR = R.length();
    int LengthY = Y.length();
    int LengthX = X.length();
    for (int i = 0; i <= (LengthS - LengthY); i++)
    {
        int yCheck = 0; // used to compare the length of y to see if it is present
        int rCheck = 0; // used to compare the length of r to see if it is present
        int lCheck = 0;
        while (yCheck < LengthY && S[i + yCheck] == Y[yCheck]) // if yCheck is less than the length of 
        {                                                      // Y && the position in S and the 
            yCheck++;                                          // Position in Y have equal values
        }                                                      // progress to the next letter
        if (yCheck == LengthY && (i-LengthL) >= 0)
        {
            while (rCheck < LengthR && S[i + yCheck + rCheck] == R[rCheck]) // same process is used to determine whether R is present
            {
                rCheck++;
            }
            while (lCheck < LengthL && S[i - LengthL + lCheck] == L[lCheck]) //while lcheck is lower than the number of letters in L && S at the position of i-LengthL+ lCheck is equal to the letter at position lCHeck in L increase lcheck by 1
            {
                lCheck++;
            }
            if (lCheck == LengthL && rCheck != LengthR)
            {
                string replace = S.replace(i, LengthY, X);
                cout << replace << " \n";
                S.replace(i, LengthX, Y);
            }           
        }       
    }
}

int main()
{
    string stringer;
    string toBeReplaced;
    string replacer;
    string before;
    string after;

    cout << "Please Enter a DNA Sequence: \n";
    cin >> stringer;
    cout << "Please Enter a fragment to be replaced \n";
    cin >> toBeReplaced;
    cout << "Please Enter a replacement fragment \n";
    cin >> replacer;
    cout << "Please Enter Preceding fragment \n";
    cin >> before;
    cout << "Please Enter Succeeding fragment \n";
    cin >> after;
    DNAreplace(stringer, before, after, toBeReplaced, replacer);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
