/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _WINC1500_CONFIG_H    /* Guard against multiple inclusion */
#define _WINC1500_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
/*** WiFi WINC Driver Configuration ***/
#define WDRV_WINC_GPIO_SOURCE               GPIO_PIN_RD1
#define WDRV_WINC_SPI_INDEX                 DRV_SPI_INDEX_0
#define WDRV_WINC_NETWORK_MODE_SOCKET
#define WDRV_WINC_DEVICE_WINC1500
#define WDRV_WINC_DEVICE_SPLIT_INIT
#define WDRV_WINC_DEVICE_ENTERPRISE_CONNECT
#define WDRV_WINC_DEVICE_EXT_CONNECT_PARAMS
#define WDRV_WINC_DEVICE_BSS_ROAMING
#define WDRV_WINC_DEVICE_FLEXIBLE_FLASH_MAP
#define WDRV_WINC_DEVICE_DYNAMIC_BYPASS_MODE
#define WDRV_WINC_DEVICE_WPA_SOFT_AP
#define WDRV_WINC_DEVICE_CONF_NTP_SERVER
#define WDRV_WINC_DEVICE_HOST_FILE_DOWNLOAD
#define WDRV_WINC_DEVICE_SOFT_AP_EXT
#define WDRV_WINC_DEVICE_MULTI_GAIN_TABLE
#define WDRV_WINC_DEVICE_URL_TYPE           unsigned char
#define WDRV_WINC_DEVICE_SCAN_STOP_ON_FIRST
#define WDRV_WINC_DEVICE_DEPRECATE_WEP
#define WDRV_WINC_DEVICE_OTA_STATUS_EXTENDED
#define WDRV_WINC_DEVICE_SCAN_SSID_LIST
#define WDRV_WINC_DEVICE_USE_SYS_DEBUG

#endif /* _WINC1500_CONFIG_H */

/* *****************************************************************************
 End of File
 */
