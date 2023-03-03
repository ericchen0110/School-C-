#include <iostream>
#include "heap.h"

using namespace std;

int const arr_size = 101;

heap::heap()
{
  for(int i=0; i<arr_size; i++)
    {
      heap_arr[i] = 0;
    }
}

int* heap::getArr()
{
  return heap_arr;
}

void heap::addNum(int num)
{
  for(int i=1; i<arr_size; i++)
    {
      if(heap_arr[i] == 0)
	{
	  heap_arr[i] == num;
	  if(moveUp(i))
	    {
	      break;
	    }
	}
    }
}

bool heap::moveUp(int index)
{
  cout << "move up index: " << index << endl;
  
  if(index == 1)
    {
      return true;
    }

  if(heap_arr[parent(index)] != 0 && heap_arr[parent(index)] < heap_arr[index])
    {
      swap(heap_arr[parent(index)], heap_arr[index]);
    }

  return moveUp(parent(index));
}

void heap::moveDown(int index)
{
  int swapID = index;

  if(left(index) != 0 && left(index) <= arr_size && heap_arr[left(index)] > heap_arr[index])
    {
      swapID = left(index);
    }

  if(right(index) != 0 && right(index) <= arr_size && heap_arr[right(index)] > heap_arr[index])
    {
      swapID = right(index);
    }

  if(swapID != index)
    {
      moveDown(swapID);
    }

  return;
}

int heap::parent(int index)
{
  return index/2;
}

int heap::left(int index)
{
  return index*2;
}

int heap::right(int index)
{
  return index*2 + 1;
}

int heap::remove()
{
  int max_num = heap_arr[1];
  int min_index = 0;
  for(int i=1; i<arr_size; i++)
    {
      if(heap_arr[i] == 0)
	{
	  min_index = i;
	}
    }
  swap(heap_arr[1], heap_arr[min_index]);
  moveDown(1);
  
  return max_num;
}
