#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}
long long MaxPairwiseProductF(const std::vector<int>& numbers) {
    int n = numbers.size();
    long long big1=0;long long big2=0;
    long long max_product;
    for(int i=0; i<n;i++){
        if(numbers[i]>big1){
            big2=big1;
            big1=numbers[i];
        }else if(numbers[i]>big2){
            big2=numbers[i];
        }
    }
    max_product=big1*big2;
    return max_product;
}

int main() {
    /*
    while(true){
        int n2;
        n2=rand()%100000+2;
        std::cout<<n2<<std::endl;
        std::vector<int> a;
        for(int i=0; i<n2;i++){
            a.push_back(rand()%100000);
        }
        for(auto c:a){
            std::cout<<c<<' ';
        }
        std::cout<<'\n';
        long long res1=MaxPairwiseProduct(a);
        long long res2=MaxPairwiseProductF(a);
        if(res1!=res2){
            std::cout<<"Wrong answer: "<<res1<<' '<<res2<<'\n';
            break;
        }else{
            std::cout<<"OK\n";
        }
    }
    */
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductF(numbers) << "\n";
    return 0;
}
