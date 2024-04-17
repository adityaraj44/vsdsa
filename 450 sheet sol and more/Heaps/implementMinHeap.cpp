class minHeap
{
public:
    int *arr;
    int size;
    // Constructor for the class.
    minHeap(int n)
    {
        arr = new int[n];
        size = 0;
    }

    // Implement the function to remove minimum element.
    int extractMinElement()
    {
        if (size == 0)
        {
            return -1;
        }
        int min = arr[0];
        arr[0] = arr[size - 1];
        size = size - 1;
        MinHeapify(arr, 0);
        return min;
    }

    void MinHeapify(int arr[], int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            MinHeapify(arr, smallest);
        }
    }

    // Implement the function to delete an element.
    void deleteElement(int ind)
    {
        // decrease the key to min possible value
        if (ind < size)
        {
            swap(arr[ind], arr[size - 1]);
            size--;
            MinHeapify(arr, ind);
        }
        else
            return;
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val)
    {

        int index = size;
        size++;
        arr[index] = val;

        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
};