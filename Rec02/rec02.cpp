//
//  main.cpp
//  Rec02
//
//  Created by CHEN ZHOU on 9/14/18.
//  N ID : N13392410

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Hydrocarbon {
    vector<string> name_p;
    int num_carbon;
    int num_hydrogen;
};

bool lessCmp (const Hydrocarbon& a, const Hydrocarbon& b) {
    if(a.num_carbon < b.num_carbon) return true;
    else if (a.num_carbon == b.num_carbon && a.num_hydrogen < b.num_hydrogen) {
        return true;
    }
    return false;
}

void merge(vector<Hydrocarbon>& v, vector<Hydrocarbon>& aux, int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        aux[k] = v[k];
    }
    
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            v[k] = aux[j++];
        }
        else if (j > hi) {
            v[k] = aux[i++];
        }
        else if (lessCmp(v[j], v[i])) {
            v[k] = aux[j++];
        }
        else {
            v[k] = aux[i++];
        }
    }
}

void mergeSort(vector<Hydrocarbon>& v, vector<Hydrocarbon>& aux, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    mergeSort(v, aux, lo, mid);
    mergeSort(v, aux, mid + 1, hi);
    merge(v, aux, lo, mid, hi);
}

void mergeSort(vector<Hydrocarbon>& v) {
    vector<Hydrocarbon> aux;
    aux.resize(v.size());
    mergeSort(v, aux, 0, (int)v.size() - 1);
    mergeSort(v, aux, 0, (int)v.size() - 1);
}


void openStream(ifstream& iput) {
    string filename;
    cout << "Type the input file name" << endl;
    cin >> filename;
    iput.open(filename);
    if (!iput) {
        filename.clear();
        cout << "Failed to open the file, try it again" << endl;
        cin >> filename;
        iput.open(filename);
    }
}

void readFromStream(ifstream& input, vector<Hydrocarbon>& vc) {
    string name;
    string formula;
    char C;
    char D;
    int num_C;
    int num_H;
    while (input >> name >> C >> num_C >> D >> num_H) {
        bool found = false;
        for (Hydrocarbon& h : vc) {
            if (h.num_carbon == num_C && h.num_hydrogen == num_H) {
                found = true;
                h.name_p.push_back(name);
                break;
            }
        }
        if (!found) {
            Hydrocarbon new_Element;
            new_Element.num_carbon = num_C;
            new_Element.num_hydrogen = num_H;
            new_Element.name_p.push_back(name);
            vc.push_back(new_Element);
        }
        
    }
}

void printVc(const vector<Hydrocarbon>& vc) {
    for (const Hydrocarbon& h : vc) {
        cout << 'C' << h.num_carbon << 'H' << h.num_hydrogen << ' ';
        for (const string& str : h.name_p) {
            cout << str << ' ';
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream input;
    vector<Hydrocarbon> vc;
    openStream(input);
    readFromStream(input, vc);
    input.close();
    mergeSort(vc);
    printVc(vc);
    return 0;
}

