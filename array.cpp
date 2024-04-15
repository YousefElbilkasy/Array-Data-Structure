#include <iostream>

using namespace std;

class Array
{
private:
  int length;
  int size;
  int *ptr;

public:
  Array(int arrsize)
  {
    length = 0;
    size = arrsize;
    ptr = new int[size];
  }

  void reverse()
  {
    if (length > 0)
    {
      int temp, lastIndex = length - 1;        //  0  1  2  3
      for (int i = 0; i < length / 2; i++)     // 10 20 30 40
      {
        temp = ptr[i];                  // temp = 10
        ptr[i] = ptr[lastIndex]; // ptr[0] = 40
        ptr[lastIndex--] = temp;   // ptr[3] = 10
      }
    }
  }
  void fill()
  {
    int numberOfItems;
    cout << "How Many Items You Want to Fill?" << endl;
    cin >> numberOfItems;

    if (numberOfItems > size)
    {
      cout << "Invalid Input, This Number of Items More Than Size of Array" << endl;
      return;
    }
    else
    {
      for (int i = 0; i < numberOfItems; i++)
      {
        cout << "Enter Item Number " << i + 1 << endl;
        cin >> ptr[i];
        length++;
      }
    }
  }
  void display()
  {
    cout << "Display Array Content" << endl;
    for (int i = 0; i < length; i++)
      cout << ptr[i] << "  ";
    cout << endl;
  }
  int getLength()
  {
    return length;
  }
  int getSize()
  {
    return size;
  }
  int searchBinary(int key)
  {
    int left = 0;
    int right = getLength() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (ptr[mid] == key)
        return mid;
      else if (ptr[mid] > ptr[left])
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  int searchSequential(int key)
  {
    for (int i = 0; i < length; i++)
      if (ptr[i] == key)
        return i;
    return -1;
  }
  void append(int newItem)
  {
    if (length >= size)
      cout << "Array is Full";
    else
      ptr[length++] = newItem;
  }
  void insert(int index, int newItem)
  {
    if (index >= 0 && index < size)
    {
      if (index == length)
      {
        ptr[index] = newItem;
        length++;
      }
      else
      {
        for (int i = length; i > index; i--)
          ptr[i] = ptr[i - 1];
        ptr[index] = newItem;
        length++;
      }
    }
    else
    {
      cout << "index out of range of array size" << endl;
    }
  }
  void Delete(int index)
  {
    if (length > 0 && length < size)
    {
      if (index == length - 1)
      {
        ptr[index] = NULL;
        length--;
      }
      else
      {
        for (int i = index; i < length; i++)
          ptr[i] = ptr[i + 1];
        length--;
      }
    }
    else
      cout << "Index is Out Of Range" << endl;
  }
  void enLarge(int newSize)
  {
    if (newSize <= size)
    {
      cout << "New Size Must Be Larger Than Old Size";
      return;
    }
    else
    {
      size = newSize;
      int *ptrOld = ptr;
      ptr = new int[newSize];
      for (int i = 0; i < length; i++)
        ptr[i] = ptrOld[i];
      delete[] ptrOld;
    }
  }
  void merge(Array other)
  {
    int newSize = size + other.getSize();
    size = newSize;
    int *oldPtr = ptr;
    ptr = new int[newSize];
    int i;
    for (i = 0; i < length; i++)
      ptr[i] = oldPtr[i];
    delete[] oldPtr;
    for (int j = 0; j < other.getLength(); j++)
    {
      ptr[i++] = other.ptr[j];
      length++;
    }
  }
};

int main()
{
  int size;
  cout << "Please, Enter The Size of Array" << endl;
  cin >> size;
  Array myArray(size);
  myArray.fill();
  myArray.display();
  // cout << "Enter The Value You Want Index Of it For searching" << endl;
  // int key;
  // cin >> key;
  // int index = myArray.searchSequential(key);
  // cout << index << endl;
  // cout << "Enter Number You Want To Insert It: ";
  // int newNum;
  // cin >> newNum;
  // cout << "Enter Index You Want To Insert in It: ";
  // int newIndex;
  // cin >> newIndex;
  // myArray.insert(newIndex, newNum);
  // myArray.display();
  // cout << "Please Enter Index Of Element You Want To Delete It" << endl;
  // int deleteIndex;
  // cin >> deleteIndex;
  // myArray.Delete(deleteIndex);
  // myArray.display();
  // cout << "Please Enter New Size For Array" << endl;
  // int newSize;
  // cin >> newSize;
  // myArray.enLarge(newSize);
  // cout << "Array Size: " << myArray.getSize() << "  Array Length: " << myArray.getLength() << endl;
  // myArray.display();
  // cout << "Other Array\n";
  // Array other(3);
  // other.fill();
  // myArray.merge(other);
  // cout << "Array Size: " << myArray.getSize() << "  Array Length: " << myArray.getLength() << endl;
  // myArray.display();
  cout << "Array Reversed: \n";
  myArray.reverse();
  myArray.display();
}