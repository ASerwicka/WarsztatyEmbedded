#ifndef EMBEDDED1_HASH_TABLE_H
#define EMBEDDED1_HASH_TABLE_H

#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

struct DataItem *search(int key);
void insert(int key,int data);
void clear();
struct DataItem* delete(struct DataItem* item);
void display();



#endif //EMBEDDED1_HASH_TABLE_H
