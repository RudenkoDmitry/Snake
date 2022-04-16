#ifndef NEW__LINKEDLIST_H_
#define NEW__LINKEDLIST_H_
#include <iostream>
using std::invalid_argument;
template<typename T>

class LinkedList {
 private:
  class LinkedListNode {
   public:
    T value;
    LinkedListNode *next;
    LinkedListNode(T value, LinkedListNode *next) {
      this->value = value;
      this->next = next;
    }
    explicit LinkedListNode(T value) {
      this->value = value;
      this->next = NULL;
    }
  };
  LinkedListNode *head = NULL;
  LinkedListNode *tail = NULL;
  int size = 0;

  void checkEmptyError() {
    if (size == 0) throw invalid_argument("Empty list");
  }

 public:
  void clear() {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  void addFirst(T value) {
    head = new LinkedListNode(value, head);
    if (size == 0) {
      tail = head;
    }
    size++;
  }

  void addLast(T value) {
    if (size == 0) {
      head = tail = new LinkedListNode(value);
    } else {
      tail->next = new LinkedListNode(value);
      tail = tail->next;
    }
    size++;
  }

  void removeFirst() {
    checkEmptyError();
    head = head->next;
    if (size == 1) {
      tail = nullptr;
    }
    size--;
  }
  LinkedListNode *getLast(){
    return tail;
  }
  LinkedListNode *getFirst(){
    return head;
  }
  void del(int index) {
    checkEmptyError();
    if (index < 0 || index >= size) throw invalid_argument("Incorrect index");
    if (index == 0) {
      removeFirst();
    } else {
      LinkedListNode *prev = getForIndex(index - 1);
      prev->next = prev->next->next;
      if (prev->next == nullptr) {
        tail = prev;
      }
      size--;
    }
  }
  LinkedListNode *getForIndex(int index) {
    if (index >= size or index < 0) throw invalid_argument("incorrect index");
    int i = 0;
    LinkedListNode *current = head;
    while (i != index) {
      current = current->next;
      i++;
    }
    return current;
  }
  int getSize() {
    return this->size;
  }
};

#endif //NEW__LINKEDLIST_H_
//сишка топ