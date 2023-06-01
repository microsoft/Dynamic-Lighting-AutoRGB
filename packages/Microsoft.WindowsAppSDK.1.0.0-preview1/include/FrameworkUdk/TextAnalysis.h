#pragma once

#include <dwrite_3.h>

namespace ABI::Microsoft::Internal::FrameworkUdk
{
    interface
        __declspec(uuid("78181988-C144-4576-8DF0-A5DBC47F8F3A"))
        ITextFormatCallbacks : public IDWriteTextAnalysisSource
    {
    public:
        virtual BOOL STDMETHODCALLTYPE SupportsGetLocaleNameList() = 0;

        STDMETHOD(GetLocaleNameList)(
            UINT32 textPosition,
            _Out_ UINT32* textLength,
            _Outptr_result_z_ WCHAR const** localeNameList
            ) = 0;
    };
}

STDAPI TextAnalysis_SetLocaleNameList(_In_ IDWriteTextFormat* textFormat, _In_z_ WCHAR const* localeNameList) noexcept;

STDAPI TextAnalysis_GetContentReadingDirection(
        _In_ IDWriteTextAnalyzer* textAnalyzer,
        _In_opt_ ABI::Microsoft::Internal::FrameworkUdk::ITextFormatCallbacks* textformatCallbacks,
        UINT32 textPosition,
        UINT32 textLength,
        _Out_ DWRITE_READING_DIRECTION* readingDirection,
        _Out_ BOOL* isAmbiguousReadingDirection
        ) noexcept;

STDAPI TextAnalysis_CreateDWritePrivateTextAnalysisSourceProxy(_In_ ABI::Microsoft::Internal::FrameworkUdk::ITextFormatCallbacks* callbacks, _Deref_out_ IDWriteTextAnalysisSource** proxy) noexcept;

