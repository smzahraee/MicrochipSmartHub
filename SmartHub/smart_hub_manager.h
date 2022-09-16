#ifndef SMART_HUB_MANAGER_H
#define SMART_HUB_MANAGER_H

#include <stdint.h>
#include <vector>
#include <array>
#include <string>


enum SmartHubStatus{
    SPI_INIT,
    CFG_ROM,
    CFG_STRAP,
    SMBUS_CHECK,
    CFG_OTP,
    CFG_SOC,
    NORMAL_MODE,
    UNKNOWN_MODE,
};
enum SmartHubCommands
{

};

class SmartHubManager {
    public:

    virtual bool Initialize()=0;

    virtual bool RegisterRead(uint32_t address,uint16_t length,std::vector<uint8_t> &buffer)=0;
    virtual bool RegisterWrite(uint32_t address,uint16_t length,const std::vector<uint8_t> &buffer)=0;

    virtual bool PortMappingUsb2(std::array<uint8_t,7> port_map)=0;
    virtual bool PortMappingUsb3(std::array<uint8_t,7> port_map)=0;

    virtual bool Reset()=0;

    virtual bool CloseEverything()=0;

    //virtual SmartHubStatus CurrentStatus()=0;

 
};

#endif // end of SMART_HUB_MANAGER_H
