# include <bits/stdc++.h>
using namespace std;

   int main() {
    int N;
    cin >> N;
    
    int logged_in = 0;
    int error_count = 0;
    
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        
        if (S == "login") logged_in = 1;

        else if (S == "logout") logged_in = 0;

        else if (S == "private" && logged_in == 0) error_count++;
    }
    
    cout << error_count << endl;
    return 0;
}



    



