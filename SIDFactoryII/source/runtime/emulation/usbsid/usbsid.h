#pragma once

#include "runtime/editor/driver/driver_utils.h"
#include "runtime/emulation/usbsid/driver/USBSID.h"

namespace Emulation
{
	class USBSID
	{
	public:
    USBSID();
		// ASid(RtMidiOut* inRtMidiOut);

		bool isPortOpen(void);
		void SetMuted(bool inMuted);

		// void SendSIDRegisterWriteOrderAndCycleInfo(std::vector<Editor::SIDWriteInformation> inSIDWriteInfoList);
		// void SendSIDType(bool is6581);
		// void SendSIDEnvironment(bool isPAL);

		void WriteToSIDRegister(unsigned char inSidReg, unsigned char inData, int cycles);
		void FlushRemainingBuffer(void);

	private:
    USBSID_NS::USBSID_Class &m_sid;

		// void SendSetChannelsSilent();
		// unsigned char GetASIDPositionFromRegisterIndex(unsigned char inSidRegister);

		bool m_Muted = false;
		// RtMidiOut* m_RtMidiOut = nullptr;

		// Physical out buffer, including protocol overhead
		// unsigned char m_ASIDOutBuffer[ASID_NUM_REGS + 12];

		// Registers
		// unsigned char m_ASIDRegisterBuffer[ASID_NUM_REGS];
		// bool m_ASIDRegisterUpdated[ASID_NUM_REGS];
	};
}
