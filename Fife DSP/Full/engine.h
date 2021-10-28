#include "core.h"

class DSPEngine{
    public:
        DSPEngine();
        ~DSPEngine();

        DSPEngine(int sample_rate, int buffer_size, int num_channels);
        void UpdateInputs();
        void UpdateChannels();
        void UpdateOutputs();

    private:
        int buffer_size, sample_rate;
        std::vector<void(*)()> input_handlers;
        std::vector<void(*)()> output_handlers;
        std::vector<Channel> channel_vector;

};