#pragma once
#include "Input.h"

namespace sg
{
    //
    // This class collects user input to a queue.
    //
    // To get user input just use Pop() method. If there were not
    // any user input Pop() method returns Input::Undefined value.
    //
    class InputQueue
    {
    public:
        InputQueue();
        ~InputQueue();

        Input Pop();
        void Clear();
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