#include <cassert>
#include "sequence1.h"

namespace main_savitch_3
{
    sequence::sequence() {
        used = 0;
        current_index = 0;
    }

    void sequence::start() { current_index = 0; }

    void sequence::advance() {
        assert(is_item());
        current_index++;
    }

    void sequence::insert(const value_type &entry) {
        assert(size() < sequence::CAPACITY);
        if (!is_item())
            current_index = 0;
        for (sequence::size_type i = used; i > current_index; i--)
            data[i] = data[i - 1];
        data[current_index] = entry;
        used++;
    }

    void sequence::attach(const sequence::value_type &entry) {
        assert(size() < sequence::CAPACITY);
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
            data[i] = data[i+1];
    }

    sequence::size_type sequence::size() const { return used; }

    bool sequence::is_item() const { return current_index != used; }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }
}