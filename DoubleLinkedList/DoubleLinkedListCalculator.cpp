#include <stdlib.h>
#include <iostream>
#include <Windows.h>

#include "DoubleLinkedList.cpp"

using namespace std;

void PrintList(DoubleLinkedList& list)
{
    for (int index = 0; index < list.Count; index++)
    {
        if (index == 0)
        {
            cout << list.First->Value << " ";
        }
        else if (index == list.Count - 1)
        {
            cout << list.Last->Value << " ";
        }
        else
        {
            DoubleNode* current = list.First;

            for (int i = 0; index < list.Count; i++)
            {
                if (i == index)
                {
                    cout << current->Value << " ";

                    break;
                }

                current = current->Next;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DoubleLinkedList list;

    list.AddFirst(1);
    list.AddLast(30);
    list.AddFirst(400);
    list.AddFirst(100);
    list.AddFirst(20);

    list.Insert(3, 33);

    cout << "Элементы коллекции: ";
    PrintList(list);

    cout << "Поиск элемента 30 - " << list.Find(30);
    cout << "Поиск элемента 130 - " << list.Find(130);

    list.Remove(1);
    list.Remove(2);
    list.Remove(3);
    list.Remove(4);
    list.Remove(5);
    list.Remove(6);

    list.AddFirst(1);
    list.AddLast(20);
    list.AddLast(30);
    list.AddLast(33);
    list.AddLast(400);

    cout << "Элементы коллекции после проведенных операций: ";
    PrintList(list);
}