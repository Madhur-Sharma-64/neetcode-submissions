class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        int i = 0;
        int j = prices.size() - 1 ;
        int ans = 0;

        while ( i < prices.size() ){

           // int diff = max - min;

            if ( min > prices[i]){
                min = prices[i];
               // i++;
            }

           // if ( max < prices[j] ){
              //  max = prices[j];
                //j--;
            //}

            //int diff = max - min;

            if ( max < prices[i] - min )
            max = prices[i] - min;

            i++;
            j--;

        }
        return max;
    }
};
