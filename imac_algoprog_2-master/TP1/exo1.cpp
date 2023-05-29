// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <random>
// #include "tp2.h"

const int tailleTb = 8;





void selectionSort(int toSort[]){
    bool comtuveu = true;
    while(comtuveu){
        comtuveu = false;
        for(int i=0;i<tailleTb;i++){
            for(int k=i;k<tailleTb;k++){
                if(toSort[i] > toSort[k]){
                    int n = toSort[i];
                    toSort[i] = toSort[k];
                    toSort[k] = n;
                    k=tailleTb;
                    comtuveu = true;
                }
            }
        }
    }
}

void insertionSort(int toSort[])
{
    int Sorted[tailleTb];
    int atrier;
    bool flagplace;
    for (int i=0;i<tailleTb;i++)
    {   
        flagplace=false;
        atrier=toSort[i];
        for (int k=0;k<i;k++)
        {
            if (atrier<Sorted[k])
            {
                for (int f=tailleTb-2;f>=k;f--)
                {   
                    Sorted[f+1]=Sorted[f];
                }
                Sorted[k]=atrier;
                flagplace=true;
                break;
            }
            
        }
        if(flagplace==false)
            {
                Sorted[i]=atrier;
            }
    }
    for(int i=0;i<tailleTb;i++){
        toSort[i]=Sorted[i];
    }
}

void bubbleSort(int toSort[])
{
    bool comtuveu = true;
    int i=0;
    int k=0;
    int temporaire;
    
    while(comtuveu){
        comtuveu = false;
        for (int k=0;k<tailleTb;k++)
        {
            i=k;
            while(toSort[i]>toSort[i+1])
                {
                    temporaire=toSort[i];
                    toSort[i]=toSort[i+1];
                    toSort[i+1]=temporaire;
                    i++;
                    comtuveu = true;
                }
        }
    }
}

void recursivequickSort(int toSort[],int tailletb)
{
    if (tailletb!=1 && tailletb!=0)
    {   
        int tabpetit[tailletb];
        int taillepetit=0;
        int tabgrand[tailletb];
        int taillegrand=0;
        int pivot=toSort[0];
        for(int i=1;i<tailletb;i++)
        {
            if (pivot>toSort[i])
            {
                tabpetit[taillepetit]=toSort[i];
                taillepetit++;
            }
            else 
            {
                tabgrand[taillegrand]=toSort[i];
                taillegrand++;
            }
        }
        int tabpetitfinal[taillepetit];
        for (int i=0;i<taillepetit;i++)
        {
            tabpetitfinal[i]=tabpetit[i];
        }
        int tabgrandfinal[taillegrand];
        for (int i=0;i<taillegrand;i++)
        {
            tabgrandfinal[i]=tabgrand[i];
        }

        recursivequickSort(tabpetitfinal,taillepetit);
        recursivequickSort(tabgrandfinal,taillegrand);

        for (int i=0;i<taillepetit;i++)
        {
            toSort[i]=tabpetitfinal[i];
        }
        toSort[taillepetit]=pivot;
        for (int i=taillepetit+1;i<tailletb;i++)
        {
            toSort[i]=tabgrandfinal[i];
        }
    }
}

int main(int argc, char *argv[])
{

    srand((unsigned)time(NULL));
    
    int tab[tailleTb];
 

    for(int i=0;i<tailleTb;i++){
        tab[i]=rand()%10;
    }

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    //recursivequickSort(tab,tailleTb);
    

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    
}



