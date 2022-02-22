#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     string pushDominoes(string dominoes)
//     {
//         vector<int> indexs;
//         vector<char> lrs;
//         for (int i = 0; i < dominoes.size(); i++)
//         {
//             if (dominoes[i] != '.')
//             {
//                 indexs.push_back(i);
//                 lrs.push_back(dominoes[i]);
//             }
//         }
//         int index = 0;
//         while (index < indexs.size())
//         {
//             第一个是左边就无所谓
//             找到最左边非.的
//             if (lrs[index] == 'L')
//             {
//                 int temp = indexs[index] - 1;
//                 while (temp >= 0 && dominoes[temp] == '.')
//                 {
//                     dominoes[temp--] = 'L';
//                 }
//             }
//             else
//             {
//                 最后一个
//                 if (index == indexs.size() - 1)
//                 {
//                     int temp = indexs[index] + 1;
//                     while (temp < dominoes.size() && dominoes[temp] == '.')
//                     {
//                         dominoes[temp++] = 'R';
//                     }
//                 }
//                 else
//                 {
//                     if (lrs[index + 1] == 'R')
//                     {
//                         int temp = indexs[index] + 1;
//                         while (dominoes[temp] == '.')
//                             dominoes[temp++] = 'R';
//                     }
//                     else
//                     {
//                         int left = indexs[index] + 1;
//                         int right = indexs[index + 1] - 1;
//                         while (left < right)
//                         {
//                             dominoes[left++] = 'R';
//                             dominoes[right--] = 'L';
//                         }
//                         index += 2;
//                         continue;
//                     }
//                 }
//             }
//             index++;
//         }
//         return dominoes;
//     }
// };
class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
        vector<int> times(dominoes.size(), -1);

        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') {
                q.push(i);
                times[i] = 0;
            }
        }

        while (!q.empty()) {
            int now_p = q.front();
            q.pop();

            int next_p = now_p + (dominoes[now_p] == 'L' ? -1 : 1);
            if (next_p < 0 || next_p >= dominoes.size() || dominoes[now_p] == '.')
                continue;

            if (times[next_p] == -1) {
                q.push(next_p);
                dominoes[next_p] = dominoes[now_p];
                times[next_p] = times[now_p] + 1;
            } else if (times[next_p] == times[now_p] + 1) {
                dominoes[next_p] = '.';
            }

        }
        return dominoes;
    }
};
