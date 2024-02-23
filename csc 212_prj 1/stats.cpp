#include "stats.h"
#include <cassert>

using namespace std;

namespace main_savitch_2C {

    statistician::statistician() {
        count = 0;
        total = 0;
    }

    void statistician::next(double r) {
        if (count == 0) {
            count++;
            total += r;
            tinyest = r;
            largest = r;
        }
        else
        {
            count++;

            total += r;

            tinyest = min(r,tinyest);

            largest = max(r,largest);
        }
    }


    double statistician::mean() const {
        assert(count>0);
        return (total / count);
    }

    double statistician::sum() const { return total; }

    int statistician::length() const { return count; }

    double statistician::minimum() const { return tinyest; }

    double statistician::maximum() const { return largest; }

    void statistician::reset()
    {
        total =0;
        count = 0;
    }

    statistician operator + (const statistician & s1, const statistician & s2)
    {
        statistician added;

        added.total = s1.sum() + s2.sum();
        added.count = s1.length() + s2.length();

        if(s1.maximum() > s2.maximum()) added.largest = s1.maximum();
        else added.largest = s2.maximum();

        if(s1.minimum() < s2.minimum()) added.tinyest = s1.minimum();
        else added.tinyest = s2.minimum();

        return added;

    }

    statistician operator * (double scale, const statistician & s)
    {
        statistician multiplied;

        multiplied.tinyest = s.tinyest * scale;
        multiplied.largest = s.largest * scale;
        multiplied.total = s.total * scale;
        multiplied.count = s.count;

        if (scale < 0)
            swap(multiplied.tinyest, multiplied.largest);

        return multiplied;
    }

    bool operator ==(const statistician& s1, const statistician& s2)
    {
        return  (s1.length() == s2.length()) &&
                (s1.sum() == s2.sum()) &&
               (s1.minimum() == s2.minimum()) &&
               (s1.maximum() == s2.maximum());
    }
}