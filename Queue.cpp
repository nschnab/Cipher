/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#include <iostream>
#include <cstdlib>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
  queueSize = 0;
  front = nullptr;
  rear = nullptr;
}

Queue::~Queue()
{
  QueueNode * garbage = front;
  while (garbage != nullptr)
    {
      front = front->next;
      garbage->next = nullptr;
      delete garbage;
      garbage = front;
    }
}

void Queue::enqueue(int num) //enqueue inserts the value in num at the rear of the queue
{
  if(isEmpty())
    {
      front = new QueueNode(num);
      rear = front;
      queueSize++;
    }
  else if (isFull())
  {
    cout<<"";
  }
  else
    {
      rear->next = new QueueNode(num);
      rear = rear->next;
      queueSize++;
    }
    // cout<<queueSize<<endl;
}

void Queue::dequeue(int &num)//dequeue removes the value at the front of the queue and copies it into num
{
  QueueNode * temp = nullptr;
  if (isEmpty())
    {
      cout << "The queue is empty."<<endl;
    }
  else
    {
      queueSize--;
      num = front->value;
      temp = front;
      front = front->next;
      delete temp;
    }
}

bool Queue::isEmpty() const
{
  if (front == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Queue::isFull()
{
  if (queueSize < 100)
  {
    return false;
  }
  else
  {
    // cout<<queueSize<<endl;
    return true;
  }
}

void Queue::clear()//dequeues all elements int the queue
{
  int value; //dummy var
  while (!isEmpty())
    {
      dequeue(value);
    }
}

int Queue::getQueueSize()
{
  return queueSize;
}