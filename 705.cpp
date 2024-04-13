/*
 * @Title: 设计哈希集合
 * @Label: 设计、数组、哈希表、链表、哈希函数
 * @Link: https://leetcode.cn/problems/design-hashset/description/
 * @Author: zhou
 * @Date: 2024-04-14 00:19:04
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 
#define MAX_LEN 100000  

using namespace std;

class MyHashSet {
    vector<int> set[MAX_LEN];

    int get_index(int num){
        return num % MAX_LEN;
    }
    int get_pos(int key, int index){
                for (int i = 0; i < set[index].size(); ++i) {
            if (set[index][i] == key) {
                return i;
            }
        }
    }
public:
    MyHashSet() {

    }
    
    void add(int key) {
        int index = get_index(key);
        int pos = get_pos(key, index);
        if (pos < 0)
        {
            set[index].push_back(key);
        }
        
    }
    
    void remove(int key) {
        int index = get_index(key);
        int pos = get_pos(key,index);
        if (pos >= 0){
            set[index].erase(set[index].begin() + pos);
        }
    }
    
    bool contains(int key) {
        int index = get_index(key);
        int pos = get_pos(key,index);
        return pos >= 0;
    }
};
int main()
{

    MyHashSet s;
    return 0;
}
