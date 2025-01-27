// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_System_RemoteSystems_2_H
#define WINRT_Windows_System_RemoteSystems_2_H
#include "winrt/impl/Windows.ApplicationModel.AppService.1.h"
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Networking.1.h"
#include "winrt/impl/Windows.Security.Credentials.1.h"
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.System.RemoteSystems.1.h"
WINRT_EXPORT namespace winrt::Windows::System::RemoteSystems
{
    struct KnownRemoteSystemCapabilities
    {
        KnownRemoteSystemCapabilities() = delete;
        [[nodiscard]] static auto AppService();
        [[nodiscard]] static auto LaunchUri();
        [[nodiscard]] static auto RemoteSession();
        [[nodiscard]] static auto SpatialEntity();
    };
    struct __declspec(empty_bases) RemoteSystem : winrt::Windows::System::RemoteSystems::IRemoteSystem,
        impl::require<RemoteSystem, winrt::Windows::System::RemoteSystems::IRemoteSystem2, winrt::Windows::System::RemoteSystems::IRemoteSystem3, winrt::Windows::System::RemoteSystems::IRemoteSystem4, winrt::Windows::System::RemoteSystems::IRemoteSystem5, winrt::Windows::System::RemoteSystems::IRemoteSystem6>
    {
        RemoteSystem(std::nullptr_t) noexcept {}
        RemoteSystem(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystem(ptr, take_ownership_from_abi) {}
        RemoteSystem(RemoteSystem const&) noexcept = default;
        RemoteSystem(RemoteSystem&&) noexcept = default;
        RemoteSystem& operator=(RemoteSystem const&) & noexcept = default;
        RemoteSystem& operator=(RemoteSystem&&) & noexcept = default;
        static auto FindByHostNameAsync(winrt::Windows::Networking::HostName const& hostName);
        static auto CreateWatcher();
        static auto CreateWatcher(param::iterable<winrt::Windows::System::RemoteSystems::IRemoteSystemFilter> const& filters);
        static auto RequestAccessAsync();
        static auto IsAuthorizationKindEnabled(winrt::Windows::System::RemoteSystems::RemoteSystemAuthorizationKind const& kind);
        static auto CreateWatcherForUser(winrt::Windows::System::User const& user);
        static auto CreateWatcherForUser(winrt::Windows::System::User const& user, param::iterable<winrt::Windows::System::RemoteSystems::IRemoteSystemFilter> const& filters);
    };
    struct __declspec(empty_bases) RemoteSystemAddedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs
    {
        RemoteSystemAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemAddedEventArgs(RemoteSystemAddedEventArgs const&) noexcept = default;
        RemoteSystemAddedEventArgs(RemoteSystemAddedEventArgs&&) noexcept = default;
        RemoteSystemAddedEventArgs& operator=(RemoteSystemAddedEventArgs const&) & noexcept = default;
        RemoteSystemAddedEventArgs& operator=(RemoteSystemAddedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemApp : winrt::Windows::System::RemoteSystems::IRemoteSystemApp,
        impl::require<RemoteSystemApp, winrt::Windows::System::RemoteSystems::IRemoteSystemApp2>
    {
        RemoteSystemApp(std::nullptr_t) noexcept {}
        RemoteSystemApp(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemApp(ptr, take_ownership_from_abi) {}
        RemoteSystemApp(RemoteSystemApp const&) noexcept = default;
        RemoteSystemApp(RemoteSystemApp&&) noexcept = default;
        RemoteSystemApp& operator=(RemoteSystemApp const&) & noexcept = default;
        RemoteSystemApp& operator=(RemoteSystemApp&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemAppRegistration : winrt::Windows::System::RemoteSystems::IRemoteSystemAppRegistration
    {
        RemoteSystemAppRegistration(std::nullptr_t) noexcept {}
        RemoteSystemAppRegistration(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemAppRegistration(ptr, take_ownership_from_abi) {}
        RemoteSystemAppRegistration(RemoteSystemAppRegistration const&) noexcept = default;
        RemoteSystemAppRegistration(RemoteSystemAppRegistration&&) noexcept = default;
        RemoteSystemAppRegistration& operator=(RemoteSystemAppRegistration const&) & noexcept = default;
        RemoteSystemAppRegistration& operator=(RemoteSystemAppRegistration&&) & noexcept = default;
        static auto GetDefault();
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct __declspec(empty_bases) RemoteSystemAuthorizationKindFilter : winrt::Windows::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter,
        impl::require<RemoteSystemAuthorizationKindFilter, winrt::Windows::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemAuthorizationKindFilter(std::nullptr_t) noexcept {}
        RemoteSystemAuthorizationKindFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemAuthorizationKindFilter(winrt::Windows::System::RemoteSystems::RemoteSystemAuthorizationKind const& remoteSystemAuthorizationKind);
        RemoteSystemAuthorizationKindFilter(RemoteSystemAuthorizationKindFilter const&) noexcept = default;
        RemoteSystemAuthorizationKindFilter(RemoteSystemAuthorizationKindFilter&&) noexcept = default;
        RemoteSystemAuthorizationKindFilter& operator=(RemoteSystemAuthorizationKindFilter const&) & noexcept = default;
        RemoteSystemAuthorizationKindFilter& operator=(RemoteSystemAuthorizationKindFilter&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemConnectionInfo : winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionInfo
    {
        RemoteSystemConnectionInfo(std::nullptr_t) noexcept {}
        RemoteSystemConnectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionInfo(ptr, take_ownership_from_abi) {}
        RemoteSystemConnectionInfo(RemoteSystemConnectionInfo const&) noexcept = default;
        RemoteSystemConnectionInfo(RemoteSystemConnectionInfo&&) noexcept = default;
        RemoteSystemConnectionInfo& operator=(RemoteSystemConnectionInfo const&) & noexcept = default;
        RemoteSystemConnectionInfo& operator=(RemoteSystemConnectionInfo&&) & noexcept = default;
        static auto TryCreateFromAppServiceConnection(winrt::Windows::ApplicationModel::AppService::AppServiceConnection const& connection);
    };
    struct __declspec(empty_bases) RemoteSystemConnectionRequest : winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest,
        impl::require<RemoteSystemConnectionRequest, winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest2, winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest3>
    {
        RemoteSystemConnectionRequest(std::nullptr_t) noexcept {}
        RemoteSystemConnectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemConnectionRequest(winrt::Windows::System::RemoteSystems::RemoteSystem const& remoteSystem);
        RemoteSystemConnectionRequest(RemoteSystemConnectionRequest const&) noexcept = default;
        RemoteSystemConnectionRequest(RemoteSystemConnectionRequest&&) noexcept = default;
        RemoteSystemConnectionRequest& operator=(RemoteSystemConnectionRequest const&) & noexcept = default;
        RemoteSystemConnectionRequest& operator=(RemoteSystemConnectionRequest&&) & noexcept = default;
        static auto CreateForApp(winrt::Windows::System::RemoteSystems::RemoteSystemApp const& remoteSystemApp);
        static auto CreateFromConnectionToken(param::hstring const& connectionToken);
        static auto CreateFromConnectionTokenForUser(winrt::Windows::System::User const& user, param::hstring const& connectionToken);
    };
    struct __declspec(empty_bases) RemoteSystemDiscoveryTypeFilter : winrt::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter,
        impl::require<RemoteSystemDiscoveryTypeFilter, winrt::Windows::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemDiscoveryTypeFilter(std::nullptr_t) noexcept {}
        RemoteSystemDiscoveryTypeFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemDiscoveryTypeFilter(winrt::Windows::System::RemoteSystems::RemoteSystemDiscoveryType const& discoveryType);
        RemoteSystemDiscoveryTypeFilter(RemoteSystemDiscoveryTypeFilter const&) noexcept = default;
        RemoteSystemDiscoveryTypeFilter(RemoteSystemDiscoveryTypeFilter&&) noexcept = default;
        RemoteSystemDiscoveryTypeFilter& operator=(RemoteSystemDiscoveryTypeFilter const&) & noexcept = default;
        RemoteSystemDiscoveryTypeFilter& operator=(RemoteSystemDiscoveryTypeFilter&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemEnumerationCompletedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs
    {
        RemoteSystemEnumerationCompletedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemEnumerationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemEnumerationCompletedEventArgs(RemoteSystemEnumerationCompletedEventArgs const&) noexcept = default;
        RemoteSystemEnumerationCompletedEventArgs(RemoteSystemEnumerationCompletedEventArgs&&) noexcept = default;
        RemoteSystemEnumerationCompletedEventArgs& operator=(RemoteSystemEnumerationCompletedEventArgs const&) & noexcept = default;
        RemoteSystemEnumerationCompletedEventArgs& operator=(RemoteSystemEnumerationCompletedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemKindFilter : winrt::Windows::System::RemoteSystems::IRemoteSystemKindFilter,
        impl::require<RemoteSystemKindFilter, winrt::Windows::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemKindFilter(std::nullptr_t) noexcept {}
        RemoteSystemKindFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemKindFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemKindFilter(param::iterable<hstring> const& remoteSystemKinds);
        RemoteSystemKindFilter(RemoteSystemKindFilter const&) noexcept = default;
        RemoteSystemKindFilter(RemoteSystemKindFilter&&) noexcept = default;
        RemoteSystemKindFilter& operator=(RemoteSystemKindFilter const&) & noexcept = default;
        RemoteSystemKindFilter& operator=(RemoteSystemKindFilter&&) & noexcept = default;
    };
    struct RemoteSystemKinds
    {
        RemoteSystemKinds() = delete;
        [[nodiscard]] static auto Phone();
        [[nodiscard]] static auto Hub();
        [[nodiscard]] static auto Holographic();
        [[nodiscard]] static auto Desktop();
        [[nodiscard]] static auto Xbox();
        [[nodiscard]] static auto Iot();
        [[nodiscard]] static auto Tablet();
        [[nodiscard]] static auto Laptop();
    };
    struct __declspec(empty_bases) RemoteSystemRemovedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs
    {
        RemoteSystemRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemRemovedEventArgs(RemoteSystemRemovedEventArgs const&) noexcept = default;
        RemoteSystemRemovedEventArgs(RemoteSystemRemovedEventArgs&&) noexcept = default;
        RemoteSystemRemovedEventArgs& operator=(RemoteSystemRemovedEventArgs const&) & noexcept = default;
        RemoteSystemRemovedEventArgs& operator=(RemoteSystemRemovedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSession : winrt::Windows::System::RemoteSystems::IRemoteSystemSession,
        impl::require<RemoteSystemSession, winrt::Windows::Foundation::IClosable>
    {
        RemoteSystemSession(std::nullptr_t) noexcept {}
        RemoteSystemSession(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSession(ptr, take_ownership_from_abi) {}
        RemoteSystemSession(RemoteSystemSession const&) noexcept = default;
        RemoteSystemSession(RemoteSystemSession&&) noexcept = default;
        RemoteSystemSession& operator=(RemoteSystemSession const&) & noexcept = default;
        RemoteSystemSession& operator=(RemoteSystemSession&&) & noexcept = default;
        static auto CreateWatcher();
    };
    struct __declspec(empty_bases) RemoteSystemSessionAddedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs
    {
        RemoteSystemSessionAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionAddedEventArgs(RemoteSystemSessionAddedEventArgs const&) noexcept = default;
        RemoteSystemSessionAddedEventArgs(RemoteSystemSessionAddedEventArgs&&) noexcept = default;
        RemoteSystemSessionAddedEventArgs& operator=(RemoteSystemSessionAddedEventArgs const&) & noexcept = default;
        RemoteSystemSessionAddedEventArgs& operator=(RemoteSystemSessionAddedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionController : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionController
    {
        RemoteSystemSessionController(std::nullptr_t) noexcept {}
        RemoteSystemSessionController(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionController(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemSessionController(param::hstring const& displayName);
        RemoteSystemSessionController(param::hstring const& displayName, winrt::Windows::System::RemoteSystems::RemoteSystemSessionOptions const& options);
        RemoteSystemSessionController(RemoteSystemSessionController const&) noexcept = default;
        RemoteSystemSessionController(RemoteSystemSessionController&&) noexcept = default;
        RemoteSystemSessionController& operator=(RemoteSystemSessionController const&) & noexcept = default;
        RemoteSystemSessionController& operator=(RemoteSystemSessionController&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionCreationResult : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionCreationResult
    {
        RemoteSystemSessionCreationResult(std::nullptr_t) noexcept {}
        RemoteSystemSessionCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionCreationResult(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionCreationResult(RemoteSystemSessionCreationResult const&) noexcept = default;
        RemoteSystemSessionCreationResult(RemoteSystemSessionCreationResult&&) noexcept = default;
        RemoteSystemSessionCreationResult& operator=(RemoteSystemSessionCreationResult const&) & noexcept = default;
        RemoteSystemSessionCreationResult& operator=(RemoteSystemSessionCreationResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionDisconnectedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs
    {
        RemoteSystemSessionDisconnectedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionDisconnectedEventArgs(RemoteSystemSessionDisconnectedEventArgs const&) noexcept = default;
        RemoteSystemSessionDisconnectedEventArgs(RemoteSystemSessionDisconnectedEventArgs&&) noexcept = default;
        RemoteSystemSessionDisconnectedEventArgs& operator=(RemoteSystemSessionDisconnectedEventArgs const&) & noexcept = default;
        RemoteSystemSessionDisconnectedEventArgs& operator=(RemoteSystemSessionDisconnectedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionInfo : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInfo
    {
        RemoteSystemSessionInfo(std::nullptr_t) noexcept {}
        RemoteSystemSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInfo(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionInfo(RemoteSystemSessionInfo const&) noexcept = default;
        RemoteSystemSessionInfo(RemoteSystemSessionInfo&&) noexcept = default;
        RemoteSystemSessionInfo& operator=(RemoteSystemSessionInfo const&) & noexcept = default;
        RemoteSystemSessionInfo& operator=(RemoteSystemSessionInfo&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitation : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitation
    {
        RemoteSystemSessionInvitation(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitation(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionInvitation(RemoteSystemSessionInvitation const&) noexcept = default;
        RemoteSystemSessionInvitation(RemoteSystemSessionInvitation&&) noexcept = default;
        RemoteSystemSessionInvitation& operator=(RemoteSystemSessionInvitation const&) & noexcept = default;
        RemoteSystemSessionInvitation& operator=(RemoteSystemSessionInvitation&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitationListener : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitationListener
    {
        RemoteSystemSessionInvitationListener(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitationListener(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitationListener(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionInvitationListener();
        RemoteSystemSessionInvitationListener(RemoteSystemSessionInvitationListener const&) noexcept = default;
        RemoteSystemSessionInvitationListener(RemoteSystemSessionInvitationListener&&) noexcept = default;
        RemoteSystemSessionInvitationListener& operator=(RemoteSystemSessionInvitationListener const&) & noexcept = default;
        RemoteSystemSessionInvitationListener& operator=(RemoteSystemSessionInvitationListener&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitationReceivedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs
    {
        RemoteSystemSessionInvitationReceivedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitationReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionInvitationReceivedEventArgs(RemoteSystemSessionInvitationReceivedEventArgs const&) noexcept = default;
        RemoteSystemSessionInvitationReceivedEventArgs(RemoteSystemSessionInvitationReceivedEventArgs&&) noexcept = default;
        RemoteSystemSessionInvitationReceivedEventArgs& operator=(RemoteSystemSessionInvitationReceivedEventArgs const&) & noexcept = default;
        RemoteSystemSessionInvitationReceivedEventArgs& operator=(RemoteSystemSessionInvitationReceivedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinRequest : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinRequest
    {
        RemoteSystemSessionJoinRequest(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinRequest(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionJoinRequest(RemoteSystemSessionJoinRequest const&) noexcept = default;
        RemoteSystemSessionJoinRequest(RemoteSystemSessionJoinRequest&&) noexcept = default;
        RemoteSystemSessionJoinRequest& operator=(RemoteSystemSessionJoinRequest const&) & noexcept = default;
        RemoteSystemSessionJoinRequest& operator=(RemoteSystemSessionJoinRequest&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinRequestedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs
    {
        RemoteSystemSessionJoinRequestedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionJoinRequestedEventArgs(RemoteSystemSessionJoinRequestedEventArgs const&) noexcept = default;
        RemoteSystemSessionJoinRequestedEventArgs(RemoteSystemSessionJoinRequestedEventArgs&&) noexcept = default;
        RemoteSystemSessionJoinRequestedEventArgs& operator=(RemoteSystemSessionJoinRequestedEventArgs const&) & noexcept = default;
        RemoteSystemSessionJoinRequestedEventArgs& operator=(RemoteSystemSessionJoinRequestedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinResult : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinResult
    {
        RemoteSystemSessionJoinResult(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionJoinResult(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionJoinResult(RemoteSystemSessionJoinResult const&) noexcept = default;
        RemoteSystemSessionJoinResult(RemoteSystemSessionJoinResult&&) noexcept = default;
        RemoteSystemSessionJoinResult& operator=(RemoteSystemSessionJoinResult const&) & noexcept = default;
        RemoteSystemSessionJoinResult& operator=(RemoteSystemSessionJoinResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionMessageChannel : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionMessageChannel
    {
        RemoteSystemSessionMessageChannel(std::nullptr_t) noexcept {}
        RemoteSystemSessionMessageChannel(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionMessageChannel(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionMessageChannel(winrt::Windows::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName);
        RemoteSystemSessionMessageChannel(winrt::Windows::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName, winrt::Windows::System::RemoteSystems::RemoteSystemSessionMessageChannelReliability const& reliability);
        RemoteSystemSessionMessageChannel(RemoteSystemSessionMessageChannel const&) noexcept = default;
        RemoteSystemSessionMessageChannel(RemoteSystemSessionMessageChannel&&) noexcept = default;
        RemoteSystemSessionMessageChannel& operator=(RemoteSystemSessionMessageChannel const&) & noexcept = default;
        RemoteSystemSessionMessageChannel& operator=(RemoteSystemSessionMessageChannel&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionOptions : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionOptions
    {
        RemoteSystemSessionOptions(std::nullptr_t) noexcept {}
        RemoteSystemSessionOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionOptions(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionOptions();
        RemoteSystemSessionOptions(RemoteSystemSessionOptions const&) noexcept = default;
        RemoteSystemSessionOptions(RemoteSystemSessionOptions&&) noexcept = default;
        RemoteSystemSessionOptions& operator=(RemoteSystemSessionOptions const&) & noexcept = default;
        RemoteSystemSessionOptions& operator=(RemoteSystemSessionOptions&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipant : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipant
    {
        RemoteSystemSessionParticipant(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipant(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipant(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionParticipant(RemoteSystemSessionParticipant const&) noexcept = default;
        RemoteSystemSessionParticipant(RemoteSystemSessionParticipant&&) noexcept = default;
        RemoteSystemSessionParticipant& operator=(RemoteSystemSessionParticipant const&) & noexcept = default;
        RemoteSystemSessionParticipant& operator=(RemoteSystemSessionParticipant&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantAddedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs
    {
        RemoteSystemSessionParticipantAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionParticipantAddedEventArgs(RemoteSystemSessionParticipantAddedEventArgs const&) noexcept = default;
        RemoteSystemSessionParticipantAddedEventArgs(RemoteSystemSessionParticipantAddedEventArgs&&) noexcept = default;
        RemoteSystemSessionParticipantAddedEventArgs& operator=(RemoteSystemSessionParticipantAddedEventArgs const&) & noexcept = default;
        RemoteSystemSessionParticipantAddedEventArgs& operator=(RemoteSystemSessionParticipantAddedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantRemovedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs
    {
        RemoteSystemSessionParticipantRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionParticipantRemovedEventArgs(RemoteSystemSessionParticipantRemovedEventArgs const&) noexcept = default;
        RemoteSystemSessionParticipantRemovedEventArgs(RemoteSystemSessionParticipantRemovedEventArgs&&) noexcept = default;
        RemoteSystemSessionParticipantRemovedEventArgs& operator=(RemoteSystemSessionParticipantRemovedEventArgs const&) & noexcept = default;
        RemoteSystemSessionParticipantRemovedEventArgs& operator=(RemoteSystemSessionParticipantRemovedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantWatcher : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher
    {
        RemoteSystemSessionParticipantWatcher(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantWatcher(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionParticipantWatcher(RemoteSystemSessionParticipantWatcher const&) noexcept = default;
        RemoteSystemSessionParticipantWatcher(RemoteSystemSessionParticipantWatcher&&) noexcept = default;
        RemoteSystemSessionParticipantWatcher& operator=(RemoteSystemSessionParticipantWatcher const&) & noexcept = default;
        RemoteSystemSessionParticipantWatcher& operator=(RemoteSystemSessionParticipantWatcher&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionRemovedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs
    {
        RemoteSystemSessionRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionRemovedEventArgs(RemoteSystemSessionRemovedEventArgs const&) noexcept = default;
        RemoteSystemSessionRemovedEventArgs(RemoteSystemSessionRemovedEventArgs&&) noexcept = default;
        RemoteSystemSessionRemovedEventArgs& operator=(RemoteSystemSessionRemovedEventArgs const&) & noexcept = default;
        RemoteSystemSessionRemovedEventArgs& operator=(RemoteSystemSessionRemovedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionUpdatedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs
    {
        RemoteSystemSessionUpdatedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionUpdatedEventArgs(RemoteSystemSessionUpdatedEventArgs const&) noexcept = default;
        RemoteSystemSessionUpdatedEventArgs(RemoteSystemSessionUpdatedEventArgs&&) noexcept = default;
        RemoteSystemSessionUpdatedEventArgs& operator=(RemoteSystemSessionUpdatedEventArgs const&) & noexcept = default;
        RemoteSystemSessionUpdatedEventArgs& operator=(RemoteSystemSessionUpdatedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionValueSetReceivedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs
    {
        RemoteSystemSessionValueSetReceivedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionValueSetReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionValueSetReceivedEventArgs(RemoteSystemSessionValueSetReceivedEventArgs const&) noexcept = default;
        RemoteSystemSessionValueSetReceivedEventArgs(RemoteSystemSessionValueSetReceivedEventArgs&&) noexcept = default;
        RemoteSystemSessionValueSetReceivedEventArgs& operator=(RemoteSystemSessionValueSetReceivedEventArgs const&) & noexcept = default;
        RemoteSystemSessionValueSetReceivedEventArgs& operator=(RemoteSystemSessionValueSetReceivedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemSessionWatcher : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionWatcher
    {
        RemoteSystemSessionWatcher(std::nullptr_t) noexcept {}
        RemoteSystemSessionWatcher(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemSessionWatcher(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionWatcher(RemoteSystemSessionWatcher const&) noexcept = default;
        RemoteSystemSessionWatcher(RemoteSystemSessionWatcher&&) noexcept = default;
        RemoteSystemSessionWatcher& operator=(RemoteSystemSessionWatcher const&) & noexcept = default;
        RemoteSystemSessionWatcher& operator=(RemoteSystemSessionWatcher&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemStatusTypeFilter : winrt::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter,
        impl::require<RemoteSystemStatusTypeFilter, winrt::Windows::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemStatusTypeFilter(std::nullptr_t) noexcept {}
        RemoteSystemStatusTypeFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemStatusTypeFilter(winrt::Windows::System::RemoteSystems::RemoteSystemStatusType const& remoteSystemStatusType);
        RemoteSystemStatusTypeFilter(RemoteSystemStatusTypeFilter const&) noexcept = default;
        RemoteSystemStatusTypeFilter(RemoteSystemStatusTypeFilter&&) noexcept = default;
        RemoteSystemStatusTypeFilter& operator=(RemoteSystemStatusTypeFilter const&) & noexcept = default;
        RemoteSystemStatusTypeFilter& operator=(RemoteSystemStatusTypeFilter&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemUpdatedEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs
    {
        RemoteSystemUpdatedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemUpdatedEventArgs(RemoteSystemUpdatedEventArgs const&) noexcept = default;
        RemoteSystemUpdatedEventArgs(RemoteSystemUpdatedEventArgs&&) noexcept = default;
        RemoteSystemUpdatedEventArgs& operator=(RemoteSystemUpdatedEventArgs const&) & noexcept = default;
        RemoteSystemUpdatedEventArgs& operator=(RemoteSystemUpdatedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemWatcher : winrt::Windows::System::RemoteSystems::IRemoteSystemWatcher,
        impl::require<RemoteSystemWatcher, winrt::Windows::System::RemoteSystems::IRemoteSystemWatcher2, winrt::Windows::System::RemoteSystems::IRemoteSystemWatcher3>
    {
        RemoteSystemWatcher(std::nullptr_t) noexcept {}
        RemoteSystemWatcher(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemWatcher(ptr, take_ownership_from_abi) {}
        RemoteSystemWatcher(RemoteSystemWatcher const&) noexcept = default;
        RemoteSystemWatcher(RemoteSystemWatcher&&) noexcept = default;
        RemoteSystemWatcher& operator=(RemoteSystemWatcher const&) & noexcept = default;
        RemoteSystemWatcher& operator=(RemoteSystemWatcher&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemWatcherErrorOccurredEventArgs : winrt::Windows::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs
    {
        RemoteSystemWatcherErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemWatcherErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
        RemoteSystemWatcherErrorOccurredEventArgs(RemoteSystemWatcherErrorOccurredEventArgs const&) noexcept = default;
        RemoteSystemWatcherErrorOccurredEventArgs(RemoteSystemWatcherErrorOccurredEventArgs&&) noexcept = default;
        RemoteSystemWatcherErrorOccurredEventArgs& operator=(RemoteSystemWatcherErrorOccurredEventArgs const&) & noexcept = default;
        RemoteSystemWatcherErrorOccurredEventArgs& operator=(RemoteSystemWatcherErrorOccurredEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteSystemWebAccountFilter : winrt::Windows::System::RemoteSystems::IRemoteSystemWebAccountFilter,
        impl::require<RemoteSystemWebAccountFilter, winrt::Windows::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemWebAccountFilter(std::nullptr_t) noexcept {}
        RemoteSystemWebAccountFilter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::RemoteSystems::IRemoteSystemWebAccountFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemWebAccountFilter(winrt::Windows::Security::Credentials::WebAccount const& account);
        RemoteSystemWebAccountFilter(RemoteSystemWebAccountFilter const&) noexcept = default;
        RemoteSystemWebAccountFilter(RemoteSystemWebAccountFilter&&) noexcept = default;
        RemoteSystemWebAccountFilter& operator=(RemoteSystemWebAccountFilter const&) & noexcept = default;
        RemoteSystemWebAccountFilter& operator=(RemoteSystemWebAccountFilter&&) & noexcept = default;
    };
}
#endif
