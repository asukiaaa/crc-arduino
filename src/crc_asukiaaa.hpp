#pragma once

#include <CRCx.h>

#define CRC_ASUKIAAA_VERSION_MAJOR 1
#define CRC_ASUKIAAA_VERSION_MINOR 0
#define CRC_ASUKIAAA_VERSION_PATCH 1

namespace crc_asukiaaa {

void setCrc16AtEnd(uint8_t* dataArr, uint8_t dataLenIncludesCrc) {
  uint16_t crc16 = crcx::crc16(dataArr, dataLenIncludesCrc - 2);
  dataArr[dataLenIncludesCrc - 2] = crc16 >> 8;
  dataArr[dataLenIncludesCrc - 1] = crc16 & 0xff;
}

bool checkCrc16AtEnd(const uint8_t* dataArr, size_t dataLenIncludesCrc) {
  uint16_t crc16Created = crcx::crc16(dataArr, dataLenIncludesCrc - 2);
  uint16_t crc16Received = ((uint16_t)dataArr[dataLenIncludesCrc - 2] << 8) +
                           dataArr[dataLenIncludesCrc - 1];
  return crc16Created == crc16Received;
}

}  // namespace crc_asukiaaa
