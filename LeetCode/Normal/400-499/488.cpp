#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=INT_MAX;
    int findMinStep(string board, string hand) {
        unordered_map<char,int>hand2cnt;
        for(char c:hand)hand2cnt[c]++;
        dfs(0,board,hand2cnt);
        return ans==INT_MAX?-1:ans;
    }
    void dfs(int usedCnt,string&board,unordered_map<char,int>&hand2cnt){
        if(usedCnt>=ans)return ;
        if(board.empty()){
            ans=min(ans,usedCnt);
            return;
        }
        for(int slow=0,fast=0;fast<=board.size();fast++){
            if(fast<board.size()&&board[slow]==board[fast])continue;
            //2个连续则需要1个，1个连续则需要两个
            int alreadyHad=fast-slow;
            int need=3-alreadyHad;
            if(hand2cnt.count(board[slow])&&hand2cnt[board[slow]]>=need){
                string newBoard=board.substr(0,slow)+board.substr(fast);
                update(newBoard);
                hand2cnt[board[slow]]-=need;
                dfs(usedCnt+need,newBoard,hand2cnt);
                hand2cnt[board[slow]]+=need;
            }
            //RRWWRRBBRR  WB,先R[B]RWWRRBBRR再R[B]RWW[W]RRBBRR
            if(need==1){
                //5种颜色，如果和[slow]不同色且hand有
                for(char color:{'R','Y','B','G','W'}){
                    if(color==board[slow]||hand2cnt.count(color)==0||hand2cnt[color]==0)continue;
                    string newBoard=board;
                    newBoard.insert(newBoard.begin()+slow+1,color);
                    hand2cnt[color]--;
                    dfs(usedCnt+1,newBoard,hand2cnt);
                    hand2cnt[color]++;
                }
            }
            slow=fast;
        }
    }
    void update(string &board){
       for(int slow=0,fast=0;fast<=board.size();fast++){
           if(fast<board.size()&&board[slow]==board[fast])continue;
           if(fast-slow>=3){
               board.erase(slow,fast-slow);
               fast=0;
           }
           slow=fast;
       } 
    }
};