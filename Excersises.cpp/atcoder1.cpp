#include <bits/stdc++.h>
using namespace std;

bool test(int x) {
    if (x <= 299 && x >= 200)  
        return true;
    return false;
}
int main() {  
    int x;
    // cout << "Enter number: ";
    cin >> x;
    
    if (test(x)) {  
        cout << "Success" << endl;
    }
    else {
        cout << "Failure\n";  
    }
    
    return 0;
}

