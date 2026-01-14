#ifndef AFT_MAX_H
#define AFT_MAX_H

#include <cstddef>

class AftMaxProcessor {
public:
    AftMaxProcessor();

    void Process(int value);
    bool CanCalculate() const;
    size_t GetResult() const;

private:
    int max_value_;
    size_t count_after_;
    size_t total_count_;
    bool has_max_;
};

#endif
