#include "stdafx.h"
#include "InputQueue.h"

namespace sg
{
    InputQueue::InputQueue()
        : m_done(false)
        , m_handleInputThread(std::async(std::launch::async, &InputQueue::HandleInput, this))
    {
    }

    InputQueue::~InputQueue()
    {
        Stop();

        if (m_handleInputThread.valid())
        {
            // If in handle input thread was called _getch and user did not
            // press some key, we will wait until user press some key.
            m_handleInputThread.get();
        }
    }

    Input InputQueue::Pop()
    {
        Input input = Input::Undefined;

        std::lock_guard<std::mutex> lock(m_lock);
        if (!m_inputQueue.empty())
        {
            input = m_inputQueue.front();
            m_inputQueue.pop();
        }

        return input;
    }

    void InputQueue::Clear()
    {
        std::lock_guard<std::mutex> lock(m_lock);
        m_inputQueue = std::queue<Input>();
    }

    void InputQueue::Stop()
    {
        m_done = true;
    }

    void InputQueue::HandleInput()
    {
        while (!m_done)
        {
            auto button = static_cast<Input>(toupper(_getch()));
            switch (button)
            {
            case Input::Up:
            case Input::Left:
            case Input::Down:
            case Input::Right:
            case Input::Enter:
            case Input::Esc:
            {
                std::lock_guard<std::mutex> lock(m_lock);
                m_inputQueue.push(button);
            }
            break;

            case Input::Undefined:
            default:
                continue;
            }
        }
    }
}