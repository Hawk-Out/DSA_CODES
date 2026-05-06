//Top DOwn Approach
#include <iostream>
#include <vector>
using namespace std;
//Driver Code Ends
int nthFibonacciUtil(int n, vector<int>& F) {
  
    // Base case
    if (n <= 1) {
        return n;
    }
    // Check if the result is
    // already in the F table
    if (F[n] != -1) {
        return F[n];
    }
    // calculate Fibonacci number
    // and store it in F table
    F[n] = nthFibonacciUtil(n - 1, F) 
          + nthFibonacciUtil(n - 2, F);
    return F[n];
}
int nthFibonacci(int n) {
    // Create a F table and 
    // initialize with -1(invalid value)
    vector<int> F(n + 1, -1);
    
    return nthFibonacciUtil(n, F);
}
//Driver Code Starts
int main() {
    int n = 5;
    int result = nthFibonacci(n);
    cout << result;
}


//Bottom Up Approach

#include <iostream>
#include <vector>
using namespace std;
//Driver Code Ends
int nthFibonacci(int n){
    
    // base cases
    if (n <= 1)
        return n;
    vector<int> F(n + 1);
    F[0] = 0; F[1] = 1;
    // solving the smaller problems first
    // and finally solving the complete problem
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}
int main(){
    int n = 5;
    int result = nthFibonacci(n);
    cout << result << endl;
    return 0;
}