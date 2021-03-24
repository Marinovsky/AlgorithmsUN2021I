#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fibonacci_sum(long long n) {
    std::vector<int> Fib(61,0);
    std::vector<int> sum(61,0);
    Fib[0]=0; Fib[1]=1;
    sum[0]=0; sum[1]=1;
    for(int i=2;i<61;i++){
        Fib[i]=(Fib[i-1]+Fib[i-2])%10;
        sum[i]=(sum[i-1]+Fib[i])%10;
    }
    /*
    for(int c:sum){
        std::cout<<c<<'\n';
    }
    std::cout<<"Val: "<<sum[60]<<'\n';
    */
    if(n<=60){
        return sum[n];
    }else{
        long long times=n/(int)60;
        //std::cout<<times<<'\n';
        int res=n%60;
        long long ans=(((times*sum[60])%10)+sum[res])%10;
        return ans;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
