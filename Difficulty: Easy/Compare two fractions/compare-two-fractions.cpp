//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
    int a=0,b=0;
    string temp1="",temp2="";
    double first,second;
    bool alert=false;
    for (char x:str){
        if (x=='/'){
            alert=true;
            temp2+=x;
            continue;
        }else if (x==','){
            alert=false;
            first=(double)a/b;
            a=0;
            b=0;
            temp1=temp2;
            temp2="";
            continue;
        }else if (x==' '){
            continue;
        }
        temp2+=x;
        if (!alert){
            a=a*10+(x-'0');
        }else{
            b=b*10+(x-'0');
        }
    }
    second=(double)a/b;
    if (first>second)return temp1;
    else if (second>first) return temp2;
    else return "equal";
      
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends