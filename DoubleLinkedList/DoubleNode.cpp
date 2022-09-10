struct DoubleNode
{
    DoubleNode* Next;
    DoubleNode* Previous;

    int Value;

    DoubleNode(int value)
    {
        Value = value;
    }
};