//
// Created by Henrik Enblom on 2023-02-12.
//

#ifndef USBKEYBOARDGAMEPAD_H
#define USBKEYBOARDGAMEPAD_H

#include "PluggableUSBHID.h"
#include "platform/Stream.h"
#include "PlatformMutex.h"

#define REPORT_ID_KEYBOARD 1
#define REPORT_ID_VOLUME 3
#define REPORT_ID_GAMEPAD 4

// values addresses
#define BTN0_7 0
#define BTN8_15 1
#define BTN16_23 2
#define BTN24_31 3
#define BTN32_39 4
#define BTN40_47 5
#define BTN48_55 6
#define BTN56_63 7
#define BTN64_71 8
#define BTN72_79 9
#define BTN80_87 10
#define BTN88_95 11
#define BTN96_103 12
#define BTN104_111 13
#define BTN112_119 14
#define BTN120_127 15

#define X_AXIS_LSB 16
#define X_AXIS_MSB 17
#define Y_AXIS_LSB 18
#define Y_AXIS_MSB 19

#define HAT0_1 20 // Hats are 4 bit direction (0-9), 2 hats per byte
#define HAT2_3 21

#define Z_AXIS_LSB 22
#define Z_AXIS_MSB 23
#define Rx_AXIS_LSB 24
#define Rx_AXIS_MSB 25
#define Ry_AXIS_LSB 26
#define Ry_AXIS_MSB 27
#define Rz_AXIS_LSB 28
#define Rz_AXIS_MSB 29

#define THROTTLE_AXIS_LSB 30
#define THROTTLE_AXIS_MSB 31
// #define S0_AXIS_LSB 30
// #define S0_AXIS_MSB 31
#define S0_AXIS_LSB 32
#define S0_AXIS_MSB 33

#define HAT_DIR_N 0
#define HAT_DIR_NE 1
#define HAT_DIR_E 2
#define HAT_DIR_SE 3
#define HAT_DIR_S 4
#define HAT_DIR_SW 5
#define HAT_DIR_W 6
#define HAT_DIR_NW 7
#define HAT_DIR_C 8

namespace arduino {
    /* Modifiers, left keys then right keys. */
    enum MODIFIER_KEY {
        KEY_CTRL = 0x01,
        KEY_SHIFT = 0x02,
        KEY_ALT = 0x04,
        KEY_LOGO = 0x08,
        KEY_RCTRL = 0x10,
        KEY_RSHIFT = 0x20,
        KEY_RALT = 0x40,
        KEY_RLOGO = 0x80,
    };


    enum MEDIA_KEY {
        KEY_NEXT_TRACK,     /*!< next Track Button */
        KEY_PREVIOUS_TRACK, /*!< Previous track Button */
        KEY_STOP,           /*!< Stop Button */
        KEY_PLAY_PAUSE,     /*!< Play/Pause Button */
        KEY_MUTE,           /*!< Mute Button */
        KEY_VOLUME_UP,      /*!< Volume Up Button */
        KEY_VOLUME_DOWN,    /*!< Volume Down Button */
    };

    enum FUNCTION_KEY {
        KEY_F1 = 128,   /* F1 key */
        KEY_F2,         /* F2 key */
        KEY_F3,         /* F3 key */
        KEY_F4,         /* F4 key */
        KEY_F5,         /* F5 key */
        KEY_F6,         /* F6 key */
        KEY_F7,         /* F7 key */
        KEY_F8,         /* F8 key */
        KEY_F9,         /* F9 key */
        KEY_F10,        /* F10 key */
        KEY_F11,        /* F11 key */
        KEY_F12,        /* F12 key */

        KEY_PRINT_SCREEN,   /* Print Screen key */
        KEY_SCROLL_LOCK,    /* Scroll lock */
        KEY_CAPS_LOCK,      /* caps lock */
        KEY_NUM_LOCK,       /* num lock */
        KEY_INSERT,         /* Insert key */
        KEY_HOME,           /* Home key */
        KEY_PAGE_UP,        /* Page Up key */
        KEY_PAGE_DOWN,      /* Page Down key */

        RIGHT_ARROW,        /* Right arrow */
        LEFT_ARROW,         /* Left arrow */
        DOWN_ARROW,         /* Down arrow */
        UP_ARROW,           /* Up arrow */
    };

// Xbox 360: STANDARD GAMEPAD Vendor: 045e Product: 028e)
    class USBKeyboardGamepad : public USBHID, public ::mbed::Stream {
    public:
        explicit USBKeyboardGamepad(bool connect_blocking = true, uint16_t vendor_id = 0x1235,
                                    uint16_t product_id = 0x0050,
                                    uint16_t product_release = 0x0001);

        explicit USBKeyboardGamepad(USBPhy *phy, uint16_t vendor_id = 0x1235, uint16_t product_id = 0x0050,
                                    uint16_t product_release = 0x0001);

        ~USBKeyboardGamepad() override;

        void SetButton(int idx, bool val);

        void SetX(uint16_t val);

        void SetY(uint16_t val);

        void SetZ(uint16_t val);

        void SetRx(uint16_t val);

        void SetRy(uint16_t val);

        void SetRz(uint16_t val);

        void SetS0(uint16_t val);

        void SetThrottle(uint16_t val);

        // 4 Hats available 0-3, direction is clockwise 0=N 1=NE 2=E 3=SE 4=S 5=SW 6=W 7=NW 8=CENTER
        void SetHat(uint8_t hatIdx, uint8_t dir);

        bool SendGamepadUpdates();

        /**
* To send a character defined by a modifier(CTRL, SHIFT, ALT) and the key
*
* @code
* //To send CTRL + s (save)
*  keyboard.SendKeyCode('s', KEY_CTRL);
* @endcode
*
* @param modifier bit 0: KEY_CTRL, bit 1: KEY_SHIFT, bit 2: KEY_ALT (default: 0)
* @param key character to send
* @returns true if there is no error, false otherwise
*/
        bool SendKeyCode(uint8_t key, uint8_t modifier = 0);

        /**
        * Send a character
        *
        * @param c character to be sent
        * @returns true if there is no error, false otherwise
        */
        int _putc(int c) override;

        /**
        * Control media keys
        *
        * @param key media key pressed (KEY_NEXT_TRACK, KEY_PREVIOUS_TRACK, KEY_STOP, KEY_PLAY_PAUSE, KEY_MUTE, KEY_VOLUME_UP, KEY_VOLUME_DOWN)
        * @returns true if there is no error, false otherwise
        */
        bool media_control(MEDIA_KEY key);

        /*
    * Called when a data is received on the OUT endpoint. Useful to switch on LED of LOCK keys
    */
        void report_rx() override;

        /**
        * Read status of lock keys. Useful to switch-on/off leds according to key pressed. Only the first three bits of the result is important:
        *   - First bit: NUM_LOCK
        *   - Second bit: CAPS_LOCK
        *   - Third bit: SCROLL_LOCK
        *
        * @returns status of lock keys
        */
        uint8_t lock_status();

        /*
    * To define the report descriptor. Warning: this method has to store the length of the report descriptor in reportLength.
    *
    * @returns pointer to the report descriptor
    */
        const uint8_t *report_desc() override;

    protected:
        /*
    * Get configuration descriptor
    *
    * @returns pointer to the configuration descriptor
    */
        const uint8_t *configuration_desc(uint8_t index) override;

    private:
        int _getc() override;

        uint8_t inputArray[35];
        uint8_t _lock_status;
        uint8_t _configuration_descriptor[41];
        PlatformMutex _mutex;
    };
}

#endif
