#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minWindow(string s, string t) {
        string str;
        map <char , int> mymap,bigmap;
    int p = 0,l_ind = 0, r_ind = 0, low = 10000000, start = 0, last = 0, diff, c = 0;

    for(char i = 'A'; i <= 'Z'; i++) {
        mymap[i] = 0;
        bigmap[i] = 0;
    }

    for(int i = 0; i < t.size(); i++) {
        mymap[t[i]] += 1;
        p += 1;
    }

    for( ; ; ) {
        if(p > 0) {
            if(mymap[s[r_ind]] > 0) {
                bigmap[s[r_ind]] += 1;
                if(bigmap[s[r_ind]] <= mymap[s[r_ind]])
                    p -= 1;
            }
            r_ind += 1;
            if(p > 0 && r_ind == s.size()) {
                break;
            }
        }
        if(p == 0) {
            diff = r_ind - 1 - l_ind;
            c++;
            if(diff < low) {
                low = diff;
                start = l_ind;
                last = r_ind - 1;
            }
            if(mymap[s[l_ind]] > 0) {
                bigmap[s[l_ind]] -= 1;
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
