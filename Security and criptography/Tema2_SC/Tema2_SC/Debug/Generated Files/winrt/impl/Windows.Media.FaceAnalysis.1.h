// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Media_FaceAnalysis_1_H
#define WINRT_Windows_Media_FaceAnalysis_1_H
#include "winrt/impl/Windows.Media.FaceAnalysis.0.h"
WINRT_EXPORT namespace winrt::Windows::Media::FaceAnalysis
{
    struct __declspec(empty_bases) IDetectedFace :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDetectedFace>
    {
        IDetectedFace(std::nullptr_t = nullptr) noexcept {}
        IDetectedFace(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IDetectedFace(IDetectedFace const&) noexcept = default;
        IDetectedFace(IDetectedFace&&) noexcept = default;
        IDetectedFace& operator=(IDetectedFace const&) & noexcept = default;
        IDetectedFace& operator=(IDetectedFace&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IFaceDetector :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFaceDetector>
    {
        IFaceDetector(std::nullptr_t = nullptr) noexcept {}
        IFaceDetector(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IFaceDetector(IFaceDetector const&) noexcept = default;
        IFaceDetector(IFaceDetector&&) noexcept = default;
        IFaceDetector& operator=(IFaceDetector const&) & noexcept = default;
        IFaceDetector& operator=(IFaceDetector&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IFaceDetectorStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFaceDetectorStatics>
    {
        IFaceDetectorStatics(std::nullptr_t = nullptr) noexcept {}
        IFaceDetectorStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IFaceDetectorStatics(IFaceDetectorStatics const&) noexcept = default;
        IFaceDetectorStatics(IFaceDetectorStatics&&) noexcept = default;
        IFaceDetectorStatics& operator=(IFaceDetectorStatics const&) & noexcept = default;
        IFaceDetectorStatics& operator=(IFaceDetectorStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IFaceTracker :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFaceTracker>
    {
        IFaceTracker(std::nullptr_t = nullptr) noexcept {}
        IFaceTracker(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IFaceTracker(IFaceTracker const&) noexcept = default;
        IFaceTracker(IFaceTracker&&) noexcept = default;
        IFaceTracker& operator=(IFaceTracker const&) & noexcept = default;
        IFaceTracker& operator=(IFaceTracker&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IFaceTrackerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFaceTrackerStatics>
    {
        IFaceTrackerStatics(std::nullptr_t = nullptr) noexcept {}
        IFaceTrackerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IFaceTrackerStatics(IFaceTrackerStatics const&) noexcept = default;
        IFaceTrackerStatics(IFaceTrackerStatics&&) noexcept = default;
        IFaceTrackerStatics& operator=(IFaceTrackerStatics const&) & noexcept = default;
        IFaceTrackerStatics& operator=(IFaceTrackerStatics&&) & noexcept = default;
    };
}
#endif
