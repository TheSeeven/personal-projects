// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210403.2

#ifndef WINRT_Windows_Devices_Midi_1_H
#define WINRT_Windows_Devices_Midi_1_H
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Windows.Devices.Midi.0.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Midi
{
    struct __declspec(empty_bases) IMidiChannelPressureMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiChannelPressureMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiChannelPressureMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiChannelPressureMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiChannelPressureMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiChannelPressureMessage(IMidiChannelPressureMessage const&) noexcept = default;
        IMidiChannelPressureMessage(IMidiChannelPressureMessage&&) noexcept = default;
        IMidiChannelPressureMessage& operator=(IMidiChannelPressureMessage const&) & noexcept = default;
        IMidiChannelPressureMessage& operator=(IMidiChannelPressureMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiChannelPressureMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiChannelPressureMessageFactory>
    {
        IMidiChannelPressureMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiChannelPressureMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiChannelPressureMessageFactory(IMidiChannelPressureMessageFactory const&) noexcept = default;
        IMidiChannelPressureMessageFactory(IMidiChannelPressureMessageFactory&&) noexcept = default;
        IMidiChannelPressureMessageFactory& operator=(IMidiChannelPressureMessageFactory const&) & noexcept = default;
        IMidiChannelPressureMessageFactory& operator=(IMidiChannelPressureMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiControlChangeMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiControlChangeMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiControlChangeMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiControlChangeMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiControlChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiControlChangeMessage(IMidiControlChangeMessage const&) noexcept = default;
        IMidiControlChangeMessage(IMidiControlChangeMessage&&) noexcept = default;
        IMidiControlChangeMessage& operator=(IMidiControlChangeMessage const&) & noexcept = default;
        IMidiControlChangeMessage& operator=(IMidiControlChangeMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiControlChangeMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiControlChangeMessageFactory>
    {
        IMidiControlChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiControlChangeMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiControlChangeMessageFactory(IMidiControlChangeMessageFactory const&) noexcept = default;
        IMidiControlChangeMessageFactory(IMidiControlChangeMessageFactory&&) noexcept = default;
        IMidiControlChangeMessageFactory& operator=(IMidiControlChangeMessageFactory const&) & noexcept = default;
        IMidiControlChangeMessageFactory& operator=(IMidiControlChangeMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiInPort :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiInPort>,
        impl::require<winrt::Windows::Devices::Midi::IMidiInPort, winrt::Windows::Foundation::IClosable>
    {
        IMidiInPort(std::nullptr_t = nullptr) noexcept {}
        IMidiInPort(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiInPort(IMidiInPort const&) noexcept = default;
        IMidiInPort(IMidiInPort&&) noexcept = default;
        IMidiInPort& operator=(IMidiInPort const&) & noexcept = default;
        IMidiInPort& operator=(IMidiInPort&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiInPortStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiInPortStatics>
    {
        IMidiInPortStatics(std::nullptr_t = nullptr) noexcept {}
        IMidiInPortStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiInPortStatics(IMidiInPortStatics const&) noexcept = default;
        IMidiInPortStatics(IMidiInPortStatics&&) noexcept = default;
        IMidiInPortStatics& operator=(IMidiInPortStatics const&) & noexcept = default;
        IMidiInPortStatics& operator=(IMidiInPortStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiMessage>
    {
        IMidiMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiMessage(IMidiMessage const&) noexcept = default;
        IMidiMessage(IMidiMessage&&) noexcept = default;
        IMidiMessage& operator=(IMidiMessage const&) & noexcept = default;
        IMidiMessage& operator=(IMidiMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiMessageReceivedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiMessageReceivedEventArgs>
    {
        IMidiMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMidiMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiMessageReceivedEventArgs(IMidiMessageReceivedEventArgs const&) noexcept = default;
        IMidiMessageReceivedEventArgs(IMidiMessageReceivedEventArgs&&) noexcept = default;
        IMidiMessageReceivedEventArgs& operator=(IMidiMessageReceivedEventArgs const&) & noexcept = default;
        IMidiMessageReceivedEventArgs& operator=(IMidiMessageReceivedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiNoteOffMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiNoteOffMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiNoteOffMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiNoteOffMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiNoteOffMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiNoteOffMessage(IMidiNoteOffMessage const&) noexcept = default;
        IMidiNoteOffMessage(IMidiNoteOffMessage&&) noexcept = default;
        IMidiNoteOffMessage& operator=(IMidiNoteOffMessage const&) & noexcept = default;
        IMidiNoteOffMessage& operator=(IMidiNoteOffMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiNoteOffMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiNoteOffMessageFactory>
    {
        IMidiNoteOffMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiNoteOffMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiNoteOffMessageFactory(IMidiNoteOffMessageFactory const&) noexcept = default;
        IMidiNoteOffMessageFactory(IMidiNoteOffMessageFactory&&) noexcept = default;
        IMidiNoteOffMessageFactory& operator=(IMidiNoteOffMessageFactory const&) & noexcept = default;
        IMidiNoteOffMessageFactory& operator=(IMidiNoteOffMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiNoteOnMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiNoteOnMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiNoteOnMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiNoteOnMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiNoteOnMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiNoteOnMessage(IMidiNoteOnMessage const&) noexcept = default;
        IMidiNoteOnMessage(IMidiNoteOnMessage&&) noexcept = default;
        IMidiNoteOnMessage& operator=(IMidiNoteOnMessage const&) & noexcept = default;
        IMidiNoteOnMessage& operator=(IMidiNoteOnMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiNoteOnMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiNoteOnMessageFactory>
    {
        IMidiNoteOnMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiNoteOnMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiNoteOnMessageFactory(IMidiNoteOnMessageFactory const&) noexcept = default;
        IMidiNoteOnMessageFactory(IMidiNoteOnMessageFactory&&) noexcept = default;
        IMidiNoteOnMessageFactory& operator=(IMidiNoteOnMessageFactory const&) & noexcept = default;
        IMidiNoteOnMessageFactory& operator=(IMidiNoteOnMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiOutPort :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiOutPort>,
        impl::require<winrt::Windows::Devices::Midi::IMidiOutPort, winrt::Windows::Foundation::IClosable>
    {
        IMidiOutPort(std::nullptr_t = nullptr) noexcept {}
        IMidiOutPort(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiOutPort(IMidiOutPort const&) noexcept = default;
        IMidiOutPort(IMidiOutPort&&) noexcept = default;
        IMidiOutPort& operator=(IMidiOutPort const&) & noexcept = default;
        IMidiOutPort& operator=(IMidiOutPort&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiOutPortStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiOutPortStatics>
    {
        IMidiOutPortStatics(std::nullptr_t = nullptr) noexcept {}
        IMidiOutPortStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiOutPortStatics(IMidiOutPortStatics const&) noexcept = default;
        IMidiOutPortStatics(IMidiOutPortStatics&&) noexcept = default;
        IMidiOutPortStatics& operator=(IMidiOutPortStatics const&) & noexcept = default;
        IMidiOutPortStatics& operator=(IMidiOutPortStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiPitchBendChangeMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiPitchBendChangeMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiPitchBendChangeMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiPitchBendChangeMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiPitchBendChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiPitchBendChangeMessage(IMidiPitchBendChangeMessage const&) noexcept = default;
        IMidiPitchBendChangeMessage(IMidiPitchBendChangeMessage&&) noexcept = default;
        IMidiPitchBendChangeMessage& operator=(IMidiPitchBendChangeMessage const&) & noexcept = default;
        IMidiPitchBendChangeMessage& operator=(IMidiPitchBendChangeMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiPitchBendChangeMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiPitchBendChangeMessageFactory>
    {
        IMidiPitchBendChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiPitchBendChangeMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiPitchBendChangeMessageFactory(IMidiPitchBendChangeMessageFactory const&) noexcept = default;
        IMidiPitchBendChangeMessageFactory(IMidiPitchBendChangeMessageFactory&&) noexcept = default;
        IMidiPitchBendChangeMessageFactory& operator=(IMidiPitchBendChangeMessageFactory const&) & noexcept = default;
        IMidiPitchBendChangeMessageFactory& operator=(IMidiPitchBendChangeMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiPolyphonicKeyPressureMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiPolyphonicKeyPressureMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiPolyphonicKeyPressureMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiPolyphonicKeyPressureMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiPolyphonicKeyPressureMessage(IMidiPolyphonicKeyPressureMessage const&) noexcept = default;
        IMidiPolyphonicKeyPressureMessage(IMidiPolyphonicKeyPressureMessage&&) noexcept = default;
        IMidiPolyphonicKeyPressureMessage& operator=(IMidiPolyphonicKeyPressureMessage const&) & noexcept = default;
        IMidiPolyphonicKeyPressureMessage& operator=(IMidiPolyphonicKeyPressureMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiPolyphonicKeyPressureMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiPolyphonicKeyPressureMessageFactory>
    {
        IMidiPolyphonicKeyPressureMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiPolyphonicKeyPressureMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiPolyphonicKeyPressureMessageFactory(IMidiPolyphonicKeyPressureMessageFactory const&) noexcept = default;
        IMidiPolyphonicKeyPressureMessageFactory(IMidiPolyphonicKeyPressureMessageFactory&&) noexcept = default;
        IMidiPolyphonicKeyPressureMessageFactory& operator=(IMidiPolyphonicKeyPressureMessageFactory const&) & noexcept = default;
        IMidiPolyphonicKeyPressureMessageFactory& operator=(IMidiPolyphonicKeyPressureMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiProgramChangeMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiProgramChangeMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiProgramChangeMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiProgramChangeMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiProgramChangeMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiProgramChangeMessage(IMidiProgramChangeMessage const&) noexcept = default;
        IMidiProgramChangeMessage(IMidiProgramChangeMessage&&) noexcept = default;
        IMidiProgramChangeMessage& operator=(IMidiProgramChangeMessage const&) & noexcept = default;
        IMidiProgramChangeMessage& operator=(IMidiProgramChangeMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiProgramChangeMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiProgramChangeMessageFactory>
    {
        IMidiProgramChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiProgramChangeMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiProgramChangeMessageFactory(IMidiProgramChangeMessageFactory const&) noexcept = default;
        IMidiProgramChangeMessageFactory(IMidiProgramChangeMessageFactory&&) noexcept = default;
        IMidiProgramChangeMessageFactory& operator=(IMidiProgramChangeMessageFactory const&) & noexcept = default;
        IMidiProgramChangeMessageFactory& operator=(IMidiProgramChangeMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSongPositionPointerMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSongPositionPointerMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiSongPositionPointerMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiSongPositionPointerMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiSongPositionPointerMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSongPositionPointerMessage(IMidiSongPositionPointerMessage const&) noexcept = default;
        IMidiSongPositionPointerMessage(IMidiSongPositionPointerMessage&&) noexcept = default;
        IMidiSongPositionPointerMessage& operator=(IMidiSongPositionPointerMessage const&) & noexcept = default;
        IMidiSongPositionPointerMessage& operator=(IMidiSongPositionPointerMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSongPositionPointerMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSongPositionPointerMessageFactory>
    {
        IMidiSongPositionPointerMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiSongPositionPointerMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSongPositionPointerMessageFactory(IMidiSongPositionPointerMessageFactory const&) noexcept = default;
        IMidiSongPositionPointerMessageFactory(IMidiSongPositionPointerMessageFactory&&) noexcept = default;
        IMidiSongPositionPointerMessageFactory& operator=(IMidiSongPositionPointerMessageFactory const&) & noexcept = default;
        IMidiSongPositionPointerMessageFactory& operator=(IMidiSongPositionPointerMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSongSelectMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSongSelectMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiSongSelectMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiSongSelectMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiSongSelectMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSongSelectMessage(IMidiSongSelectMessage const&) noexcept = default;
        IMidiSongSelectMessage(IMidiSongSelectMessage&&) noexcept = default;
        IMidiSongSelectMessage& operator=(IMidiSongSelectMessage const&) & noexcept = default;
        IMidiSongSelectMessage& operator=(IMidiSongSelectMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSongSelectMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSongSelectMessageFactory>
    {
        IMidiSongSelectMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiSongSelectMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSongSelectMessageFactory(IMidiSongSelectMessageFactory const&) noexcept = default;
        IMidiSongSelectMessageFactory(IMidiSongSelectMessageFactory&&) noexcept = default;
        IMidiSongSelectMessageFactory& operator=(IMidiSongSelectMessageFactory const&) & noexcept = default;
        IMidiSongSelectMessageFactory& operator=(IMidiSongSelectMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSynthesizer :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSynthesizer>,
        impl::require<winrt::Windows::Devices::Midi::IMidiSynthesizer, winrt::Windows::Foundation::IClosable, winrt::Windows::Devices::Midi::IMidiOutPort>
    {
        IMidiSynthesizer(std::nullptr_t = nullptr) noexcept {}
        IMidiSynthesizer(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSynthesizer(IMidiSynthesizer const&) noexcept = default;
        IMidiSynthesizer(IMidiSynthesizer&&) noexcept = default;
        IMidiSynthesizer& operator=(IMidiSynthesizer const&) & noexcept = default;
        IMidiSynthesizer& operator=(IMidiSynthesizer&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSynthesizerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSynthesizerStatics>
    {
        IMidiSynthesizerStatics(std::nullptr_t = nullptr) noexcept {}
        IMidiSynthesizerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSynthesizerStatics(IMidiSynthesizerStatics const&) noexcept = default;
        IMidiSynthesizerStatics(IMidiSynthesizerStatics&&) noexcept = default;
        IMidiSynthesizerStatics& operator=(IMidiSynthesizerStatics const&) & noexcept = default;
        IMidiSynthesizerStatics& operator=(IMidiSynthesizerStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiSystemExclusiveMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiSystemExclusiveMessageFactory>
    {
        IMidiSystemExclusiveMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiSystemExclusiveMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiSystemExclusiveMessageFactory(IMidiSystemExclusiveMessageFactory const&) noexcept = default;
        IMidiSystemExclusiveMessageFactory(IMidiSystemExclusiveMessageFactory&&) noexcept = default;
        IMidiSystemExclusiveMessageFactory& operator=(IMidiSystemExclusiveMessageFactory const&) & noexcept = default;
        IMidiSystemExclusiveMessageFactory& operator=(IMidiSystemExclusiveMessageFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiTimeCodeMessage :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiTimeCodeMessage>,
        impl::require<winrt::Windows::Devices::Midi::IMidiTimeCodeMessage, winrt::Windows::Devices::Midi::IMidiMessage>
    {
        IMidiTimeCodeMessage(std::nullptr_t = nullptr) noexcept {}
        IMidiTimeCodeMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiTimeCodeMessage(IMidiTimeCodeMessage const&) noexcept = default;
        IMidiTimeCodeMessage(IMidiTimeCodeMessage&&) noexcept = default;
        IMidiTimeCodeMessage& operator=(IMidiTimeCodeMessage const&) & noexcept = default;
        IMidiTimeCodeMessage& operator=(IMidiTimeCodeMessage&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IMidiTimeCodeMessageFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMidiTimeCodeMessageFactory>
    {
        IMidiTimeCodeMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IMidiTimeCodeMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IMidiTimeCodeMessageFactory(IMidiTimeCodeMessageFactory const&) noexcept = default;
        IMidiTimeCodeMessageFactory(IMidiTimeCodeMessageFactory&&) noexcept = default;
        IMidiTimeCodeMessageFactory& operator=(IMidiTimeCodeMessageFactory const&) & noexcept = default;
        IMidiTimeCodeMessageFactory& operator=(IMidiTimeCodeMessageFactory&&) & noexcept = default;
    };
}
#endif
