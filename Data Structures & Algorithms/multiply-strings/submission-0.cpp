class Solution {
public:
int n, m;
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") 
            return "0";
        

        n = num1.size();
        m = num2.size();  
        vector<int> ans (n+m+1, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        } 

        reverse(ans.begin(), ans.end());

        for ( int i = n+m ; i >=1 ; i-- ) {
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }

        string res = "";
        int zero = 0;
        while ( zero < n+m+1 && ans[zero] == 0 ) zero++;

        for ( int i = zero; i < n+m+1 ; i++ ) {
            res += to_string(ans[i]);
        }

        return res;

    }
};
