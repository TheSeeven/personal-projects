// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Media_Casting_1_H
#define WINRT_Windows_Media_Casting_1_H
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Windows.Media.Casting.0.h"
WINRT_EXPORT namespace winrt::Windows::Media::Casting
{
    struct __declspec(empty_bases) ICastingConnection :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingConnection>,
        impl::require<winrt::Windows::Media::Casting::ICastingConnection, winrt::Windows::Foundation::IClosable>
    {
        ICastingConnection(std::nullptr_t = nullptr) noexcept {}
        ICastingConnection(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingConnection(ICastingConnection const&) noexcept = default;
        ICastingConnection(ICastingConnection&&) noexcept = default;
        ICastingConnection& operator=(ICastingConnection const&) & noexcept = default;
        ICastingConnection& operator=(ICastingConnection&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingConnectionErrorOccurredEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingConnectionErrorOccurredEventArgs>
    {
        ICastingConnectionErrorOccurredEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICastingConnectionErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingConnectionErrorOccurredEventArgs(ICastingConnectionErrorOccurredEventArgs const&) noexcept = default;
        ICastingConnectionErrorOccurredEventArgs(ICastingConnectionErrorOccurredEventArgs&&) noexcept = default;
        ICastingConnectionErrorOccurredEventArgs& operator=(ICastingConnectionErrorOccurredEventArgs const&) & noexcept = default;
        ICastingConnectionErrorOccurredEventArgs& operator=(ICastingConnectionErrorOccurredEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingDevice :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingDevice>
    {
        ICastingDevice(std::nullptr_t = nullptr) noexcept {}
        ICastingDevice(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingDevice(ICastingDevice const&) noexcept = default;
        ICastingDevice(ICastingDevice&&) noexcept = default;
        ICastingDevice& operator=(ICastingDevice const&) & noexcept = default;
        ICastingDevice& operator=(ICastingDevice&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingDevicePicker :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingDevicePicker>
    {
        ICastingDevicePicker(std::nullptr_t = nullptr) noexcept {}
        ICastingDevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingDevicePicker(ICastingDevicePicker const&) noexcept = default;
        ICastingDevicePicker(ICastingDevicePicker&&) noexcept = default;
        ICastingDevicePicker& operator=(ICastingDevicePicker const&) & noexcept = default;
        ICastingDevicePicker& operator=(ICastingDevicePicker&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingDevicePickerFilter :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingDevicePickerFilter>
    {
        ICastingDevicePickerFilter(std::nullptr_t = nullptr) noexcept {}
        ICastingDevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingDevicePickerFilter(ICastingDevicePickerFilter const&) noexcept = default;
        ICastingDevicePickerFilter(ICastingDevicePickerFilter&&) noexcept = default;
        ICastingDevicePickerFilter& operator=(ICastingDevicePickerFilter const&) & noexcept = default;
        ICastingDevicePickerFilter& operator=(ICastingDevicePickerFilter&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingDeviceSelectedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingDeviceSelectedEventArgs>
    {
        ICastingDeviceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICastingDeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingDeviceSelectedEventArgs(ICastingDeviceSelectedEventArgs const&) noexcept = default;
        ICastingDeviceSelectedEventArgs(ICastingDeviceSelectedEventArgs&&) noexcept = default;
        ICastingDeviceSelectedEventArgs& operator=(ICastingDeviceSelectedEventArgs const&) & noexcept = default;
        ICastingDeviceSelectedEventArgs& operator=(ICastingDeviceSelectedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingDeviceStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingDeviceStatics>
    {
        ICastingDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ICastingDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingDeviceStatics(ICastingDeviceStatics const&) noexcept = default;
        ICastingDeviceStatics(ICastingDeviceStatics&&) noexcept = default;
        ICastingDeviceStatics& operator=(ICastingDeviceStatics const&) & noexcept = default;
        ICastingDeviceStatics& operator=(ICastingDeviceStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ICastingSource :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICastingSource>
    {
        ICastingSource(std::nullptr_t = nullptr) noexcept {}
        ICastingSource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        ICastingSource(ICastingSource const&) noexcept = default;
        ICastingSource(ICastingSource&&) noexcept = default;
        ICastingSource& operator=(ICastingSource const&) & noexcept = default;
        ICastingSource& operator=(ICastingSource&&) & noexcept = default;
    };
}
#endif
