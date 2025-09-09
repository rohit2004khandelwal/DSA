class Solution {
public:
    int MOD = 1e9 + 7;
    int n, delay, forget;
    vector<int> t;

    //This returns number of people who first learn the secret on "day"
    int solve(int day) {
        if (day == 1) 
            return 1;
        if (day <= 0) 
            return 0;
            
        if (t[day] != -1)
            return t[day];

        long long result = 0;
        // people who can share today are those who learned it in
        // [day - forget + 1, day - delay]
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                result = (result + solve(prev)) % MOD;
            }
        }
        return t[day] = (int) result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->n      = n;
        this->delay  = delay;
        this->forget = forget;
        t.assign(n + 1, -1);

        int total = 0;
        // only count people who haven't forgotten by day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + solve(day)) % MOD;
            }
        }
        return total;
    }
};