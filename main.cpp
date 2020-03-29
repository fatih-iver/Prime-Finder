#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <iomanip>


using namespace std;

int main(int argc, char *argv[]) {

    auto start = chrono::high_resolution_clock::now();

    int M = stoi(argv[1]);

    int N = M + 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for(n = 5; n <= N; n+=2){

        int rem;
        int quo;

        int k = 0;

        do{

            k += 1;

            rem = n % primes.at(k);

            if(rem == 0)
                break;

            quo = n / primes.at(k);

        } while(quo > primes.at(k));

        if(rem == 0)
            continue;

        primes.push_back(n);

    }

    cout << "Greatest prime smaller than " << N << ": " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count() *  1e-9;

    cout << "Time taken by program: " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;

    /*
    int nthreads, tid;

    #pragma omp parallel private(tid)
    {

        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);

        if (tid == 0)
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

    }

    */

}
