#include "usbsid.h"

#include "runtime/environmentdefines.h"

#include <array>
#include <vector>

namespace Emulation
{
  USBSID::USBSID()
  : m_sid(*(new USBSID_NS::USBSID_Class))
  {
    using namespace Utility;

    m_sid.USBSID_Init(true, true);  /* with cycles and buffer */
  }

  bool USBSID::isPortOpen(void)
  {
    return m_sid.USBSID_isOpen();
  }

  void USBSID::SetMuted(bool inMuted)
  {
    if (inMuted) {
      m_sid.USBSID_Mute();
    } else {
      m_sid.USBSID_UnMute();
    }
  }
  void USBSID::WriteToSIDRegister(unsigned char inSidReg, unsigned char inData, int cycles)
  {
    m_sid.USBSID_WriteRingCycled(inSidReg, inData, cycles);
  }

  void USBSID::FlushRemainingBuffer(void)
  {
    m_sid.USBSID_SetFlush();
  }
}
