// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_UI_Accessibility_2_H
#define WINRT_Windows_UI_Accessibility_2_H
#include "winrt/impl/Windows.UI.Accessibility.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::Accessibility
{
    struct __declspec(empty_bases) ScreenReaderPositionChangedEventArgs : winrt::Windows::UI::Accessibility::IScreenReaderPositionChangedEventArgs
    {
        ScreenReaderPositionChangedEventArgs(std::nullptr_t) noexcept {}
        ScreenReaderPositionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Accessibility::IScreenReaderPositionChangedEventArgs(ptr, take_ownership_from_abi) {}
        ScreenReaderPositionChangedEventArgs(ScreenReaderPositionChangedEventArgs const&) noexcept = default;
        ScreenReaderPositionChangedEventArgs(ScreenReaderPositionChangedEventArgs&&) noexcept = default;
        ScreenReaderPositionChangedEventArgs& operator=(ScreenReaderPositionChangedEventArgs const&) & noexcept = default;
        ScreenReaderPositionChangedEventArgs& operator=(ScreenReaderPositionChangedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ScreenReaderService : winrt::Windows::UI::Accessibility::IScreenReaderService
    {
        ScreenReaderService(std::nullptr_t) noexcept {}
        ScreenReaderService(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Accessibility::IScreenReaderService(ptr, take_ownership_from_abi) {}
        ScreenReaderService();
        ScreenReaderService(ScreenReaderService const&) noexcept = default;
        ScreenReaderService(ScreenReaderService&&) noexcept = default;
        ScreenReaderService& operator=(ScreenReaderService const&) & noexcept = default;
        ScreenReaderService& operator=(ScreenReaderService&&) & noexcept = default;
    };
}
#endif
