/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Functions.h
 * Author: Freeman Yiu
 *
 * Created on 11 November 2023, 11:22 pm
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Game.h"
using namespace std;


void assign(Game&,int,char);
void printBarrier(char,const int);
template <class T> void merge(T*,int,int,int);
template <class T> void mergesort(T*,int,int);
bool collidesVert(Game&,int,int,int);
bool collidesHorz(Game&,int,int,int);
bool pOOB(int,int);
char getletter(char*,int);

//Function for merge sort using templates
template <class T>
void mergesort(T *arr,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

//Function for merge in merge sort above
template <class T>
void merge(T *arr,int l,int m,int r){
    int low=m-l+1;
    int high=r-m;
    T arrl[low],arrR[high];
    for(int i=0;i<low;i++){
        arrl[i]=arr[l+i];
    }
    for(int j=0;j<high;j++){
        arrR[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<low&&j<high){
        if(arrl[i]<=arrR[j]){
            arr[k]=arrl[i];
            i++;
        }
        else{
            arr[k]=arrR[j];
            j++;
        }
        k++;
    }
    while(i<low){
        arr[k]=arrl[i];
        i++;
        k++;
    }
    while(j<high){
        arr[k]=arrR[j];
        j++;
        k++;
    }
}



#endif /* FUNCTIONS_H */

