#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
using namespace std;
const int tailleTb=8;

struct Noeud{
    int val;
    Noeud* gauche;
    Noeud* droite;
};

void recursivQuickSort(std::vector<int>& toSort, int size){
    if(size!=1 && size!=0){
        int pivot = toSort[0];
        std::cout << "affiche pivot : " << pivot << "\n";

        std::vector<int> lowers;
        std::vector<int> greaters;

        for(int k=1;k<size;k++){
            if(toSort[k]<pivot){
                lowers.push_back(toSort[k]);
            }
            else{
                greaters.push_back(toSort[k]);
            }
        }

        recursivQuickSort(lowers, lowers.size());
        recursivQuickSort(greaters, greaters.size());

        for(int i=0;i<lowers.size();i++){
            toSort[i] = lowers[i];
        }

        toSort[lowers.size()] = pivot;

        int temp = lowers.size()+1;

        for(temp;temp<size;temp++){
            toSort[temp] = greaters[temp-(lowers.size()+1)];
        }
    }
    else{
        return;
    }
}


int binarySearch(int tab[],int tailletab,int toSearch)
{
int start=0;
int end=tailletab;
int mid=(start+end)/2;
while(end-mid>1 && mid-start>1)
{
    if (toSearch==tab[mid])return mid;
    if(toSearch>tab[mid])start=mid;
    else end=mid;
    mid=(start+end)/2;
}
return -1;
}


int binarySearchrecursive(int tab[],int tailletab,int toSearch)
{
	cout<<"n"<<tab[tailletab/2]<<"\n";
	if(tailletab==0 ||(tailletab==1 && tab[0]!=toSearch))return -1;
	if (tab[tailletab/2]==toSearch) return tailletab/2;
	if(tab[tailletab/2]<toSearch) return binarySearch(tab+1+tailletab/2,tailletab-1-tailletab/2,toSearch);//les tab sont des pointeurs sur lesquels ont peut faire des opérations qui modifient l'endroit ou on regarde en premier ;
	
	return binarySearch(tab,tailletab/2,toSearch);
}

void binarySearchAll(int tab[], int toSearch, int indexMin, int indexMax,int tailletab)
{
	// do not use increments, use two different binary search loop
    
    indexMin=binarySearch(tab,tailletab,toSearch);
    indexMax=indexMin;
    if (indexMin!=-1)
    {
        while (tab[indexMax]==toSearch)
        {
            indexMax+=1;
        }
        indexMax-=1;
    }
}

void insertNumber(int value,Noeud* arbre)//on part d'un abre vide mais avec déjà une base sur laquelle placer les nouveaux éléments; 
{

}

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
    std::vector<int> tab;
	int achercher=rand()%10;
	

    for(int i=0;i<tailleTb;i++){
        tab.push_back(rand()%10);
    }

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    recursivQuickSort(tab,tab.size());

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }
	
	int tabnv[tailleTb];
	for(int i=0;i<tailleTb;i++)tabnv[i]=tab[i];
	cout<<"a chercher \t"<<achercher<<"\n";
	cout<<"à chercher est ici \t"<<binarySearch(tabnv,tailleTb,achercher)<<"\n";
	// cout<<"ce prgm ne peut pas fonctionner en recusrif"<<"\n";



}
