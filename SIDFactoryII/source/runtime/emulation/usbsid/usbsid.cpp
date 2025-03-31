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

    m_sid.USBSID_Init(false, false);
  }

  void USBSID::WriteToSIDRegister(unsigned char inSidReg, unsigned char inData, int cycles)
  {
    // m_sid.USBSID_Write(inSidReg, inData);
    m_sid.USBSID_WriteCycled(inSidReg, inData, cycles);
  }
}
