#include<iostream>
#include<String>

using namespace std;

  int String(string s) {
     int L_count = 0;
     int R_count = 0;
     int count_substring =0;

     for(int i=0; i < s.length(); i++){
        if (s[i] == 'L') {
            L_count ++ ;
        }
        else {
            R_count ++;
        }

        if( L_count ==R_count ) {
             count_substring ++ ;
             L_count = 0;
             R_count = 0;
        }
     }
     return count_substring ;




  }

int main() {
      string s ;
      cin >> s;

      cout << String(s);

}
