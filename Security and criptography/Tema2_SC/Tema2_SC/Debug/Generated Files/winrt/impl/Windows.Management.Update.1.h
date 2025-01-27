// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Management_Update_1_H
#define WINRT_Windows_Management_Update_1_H
#include "winrt/impl/Windows.Management.Update.0.h"
WINRT_EXPORT namespace winrt::Windows::Management::Update
{
    struct __declspec(empty_bases) IPreviewBuildsManager :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsManager>
    {
        IPreviewBuildsManager(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPreviewBuildsManager(IPreviewBuildsManager const&) noexcept = default;
        IPreviewBuildsManager(IPreviewBuildsManager&&) noexcept = default;
        IPreviewBuildsManager& operator=(IPreviewBuildsManager const&) & noexcept = default;
        IPreviewBuildsManager& operator=(IPreviewBuildsManager&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPreviewBuildsManagerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsManagerStatics>
    {
        IPreviewBuildsManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPreviewBuildsManagerStatics(IPreviewBuildsManagerStatics const&) noexcept = default;
        IPreviewBuildsManagerStatics(IPreviewBuildsManagerStatics&&) noexcept = default;
        IPreviewBuildsManagerStatics& operator=(IPreviewBuildsManagerStatics const&) & noexcept = default;
        IPreviewBuildsManagerStatics& operator=(IPreviewBuildsManagerStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPreviewBuildsState :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsState>
    {
        IPreviewBuildsState(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsState(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPreviewBuildsState(IPreviewBuildsState const&) noexcept = default;
        IPreviewBuildsState(IPreviewBuildsState&&) noexcept = default;
        IPreviewBuildsState& operator=(IPreviewBuildsState const&) & noexcept = default;
        IPreviewBuildsState& operator=(IPreviewBuildsState&&) & noexcept = default;
    };
}
#endif
