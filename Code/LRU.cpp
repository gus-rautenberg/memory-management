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
        // cout << "vetorReference string e seu t" << vetorReferenceString[t] << "seu t : " << t << endl;
        primeirosFrames += 1;
        for(frames& frame : vetorFrames){
            frame.count++;
        }
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[t + 1]){
                // cout << "t + 1 " << vetorReferenceString[t+1] << endl;
                while(vetorFrames[j].espacoLivre == vetorReferenceString[t+1]){
                    // cout << "J : " << j << endl;
                    // cout << "vetorFrames : " << vetorFrames[j].espacoLivre << endl;
                    t++;
                    // cout << "T : " << t << endl;
                    j = 0;
                }

            }
        }

    };   
    // cout << primeirosFrames << endl;

    // for(int i= 0; i <vetorFrames.size(); i++){
    //     cout << "Frame " << i << ": espacoLivre = " << vetorFrames[i].espacoLivre << ", count = " << vetorFrames[i].count << endl;
    // }

    for(int i  = numFrames  ; i < vetorReferenceString.size(); i++){
        // cout << vetorReferenceString.size() << endl;
        // for(int i= 0; i <vetorFrames.size(); i++){
        // cout << "Frame " << i << ": espacoLivre = " << vetorFrames[i].espacoLivre << ", count = " << vetorFrames[i].count << endl;
        // }
        bool notFalha = false;
        for(int j = 0; j < numFrames; j++){
            if(vetorFrames[j].espacoLivre == vetorReferenceString[i]){
                notFalha = true;
                vetorFrames[j].count = 0;
                //cout << "entrou aqui quando i era: " << i << endl;
                //cout << "vetor frames: "<< vetorFrames[j].espacoLivre << endl;
                //cout << "vetor referenceString: "<< vetorReferenceString[i] << endl;
                break;
            }
        }  
            if(notFalha){
                //cout << "ja tinha " << endl;
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }

            else{
                frames* maiorCount = &vetorFrames[0];
                for(int i = 1;i < vetorFrames.size(); i++){
                    if(vetorFrames[i].count > maiorCount->count){
                        maiorCount = &vetorFrames[i];
                        //cout <<"maior count achado soq dentro do for : " << maiorCount->espacoLivre << endl;
                    }
                    //cout <<"maior Count achado : " << maiorCount->espacoLivre << endl;
                }
                maiorCount->espacoLivre = vetorReferenceString[i];
                //cout << "substituto do maior count: " << maiorCount->espacoLivre << endl;
                maiorCount->count = 0;
                numFalhas += 1;
                //cout << "numero de falhas: " << numFalhas << endl;
                for(frames& frame : vetorFrames){
                    frame.count++;
                }
            }  
    }   
    return numFalhas + primeirosFrames;
}
