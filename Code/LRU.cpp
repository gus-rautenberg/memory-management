#include "LRU.h"

int lruAlgorithm(vector<int>& vetorReferenceString, int numFrames){
    struct frames{
        int espacoLivre;
        int count;
    };
    int numFalhas = 0;
    int auxiliarLoopInicial = 0;
    int primeirosFrames = 0;
    vector<frames> vetorFrames;

    if(vetorReferenceString.size() < numFrames){
        auxiliarLoopInicial = vetorReferenceString.size();
    }
    else{
        auxiliarLoopInicial = numFrames;
    }

    for(int i = 0, t = 0; i < auxiliarLoopInicial && t < vetorReferenceString.size(); i++, t++){
        
        frames frame;
        frame.espacoLivre = vetorReferenceString[t];
        frame.count = 0;
        vetorFrames.push_back(frame);

        primeirosFrames += 1;
        for(frames& frame : vetorFrames){
            frame.count++;
        }
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[t + 1]){
                while(vetorFrames[j].espacoLivre == vetorReferenceString[t+1]){
                    t++;
                    j = 0;
                }
            }
        }

    };   

    for(int i  = numFrames  ; i < vetorReferenceString.size(); i++){
        bool notFalha = false;
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[i]){
                notFalha = true;
                vetorFrames[j].count = 0;
                break;
            }
        }  
            if(notFalha){
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }

            else{
                frames* maiorCount = &vetorFrames[0];
                for(int i = 1;i < vetorFrames.size(); i++){
                    if(vetorFrames[i].count > maiorCount->count){
                        maiorCount = &vetorFrames[i];
                    }
                }
                maiorCount->espacoLivre = vetorReferenceString[i];
                maiorCount->count = 0;
                numFalhas += 1;
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }  
    }   
    return numFalhas + primeirosFrames;
}
