// A concert hall has n rows numbered from 0 to n - 1, each with m seats, numbered from 0 to m - 1. You need to design a ticketing system that can allocate seats in the following cases:

// If a group of k spectators can sit together in a row.
// If every member of a group of k spectators can get a seat. They may or may not sit together.
// Note that the spectators are very picky. Hence:

// They will book seats only if each member of their group can get a seat with row number less than or equal to maxRow. maxRow can vary from group to group.
// In case there are multiple rows to choose from, the row with the smallest number is chosen. If there are multiple seats to choose in the same row, the seat with the smallest number is chosen.
// Implement the BookMyShow class:

// BookMyShow(int n, int m) Initializes the object with n as number of rows and m as number of seats per row.
// int[] gather(int k, int maxRow) Returns an array of length 2 denoting the row and seat number (respectively) of the first seat being allocated to the k members of the group, who must sit together. In other words, it returns the smallest possible r and c such that all [c, c + k - 1] seats are valid and empty in row r, and r <= maxRow. Returns [] in case it is not possible to allocate seats to the group.
// boolean scatter(int k, int maxRow) Returns true if all k members of the group can be allocated seats in rows 0 to maxRow, who may or may not sit together. If the seats can be allocated, it allocates k seats to the group with the smallest row numbers, and the smallest possible seat numbers in each row. Otherwise, returns false.
 

// Example 1:

// Input
// ["BookMyShow", "gather", "gather", "scatter", "scatter"]
// [[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
// Output
// [null, [0, 0], [], true, false]

// Explanation
// BookMyShow bms = new BookMyShow(2, 5); // There are 2 rows with 5 seats each 
// bms.gather(4, 0); // return [0, 0]
//                   // The group books seats [0, 3] of row 0. 
// bms.gather(2, 0); // return []
//                   // There is only 1 seat left in row 0,
//                   // so it is not possible to book 2 consecutive seats. 
// bms.scatter(5, 1); // return True
//                    // The group books seat 4 of row 0 and seats [0, 3] of row 1. 
// bms.scatter(5, 1); // return False
//                    // There is only one seat left in the hall.
 

// Constraints:

// 1 <= n <= 5 * 104
// 1 <= m, k <= 109
// 0 <= maxRow <= n - 1
// At most 5 * 104 calls in total will be made to gather and scatter.

// SOLUTION

class BookMyShow {
    int n;
    int m;
    vector<array<long long, 2>> stree; // segment tree that tracks (max, sum) of each segment
public:
    void build(int i, int p, int q) {
        if (p == q) {
            stree[i] = {m, m};
            return;
        }
        int r = (p + q) / 2;
        stree[i] = {m, (long long)(q-p+1)*m};
        build(2*i+1, p, r);
        build(2*i+2, r+1, q);
    }

    vector<int> query_max(int i, int p, int q, int k, int maxRow) {
        if (p > maxRow)
            return {};
        if (stree[i][0] < k)
            return {};
        if (p == q)
            return {p, (int)(m - stree[i][0])};
        int r = (p + q) / 2;
        vector<int> ret = query_max(2*i+1, p, r, k, maxRow);
        if (ret.size())
            return ret;
        return query_max(2*i+2, r+1, q, k, maxRow);
    }

    void update_max(int i, int p, int q, int row, int k) {
        if (p > row || q < row)
            return;
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        int r = (p + q) / 2;
        stree[i][1] -= k;
        update_max(2*i+1, p, r, row, k);
        update_max(2*i+2, r+1, q, row, k);
        stree[i][0] = max(stree[2*i+1][0], stree[2*i+2][0]);
    }

    long long query_sum(int i, int p, int q, int maxRow) {
        if (p > maxRow)
            return 0;
        if (q <= maxRow)
            return stree[i][1];
        int r = (p + q) / 2;
        return query_sum(2*i+1, p, r, maxRow) + query_sum(2*i+2, r+1, q, maxRow);
    }

    void update_sum(int i, int p, int q, int k, int maxRow) {
        if (p > maxRow)
            return;
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        int r = (p + q) / 2;
        stree[i][1] -= k;
        if (r+1 > maxRow || stree[2*i+1][1] >= k) {
            update_sum(2*i+1, p, r, k, maxRow);
        } else {
            k -= stree[2*i+1][1];
            update_sum(2*i+1, p, r, stree[2*i+1][1], maxRow);
            // Be aware: stree[2*i+1][1] updates while updating the left tree
            update_sum(2*i+2, r+1, q, k, maxRow);
        }
        stree[i][0] = max(stree[2*i+1][0], stree[2*i+2][0]);
    }


    BookMyShow(int n_in, int m_in) {
        n = n_in;
        m = m_in;

        int sz = 1;
        while (sz < n*2)
            sz <<= 1;
        stree.resize(sz);

        build(0, 0, n-1);
    }

    vector<int> gather(int k, int maxRow) {
        // cout << "gather " << k << " " << maxRow << endl;
        vector<int> ret = query_max(0, 0, n-1, k, maxRow);
        if (ret.size())
            update_max(0, 0, n-1, ret[0], k);
        return ret;
    }

    bool scatter(int k, int maxRow) {
        // cout << "scatter " << k << " " << maxRow << endl;
        long long cnt = query_sum(0, 0, n-1, maxRow);
        bool ret = cnt >= k;
        if (ret)
            update_sum(0, 0, n-1, k, maxRow);
        return ret;
    }
};
/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */