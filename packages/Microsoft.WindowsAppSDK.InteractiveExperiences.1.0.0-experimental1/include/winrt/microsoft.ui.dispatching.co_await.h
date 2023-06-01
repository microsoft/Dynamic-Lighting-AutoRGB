
// Copyright (c) Microsoft Corporation.  All rights reserved.
#pragma once

#ifdef CPPWINRT_VERSION
WINRT_EXPORT namespace winrt
{
    [[nodiscard]] inline auto resume_foreground(
        Microsoft::UI::Dispatching::DispatcherQueue const& dispatcher,
        Microsoft::UI::Dispatching::DispatcherQueuePriority const priority = Microsoft::UI::Dispatching::DispatcherQueuePriority::Normal) noexcept
    {
        struct awaitable
        {
            awaitable(Microsoft::UI::Dispatching::DispatcherQueue const& dispatcher, Microsoft::UI::Dispatching::DispatcherQueuePriority const priority) noexcept :
                m_dispatcher(dispatcher),
                m_priority(priority)
            {
            }

            bool await_ready() const noexcept
            {
                return false;
            }

            bool await_resume() const noexcept
            {
                return m_queued;
            }

            bool await_suspend(impl::coroutine_handle<> handle)
            {
                return m_dispatcher.TryEnqueue(m_priority, [handle, this]
                    {
                        m_queued = true;
                        handle();
                    });
            }

        private:
            Microsoft::UI::Dispatching::DispatcherQueue const& m_dispatcher;
            Microsoft::UI::Dispatching::DispatcherQueuePriority const m_priority;
            bool m_queued{};
        };

        return awaitable{ dispatcher, priority };
    };

#ifdef WINRT_IMPL_COROUTINES
    inline auto operator co_await(Microsoft::UI::Dispatching::DispatcherQueue const& dispatcher)
    {
        return resume_foreground(dispatcher);
    }
#endif
}
#endif