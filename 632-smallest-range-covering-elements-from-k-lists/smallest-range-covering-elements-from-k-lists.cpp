class Solution {
public:
class Info{
    public:
    int data;
    int rindex;
    int cindex;
    Info(int x, int y, int z){
        this->data = x;
        this->rindex = y;
        this->cindex = z;
    }
};
class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int totalrows = nums.size();
        for(int row=0;row<totalrows;row++){
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        int ans_start = mini;
        int ans_end = maxi;
        
        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();
            int frontdata = front->data;
            int front_rindex = front->rindex;
            int front_cindex = front->cindex;

            mini = front->data;
            if((maxi - mini) < (ans_end - ans_start)){
                ans_start = mini;
                ans_end = maxi;
            }
            //as lists have different cols so instead of totalcols
            //we will take currtotalcols as when it ends it breaks
            int currtotalcols = nums[front_rindex].size();
            if(front_cindex+1 < currtotalcols){
                int element = nums[front_rindex][front_cindex+1];
                Info* temp = new Info(element, front_rindex, front_cindex+1);
                maxi = max(maxi, element);
                pq.push(temp);
            }
            else{
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};