#include "LRU.h"
#include "OPT.h"
#include "referenceString.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <pthread.h>
#include <semaphore.h>
#include <fstream>

using namespace std;
// g++ LRU.cpp OPT.cpp referenceString.cpp main.cpp -o main

sem_t fullOut, emptyOut, mutexOut;

struct thread_args
{
    vector<int> reference_string;
    int i;
    int j;
};

ofstream out("results.out");

void *run_opt(void *threadarg){
    thread_args *args;
    args = (thread_args *) threadarg;
    OPT memory(args->j);
    int miss = memory.count_misses(args->reference_string);
    sem_wait(&emptyOut);
    sem_wait(&mutexOut);
    out << "OPT Misses from trace" << args->i << " with " << args->j << " pages: " << miss << endl;
    sem_post(&fullOut);
    sem_post(&mutexOut);

    return NULL;
}

int main(int argc, char const *argv[])
{
    sem_init(&fullOut, 0, 0);
    sem_init(&emptyOut, 0, 12);
    sem_init(&mutexOut, 0, 1);

    pthread_t thread[16];
    int teste = 0;

    vector<int> reference_string[5];
    for (int i = 1; i <= 4; i++) {
        vector<string> log = getLog(to_string(i));
        reference_string[i] = generateReferenceString(log);

        cout << "foi o log" << endl;

        for (int j = 4; j <= 32; j *= 2) {
            int miss = lruAlgorithm(reference_string[i], j);
            cout << "LRU Misses: " << miss << endl;
            thread_args args;
            args.reference_string = reference_string[i];
            args.i = i;
            cout << i << j << endl;
            args.j = j;

            pthread_create(&thread[teste], NULL, &run_opt, (void *) &args);
            teste++;
        }   
        
    }
    for (int i = 0; i < 16; i++) {
        pthread_join(thread[i], NULL);
    }    
    return 0;
}