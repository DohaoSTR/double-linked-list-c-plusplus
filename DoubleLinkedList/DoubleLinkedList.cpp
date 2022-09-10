#include <iostream>
#include "DoubleNode.cpp"

using namespace std;

class DoubleLinkedList
{
public:
    DoubleNode* First;
    DoubleNode* Last;
    int Count;

    DoubleLinkedList()
    {
        First = NULL;
        Last = NULL;

        Count = 0;
    }

    void AddFirst(int value)
    {
        DoubleNode* node = new DoubleNode(value);
        DoubleNode* temp = Last;

        node->Next = temp;
        node->Previous = NULL;

        if (Count == 0)
        {
            First = node;
            Last = First;
        }
        else
        {
            First = node;
            temp->Previous = node;
        }

        Count++;
    }

    void AddLast(int value)
    {
        DoubleNode* node = new DoubleNode(value);
        DoubleNode* temp = Last;

        node->Next = NULL;
        node->Previous = node;
        Last = node;

        if (Count == 0)
        {
            Last = node;
            First = Last;
        }
        else
        {
            Last = node;
            temp->Next = node;
        }

        Count++;
    }

    void Insert(int index, int value)
    {
        DoubleNode* node = new DoubleNode(value);

        if (index == 0)
        {
            AddFirst(value);
        }
        else if (index >= Count)
        {
            AddLast(value);
        }
        else
        {
            DoubleNode* temp = First;

            int i = 0;

            while (temp != NULL)
            {
                if (index == i)
                {
                    node->Previous = temp->Previous;
                    node->Next = temp;
                    temp->Previous->Next = node;
                    temp->Previous = node;

                    Count++;

                    break;
                }
                i++;
                temp = temp->Next;
            }
        }
    }

    bool Remove(int index)
    {
        DoubleNode* temp = First;

        if (index == 0)
        {
            temp->Next->Previous = temp->Next;
            First = First->Next;

            Count--;

            return true;
        }
        else if (index == Count - 1)
        {
            temp->Previous = NULL;
            Last = Last->Previous;

            Count--;

            return true;
        }
        else
        {
            int i = 0;

            while (temp != NULL)
            {
                if (i == index)
                {
                    temp->Previous->Next = temp->Next;
                    temp->Next->Previous = temp->Previous;

                    Count--;

                    return true;
                }

                temp = temp->Next;
                i++;
            }
        }
        return false;
    }

    bool Find(int value)
    {
        DoubleNode* current = First;
        for (int i = 0; i < Count; i++)
        {
            if (current->Value == value)
            {
                return true;
            }

            current = current->Next;
        }

        return false;
    }
};