#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long tmp_previous=0;

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int main() {

    std::vector<int> Fib(10000001,0);

    Fib[0]=0;
    Fib[1]=1;

    for(int i=2; i<10000001;++i){
        Fib[i]=(Fib[i-1]+Fib[i-2])%10;
    }
    // test case
    /*
    for(int i=0; i<10000001;i++){
        int res1=Fib[i];
        int res2=get_fibonacci_last_digit_naive(i);
        std::cout<<"Case "<<i<<'\n';
        if(res1==res2){
            std::cout<<"Ok"<<'\n';
        }else{
            std::cout<<"Wrong answer "<<res1<<' '<<res2<<'\n';
            break;
        }
    }
    */
    int n;
    std::cin >> n;
    int c = Fib[n];
    std::cout << c << '\n';

    return 0;
}
