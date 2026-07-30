class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // int max = 0;
        // for ( int i = 0 ; i < stones.size() ; i++ ) {
        //     if ( max < stones[i] )
        //     max = stones[i];
        // }

        // vector<int> frq (max+1, 0);

        // for ( int i = 0 ; i < stones.size() ; i++ ) 
        // frq[i]++;

        // int fi = max, sec = max;

        // while ( fi > 0 ) {

        //     if ( frq[fi] % 2 == 0 ) {
        //         fi--;
        //         continue;
        //     }

        //     int i = min(fi-1, sec);
        //     while ( i > 0 && frq[i] == 0 ) i--;

        //     if ( i == 0 ) return fi;

        //     sec = i;
        //     frq[fi]--;
        //     frq[sec]--;
        //     frq[fi-sec]--;
        //     if ( fi - sec > sec ) fi = fi - sec;
        //     else fi = sec;
            
        // }

        // return fi;
    
        // int residual = 0;

        // sort(stones.begin(), stones.end());
        // int max;
        // int sec_max;

        // for ( int i = stones.size() - 1 ; i > 0 ; i-- ) {
        //     if ( stones[i] < residual ) {
        //         max = residual;
        //         sec_max = stones[i];
        //     }

        //     else if ( stones[i-1] < residual ) {
        //         max = stones[i];
        //         sec_max = residual;
        //     }

        //     else {
        //         max = stones[i];
        //         sec_max = stones[i-1]; 
        //     }

        //     residual = max - sec_max ;
        // }

        // return residual ;
        priority_queue<int> pq;

for (int x : stones)
    pq.push(x);

while (pq.size() > 1) {
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();

    if (x != y)
        pq.push(x - y);
}

return pq.empty() ? 0 : pq.top();

    }
};
