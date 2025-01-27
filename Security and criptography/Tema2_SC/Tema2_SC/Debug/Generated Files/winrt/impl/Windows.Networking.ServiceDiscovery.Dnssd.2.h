// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Networking_ServiceDiscovery_Dnssd_2_H
#define WINRT_Windows_Networking_ServiceDiscovery_Dnssd_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Networking.1.h"
#include "winrt/impl/Windows.Networking.ServiceDiscovery.Dnssd.1.h"
WINRT_EXPORT namespace winrt::Windows::Networking::ServiceDiscovery::Dnssd
{
    struct __declspec(empty_bases) DnssdRegistrationResult : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult,
        impl::require<DnssdRegistrationResult, winrt::Windows::Foundation::IStringable>
    {
        DnssdRegistrationResult(std::nullptr_t) noexcept {}
        DnssdRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult(ptr, take_ownership_from_abi) {}
        DnssdRegistrationResult();
        DnssdRegistrationResult(DnssdRegistrationResult const&) noexcept = default;
        DnssdRegistrationResult(DnssdRegistrationResult&&) noexcept = default;
        DnssdRegistrationResult& operator=(DnssdRegistrationResult const&) & noexcept = default;
        DnssdRegistrationResult& operator=(DnssdRegistrationResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DnssdServiceInstance : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance,
        impl::require<DnssdServiceInstance, winrt::Windows::Foundation::IStringable>
    {
        DnssdServiceInstance(std::nullptr_t) noexcept {}
        DnssdServiceInstance(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance(ptr, take_ownership_from_abi) {}
        DnssdServiceInstance(param::hstring const& dnssdServiceInstanceName, winrt::Windows::Networking::HostName const& hostName, uint16_t port);
        DnssdServiceInstance(DnssdServiceInstance const&) noexcept = default;
        DnssdServiceInstance(DnssdServiceInstance&&) noexcept = default;
        DnssdServiceInstance& operator=(DnssdServiceInstance const&) & noexcept = default;
        DnssdServiceInstance& operator=(DnssdServiceInstance&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DnssdServiceInstanceCollection : winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>
    {
        DnssdServiceInstanceCollection(std::nullptr_t) noexcept {}
        DnssdServiceInstanceCollection(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>(ptr, take_ownership_from_abi) {}
        DnssdServiceInstanceCollection(DnssdServiceInstanceCollection const&) noexcept = default;
        DnssdServiceInstanceCollection(DnssdServiceInstanceCollection&&) noexcept = default;
        DnssdServiceInstanceCollection& operator=(DnssdServiceInstanceCollection const&) & noexcept = default;
        DnssdServiceInstanceCollection& operator=(DnssdServiceInstanceCollection&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DnssdServiceWatcher : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher
    {
        DnssdServiceWatcher(std::nullptr_t) noexcept {}
        DnssdServiceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher(ptr, take_ownership_from_abi) {}
        DnssdServiceWatcher(DnssdServiceWatcher const&) noexcept = default;
        DnssdServiceWatcher(DnssdServiceWatcher&&) noexcept = default;
        DnssdServiceWatcher& operator=(DnssdServiceWatcher const&) & noexcept = default;
        DnssdServiceWatcher& operator=(DnssdServiceWatcher&&) & noexcept = default;
    };
}
#endif
