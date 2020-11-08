#ifndef NDIMARRAY
#define NDIMARRAY

template <class Type>
class NDimArray {
private:
    unsigned dimensions;
    unsigned size;
    unsigned *length;
    Type *array;
    NDimArray();
public:
    NDimArray(unsigned dimensions, const unsigned *length) {
        this->dimensions = dimensions;
        this->length = const_cast<unsigned*>(length);
        this->size = 1;
        for(unsigned i = 0; i < dimensions; i++)
            size *= length[i];
        this->array = new Type[size];
    };
    ~NDimArray() {
        delete[] this->length;
        delete[] this->array;
    };
    Type& get(unsigned *indexes) const {
        unsigned index = 0;
        for(unsigned i = 0; i < dimensions; i++)
            index += length[i] * indexes[i];
        return this->array[index];
    };
    Type& set(unsigned *indexes, Type& value);
};

#endif //NDIMARRAY
