#pragma once
#include "Input.h"

namespace sg
{
    class InputQueue
    {
    public:
        InputQueue();
        ~InputQueue();

        //
        // Try pop charachter from input.
        // If user press some key, this method will return char value
        // and delete it from queue. Otherwise it will return std::nullopt.
        //
        Input Pop();

        //
        // Clear input queue.
        //
        void Clear();

        //
        // Stops working thread, which handle input.
        //
        void Stop();

    private:
        void HandleInput();

    private:
        std::mutex m_lock;
        std::atomic_bool m_done;
        std::queue<Input> m_inputQueue;
        std::future<void> m_handleInputThread;
    };
}