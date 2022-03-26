# General steps for porting the Wireless stack (H3) to an unsupported part

Currently, the Wireless stack in Harmony v3 supports only the SAM E54 and SAM D21 through example apps.  The MHC cannot generate code for any device that does not have an EIC.  This is due to the fact that the code was written to a specific peripheral instead of using System Services for generalized interrupts.

## Steps:

1. Create Harmony v3 project for target processor.
2. Open demo app for SAM E54 (Used wireless/apps/ap_scan/firmware/sam_e54_xpro_winc1500.X )
3. Copy all the files and subfolders from the wireless/apps/ap_scan/firmware/src/config/sam_e54_xpro_winc1500/driver/winc directory.  In other words, grab the winc directory and move into the target processor project as user code (don't try and insert it back into the driver tree.)
4. Inside the target processor Harmony v3 project, add the source and include files into your project.

### Source Files:

<img src="C:\Projects\Wireless-PortToUnsupportedPart\images\SourceFiles.png" alt="SourceFiles" style="zoom:67%;" />

### Include Files:

<img src="C:\Projects\Wireless-PortToUnsupportedPart\images\IncludeFiles.png" alt="IncludeFiles" style="zoom: 67%;" />

5.  Now interface the winc driver into the target processor Harmony v3 project.  Focus on the following files:
   - wdrv_winc_eint.c - Interrupt interface
   - wdrv_winc_gpio.c - Reset and Chip Enable interface
   - wdrv_winc_spi.c - SPI interface
6. Looking at wdrv_winc_eint.c, notice the WDRV_EIC_SOURCE define.  If it isn't present the generated code is correct for PIC32MZ (or other device without the EIC).  Make sure the defines are generated and make the pin selected for the interrupt.
7. Looking at wdrv_winc_gpio.c, name the reset pin WDRV_WINC_RESETN in the MHC pin configuration tool and this should line up and match.  Same for the chip select, name it WDRV_WINC_CHIP_EN
8. Looking at wdrv_winc_spi.c, notice there is code for handling the cache (important for the PIC32MZ and SAM V71).  No modification needed for the PIC32MZ as the compiler will make sure it is included through the \_\_PIC32MZ\_\_ define.  The trick here is to make sure that the target processor has an SPI port defined for Instance 0 (that is what the code expects - but this can be changed) and the pins are connected.
9. Test compile and download to the target board.  Testing involves making sure the Reset pin toggles then the SPI slave select.  After making sure those both are working, ensure that you have SPI toggling (the wireless init routine will start communication with the device).  The last bit is the interrupt which is needed on receive.