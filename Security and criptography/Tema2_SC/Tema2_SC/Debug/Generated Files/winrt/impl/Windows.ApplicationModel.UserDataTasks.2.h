// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_ApplicationModel_UserDataTasks_2_H
#define WINRT_Windows_ApplicationModel_UserDataTasks_2_H
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.ApplicationModel.UserDataTasks.1.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::UserDataTasks
{
    struct __declspec(empty_bases) UserDataTask : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTask
    {
        UserDataTask(std::nullptr_t) noexcept {}
        UserDataTask(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTask(ptr, take_ownership_from_abi) {}
        UserDataTask();
        UserDataTask(UserDataTask const&) noexcept = default;
        UserDataTask(UserDataTask&&) noexcept = default;
        UserDataTask& operator=(UserDataTask const&) & noexcept = default;
        UserDataTask& operator=(UserDataTask&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskBatch : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskBatch
    {
        UserDataTaskBatch(std::nullptr_t) noexcept {}
        UserDataTaskBatch(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskBatch(ptr, take_ownership_from_abi) {}
        UserDataTaskBatch(UserDataTaskBatch const&) noexcept = default;
        UserDataTaskBatch(UserDataTaskBatch&&) noexcept = default;
        UserDataTaskBatch& operator=(UserDataTaskBatch const&) & noexcept = default;
        UserDataTaskBatch& operator=(UserDataTaskBatch&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskList : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskList
    {
        UserDataTaskList(std::nullptr_t) noexcept {}
        UserDataTaskList(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskList(ptr, take_ownership_from_abi) {}
        UserDataTaskList(UserDataTaskList const&) noexcept = default;
        UserDataTaskList(UserDataTaskList&&) noexcept = default;
        UserDataTaskList& operator=(UserDataTaskList const&) & noexcept = default;
        UserDataTaskList& operator=(UserDataTaskList&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskListLimitedWriteOperations : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskListLimitedWriteOperations
    {
        UserDataTaskListLimitedWriteOperations(std::nullptr_t) noexcept {}
        UserDataTaskListLimitedWriteOperations(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskListLimitedWriteOperations(ptr, take_ownership_from_abi) {}
        UserDataTaskListLimitedWriteOperations(UserDataTaskListLimitedWriteOperations const&) noexcept = default;
        UserDataTaskListLimitedWriteOperations(UserDataTaskListLimitedWriteOperations&&) noexcept = default;
        UserDataTaskListLimitedWriteOperations& operator=(UserDataTaskListLimitedWriteOperations const&) & noexcept = default;
        UserDataTaskListLimitedWriteOperations& operator=(UserDataTaskListLimitedWriteOperations&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskListSyncManager : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskListSyncManager
    {
        UserDataTaskListSyncManager(std::nullptr_t) noexcept {}
        UserDataTaskListSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskListSyncManager(ptr, take_ownership_from_abi) {}
        UserDataTaskListSyncManager(UserDataTaskListSyncManager const&) noexcept = default;
        UserDataTaskListSyncManager(UserDataTaskListSyncManager&&) noexcept = default;
        UserDataTaskListSyncManager& operator=(UserDataTaskListSyncManager const&) & noexcept = default;
        UserDataTaskListSyncManager& operator=(UserDataTaskListSyncManager&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskManager : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskManager
    {
        UserDataTaskManager(std::nullptr_t) noexcept {}
        UserDataTaskManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskManager(ptr, take_ownership_from_abi) {}
        UserDataTaskManager(UserDataTaskManager const&) noexcept = default;
        UserDataTaskManager(UserDataTaskManager&&) noexcept = default;
        UserDataTaskManager& operator=(UserDataTaskManager const&) & noexcept = default;
        UserDataTaskManager& operator=(UserDataTaskManager&&) & noexcept = default;
        static auto GetDefault();
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct __declspec(empty_bases) UserDataTaskQueryOptions : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskQueryOptions
    {
        UserDataTaskQueryOptions(std::nullptr_t) noexcept {}
        UserDataTaskQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskQueryOptions(ptr, take_ownership_from_abi) {}
        UserDataTaskQueryOptions();
        UserDataTaskQueryOptions(UserDataTaskQueryOptions const&) noexcept = default;
        UserDataTaskQueryOptions(UserDataTaskQueryOptions&&) noexcept = default;
        UserDataTaskQueryOptions& operator=(UserDataTaskQueryOptions const&) & noexcept = default;
        UserDataTaskQueryOptions& operator=(UserDataTaskQueryOptions&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskReader : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskReader
    {
        UserDataTaskReader(std::nullptr_t) noexcept {}
        UserDataTaskReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskReader(ptr, take_ownership_from_abi) {}
        UserDataTaskReader(UserDataTaskReader const&) noexcept = default;
        UserDataTaskReader(UserDataTaskReader&&) noexcept = default;
        UserDataTaskReader& operator=(UserDataTaskReader const&) & noexcept = default;
        UserDataTaskReader& operator=(UserDataTaskReader&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskRecurrenceProperties : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskRecurrenceProperties
    {
        UserDataTaskRecurrenceProperties(std::nullptr_t) noexcept {}
        UserDataTaskRecurrenceProperties(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskRecurrenceProperties(ptr, take_ownership_from_abi) {}
        UserDataTaskRecurrenceProperties();
        UserDataTaskRecurrenceProperties(UserDataTaskRecurrenceProperties const&) noexcept = default;
        UserDataTaskRecurrenceProperties(UserDataTaskRecurrenceProperties&&) noexcept = default;
        UserDataTaskRecurrenceProperties& operator=(UserDataTaskRecurrenceProperties const&) & noexcept = default;
        UserDataTaskRecurrenceProperties& operator=(UserDataTaskRecurrenceProperties&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskRegenerationProperties : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskRegenerationProperties
    {
        UserDataTaskRegenerationProperties(std::nullptr_t) noexcept {}
        UserDataTaskRegenerationProperties(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskRegenerationProperties(ptr, take_ownership_from_abi) {}
        UserDataTaskRegenerationProperties();
        UserDataTaskRegenerationProperties(UserDataTaskRegenerationProperties const&) noexcept = default;
        UserDataTaskRegenerationProperties(UserDataTaskRegenerationProperties&&) noexcept = default;
        UserDataTaskRegenerationProperties& operator=(UserDataTaskRegenerationProperties const&) & noexcept = default;
        UserDataTaskRegenerationProperties& operator=(UserDataTaskRegenerationProperties&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UserDataTaskStore : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskStore
    {
        UserDataTaskStore(std::nullptr_t) noexcept {}
        UserDataTaskStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::UserDataTasks::IUserDataTaskStore(ptr, take_ownership_from_abi) {}
        UserDataTaskStore(UserDataTaskStore const&) noexcept = default;
        UserDataTaskStore(UserDataTaskStore&&) noexcept = default;
        UserDataTaskStore& operator=(UserDataTaskStore const&) & noexcept = default;
        UserDataTaskStore& operator=(UserDataTaskStore&&) & noexcept = default;
    };
}
#endif
