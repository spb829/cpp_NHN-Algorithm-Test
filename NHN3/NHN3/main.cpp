//
//  main.cpp
//  NHN3
//
//  Created by Macbook Pro on 2017. 9. 26..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
int n;
vector<vector<char>> inputs;

struct Tile{
public:
    bool top = false;
    bool right = false;
    bool bottom = false;
    bool left = false;
    
    Tile(bool a, bool b, bool c, bool d){
        this->top = a;
        this->right = b;
        this->bottom = c;
        this->left = d;
    }
    
    bool operator==(const Tile &other) const{
        if ((this->top == other.top) &&
            (this->bottom == other.bottom) &&
            (this->left == other.left) &&
            (this->right == other.right)) {
                return true;
            }
        return false;
    }
    
    bool operator!=(const Tile &other) const {
        return !(*this == other);
    }
};

Tile tiles[16] = {
    Tile(0,0,0,0), Tile(1,0,0,0), Tile(0,0,0,1), Tile(1,0,0,1),
    Tile(0,1,0,0), Tile(1,1,0,0), Tile(0,1,0,1), Tile(1,1,0,1),
    Tile(0,0,1,0), Tile(1,0,1,0), Tile(0,0,1,1), Tile(1,0,1,1),
    Tile(0,1,1,0), Tile(1,1,1,0), Tile(0,1,1,1), Tile(1,1,1,1)
};

int findIndexOfTile(Tile t){
    for (int i = 0; i < 16; i++)
        if (tiles[i] == t)
            return i;
    
    return -1;
}

void solution(){
    for (int i = 0; i < n; i++){
        //cout << i << " : " << endl;
        for (int j = 0; j < n; j++){
            //cout << inputs[i][j] << "\t";
            char c = inputs[i][j];
            if (j)
                cout << " ";
            if (c == '0'){
                cout << "-1";
                continue;
            }
            
            bool top = false;
            bool right = false;
            bool bottom = false;
            bool left = false;
            
            // 첫번째 행이 아니고 위 행이 같은 그룹이면..
            if (i && inputs[i-1][j] == c)
                top = true;
            if (j && inputs[i][j-1] == c)
                left = true;
            if (i < n-1 && inputs[i+1][j] == c)
                bottom = true;
            if (j < n-1 && inputs[i][j+1] == c)
                right = true;
            
            Tile need = Tile(top, right, bottom, left);
            
            int value = findIndexOfTile(need) + (c - 'A') * 16;
            
            if (to_string(value).length() == 1)
                cout << " ";
            
            cout << value;
        }
        cout << endl;
    }
}

void inputData(){
    string line;
    
    // Get size of N
    getline(cin, line);
    n = stoi(line);
    
    // Init Input Texts (array of char)
    for (int i = 0; i < n; i++){
        getline(cin, line);
        istringstream iss(line);
        
        inputs.push_back(vector<char>(istream_iterator<char>(iss), istream_iterator<char>()));
    }
    
    
}

void printData(){
    int a = 0;
    cout << endl << "data :" << endl;
    for (auto i = inputs.begin(); i != inputs.end(); ++i){
        cout << a++ << " : " << endl;
        for (auto j = i->begin(); j != i->end(); ++j){
            cout << *j << "\t";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    inputData();
    
    solution();
    return 0;
}
