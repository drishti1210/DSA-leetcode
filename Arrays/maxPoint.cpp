class Solution {
public:
    using VI = vector<int>;
    int maxScore(VI& A, int K) {
        int N = A.size(),
            i = 0,
            j = N - K;
        auto total = accumulate(A.begin() + j, A.end(), 0),
             best = total;
        while (K--) best = max(best, total += A[i++] - A[j++]);  // slide window by K 👉
        return best;
    }
};