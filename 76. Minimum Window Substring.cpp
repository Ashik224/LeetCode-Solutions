#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minWindow(string s, string t) {
        string str;
        map <char , int> mymap,bigmap;
    int p = 0,l_ind = 0, r_ind = 0, low = 10000000, start = 0, last = 0, diff, c = 0;

    //Intialize the maps by 0
    for(char i = 'A'; i <= 'Z'; i++) {
        mymap[i] = 0;
        bigmap[i] = 0;
    }

    //increment the mymap values related to the small string chars
    for(int i = 0; i < t.size(); i++) {
        mymap[t[i]] += 1;
        p += 1;
    }

    for( ; ; ) {
        if(p > 0) {
            //check if the char is present in the small string
            if(mymap[s[r_ind]] > 0) {
                //count how many times that char is present in the big string
                bigmap[s[r_ind]] += 1;
                //decrement the p only if the char is less than or equal to
                //the small string's character's count
                if(bigmap[s[r_ind]] <= mymap[s[r_ind]])
                    p -= 1;
            }
            r_ind += 1;
            //This means, no more expected window is possible
            if(p > 0 && r_ind == s.size()) {
                break;
            }
        }
        if(p == 0) {
            //calculate the diff
            diff = r_ind - 1 - l_ind;
            c++;
            if(diff < low) {
                low = diff;
                start = l_ind;
                last = r_ind - 1;
            }
            //start traversing with the left index
            if(mymap[s[l_ind]] > 0) {
                bigmap[s[l_ind]] -= 1;
                //check if a char is still more than the required
                //amount after decrementing
                if(bigmap[s[l_ind]] >= mymap[s[l_ind]])
                    l_ind += 1;
                else if(bigmap[s[l_ind]] < mymap[s[l_ind]]) {
                    p += 1;
                    if(r_ind == s.size()) break;
                    l_ind += 1;
                }
            }
            else l_ind += 1;
        }
    }

    if(c == 0) {
        str = "";
        return str;
    }
    else {
        for(int i = start; i <= last; i++) {
            str += s[i];
        }
        return str;
    }

    }
};

int main()
{
    Solution solutionObj;
    string s,t;
    cin >> s >> t;
    string str1 = solutionObj.minWindow(s , t);
    cout << str1 << endl;
}
