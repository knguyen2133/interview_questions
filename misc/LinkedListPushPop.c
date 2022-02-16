struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *tail;

// LIFO
int pop()
{
    struct Node *temp = head;
    if (!head)
    {
        return -1;
    }
    temp->data = NULL;
    head = head->next;
    free(temp);
    return 0;
}

int push(int a)
{
    struct Node *temp;

    if (!head)
    {
        return -1;
    }

    temp->data = a;
    temp->next = head;
    head = temp;
    return 0;
}

//FIFO
int pop()
{
    struct Node *temp = head;

    if (!head)
    {
        return -1;
    }
    temp->data = NULL;
    head = head->next;
    free(temp);
    return 0;
}

int push(int a)
{
    struct Node *temp;

    if (!tail)
    {
        return -1;
    }

    temp->data = a;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
    return 0;
}