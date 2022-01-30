// Write a function that will consider an array and return the number of odd numbers

// Be aware of decay for length
int Num_Of_Odds(int* array, int length)
{
    int counter = 0;
    for (int i = 0; i < length); ++i) {
    if (array[i] % 2 != 0) {
        ++counter;
    }
    }

    return counter;
}