#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

double findPrimeNumbers(int M, int T, int S, int C, bool output){

    auto start = chrono::high_resolution_clock::now();

    int SL = sqrt(M);

    int SU = SL % 2 == 0 ? SL + 1 : SL + 2;

    int N = M + 1;

    omp_set_num_threads(T);

    omp_set_schedule(static_cast<omp_sched_t>(S), C);

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

    #pragma omp parallel default(shared) private(n)
    {

        vector<int> primesT;

        #pragma omp for
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

    auto end = chrono::high_resolution_clock::now();

    double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count() *  1e-9;

    if(output){
        cout << endl << primes.size() << " prime numbers found in the interval [2," << M << "]." << endl;
        cout << "Calculation time is " <<  fixed << time_taken << setprecision(9) << " seconds." << endl;
        cout << "Check the created primes.txt file to see found prime numbers!" << endl;

        ofstream outfile;

        outfile.open("primes.txt");

        for(int prime : primes)
            outfile << prime << endl;

        outfile.close();
    }

    return time_taken;

}

int main(int argc, char *argv[]) {

    int M = stoi(argv[1]);

    int T = argc > 2 ? stoi(argv[2]) : 1;

    int S = argc > 3 ? stoi(argv[3]) : 4;

    int C = argc > 4 ? stoi(argv[4]) : 0;

    findPrimeNumbers(M, T, S, C, true);

    cout << endl << "Waiting for result.txt file to be created!" << endl;

    ofstream outfile;

    outfile.open("results.txt");

    cout << "M" << "," << "Openmp Loop Scheduling Method" << "," << "Chunk Size" << ",";
    outfile << "M" << "," << "Openmp Loop Scheduling Method" << "," << "Chunk Size" << ",";


    for(int t =1; t <= T; t*=2){
        cout << "," << "T" << t;
        outfile << "," << "T" << t;
    }

    for(int s = 2; s <= T; s*=2){
        cout << "," << "S" << s;
        outfile << "," << "S" << s;
    }

    cout << endl;
    outfile << endl;

    for(int s = 1; s <= 4; s++){

        for(int c = 1; c < M; c *= 10){

            cout << M << "," << s << "," << c;
            outfile << M << "," << s << "," << c;

            vector<double> times;

            for(int t =1; t <= T; t*=2){
                double time = findPrimeNumbers(M, t, s, c, false);
                cout << "," << time;
                outfile << "," << time;
                times.push_back(time);
            }

            for(int i = 1; i < times.size(); i++){
                cout << "," << times.at(0) / times.at(i);
                outfile << "," << times.at(0) / times.at(i);
            }

            cout << endl;
            outfile << endl;

        }
    }

    outfile.close();

    cout << "Check the created results.txt file to see calculation results!" << endl;

    return 0;

}
