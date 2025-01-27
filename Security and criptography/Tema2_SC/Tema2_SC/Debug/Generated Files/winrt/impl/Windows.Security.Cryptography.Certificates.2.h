// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Security_Cryptography_Certificates_2_H
#define WINRT_Windows_Security_Cryptography_Certificates_2_H
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Security.Cryptography.Certificates.1.h"
WINRT_EXPORT namespace winrt::Windows::Security::Cryptography::Certificates
{
    struct __declspec(empty_bases) Certificate : winrt::Windows::Security::Cryptography::Certificates::ICertificate,
        impl::require<Certificate, winrt::Windows::Security::Cryptography::Certificates::ICertificate2, winrt::Windows::Security::Cryptography::Certificates::ICertificate3>
    {
        Certificate(std::nullptr_t) noexcept {}
        Certificate(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificate(ptr, take_ownership_from_abi) {}
        explicit Certificate(winrt::Windows::Storage::Streams::IBuffer const& certBlob);
        Certificate(Certificate const&) noexcept = default;
        Certificate(Certificate&&) noexcept = default;
        Certificate& operator=(Certificate const&) & noexcept = default;
        Certificate& operator=(Certificate&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CertificateChain : winrt::Windows::Security::Cryptography::Certificates::ICertificateChain
    {
        CertificateChain(std::nullptr_t) noexcept {}
        CertificateChain(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateChain(ptr, take_ownership_from_abi) {}
        CertificateChain(CertificateChain const&) noexcept = default;
        CertificateChain(CertificateChain&&) noexcept = default;
        CertificateChain& operator=(CertificateChain const&) & noexcept = default;
        CertificateChain& operator=(CertificateChain&&) & noexcept = default;
    };
    struct CertificateEnrollmentManager
    {
        CertificateEnrollmentManager() = delete;
        static auto CreateRequestAsync(winrt::Windows::Security::Cryptography::Certificates::CertificateRequestProperties const& request);
        static auto InstallCertificateAsync(param::hstring const& certificate, winrt::Windows::Security::Cryptography::Certificates::InstallOptions const& installOption);
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, winrt::Windows::Security::Cryptography::Certificates::ExportOption const& exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel const& keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions const& installOption, param::hstring const& friendlyName);
        [[nodiscard]] static auto UserCertificateEnrollmentManager();
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, winrt::Windows::Security::Cryptography::Certificates::ExportOption const& exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel const& keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions const& installOption, param::hstring const& friendlyName, param::hstring const& keyStorageProvider);
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, winrt::Windows::Security::Cryptography::Certificates::PfxImportParameters const& pfxImportParameters);
    };
    struct __declspec(empty_bases) CertificateExtension : winrt::Windows::Security::Cryptography::Certificates::ICertificateExtension
    {
        CertificateExtension(std::nullptr_t) noexcept {}
        CertificateExtension(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateExtension(ptr, take_ownership_from_abi) {}
        CertificateExtension();
        CertificateExtension(CertificateExtension const&) noexcept = default;
        CertificateExtension(CertificateExtension&&) noexcept = default;
        CertificateExtension& operator=(CertificateExtension const&) & noexcept = default;
        CertificateExtension& operator=(CertificateExtension&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CertificateKeyUsages : winrt::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages
    {
        CertificateKeyUsages(std::nullptr_t) noexcept {}
        CertificateKeyUsages(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages(ptr, take_ownership_from_abi) {}
        CertificateKeyUsages();
        CertificateKeyUsages(CertificateKeyUsages const&) noexcept = default;
        CertificateKeyUsages(CertificateKeyUsages&&) noexcept = default;
        CertificateKeyUsages& operator=(CertificateKeyUsages const&) & noexcept = default;
        CertificateKeyUsages& operator=(CertificateKeyUsages&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CertificateQuery : winrt::Windows::Security::Cryptography::Certificates::ICertificateQuery,
        impl::require<CertificateQuery, winrt::Windows::Security::Cryptography::Certificates::ICertificateQuery2>
    {
        CertificateQuery(std::nullptr_t) noexcept {}
        CertificateQuery(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateQuery(ptr, take_ownership_from_abi) {}
        CertificateQuery();
        CertificateQuery(CertificateQuery const&) noexcept = default;
        CertificateQuery(CertificateQuery&&) noexcept = default;
        CertificateQuery& operator=(CertificateQuery const&) & noexcept = default;
        CertificateQuery& operator=(CertificateQuery&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CertificateRequestProperties : winrt::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,
        impl::require<CertificateRequestProperties, winrt::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2, winrt::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3, winrt::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4>
    {
        CertificateRequestProperties(std::nullptr_t) noexcept {}
        CertificateRequestProperties(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties(ptr, take_ownership_from_abi) {}
        CertificateRequestProperties();
        CertificateRequestProperties(CertificateRequestProperties const&) noexcept = default;
        CertificateRequestProperties(CertificateRequestProperties&&) noexcept = default;
        CertificateRequestProperties& operator=(CertificateRequestProperties const&) & noexcept = default;
        CertificateRequestProperties& operator=(CertificateRequestProperties&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CertificateStore : winrt::Windows::Security::Cryptography::Certificates::ICertificateStore,
        impl::require<CertificateStore, winrt::Windows::Security::Cryptography::Certificates::ICertificateStore2>
    {
        CertificateStore(std::nullptr_t) noexcept {}
        CertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICertificateStore(ptr, take_ownership_from_abi) {}
        CertificateStore(CertificateStore const&) noexcept = default;
        CertificateStore(CertificateStore&&) noexcept = default;
        CertificateStore& operator=(CertificateStore const&) & noexcept = default;
        CertificateStore& operator=(CertificateStore&&) & noexcept = default;
    };
    struct CertificateStores
    {
        CertificateStores() = delete;
        static auto FindAllAsync();
        static auto FindAllAsync(winrt::Windows::Security::Cryptography::Certificates::CertificateQuery const& query);
        [[nodiscard]] static auto TrustedRootCertificationAuthorities();
        [[nodiscard]] static auto IntermediateCertificationAuthorities();
        static auto GetStoreByName(param::hstring const& storeName);
        static auto GetUserStoreByName(param::hstring const& storeName);
    };
    struct __declspec(empty_bases) ChainBuildingParameters : winrt::Windows::Security::Cryptography::Certificates::IChainBuildingParameters
    {
        ChainBuildingParameters(std::nullptr_t) noexcept {}
        ChainBuildingParameters(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::IChainBuildingParameters(ptr, take_ownership_from_abi) {}
        ChainBuildingParameters();
        ChainBuildingParameters(ChainBuildingParameters const&) noexcept = default;
        ChainBuildingParameters(ChainBuildingParameters&&) noexcept = default;
        ChainBuildingParameters& operator=(ChainBuildingParameters const&) & noexcept = default;
        ChainBuildingParameters& operator=(ChainBuildingParameters&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ChainValidationParameters : winrt::Windows::Security::Cryptography::Certificates::IChainValidationParameters
    {
        ChainValidationParameters(std::nullptr_t) noexcept {}
        ChainValidationParameters(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::IChainValidationParameters(ptr, take_ownership_from_abi) {}
        ChainValidationParameters();
        ChainValidationParameters(ChainValidationParameters const&) noexcept = default;
        ChainValidationParameters(ChainValidationParameters&&) noexcept = default;
        ChainValidationParameters& operator=(ChainValidationParameters const&) & noexcept = default;
        ChainValidationParameters& operator=(ChainValidationParameters&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CmsAttachedSignature : winrt::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature
    {
        CmsAttachedSignature(std::nullptr_t) noexcept {}
        CmsAttachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature(ptr, take_ownership_from_abi) {}
        explicit CmsAttachedSignature(winrt::Windows::Storage::Streams::IBuffer const& inputBlob);
        CmsAttachedSignature(CmsAttachedSignature const&) noexcept = default;
        CmsAttachedSignature(CmsAttachedSignature&&) noexcept = default;
        CmsAttachedSignature& operator=(CmsAttachedSignature const&) & noexcept = default;
        CmsAttachedSignature& operator=(CmsAttachedSignature&&) & noexcept = default;
        static auto GenerateSignatureAsync(winrt::Windows::Storage::Streams::IBuffer const& data, param::async_iterable<winrt::Windows::Security::Cryptography::Certificates::CmsSignerInfo> const& signers, param::async_iterable<winrt::Windows::Security::Cryptography::Certificates::Certificate> const& certificates);
    };
    struct __declspec(empty_bases) CmsDetachedSignature : winrt::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature
    {
        CmsDetachedSignature(std::nullptr_t) noexcept {}
        CmsDetachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature(ptr, take_ownership_from_abi) {}
        explicit CmsDetachedSignature(winrt::Windows::Storage::Streams::IBuffer const& inputBlob);
        CmsDetachedSignature(CmsDetachedSignature const&) noexcept = default;
        CmsDetachedSignature(CmsDetachedSignature&&) noexcept = default;
        CmsDetachedSignature& operator=(CmsDetachedSignature const&) & noexcept = default;
        CmsDetachedSignature& operator=(CmsDetachedSignature&&) & noexcept = default;
        static auto GenerateSignatureAsync(winrt::Windows::Storage::Streams::IInputStream const& data, param::async_iterable<winrt::Windows::Security::Cryptography::Certificates::CmsSignerInfo> const& signers, param::async_iterable<winrt::Windows::Security::Cryptography::Certificates::Certificate> const& certificates);
    };
    struct __declspec(empty_bases) CmsSignerInfo : winrt::Windows::Security::Cryptography::Certificates::ICmsSignerInfo
    {
        CmsSignerInfo(std::nullptr_t) noexcept {}
        CmsSignerInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICmsSignerInfo(ptr, take_ownership_from_abi) {}
        CmsSignerInfo();
        CmsSignerInfo(CmsSignerInfo const&) noexcept = default;
        CmsSignerInfo(CmsSignerInfo&&) noexcept = default;
        CmsSignerInfo& operator=(CmsSignerInfo const&) & noexcept = default;
        CmsSignerInfo& operator=(CmsSignerInfo&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CmsTimestampInfo : winrt::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo
    {
        CmsTimestampInfo(std::nullptr_t) noexcept {}
        CmsTimestampInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo(ptr, take_ownership_from_abi) {}
        CmsTimestampInfo(CmsTimestampInfo const&) noexcept = default;
        CmsTimestampInfo(CmsTimestampInfo&&) noexcept = default;
        CmsTimestampInfo& operator=(CmsTimestampInfo const&) & noexcept = default;
        CmsTimestampInfo& operator=(CmsTimestampInfo&&) & noexcept = default;
    };
    struct KeyAlgorithmNames
    {
        KeyAlgorithmNames() = delete;
        [[nodiscard]] static auto Rsa();
        [[nodiscard]] static auto Dsa();
        [[nodiscard]] static auto Ecdh256();
        [[nodiscard]] static auto Ecdh384();
        [[nodiscard]] static auto Ecdh521();
        [[nodiscard]] static auto Ecdsa256();
        [[nodiscard]] static auto Ecdsa384();
        [[nodiscard]] static auto Ecdsa521();
        [[nodiscard]] static auto Ecdsa();
        [[nodiscard]] static auto Ecdh();
    };
    struct KeyAttestationHelper
    {
        KeyAttestationHelper() = delete;
        static auto DecryptTpmAttestationCredentialAsync(param::hstring const& credential);
        static auto GetTpmAttestationCredentialId(param::hstring const& credential);
        static auto DecryptTpmAttestationCredentialAsync(param::hstring const& credential, param::hstring const& containerName);
    };
    struct KeyStorageProviderNames
    {
        KeyStorageProviderNames() = delete;
        [[nodiscard]] static auto SoftwareKeyStorageProvider();
        [[nodiscard]] static auto SmartcardKeyStorageProvider();
        [[nodiscard]] static auto PlatformKeyStorageProvider();
        [[nodiscard]] static auto PassportKeyStorageProvider();
    };
    struct __declspec(empty_bases) PfxImportParameters : winrt::Windows::Security::Cryptography::Certificates::IPfxImportParameters
    {
        PfxImportParameters(std::nullptr_t) noexcept {}
        PfxImportParameters(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::IPfxImportParameters(ptr, take_ownership_from_abi) {}
        PfxImportParameters();
        PfxImportParameters(PfxImportParameters const&) noexcept = default;
        PfxImportParameters(PfxImportParameters&&) noexcept = default;
        PfxImportParameters& operator=(PfxImportParameters const&) & noexcept = default;
        PfxImportParameters& operator=(PfxImportParameters&&) & noexcept = default;
    };
    struct StandardCertificateStoreNames
    {
        StandardCertificateStoreNames() = delete;
        [[nodiscard]] static auto Personal();
        [[nodiscard]] static auto TrustedRootCertificationAuthorities();
        [[nodiscard]] static auto IntermediateCertificationAuthorities();
    };
    struct __declspec(empty_bases) SubjectAlternativeNameInfo : winrt::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,
        impl::require<SubjectAlternativeNameInfo, winrt::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2>
    {
        SubjectAlternativeNameInfo(std::nullptr_t) noexcept {}
        SubjectAlternativeNameInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo(ptr, take_ownership_from_abi) {}
        SubjectAlternativeNameInfo();
        SubjectAlternativeNameInfo(SubjectAlternativeNameInfo const&) noexcept = default;
        SubjectAlternativeNameInfo(SubjectAlternativeNameInfo&&) noexcept = default;
        SubjectAlternativeNameInfo& operator=(SubjectAlternativeNameInfo const&) & noexcept = default;
        SubjectAlternativeNameInfo& operator=(SubjectAlternativeNameInfo&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserCertificateEnrollmentManager : winrt::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,
        impl::require<UserCertificateEnrollmentManager, winrt::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>
    {
        UserCertificateEnrollmentManager(std::nullptr_t) noexcept {}
        UserCertificateEnrollmentManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager(ptr, take_ownership_from_abi) {}
        UserCertificateEnrollmentManager(UserCertificateEnrollmentManager const&) noexcept = default;
        UserCertificateEnrollmentManager(UserCertificateEnrollmentManager&&) noexcept = default;
        UserCertificateEnrollmentManager& operator=(UserCertificateEnrollmentManager const&) & noexcept = default;
        UserCertificateEnrollmentManager& operator=(UserCertificateEnrollmentManager&&) & noexcept = default;
        using winrt::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager::ImportPfxDataAsync;
        using impl::consume_t<UserCertificateEnrollmentManager, winrt::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>::ImportPfxDataAsync;
    };
    struct __declspec(empty_bases) UserCertificateStore : winrt::Windows::Security::Cryptography::Certificates::IUserCertificateStore
    {
        UserCertificateStore(std::nullptr_t) noexcept {}
        UserCertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Security::Cryptography::Certificates::IUserCertificateStore(ptr, take_ownership_from_abi) {}
        UserCertificateStore(UserCertificateStore const&) noexcept = default;
        UserCertificateStore(UserCertificateStore&&) noexcept = default;
        UserCertificateStore& operator=(UserCertificateStore const&) & noexcept = default;
        UserCertificateStore& operator=(UserCertificateStore&&) & noexcept = default;
    };
}
#endif
