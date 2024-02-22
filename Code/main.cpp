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
    OPT memory;
    vector<int> reference_string;
    int i;
    int j;
};

ofstream out("results.out");

void *run_opt(void *threadarg){
    thread_args *args;
    args = (thread_args *) threadarg;

    int miss = args->memory.count_misses(args->reference_string);
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

    pthread_t thread[5][33];

    vector<int> reference_string[5];
    for (size_t i = 1; i <= 4; i++) {
        vector<string> log = getLog(to_string(i));
        reference_string[i] = generateReferenceString(log);

        for (int j = 4; j <= 32; j *= 2) {
            out << "LRU Misses: " << lruAlgorithm(reference_string[i], j);
            OPT memory(j);
            thread_args args;
            args.memory = memory;
            args.reference_string = reference_string[i];
            args.i = i;
            args.j = j;

            pthread_create(&thread[i-1][j-1], NULL, &run_opt, NULL);
            pthread_join(thread[i-1][j-1], NULL);
        }   
    }
    return 0;
}