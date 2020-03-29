#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

    auto start = chrono::high_resolution_clock::now();

    int M = stoi(argv[1]);

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    int T = argc > 2 ? stoi(argv[2]) : 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for(n = 5; n <= SL; n+=2){

        int rem;
        int quo;

        int k = 0;
        int pk;

        do{

            k += 1;

            if(k >= primes.size())
                break;

            pk = primes.at(k);

            rem = n % pk;

            if(rem == 0)
                break;

            quo = n / pk;

        } while(quo > pk);

        if(rem == 0)
            continue;

        primes.push_back(n);

    }

    //-----------------------------------------------------------------------------


    #pragma omp parallel num_threads(T) default(shared) private(n)
    {

        vector<int> primesT;

        #pragma omp for schedule(auto)
        for(n = SU; n <= N; n+=2){

            int rem;
            int quo;

            int k = 0;
            int pk;

            do{

                k += 1;

                if(k >= primes.size())
                    break;

                pk = primes.at(k);

                rem = n % pk;

                if(rem == 0)
                    break;

                quo = n / pk;

            } while(quo > pk);

            if(rem == 0)
                continue;

            primesT.push_back(n);

        }

        #pragma omp critical
        {
            for(int prime: primesT)
                primes.push_back(prime);
        }
    }

    //-----------------------------------------------------------------------------

    sort(primes.begin(), primes.end());

    /*
    for(int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
    cout << endl;
     */

    cout << "Greatest prime smaller than or equal to "<< M << " is " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count() *  1e-9;

    cout << "Time taken by the program is " << fixed<< time_taken << setprecision(9) << " seconds" << endl;

    return 0;

}
