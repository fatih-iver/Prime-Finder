#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double calculateAuto(int M, int T) {
    auto start = chrono::high_resolution_clock::now();

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for (n = 5; n <= SL; n += 2) {

        int rem;
        int quo;

        int k = 0;
        int pk;

        do {

            k += 1;

            if (k >= primes.size())
                break;

            pk = primes.at(k);

            rem = n % pk;

            if (rem == 0)
                break;

            quo = n / pk;

        } while (quo > pk);

        if (rem == 0)
            continue;

        primes.push_back(n);

    }

    //-----------------------------------------------------------------------------


#pragma omp parallel num_threads(T) default(shared) private(n)
    {

        vector<int> primesT;

#pragma omp for schedule(auto)
        for (n = SU; n <= N; n += 2) {

            int rem;
            int quo;

            int k = 0;
            int pk;

            do {

                k += 1;

                if (k >= primes.size())
                    break;

                pk = primes.at(k);

                rem = n % pk;

                if (rem == 0)
                    break;

                quo = n / pk;

            } while (quo > pk);

            if (rem == 0)
                continue;

            primesT.push_back(n);

        }

#pragma omp critical
        {
            for (int prime: primesT)
                primes.push_back(prime);
        }
    }

    //-----------------------------------------------------------------------------

    sort(primes.begin(), primes.end());


    //cout << "Greatest prime smaller than "<< N << ": " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;

    return time_taken;

}


double calculateStatic(int M, int T, int CS) {
    auto start = chrono::high_resolution_clock::now();

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for (n = 5; n <= SL; n += 2) {

        int rem;
        int quo;

        int k = 0;
        int pk;

        do {

            k += 1;

            if (k >= primes.size())
                break;

            pk = primes.at(k);

            rem = n % pk;

            if (rem == 0)
                break;

            quo = n / pk;

        } while (quo > pk);

        if (rem == 0)
            continue;

        primes.push_back(n);

    }

    //-----------------------------------------------------------------------------


#pragma omp parallel num_threads(T) default(shared) private(n)
    {

        vector<int> primesT;

#pragma omp for schedule(static, CS)
        for (n = SU; n <= N; n += 2) {

            int rem;
            int quo;

            int k = 0;
            int pk;

            do {

                k += 1;

                if (k >= primes.size())
                    break;

                pk = primes.at(k);

                rem = n % pk;

                if (rem == 0)
                    break;

                quo = n / pk;

            } while (quo > pk);

            if (rem == 0)
                continue;

            primesT.push_back(n);

        }

#pragma omp critical
        {
            for (int prime: primesT)
                primes.push_back(prime);
        }
    }

    //-----------------------------------------------------------------------------

    sort(primes.begin(), primes.end());


    //cout << "Greatest prime smaller than "<< N << ": " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;

    return time_taken;

}


double calculateGuided(int M, int T, int CS) {
    auto start = chrono::high_resolution_clock::now();

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for (n = 5; n <= SL; n += 2) {

        int rem;
        int quo;

        int k = 0;
        int pk;

        do {

            k += 1;

            if (k >= primes.size())
                break;

            pk = primes.at(k);

            rem = n % pk;

            if (rem == 0)
                break;

            quo = n / pk;

        } while (quo > pk);

        if (rem == 0)
            continue;

        primes.push_back(n);

    }

    //-----------------------------------------------------------------------------


#pragma omp parallel num_threads(T) default(shared) private(n)
    {

        vector<int> primesT;

#pragma omp for schedule(guided, CS)
        for (n = SU; n <= N; n += 2) {

            int rem;
            int quo;

            int k = 0;
            int pk;

            do {

                k += 1;

                if (k >= primes.size())
                    break;

                pk = primes.at(k);

                rem = n % pk;

                if (rem == 0)
                    break;

                quo = n / pk;

            } while (quo > pk);

            if (rem == 0)
                continue;

            primesT.push_back(n);

        }

#pragma omp critical
        {
            for (int prime: primesT)
                primes.push_back(prime);
        }
    }

    //-----------------------------------------------------------------------------

    sort(primes.begin(), primes.end());


    //cout << "Greatest prime smaller than "<< N << ": " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;

    return time_taken;

}


double calculateDynamic(int M, int T, int CS) {
    auto start = chrono::high_resolution_clock::now();

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    int n;

    for (n = 5; n <= SL; n += 2) {

        int rem;
        int quo;

        int k = 0;
        int pk;

        do {

            k += 1;

            if (k >= primes.size())
                break;

            pk = primes.at(k);

            rem = n % pk;

            if (rem == 0)
                break;

            quo = n / pk;

        } while (quo > pk);

        if (rem == 0)
            continue;

        primes.push_back(n);

    }

    //-----------------------------------------------------------------------------


#pragma omp parallel num_threads(T) default(shared) private(n)
    {

        vector<int> primesT;

#pragma omp for schedule(dynamic, CS)
        for (n = SU; n <= N; n += 2) {

            int rem;
            int quo;

            int k = 0;
            int pk;

            do {

                k += 1;

                if (k >= primes.size())
                    break;

                pk = primes.at(k);

                rem = n % pk;

                if (rem == 0)
                    break;

                quo = n / pk;

            } while (quo > pk);

            if (rem == 0)
                continue;

            primesT.push_back(n);

        }

#pragma omp critical
        {
            for (int prime: primesT)
                primes.push_back(prime);
        }
    }

    //-----------------------------------------------------------------------------

    sort(primes.begin(), primes.end());


    //cout << "Greatest prime smaller than "<< N << ": " << primes.back() << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count() * 1e-9;

    return time_taken;

}

int main(int argc, char *argv[]) {

    //cout  << calculate(stoi(argv[1]), argc > 2 ? stoi(argv[2]) : 1);



    for (int M = 100000; M <= 100000000; M *= 10) {

        cout << M << "," << "auto" << "," << "-" << ",";

        for (int T = 1; T <= 64; T *= 2) {

            cout << fixed << calculateAuto(M, T) << setprecision(6);

            if (T != 64)
                cout << ",";

        }

        cout << endl;
    }



    for (int M = 100000; M <= 100000000; M *= 10) {

        for (int CS = 1; CS < M; CS *= 10) {

            cout << M << "," << "static" << "," << CS << ",";

            for (int T = 1; T <= 64; T *= 2) {

                cout << fixed << calculateStatic(M, T, CS) << setprecision(6);

                if (T != 64)
                    cout << ",";

            }

            cout << endl;

        }
    }


    for (int M = 100000; M <= 100000000; M *= 10) {

        for (int CS = 1; CS < M; CS *= 10) {

            cout << M << "," << "dynamic" << "," << CS << ",";

            for (int T = 1; T <= 64; T *= 2) {


                cout << fixed << calculateDynamic(M, T, CS) << setprecision(6);

                if (T != 64)
                    cout << ",";

            }

            cout << endl;

        }
    }


    for (int M = 100000; M <= 100000000; M *= 10) {

        for (int CS = 1; CS < M; CS *= 10) {

            cout << M << "," << "guided" << "," << CS << ",";

            for (int T = 1; T <= 64; T *= 2) {

                cout << fixed << calculateGuided(M, T, CS) << setprecision(6);

                if (T != 64)
                    cout << ",";

            }

            cout << endl;

        }

    }

    return 0;

}


