class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;
        for(int i=1; i<=8; i++){
            q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr>=low && curr<=high){
                result.push_back(curr);
            }
            int last_digit=curr%10;
            if(last_digit<9){
                long long next_num=(long long)curr*10+(last_digit+1);
                if(next_num<=high){
                    q.push(next_num);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};