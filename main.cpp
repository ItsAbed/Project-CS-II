//
//  main.cpp
//  CSII project
//
//  Created by Mohamed Mansour on 23/04/2023.
// C++ program for Naive Pattern Searching algorithm and hamming distance

#include <string>
#include <iostream>
#include<fstream>
using namespace std;

void search(char* pat, char* txt);
int hammingDist(string str1, string str2);

// Driver's Code
int main()
{
    ifstream in("texttobecompared");
    string tex((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

    ifstream inn("patternpath");
    string patt((istreambuf_iterator<char>(inn)), istreambuf_iterator<char>());
    
    const int l = tex.length();
    const int length = patt.length();
    
    string text = tex.c_str();
    string pattern = patt.c_str();

    char* txt = new char[l + 1];
    char* pat = new char[length + 1];

    strcpy(pat, pattern.c_str());
    strcpy(txt, text.c_str());
    
      // Function call
    search(pat, txt);
    cout<<pattern<<"\n"<<text<<endl;
    cout<<"the hamming distance is " <<hammingDist(pattern, text)<<endl;
}

int hammingDist(string str1, string str2)
{
    int i = 0, count = 0;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}
//hamming distance function

void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    cout<<N<<" "<<M<<endl;
    cout<<pat<<"\n"<<txt<<endl;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        else if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index " << i<< endl;
    }
}
//naive pattern search algorithm(brute force search)
