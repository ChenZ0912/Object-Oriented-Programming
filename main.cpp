//
//  main.cpp
//  Rec02
//
//  Created by Student on 9/14/18.
//  Copyright © 2018 Student. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class Hydrocarbon {
    vector<string> formula;
    int num_carbon;
    int num_hydrogen;
public:
    Hydrocarbon(int c, int d)
    : num_carbon(c), num_hydrogen(d){ }
    void add_formula(const string& f) {
        formula.push_back(f);
    }
    int get_c() {
        return num_carbon;
    }
    int get_h() {
        return num_hydrogen;
    }
};

vector<Hydrocarbon> aux;

int c_compare (Hydrocarbon& a, Hydrocarbon& b) {
    if(a.get_c() < b.get_c()) return -1;
    else if (a.get_c() == b.get_c()) return 0;
    else return 1;
}

int h_compare (Hydrocarbon& a, Hydrocarbon& b) {
    if(a.get_h() < b.get_h()) return -1;
    else if (a.get_h() == b.get_h()) return 0;
    else return 1;
}

void merge(vector<Hydrocarbon>& v, int lo, int mid, int hi, int(*cmp)(Hydrocarbon& a, Hydrocarbon b)) {
    
}

void mergeSort(vector<Hydrocarbon>& v, int lo, int hi, int(*cmp)(Hydrocarbon& a, Hydrocarbon b)) {
    if (lo > hi) {
        return;
    }
}

void mergeSort(vector<Hydrocarbon>& v) {
    aux.resize(v.size());
    mergeSort(v, 0, v.size() - 1, c_compare);
    mergeSort(v, 0, v.size() - 1, h_compare);
}





int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
