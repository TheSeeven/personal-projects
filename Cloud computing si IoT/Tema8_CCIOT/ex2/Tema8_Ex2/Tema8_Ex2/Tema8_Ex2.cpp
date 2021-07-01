// Tema8_Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int number;

typedef tuple<string, string, number, number, number> BakedProduct;
struct BakedProductComparator {
    constexpr bool operator()(
        BakedProduct const& a,
        BakedProduct const& b)
        const noexcept     {
        return (get<3>(a) * get<4>(a)) < (get<3>(b) * get<4>(b));
    }
};



void printBakeryProduct(priority_queue<BakedProduct, vector<BakedProduct>, BakedProductComparator> pq) {
    while ( !pq.empty() ) {
        BakedProduct temp = pq.top();
        cout << "Name: " << get<0>(temp) << " Sweetness: " << get<1>(temp) << " Portion size: " << get<2>(temp) << " Stock: " << get<3>(temp) << " Price: " << get<4>(temp) << endl;
        pq.pop();
    }
}

void printBakeryProduct(priority_queue<BakedProduct> pq) {
    while ( !pq.empty() ) {
        BakedProduct temp = pq.top();
        cout << "Name: " << get<0>(temp) << " Sweetness: " << get<1>(temp) << " Portion size: " << get<2>(temp) << " Stock: " << get<3>(temp) << " Price: " << get<4>(temp) << endl;
        pq.pop();
    }
}


int main()
{
    cout << "Before sorting " << endl;
    priority_queue<BakedProduct> q;
    q.push(make_tuple("Vanilla Cake","medium",400,50,25));
    q.push(make_tuple("Ciocolate Cake", "high",400,60,27));
    q.push(make_tuple("Apple pie","low",350,45,15));
    q.push(make_tuple("Tiramisu","medium",350,30,32));
    q.push(make_tuple("House bread","none",600,120,4));
    
    printBakeryProduct(q);
    cout << endl << "After sorting" << endl;
    priority_queue<BakedProduct, vector<BakedProduct>, BakedProductComparator> soretdByStockPrice;
    soretdByStockPrice.push(make_tuple("Vanilla Cake", "medium", 400, 50, 25));
    soretdByStockPrice.push(make_tuple("Ciocolate Cake", "high", 400, 60, 27));
    soretdByStockPrice.push(make_tuple("Apple pie", "low", 350, 45, 15));
    soretdByStockPrice.push(make_tuple("Tiramisu", "medium", 350, 30, 32));
    soretdByStockPrice.push(make_tuple("House bread", "none", 600, 120, 4));
    printBakeryProduct(soretdByStockPrice);



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
