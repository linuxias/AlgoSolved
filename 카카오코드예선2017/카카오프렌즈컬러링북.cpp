#define _CRT_SECURE_NO_WARNINS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, area_sum;
bool is_visited[101][101];

const vector<pair<int, int>> move_offset = {
    {0, 1},
    {0 , -1},
    {1, 0},
    {-1, 0}
};

inline void findArea(const int& x, const int& y, const vector<vector<int>>& picture) {
    is_visited[x][y] = true;
    area_sum++;
    for (const auto& off : move_offset) {
        auto sx = x + off.first;
        auto sy = y + off.second;
        
        if (sx >= M || sx < 0 || sy >= N || sy < 0)
            continue;
        if (is_visited[sx][sy])
            continue;
        if (picture[x][y] != picture[sx][sy])
            continue;
        findArea(sx, sy, picture);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    area_sum = 0;

    // Init visited check array
    fill(&is_visited[0][0], &is_visited[m][n], false);

    vector<int> checked_area;
    
    for (int sx = 0; sx < m; sx++) {
        for (int sy = 0; sy < n; sy++) {
            if (is_visited[sx][sy] == false && picture[sx][sy] != 0) {
                area_sum = 0;
                findArea(sx, sy, picture);
                checked_area.push_back(area_sum);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = checked_area.size();
    answer[1] = *max_element(checked_area.begin(), checked_area.end());
    return answer;
}

