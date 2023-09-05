
class AllPassFilter
    {
    public:
        AllPassFilter() noexcept {}

        void setSize (const int size)
        {
            if (size != bufferSize)
            {
                bufferIndex = 0;
                buffer.malloc (size);
                bufferSize = size;
            }

            clear();
        }

        void clear() noexcept
        {
            buffer.clear ((size_t) bufferSize);
        }

        float process (const float input) noexcept
        {
            const float bufferedValue = buffer [bufferIndex];
            float temp = input + (bufferedValue * 0.5f);
            // wtf is JUCE_UNDENORMALISE (temp);
            buffer [bufferIndex] = temp;
            bufferIndex = (bufferIndex + 1) % bufferSize;
            return bufferedValue - input;
        }

    private:
        HeapBlock<float> buffer;
        int bufferSize = 0, bufferIndex = 0;
    };

