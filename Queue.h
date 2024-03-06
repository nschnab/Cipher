/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue
{
  struct QueueNode
  {
    int value;
    QueueNode * next;
    QueueNode(int value1, QueueNode *next1 = nullptr)
    {
      // cout<<"i"<<endl;
      value = value1;
      next = next1;
    }
  };
  //these track ront and rear of the queue
  QueueNode *front;
  QueueNode *rear;
public:
  //cont and destr
  Queue();
  Queue(const Queue&);
  ~Queue();

  //member functions
  void enqueue(int);
  void dequeue(int &);
  bool isEmpty() const;
  bool isFull();
  void clear();
  int getQueueSize();
private:
  int *p;
  int queueSize;
};
#endif
