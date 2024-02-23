#include "sequence2.h"
#include <iostream>
#include <cassert>

using namespace std;
namespace main_savitch_4 {
    sequence::sequence(size_type initial_capacity) {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
    }

    sequence::sequence(const sequence &source) {
        data = new value_type[source.capacity];
        used = source.used;
        capacity = source.capacity;
        current_index = source.current_index;
        copy(source.data, source.data + used, data);
    }

    sequence::~sequence() {
        delete[] data;
    }


    void sequence::resize(sequence::size_type new_capacity) {
        if (new_capacity == capacity)
            return;
        if (new_capacity < used)
            new_capacity = used;
        value_type *larger_arr = new value_type[new_capacity];
        copy(data, data + used, larger_arr);
        delete[] data;
        data = larger_arr;
        capacity = new_capacity;
    }

    void sequence::start() { current_index = 0; }

    void sequence::advance() {
        assert(is_item());
        current_index++;
    }

    void sequence::insert(const value_type &entry) {
        if (capacity == used)
            resize(capacity + (capacity * 0.1));

        if (!is_item())
            current_index = 0;
        for (sequence::size_type i = used; i > current_index; i--)
            data[i] = data[i - 1];
        data[current_index] = entry;
        used++;
    }

    void sequence::attach(const sequence::value_type &entry) {
        if (capacity == used)
            resize(capacity + (capacity * 0.1));

        is_item() ? current_index++ : current_index = used;
        for (sequence::size_type i = used; i > current_index; i--)
            data[i] = data[i - 1];
        data[current_index] = entry;
        used++;
    }

    void sequence::remove_current() {
        assert(is_item());
        used--;
        for (sequence::size_type i = current_index; i < used; i++)
            data[i] = data[i + 1];
    }

    sequence::size_type sequence::size() const { return used; }

    bool sequence::is_item() const { return current_index != used; }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }

    void sequence::operator+=(const sequence &source) {
        if (capacity < source.used + used)
            resize(capacity + source.used);
        for (size_t i = used; i < used + source.used; i++)
            data[i] = source.data[i];
        used = used + source.used;
    }

    void sequence::operator=(const sequence &source) {
        if (this != &source) {
            capacity = source.capacity;
            data = new value_type[capacity];
            used = source.used;
            current_index = source.current_index;
            for (int i = 0; i < used; i++)
                data[i] = source.data[i];
        }
    }

    sequence operator+(const sequence &source1, const sequence &source2) {
        sequence result(source1.size() + source2.size());
        result += source1;
        result += source2;
        return result;
    }

    sequence::value_type sequence::operator[](size_type index) const {
        assert(index < used);
        return data[index];
    }

}