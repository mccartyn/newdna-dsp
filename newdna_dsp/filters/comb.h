class CombFilter
    {
    public:
        CombFilter() noexcept {}

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
            last = 0;
            buffer.clear ((size_t) bufferSize);
        }

        float process (const float input, const float damp, const float feedbackLevel) noexcept
        {
            const float output = buffer[bufferIndex];
            last = (output * (1.0f - damp)) + (last * damp);
            //wtf is JUCE_UNDENORMALISE (last);

            float temp = input + (last * feedbackLevel);
            //wtf is JUCE_UNDENORMALISE (temp);
            buffer[bufferIndex] = temp;
            bufferIndex = (bufferIndex + 1) % bufferSize;
            return output;
        }

    private:
        HeapBlock<float> buffer;

        int bufferSize = 0, bufferIndex = 0;
        float last = 0.0f;
    };
