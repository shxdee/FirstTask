#include "DynamicIntArray.h"

DynamicIntArrayNumber::DynamicIntArrayNumber() {
    size = 8;
    buffer = 0;
    arr = new int[8];
    }

DynamicIntArrayNumber::DynamicIntArrayNumber(int size) {
        buffer = 0;
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

DynamicIntArrayNumber::DynamicIntArrayNumber(int size, int n) {
        buffer = 0;
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }

DynamicIntArrayNumber::DynamicIntArrayNumber(int size, int n, int buffer) {
    this->buffer = buffer;
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}

DynamicIntArrayNumber::DynamicIntArrayNumber(const DynamicIntArrayNumber& dynamic) {
        buffer = 0; int i;
        size = dynamic.size;
        arr = new int[size];
        for (int i = 0; i < dynamic.size; i++) {
            arr[i] = dynamic.arr[i];
        }
    }

DynamicIntArrayNumber::DynamicIntArrayNumber(DynamicIntArrayNumber&& dynamic)
        : arr(dynamic.arr), size(dynamic.size)
    {
        dynamic.arr = nullptr;
        
    }

DynamicIntArrayNumber::~DynamicIntArrayNumber()
    {
        delete[] arr;
    }

int& DynamicIntArrayNumber::operator[](const int index) {
    return arr[index];
}

int DynamicIntArrayNumber::getSizeOfArray() {
        return size;
    }

int DynamicIntArrayNumber::getElementOfArray(int i) {
        return arr[i];
    }

//void DynamicIntArrayNumber::resize(int newSize) {
//        int* newArray = new int[newSize];
//        if (size >= newSize) {
//            for (int i = 0; i < newSize; i++) {
//                newArray[i] = arr[i];
//            }
//            delete[] arr;
//            size = newSize;
//            this->arr = newArray;
//        }
//        if (size < newSize) {
//            for (int i = 0; i < size; i++) {
//                newArray[i] = arr[i];
//            }
//            for (int k = 0; k < newSize - size; k++) {
//                newArray[k+size] = 0;
//            }
//            delete[] arr;
//            size = newSize;
//            this->arr = newArray;
//        }
//    }

DynamicIntArrayNumber& DynamicIntArrayNumber::operator=(const DynamicIntArrayNumber& dynamic) {
        delete[] arr;
        size = dynamic.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = dynamic.arr[i];
        }
        
        return *this;
    }
DynamicIntArrayNumber& DynamicIntArrayNumber::operator=(DynamicIntArrayNumber&& dynamic ) {
        delete[] arr;
        size = dynamic.size;
        arr = dynamic.arr;
        dynamic.arr = nullptr;
        return *this;
    }

bool operator== (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2) {
    if (d1.size == d2.size) {
        for (int i = 0; i < d1.size; i++) {
            if (d1.arr[i] != d2.arr[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator != (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    return !(d1 == d2);
}

bool operator> (const const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] <= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator>= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] < d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] >= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator<= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] > d2.arr[i]) {
            return false;
        }
    }
    return true;
}

DynamicIntArrayNumber operator+(DynamicIntArrayNumber& d1, DynamicIntArrayNumber& d2) {
    
    DynamicIntArrayNumber result = DynamicIntArrayNumber(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++) {
        result.arr[i] = d1[i];
    }
    for (int i = d1.size; i < (d1.size + d2.size); i++) {
        result.arr[i] = d2[i - d1.size];
    }
    return result;
}

ostream& operator<< (ostream& out, const DynamicIntArrayNumber& dynamic)
{ 
    out << "[";
    for (int i = 0; i < dynamic.size; i++) {
        out << dynamic.arr[i] << ", ";
    }
    out << "]";

    return out;
}

istream& operator>> (istream& in, DynamicIntArrayNumber& dynamic)
{
    for (int i = 0; i < dynamic.size; i++) {
        in >> dynamic.arr[i];
    }
    return in;
}

void DynamicIntArrayNumber::reserve(int n) {
    buffer = n;
    int* newarr = new int[n];
    for (int i = 0; i < size; ++i) {
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
}

int DynamicIntArrayNumber::capacity() {
    return buffer;
}

void DynamicIntArrayNumber::resize(int n) {
    size = n;
    buffer = n;
    int* newarr = new int[n];
    for (int i = 0; i < n; ++i) {
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
}

void DynamicIntArrayNumber::push_back(int x) {
    if (size == buffer) reserve(2 * buffer);
    arr[size] = x;
    ++size;
}

void DynamicIntArrayNumber::pop_back() {
    --size;
}


