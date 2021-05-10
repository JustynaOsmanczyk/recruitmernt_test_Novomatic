#include <vector>
#include <iostream>
#include <unordered_map>
#include<cassert>
using namespace std;

template <typename T>
class my_vector {
    vector<T> data;
    unordered_map<T, int> indices;

public:

    void push_back(const T& t) {
        if (indices.count(t) > 0){
            // element already in this vector
            return;
        }
        indices[t] = data.size();
        data.push_back(t);
    }

    const T& operator[](const int idx) const {
        assert(data.size() > idx && idx >= 0);
        return data[idx];
    }

    void erase(const T& t) {
        if (indices.count(t) == 0) {
            // no such element
            return;
        }
        int idx = indices[t];
        swap(data[idx], data.back());
        indices[data[idx]] = idx;
        indices.erase(data.back());
        data.pop_back();
    }

    int size(){
        return data.size();
    }
};

int main(){
    my_vector<int> V;
    for(int i = 0; i < 15; i++){
        V.push_back(7 * i + 4);
    }
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
    cout << "\n---------------\n Erase 53\n";
    V.erase(53);
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
    cout << "\n---------------\n Erase 54\n";
    V.erase(54);
    for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
    }
    cout << "\n---------------\n";

    my_vector<string> W;
    for(int i = 0; i < 15; i++){
        string s = "";
        for(int x = 0; x < 3; x++){
            s += 'a' + i + x;
        }
        W.push_back(s);
    }
    for(int i = 0; i < W.size(); i++){
        cout << W[i] << " ";
    }
    cout << "\n---------------\n Erase ghi\n";
    W.erase("ghi");
    for(int i = 0; i < W.size(); i++){
        cout << W[i] << " ";
    }
    cout << "\n---------------\n Erase fff\n";
    W.erase("fff");
    for(int i = 0; i < W.size(); i++){
        cout << W[i] << " ";
    }
    cout << "\n---------------\n";

}

