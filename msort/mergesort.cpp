#include <iostream>
#include <vector>
#include <cstdlib>

// Tanmoy Paul
std::vector<int> merge(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> temp;

    int size = (a.size() > b.size() ? a.size() : b.size());
    bool fin = false; 

    while(!fin)
    {
        if(a[0] < b[0])
        {
            temp.push_back(a[0]);
            a.erase(a.begin());
        }
        else
        {
            temp.push_back(b[0]);
            b.erase(b.begin());
        }

        if (a.size() == 0 || b.size() == 0) fin = true;
    }
    if (a.size() == 0)
    {
        for (int i = 0; i < b.size(); i++)
        {
            temp.push_back(b[i]);
        }
    }
    else if (b.size() == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            temp.push_back(a[i]);
        }
    }
    return temp;
}

//Sunqiao Lin
std::vector<int> msort(std::vector<int> x){
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> sorted;
    if(x.size()<2){
        return x;
    }
    int mid = x.size()/2;

    for(int i =0;i<mid;i++){
        a.push_back(x[i]);
    }
    for(int i = mid;i<x.size();i++){
        b.push_back(x[i]);
    }

    a = msort(a);
    b = msort(b);
    sorted = merge(a,b);
    return sorted;
}

void print_vector(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    srand(time(NULL));
    std::vector<int> a(20);
    int i;
    for(i=0;i<20;i++){
        a[i] = rand()%100;
    }

    std::cout << "Unsorted vector: " << std::endl;
    print_vector(a);
    a = msort(a);
    std::cout << "Sorted vector: " << std::endl;
    print_vector(a);
}

