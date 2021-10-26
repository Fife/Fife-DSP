#include "core.h"

class DSPEngine{
    public:
        DSPEngine();
        ~DSPEngine();
    private:
        int num_channels, buffer_size, sample_rate;
        std::vector<void(*)()> input_handlers;
        std::vector<void(*)()> output_handlers;
};