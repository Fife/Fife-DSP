#include "core.h"

class Channel{
    public:
        Channel();
        ~Channel();
        Channel(std::vector<void(*)()> function_list, IO_Block io_input, IO_Block io_output, AudioBufferU input, AudioBufferU output);
        AddDSP();
        RemoveDSP();
        ToggleDSP(std::string id);

    private:
        std::vector<DSPFunction> DSPFunctionList;
        IO_Block input_block;
        IO_Block output_block;
        AudioBufferU input, output;
};

struct StereoChannel{
    Channel left;
    Channel right;
};