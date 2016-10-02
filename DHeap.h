/*Nancy Tang Assignment 5 DHeap.h
This is a template class for a priority heap that works with dijkstra's
algorithm. Since values are changed by dijkstra's from outside of the heap, the
heap needs to be able to go in and rearrange things in the heap after the
changes.*/

#ifndef DHEAP_H
#define DHEAP_H
#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
class DHeap {

public:

   DHeap(bool (*compare)(T* left, T* right));
   ~DHeap();
   int push(T* data);
   T* pop();
   bool is_empty();
   void decreaseKey(T* data);
   
private:
   std::vector<T*> v;
   int size;
   bool (*cmp)(T* left, T* right);
};


template <typename T>
DHeap<T>::DHeap(bool (*compare)(T* left, T* right)) {
   size = 0;
   cmp = compare;
   v.resize(1); // gives v[0] default value so heap index can start at 1
}

template <typename T>
DHeap<T>::~DHeap() {
   cmp = NULL;
}

// push function to add objects to the heap
// function maintains binary heap properties after insertion
template <typename T>
int DHeap<T>::push(T* data) {
   size++;
   v.push_back(data);
   bool fixed = false;
   int i = size;
   T* temp = v[size];
   while (!fixed && i / 2 > 0) {
      if(cmp(v[i], v[i / 2])) {
         v[i] = v[i / 2];
         v[i]->setPriority(i);
         v[i / 2] = temp;
         i = i / 2;
      } else {
         fixed = true;
      }
   }
   return i;
}

// pop function to remove the first object from the heap
// function maintains binary heap properties after deletion
template <typename T>
T* DHeap<T>::pop() {
   if (size == 1) {
      T* temp = v[1];
      size = 0;
      v.resize(size);
      return temp;
   }
   T* temp = v[1];
   v[1] = v[size];
   v[size] = NULL;
   v.resize(size);
   size--;
   T* temp2 = v[1];
   bool fixed = false;
   int i = 1;
   while (!fixed && (i * 2) < size) {
      if (cmp(v[i], v[2 * i]) && cmp(v[i], v[2 * i + 1])) {
         fixed = true;
      } else if (cmp(v[2 * i], v[i]) && cmp(v[2 * i + 1], v[i])) {
         if (cmp(v[2 * i], v[2 * i + 1])) {
            v[i] = v[2 * i];
            v[i]->setPriority(i);
            v[2 * i] = temp2;
            i = 2 * i;
            
         } else {
            v[i] = v[2 * i + 1];
            v[i]->setPriority(i);
            v[2 * i + 1] = temp2;
            i = 2 * i + 1;
         }
      } else if (cmp(v[2 * i], v[2 * i + 1])) {
         v[i] = v[2 * i];
         v[i]->setPriority(i);
         v[2 * i] = temp2;
         i = 2 * i;
      } else {
         v[i] = v[2 * i + 1];
         v[i]->setPriority(i);
         v[2 * i + 1] = temp2;
         i = 2 * i + 1;
      }
   }
   v[i]->setPriority(i);
   
   if (!fixed && (i * 2) == size) {
      if(cmp(v[i * 2], v[i])) {
         v[i] = v[2 * i];
         v[i]->setPriority(i);
         v[2 * i] = temp2;
         v[2 * i]->setPriority(2 * i);
      }
   }
   return temp;
}

template <typename T>
bool DHeap<T>::is_empty() {
   return (size == 0);
}

// updates data within heap once the values have been changed externally
template <typename T>
void DHeap<T>::decreaseKey(T* data) {
   bool fixed = false;
   int i = data->getPriority();
   T* temp = data;
   while (!fixed && i / 2 > 0) {
      if(cmp(v[i], v[i / 2])) {
         v[i] = v[i / 2];
         v[i]->setPriority(i);
         v[i / 2] = temp;
         i = i / 2;
      } else {
         fixed = true;
      }
   }
   v[i]->setPriority(i);
}

#endif