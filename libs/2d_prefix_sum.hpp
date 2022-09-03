//
// Created by tuan on 31/08/2022.
//

#ifndef ACM_2D_PREFIX_SUM_HPP
#define ACM_2D_PREFIX_SUM_HPP

#include <vector>

class prefix_sum_2d {
private:
    std::vector<std::vector<long long>> p;
public:
    prefix_sum_2d(const std::vector<std::vector<long long>> &a) {
        p.resize(a.size(), std::vector<long long>(a[0].size(), 0));
        for (int i = 1; i < a.size(); i++) {
            for (int j = 1; j < a[0].size(); j++) {
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
            }
        }
    }

    long long sum(int sx, int sy, int ex, int ey) {
        return p[ex][ey] - p[ex][sy - 1] - p[sx - 1][ey] + p[sx - 1][sy - 1];
    }
};

#endif //ACM_2D_PREFIX_SUM_HPP
