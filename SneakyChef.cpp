#include <iostream>
using namespace std;
void chef(string &s1, string s2);

/* CS31 PROBLEM: SNEAKY CHEF
 * given 2 strings, trace the function chef() to find the output of main()
 * CAVEAT #1: chef() will only permanently modify one of the parameters, which is
 * passed by reference. The other, which is passed by value, will not be modified
 * CAVEAT #2: a good understanding of for loops is needed because you will have
 * to realize that the for loop is examining the two strings backwards (from index
 * n-1 to 0)
 * CAVEAT #3: The student should also understand the meaning of % (remainder), this
 * needs to be paired with acknowledging that calling a function will executing its
 * output statements
 */

void chef(string &s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    for (int i = 1; i <= min(m, n); i++) {
        // iterate the length of the shorter string
        if (s1[m-i] < s2[n-i]) {
            s1 = s1.substr(m-i+1);
            s2 = s2.substr(n-i+1);
            cout << i/2 << endl;
            break;
        } else if (s1[m-i] > s2[n-i]) {  // Hint: you'll break here!
            s1 = s1.substr(0, m-i+1);
            s2 = s2.substr(0, n-i+1);
            cout << i%2 << endl;
            break;
        } else {  // Hint: you'll hit this first!
            continue;
        }
    }
}

int main() {
    string s1 = "smoburger";
    string s2 = "nachoburger";
    chef(s1, s2);
    cout << s1 << endl << s2; 
}

/* CORRECT OUTPUT:
 >> 0
 >> sm
 >> nachoburger
 */

