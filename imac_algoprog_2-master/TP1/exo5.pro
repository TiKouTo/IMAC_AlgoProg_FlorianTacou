#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <array>
// using namespace std;

// Qt est trop lent sur mon ordi, je fais sans 


int power(int valeur,int n )
{
    if (n==0)
    {
        return 1;
    }

    return power(valeur,n-1)*valeur;
}

int Fibonacci(int n)
{
if (n==1 || n==2)
{
    return 1;
}
return Fibonacci(n-1)+Fibonacci(n-2);
}

int search(int value, int arraysearch[],int size){
    if (value==arraysearch[-1])return size-1;
    if (size==1) return -1;
    size=search(value,arraysearch,size-1);
    return size;
}

//je n'ai pas passé plus de 20 mins à chercher sur internet donc je n'ai pas compris comment on se sert / include les array; 
//
void allEvens(array evens[], int arrayallEvens[], int evenSize, int arraySize)//on peut utiliser des tableaux non dynamiques ; pour cela il faut donner à evens une taille max de arraysize, evensize est sa taille réelle;
{
    
    if (arrayallEvens[-1]%2==0)
    {
    evens.insert(0,arrayallEvens[-1]) ;
    evenSize++;
    }
    if (arraySize!=1)allEvens(evens,arrayallEvens,evenSize,arraySize-1);
    //normalement j'ai pas besoin de faire de return si j'ai bien compris; la fonction s'arrête et le prgm continue à la ligne d'après l'appel de la fonction
}
//pareil pour vec (pas compris) donc j'ai remplacé par 2 entiers (la partie réelle et imaginaire), 
bool mandelbrot(int Rez,int Imz, int Repoint, int Impoint,int n) 
{//z1=z^^2+point


    if (n==0)return false;
    
    Rez=Rez*Rez-Imz*Imz+Repoint;
    Imz=2*Rez*Imz+Impoint;
    if(sqrt(Rez*Rez+Imz*Imz)>2)return true;
    return mandelbrot(Rez,Imz,Repoint,Impoint,n-1);//on réduit n jusqu'à 0 afin qu'il serve de compteur pour savoir combien de fois on a appliqué la fonction à z;
}

struct Dynatableau
{
int size=1;


}Dynatableau;

struct liste
{

}liste;


void ajoute(int valeur)
{

}



int main()
{
std::cout<<Fibonacci(6)<<"\n";
}
