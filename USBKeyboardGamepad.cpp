//
// Created by Henrik Enblom on 2023-02-12.
//

#include "USBKeyboardGamepad.h"
#include "usb_phy_api.h"

using namespace arduino;

typedef struct {
    unsigned char usage;
    unsigned char modifier;
} KEYMAP;

#ifdef US_KEYBOARD
/* US keyboard (as HID standard) */
#define KEYMAP_SIZE (152)
const KEYMAP keymap[KEYMAP_SIZE] = {
    {0, 0},             /* NUL */
    {0, 0},             /* SOH */
    {0, 0},             /* STX */
    {0, 0},             /* ETX */
    {0, 0},             /* EOT */
    {0, 0},             /* ENQ */
    {0, 0},             /* ACK */
    {0, 0},             /* BEL */
    {0x2a, 0},          /* BS  */  /* Keyboard Delete (Backspace) */
    {0x2b, 0},          /* TAB */  /* Keyboard Tab */
    {0x28, 0},          /* LF  */  /* Keyboard Return (Enter) */
    {0, 0},             /* VT  */
    {0, 0},             /* FF  */
    {0, 0},             /* CR  */
    {0, 0},             /* SO  */
    {0, 0},             /* SI  */
    {0, 0},             /* DEL */
    {0, 0},             /* DC1 */
    {0, 0},             /* DC2 */
    {0, 0},             /* DC3 */
    {0, 0},             /* DC4 */
    {0, 0},             /* NAK */
    {0, 0},             /* SYN */
    {0, 0},             /* ETB */
    {0, 0},             /* CAN */
    {0, 0},             /* EM  */
    {0, 0},             /* SUB */
    {0, 0},             /* ESC */
    {0, 0},             /* FS  */
    {0, 0},             /* GS  */
    {0, 0},             /* RS  */
    {0, 0},             /* US  */
    {0x2c, 0},          /*   */
    {0x1e, KEY_SHIFT},      /* ! */
    {0x34, KEY_SHIFT},      /* " */
    {0x20, KEY_SHIFT},      /* # */
    {0x21, KEY_SHIFT},      /* $ */
    {0x22, KEY_SHIFT},      /* % */
    {0x24, KEY_SHIFT},      /* & */
    {0x34, 0},          /* ' */
    {0x26, KEY_SHIFT},      /* ( */
    {0x27, KEY_SHIFT},      /* ) */
    {0x25, KEY_SHIFT},      /* * */
    {0x2e, KEY_SHIFT},      /* + */
    {0x36, 0},          /* , */
    {0x2d, 0},          /* - */
    {0x37, 0},          /* . */
    {0x38, 0},          /* / */
    {0x27, 0},          /* 0 */
    {0x1e, 0},          /* 1 */
    {0x1f, 0},          /* 2 */
    {0x20, 0},          /* 3 */
    {0x21, 0},          /* 4 */
    {0x22, 0},          /* 5 */
    {0x23, 0},          /* 6 */
    {0x24, 0},          /* 7 */
    {0x25, 0},          /* 8 */
    {0x26, 0},          /* 9 */
    {0x33, KEY_SHIFT},      /* : */
    {0x33, 0},          /* ; */
    {0x36, KEY_SHIFT},      /* < */
    {0x2e, 0},          /* = */
    {0x37, KEY_SHIFT},      /* > */
    {0x38, KEY_SHIFT},      /* ? */
    {0x1f, KEY_SHIFT},      /* @ */
    {0x04, KEY_SHIFT},      /* A */
    {0x05, KEY_SHIFT},      /* B */
    {0x06, KEY_SHIFT},      /* C */
    {0x07, KEY_SHIFT},      /* D */
    {0x08, KEY_SHIFT},      /* E */
    {0x09, KEY_SHIFT},      /* F */
    {0x0a, KEY_SHIFT},      /* G */
    {0x0b, KEY_SHIFT},      /* H */
    {0x0c, KEY_SHIFT},      /* I */
    {0x0d, KEY_SHIFT},      /* J */
    {0x0e, KEY_SHIFT},      /* K */
    {0x0f, KEY_SHIFT},      /* L */
    {0x10, KEY_SHIFT},      /* M */
    {0x11, KEY_SHIFT},      /* N */
    {0x12, KEY_SHIFT},      /* O */
    {0x13, KEY_SHIFT},      /* P */
    {0x14, KEY_SHIFT},      /* Q */
    {0x15, KEY_SHIFT},      /* R */
    {0x16, KEY_SHIFT},      /* S */
    {0x17, KEY_SHIFT},      /* T */
    {0x18, KEY_SHIFT},      /* U */
    {0x19, KEY_SHIFT},      /* V */
    {0x1a, KEY_SHIFT},      /* W */
    {0x1b, KEY_SHIFT},      /* X */
    {0x1c, KEY_SHIFT},      /* Y */
    {0x1d, KEY_SHIFT},      /* Z */
    {0x2f, 0},          /* [ */
    {0x31, 0},          /* \ */
    {0x30, 0},          /* ] */
    {0x23, KEY_SHIFT},      /* ^ */
    {0x2d, KEY_SHIFT},      /* _ */
    {0x35, 0},          /* ` */
    {0x04, 0},          /* a */
    {0x05, 0},          /* b */
    {0x06, 0},          /* c */
    {0x07, 0},          /* d */
    {0x08, 0},          /* e */
    {0x09, 0},          /* f */
    {0x0a, 0},          /* g */
    {0x0b, 0},          /* h */
    {0x0c, 0},          /* i */
    {0x0d, 0},          /* j */
    {0x0e, 0},          /* k */
    {0x0f, 0},          /* l */
    {0x10, 0},          /* m */
    {0x11, 0},          /* n */
    {0x12, 0},          /* o */
    {0x13, 0},          /* p */
    {0x14, 0},          /* q */
    {0x15, 0},          /* r */
    {0x16, 0},          /* s */
    {0x17, 0},          /* t */
    {0x18, 0},          /* u */
    {0x19, 0},          /* v */
    {0x1a, 0},          /* w */
    {0x1b, 0},          /* x */
    {0x1c, 0},          /* y */
    {0x1d, 0},          /* z */
    {0x2f, KEY_SHIFT},      /* { */
    {0x31, KEY_SHIFT},      /* | */
    {0x30, KEY_SHIFT},      /* } */
    {0x35, KEY_SHIFT},      /* ~ */
    {0, 0},             /* DEL */

    {0x3a, 0},          /* F1 */
    {0x3b, 0},          /* F2 */
    {0x3c, 0},          /* F3 */
    {0x3d, 0},          /* F4 */
    {0x3e, 0},          /* F5 */
    {0x3f, 0},          /* F6 */
    {0x40, 0},          /* F7 */
    {0x41, 0},          /* F8 */
    {0x42, 0},          /* F9 */
    {0x43, 0},          /* F10 */
    {0x44, 0},          /* F11 */
    {0x45, 0},          /* F12 */

    {0x46, 0},          /* PRINT_SCREEN */
    {0x47, 0},          /* SCROLL_LOCK */
    {0x39, 0},          /* CAPS_LOCK */
    {0x53, 0},          /* NUM_LOCK */
    {0x49, 0},          /* INSERT */
    {0x4a, 0},          /* HOME */
    {0x4b, 0},          /* PAGE_UP */
    {0x4e, 0},          /* PAGE_DOWN */

    {0x4f, 0},          /* RIGHT_ARROW */
    {0x50, 0},          /* LEFT_ARROW */
    {0x51, 0},          /* DOWN_ARROW */
    {0x52, 0},          /* UP_ARROW */
};

#else
/* UK keyboard */
#define KEYMAP_SIZE (152)
const KEYMAP keymap[KEYMAP_SIZE] = {
        {0,    0},             /* NUL */
        {0,    0},             /* SOH */
        {0,    0},             /* STX */
        {0,    0},             /* ETX */
        {0,    0},             /* EOT */
        {0,    0},             /* ENQ */
        {0,    0},             /* ACK */
        {0,    0},             /* BEL */
        {0x2a, 0},          /* BS  */  /* Keyboard Delete (Backspace) */
        {0x2b, 0},          /* TAB */  /* Keyboard Tab */
        {0x28, 0},          /* LF  */  /* Keyboard Return (Enter) */
        {0,    0},             /* VT  */
        {0,    0},             /* FF  */
        {0,    0},             /* CR  */
        {0,    0},             /* SO  */
        {0,    0},             /* SI  */
        {0,    0},             /* DEL */
        {0,    0},             /* DC1 */
        {0,    0},             /* DC2 */
        {0,    0},             /* DC3 */
        {0,    0},             /* DC4 */
        {0,    0},             /* NAK */
        {0,    0},             /* SYN */
        {0,    0},             /* ETB */
        {0,    0},             /* CAN */
        {0,    0},             /* EM  */
        {0,    0},             /* SUB */
        {0,    0},             /* ESC */
        {0,    0},             /* FS  */
        {0,    0},             /* GS  */
        {0,    0},             /* RS  */
        {0,    0},             /* US  */
        {0x2c, 0},          /*   */
        {0x1e, KEY_SHIFT},      /* ! */
        {0x1f, KEY_SHIFT},      /* " */
        {0x32, 0},          /* # */
        {0x21, KEY_SHIFT},      /* $ */
        {0x22, KEY_SHIFT},      /* % */
        {0x24, KEY_SHIFT},      /* & */
        {0x34, 0},          /* ' */
        {0x26, KEY_SHIFT},      /* ( */
        {0x27, KEY_SHIFT},      /* ) */
        {0x25, KEY_SHIFT},      /* * */
        {0x2e, KEY_SHIFT},      /* + */
        {0x36, 0},          /* , */
        {0x2d, 0},          /* - */
        {0x37, 0},          /* . */
        {0x38, 0},          /* / */
        {0x27, 0},          /* 0 */
        {0x1e, 0},          /* 1 */
        {0x1f, 0},          /* 2 */
        {0x20, 0},          /* 3 */
        {0x21, 0},          /* 4 */
        {0x22, 0},          /* 5 */
        {0x23, 0},          /* 6 */
        {0x24, 0},          /* 7 */
        {0x25, 0},          /* 8 */
        {0x26, 0},          /* 9 */
        {0x33, KEY_SHIFT},      /* : */
        {0x33, 0},          /* ; */
        {0x36, KEY_SHIFT},      /* < */
        {0x2e, 0},          /* = */
        {0x37, KEY_SHIFT},      /* > */
        {0x38, KEY_SHIFT},      /* ? */
        {0x34, KEY_SHIFT},      /* @ */
        {0x04, KEY_SHIFT},      /* A */
        {0x05, KEY_SHIFT},      /* B */
        {0x06, KEY_SHIFT},      /* C */
        {0x07, KEY_SHIFT},      /* D */
        {0x08, KEY_SHIFT},      /* E */
        {0x09, KEY_SHIFT},      /* F */
        {0x0a, KEY_SHIFT},      /* G */
        {0x0b, KEY_SHIFT},      /* H */
        {0x0c, KEY_SHIFT},      /* I */
        {0x0d, KEY_SHIFT},      /* J */
        {0x0e, KEY_SHIFT},      /* K */
        {0x0f, KEY_SHIFT},      /* L */
        {0x10, KEY_SHIFT},      /* M */
        {0x11, KEY_SHIFT},      /* N */
        {0x12, KEY_SHIFT},      /* O */
        {0x13, KEY_SHIFT},      /* P */
        {0x14, KEY_SHIFT},      /* Q */
        {0x15, KEY_SHIFT},      /* R */
        {0x16, KEY_SHIFT},      /* S */
        {0x17, KEY_SHIFT},      /* T */
        {0x18, KEY_SHIFT},      /* U */
        {0x19, KEY_SHIFT},      /* V */
        {0x1a, KEY_SHIFT},      /* W */
        {0x1b, KEY_SHIFT},      /* X */
        {0x1c, KEY_SHIFT},      /* Y */
        {0x1d, KEY_SHIFT},      /* Z */
        {0x2f, 0},          /* [ */
        {0x64, 0},          /* \ */
        {0x30, 0},          /* ] */
        {0x23, KEY_SHIFT},      /* ^ */
        {0x2d, KEY_SHIFT},      /* _ */
        {0x35, 0},          /* ` */
        {0x04, 0},          /* a */
        {0x05, 0},          /* b */
        {0x06, 0},          /* c */
        {0x07, 0},          /* d */
        {0x08, 0},          /* e */
        {0x09, 0},          /* f */
        {0x0a, 0},          /* g */
        {0x0b, 0},          /* h */
        {0x0c, 0},          /* i */
        {0x0d, 0},          /* j */
        {0x0e, 0},          /* k */
        {0x0f, 0},          /* l */
        {0x10, 0},          /* m */
        {0x11, 0},          /* n */
        {0x12, 0},          /* o */
        {0x13, 0},          /* p */
        {0x14, 0},          /* q */
        {0x15, 0},          /* r */
        {0x16, 0},          /* s */
        {0x17, 0},          /* t */
        {0x18, 0},          /* u */
        {0x19, 0},          /* v */
        {0x1a, 0},          /* w */
        {0x1b, 0},          /* x */
        {0x1c, 0},          /* y */
        {0x1d, 0},          /* z */
        {0x2f, KEY_SHIFT},      /* { */
        {0x64, KEY_SHIFT},      /* | */
        {0x30, KEY_SHIFT},      /* } */
        {0x32, KEY_SHIFT},      /* ~ */
        {0,    0},            /* DEL */

        {0x3a, 0},          /* F1 */
        {0x3b, 0},          /* F2 */
        {0x3c, 0},          /* F3 */
        {0x3d, 0},          /* F4 */
        {0x3e, 0},          /* F5 */
        {0x3f, 0},          /* F6 */
        {0x40, 0},          /* F7 */
        {0x41, 0},          /* F8 */
        {0x42, 0},          /* F9 */
        {0x43, 0},          /* F10 */
        {0x44, 0},          /* F11 */
        {0x45, 0},          /* F12 */

        {0x46, 0},          /* PRINT_SCREEN */
        {0x47, 0},          /* SCROLL_LOCK */
        {0x39, 0},          /* CAPS_LOCK */
        {0x53, 0},          /* NUM_LOCK */
        {0x49, 0},          /* INSERT */
        {0x4a, 0},          /* HOME */
        {0x4b, 0},          /* PAGE_UP */
        {0x4e, 0},          /* PAGE_DOWN */

        {0x4f, 0},          /* RIGHT_ARROW */
        {0x50, 0},          /* LEFT_ARROW */
        {0x51, 0},          /* DOWN_ARROW */
        {0x52, 0},          /* UP_ARROW */
};
#endif

USBKeyboardGamepad::USBKeyboardGamepad(bool connect_blocking,
                                       uint16_t vendor_id,
                                       uint16_t product_id,
                                       uint16_t product_release) :
        USBHID(get_usb_phy(), 0, 0, vendor_id, product_id, product_release) {
    _lock_status = 0;
    for (int i = 0; i < 4; i++) {
        SetHat(i, HAT_DIR_C);
    }
}

USBKeyboardGamepad::USBKeyboardGamepad(USBPhy *phy, uint16_t vendor_id, uint16_t product_id, uint16_t product_release)
        : USBHID(phy, 0, 0, vendor_id, product_id, product_release) {
    _lock_status = 0;
    for (int i = 0; i < 4; i++) {
        SetHat(i, HAT_DIR_C);
    }
}

USBKeyboardGamepad::~USBKeyboardGamepad() {
    for (int i = 0; i < 4; i++) {
        SetHat(i, HAT_DIR_C);
    }
}

const uint8_t *USBKeyboardGamepad::report_desc() {
    static const uint8_t reportDescriptor[] = {
            // Keyboard
            USAGE_PAGE(1), 0x01,                    // Generic Desktop
            USAGE(1), 0x06,                         // Keyboard
            COLLECTION(1), 0x01,                    // Application
            REPORT_ID(1), REPORT_ID_KEYBOARD,

            USAGE_PAGE(1), 0x07,                    // Key Codes
            USAGE_MINIMUM(1), 0xE0,
            USAGE_MAXIMUM(1), 0xE7,
            LOGICAL_MINIMUM(1), 0x00,
            LOGICAL_MAXIMUM(1), 0x01,
            REPORT_SIZE(1), 0x01,
            REPORT_COUNT(1), 0x08,
            INPUT(1), 0x02,                         // Data, Variable, Absolute
            REPORT_COUNT(1), 0x01,
            REPORT_SIZE(1), 0x08,
            INPUT(1), 0x01,                         // Constant


            REPORT_COUNT(1), 0x05,
            REPORT_SIZE(1), 0x01,
            USAGE_PAGE(1), 0x08,                    // LEDs
            USAGE_MINIMUM(1), 0x01,
            USAGE_MAXIMUM(1), 0x05,
            OUTPUT(1), 0x02,                        // Data, Variable, Absolute
            REPORT_COUNT(1), 0x01,
            REPORT_SIZE(1), 0x03,
            OUTPUT(1), 0x01,                        // Constant


            REPORT_COUNT(1), 0x06,
            REPORT_SIZE(1), 0x08,
            LOGICAL_MINIMUM(1), 0x00,
            LOGICAL_MAXIMUM(1), 0x65,
            USAGE_PAGE(1), 0x07,                    // Key Codes
            USAGE_MINIMUM(1), 0x00,
            USAGE_MAXIMUM(1), 0x65,
            INPUT(1), 0x00,                         // Data, Array
            END_COLLECTION(0),

            // Media Control
            USAGE_PAGE(1), 0x0C,
            USAGE(1), 0x01,
            COLLECTION(1), 0x01,
            REPORT_ID(1), REPORT_ID_VOLUME,
            USAGE_PAGE(1), 0x0C,
            LOGICAL_MINIMUM(1), 0x00,
            LOGICAL_MAXIMUM(1), 0x01,
            REPORT_SIZE(1), 0x01,
            REPORT_COUNT(1), 0x07,
            USAGE(1), 0xB5,             // Next Track
            USAGE(1), 0xB6,             // Previous Track
            USAGE(1), 0xB7,             // Stop
            USAGE(1), 0xCD,             // Play / Pause
            USAGE(1), 0xE2,             // Mute
            USAGE(1), 0xE9,             // Volume Up
            USAGE(1), 0xEA,             // Volume Down
            INPUT(1), 0x02,             // Input (Data, Variable, Absolute)
            REPORT_COUNT(1), 0x01,
            INPUT(1), 0x01,
            END_COLLECTION(0),

            // Gamepad
            0x05, 0x01, // USAGE_PAGE (Generic Desktop)
            0x09, 0x04, // USAGE (Gamepad)
            0xa1, 0x01, // COLLECTION (Application)
            0x85, REPORT_ID_GAMEPAD, //   REPORT_ID

            0x05, 0x09, // USAGE_PAGE (Button)
            0x19, 0x01, // USAGE_MINIMUM (Button 1)
            0x29, 0x80, // USAGE_MAXIMUM (Button 128)
            0x15, 0x00, // LOGICAL_MINIMUM (0)
            0x25, 0x01, // LOGICAL_MAXIMUM (1)
            0x95, 0x80, // REPORT_COUNT (128)
            0x75, 0x01, // REPORT_SIZE (1)
            0x81, 0x02, // INPUT (Data,Var,Abs)

            0x05, 0x01,       // USAGE_PAGE (Generic Desktop) // analog axes
            0x09, 0x30,       // USAGE (X)
            0x09, 0x31,       // USAGE (Y)
            0x16, 0x01, 0x80, //LOGICAL_MINIMUM (-32767)
            0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767)
            0x75, 0x10,       //     REPORT_SIZE (16)
            0x95, 0x02,       // REPORT_COUNT (2)
            0x81, 0x02,       // INPUT (Data,Var,Abs)

            0x09, 0x39,     // USAGE (HATSWITCH)
            0x15, 0x00,     // LOGICAL_MINIMUM (0)
            0x25, 0x07,     // LOGICAL_MAXIMUM (7)
            0x35, 0x00,     // PHYSICAL_MINIMUM (0)
            0x46, 0x38, 01, // PHYSICAL_MAXIMUM (315)
            0x65, 0x14,     // UNIT (Eng Rot:Angular Pos)
            0x75, 0x04,     // REPORT_SIZE (4)
            0x95, 0x01,     // REPORT_COUNT (1)
            0x81, 0x02,     // INPUT(Data, Var, Abs)

            0x09, 0x39,     // USAGE (HATSWITCH)
            0x15, 0x00,     // LOGICAL_MINIMUM (0)
            0x25, 0x07,     // LOGICAL_MAXIMUM (7)
            0x35, 0x00,     // PHYSICAL_MINIMUM (0)
            0x46, 0x38, 01, // PHYSICAL_MAXIMUM (315)
            0x65, 0x14,     // UNIT (Eng Rot:Angular Pos)
            0x75, 0x04,     // REPORT_SIZE (4)
            0x95, 0x01,     // REPORT_COUNT (1)
            0x81, 0x02,     // INPUT(Data, Var, Abs)

            0x09, 0x39,     // USAGE (HATSWITCH)
            0x15, 0x00,     // LOGICAL_MINIMUM (0)
            0x25, 0x07,     // LOGICAL_MAXIMUM (7)
            0x35, 0x00,     // PHYSICAL_MINIMUM (0)
            0x46, 0x38, 01, // PHYSICAL_MAXIMUM (315)
            0x65, 0x14,     // UNIT (Eng Rot:Angular Pos)
            0x75, 0x04,     // REPORT_SIZE (4)
            0x95, 0x01,     // REPORT_COUNT (1)
            0x81, 0x02,     // INPUT(Data, Var, Abs)

            0x09, 0x39,     // USAGE (HATSWITCH)
            0x15, 0x00,     // LOGICAL_MINIMUM (0)
            0x25, 0x07,     // LOGICAL_MAXIMUM (7)
            0x35, 0x00,     // PHYSICAL_MINIMUM (0)
            0x46, 0x38, 01, // PHYSICAL_MAXIMUM (315)
            0x65, 0x14,     // UNIT (Eng Rot:Angular Pos)
            0x75, 0x04,     // REPORT_SIZE (4)
            0x95, 0x01,     // REPORT_COUNT (1)
            0x81, 0x02,     // INPUT(Data, Var, Abs)

            0x09, 0x32,       // USAGE (Z)
            0x09, 0x33,       // USAGE (Rx)
            0x09, 0x34,       // USAGE (Ry)
            0x09, 0x35,       // USAGE (Rz)   //36-37=steering s0
            0x16, 0x01, 0x80, //LOGICAL_MINIMUM (-32767)
            0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767)
            0x75, 0x10,       //     REPORT_SIZE (16)
            0x95, 0x04,       //     REPORT_COUNT (4)
            0x81, 0x02,       //     INPUT (Data, Variable, Absolute) ;20 bytes (slider 1 and slider 2)

            0x05, 0x02, //   USAGE_PAGE (Simulation Controls)
            0x09, 0xBB, //   USAGE (Throttle)
            0x16, 0x01, 0x80, //LOGICAL_MINIMUM (-32767)
            0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767)
            0x75, 0x10,       //     REPORT_SIZE (16)
            0x95, 0x01,       //     REPORT_COUNT (2)
            0x81, 0x02,                    //   INPUT (Data,Var,Abs)

            0x05, 0x01,       // USAGE_PAGE (Generic Desktop) // analog axes
            0x09, 0x36, //   USAGE (Slider)
            0x16, 0x01, 0x80, //LOGICAL_MINIMUM (-32767)
            0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767)
            0x75, 0x10,       //     REPORT_SIZE (16)
            0x95, 0x01,       //     REPORT_COUNT (2)
            0x81, 0x02,                    //   INPUT (Data,Var,Abs)

            0xc0 // END_COLLECTION
    };
    reportLength = sizeof(reportDescriptor);
    return reportDescriptor;
}

void USBKeyboardGamepad::SetButton(int idx, bool val) {
    if (idx > 128 || idx < 0) {
        return;
    }
    bitWrite(inputArray[idx / 8], idx % 8, val);
}

void USBKeyboardGamepad::SetX(uint16_t val) {
    inputArray[X_AXIS_LSB] = LSB(val);
    inputArray[X_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetY(uint16_t val) {
    inputArray[Y_AXIS_LSB] = LSB(val);
    inputArray[Y_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetZ(uint16_t val) {
    inputArray[Z_AXIS_LSB] = LSB(val);
    inputArray[Z_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetRx(uint16_t val) {
    inputArray[Rx_AXIS_LSB] = LSB(val);
    inputArray[Rx_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetRy(uint16_t val) {
    inputArray[Ry_AXIS_LSB] = LSB(val);
    inputArray[Ry_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetRz(uint16_t val) {
    inputArray[Rz_AXIS_LSB] = LSB(val);
    inputArray[Rz_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetS0(uint16_t val) {
    inputArray[S0_AXIS_LSB] = LSB(val);
    inputArray[S0_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetThrottle(uint16_t val) {
    inputArray[THROTTLE_AXIS_LSB] = LSB(val);
    inputArray[THROTTLE_AXIS_MSB] = MSB(val);
}

void USBKeyboardGamepad::SetHat(uint8_t hatIdx, uint8_t dir) {
    uint8_t hatDir[9][4] = {
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 1, 0, 0},
            {0, 1, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 0, 0, 0}};
    switch (hatIdx) {
        case 0:
            for (int i = 0; i < 4; i++) {
                bitWrite(inputArray[HAT0_1], 3 - i, hatDir[dir][i]);
            }
            break;
        case 1:
            for (int i = 0; i < 4; i++) {
                bitWrite(inputArray[HAT0_1], 7 - i, hatDir[dir][i]);
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                bitWrite(inputArray[HAT2_3], 3 - i, hatDir[dir][i]);
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++) {
                bitWrite(inputArray[HAT2_3], 7 - i, hatDir[dir][i]);
            }
            break;
    }
}

bool USBKeyboardGamepad::SendGamepadUpdates() {
    _mutex.lock();

    HID_REPORT report;
    report.data[0] = REPORT_ID_GAMEPAD;
    for (int i = 1; i < 36; i++) {
        report.data[i] = inputArray[i - 1];
    }

    report.length = 35;

    if (!send(&report)) {
        _mutex.unlock();
        return false;
    }

    _mutex.unlock();
    return true;
}

#define DEFAULT_CONFIGURATION (1)
#define TOTAL_DESCRIPTOR_LENGTH ((1 * CONFIGURATION_DESCRIPTOR_LENGTH) \
                               + (1 * INTERFACE_DESCRIPTOR_LENGTH) \
                               + (1 * HID_DESCRIPTOR_LENGTH) \
                               + (2 * ENDPOINT_DESCRIPTOR_LENGTH))

const uint8_t *USBKeyboardGamepad::configuration_desc(uint8_t index) {
    if (index != 0) {
        return NULL;
    }
    uint8_t configuration_descriptor_temp[] = {
            CONFIGURATION_DESCRIPTOR_LENGTH,    // bLength
            CONFIGURATION_DESCRIPTOR,           // bDescriptorType
            LSB(TOTAL_DESCRIPTOR_LENGTH),       // wTotalLength (LSB)
            MSB(TOTAL_DESCRIPTOR_LENGTH),       // wTotalLength (MSB)
            0x01,                               // bNumInterfaces
            DEFAULT_CONFIGURATION,              // bConfigurationValue
            0x00,                               // iConfiguration
            C_RESERVED | C_SELF_POWERED,        // bmAttributes
            C_POWER(0),                         // bMaxPower

            INTERFACE_DESCRIPTOR_LENGTH,        // bLength
            INTERFACE_DESCRIPTOR,               // bDescriptorType
            0x00,                               // bInterfaceNumber
            0x00,                               // bAlternateSetting
            0x02,                               // bNumEndpoints
            HID_CLASS,                          // bInterfaceClass
            HID_SUBCLASS_BOOT,                  // bInterfaceSubClass
            HID_PROTOCOL_KEYBOARD,              // bInterfaceProtocol
            0x00,                               // iInterface

            HID_DESCRIPTOR_LENGTH,              // bLength
            HID_DESCRIPTOR,                     // bDescriptorType
            LSB(HID_VERSION_1_11),              // bcdHID (LSB)
            MSB(HID_VERSION_1_11),              // bcdHID (MSB)
            0x00,                               // bCountryCode
            0x01,                               // bNumDescriptors
            REPORT_DESCRIPTOR,                  // bDescriptorType
            (uint8_t) (LSB(report_desc_length())), // wDescriptorLength (LSB)
            (uint8_t) (MSB(report_desc_length())), // wDescriptorLength (MSB)

            ENDPOINT_DESCRIPTOR_LENGTH,         // bLength
            ENDPOINT_DESCRIPTOR,                // bDescriptorType
            _int_in,                            // bEndpointAddress
            E_INTERRUPT,                        // bmAttributes
            LSB(MAX_HID_REPORT_SIZE),           // wMaxPacketSize (LSB)
            MSB(MAX_HID_REPORT_SIZE),           // wMaxPacketSize (MSB)
            1,                                  // bInterval (milliseconds)

            ENDPOINT_DESCRIPTOR_LENGTH,         // bLength
            ENDPOINT_DESCRIPTOR,                // bDescriptorType
            _int_out,                           // bEndpointAddress
            E_INTERRUPT,                        // bmAttributes
            LSB(MAX_HID_REPORT_SIZE),           // wMaxPacketSize (LSB)
            MSB(MAX_HID_REPORT_SIZE),           // wMaxPacketSize (MSB)
            1,                                  // bInterval (milliseconds)
    };
    MBED_ASSERT(sizeof(configuration_descriptor_temp) == sizeof(_configuration_descriptor));
    memcpy(_configuration_descriptor, configuration_descriptor_temp, sizeof(_configuration_descriptor));
    return _configuration_descriptor;
}

int USBKeyboardGamepad::_getc() {
    return -1;
}

bool USBKeyboardGamepad::SendKeyCode(uint8_t key, uint8_t modifier) {
    _mutex.lock();

    uint8_t code;
    if (key >= 136) {
        code = key - 136;
    } else {
        code = keymap[key].usage;
    }

    // Send a simulated keyboard keypress. Returns true if successful.
    HID_REPORT report;

    report.data[0] = REPORT_ID_KEYBOARD;
    report.data[1] = modifier;
    report.data[2] = 0;
    report.data[3] = code;
    report.data[4] = 0;
    report.data[5] = 0;
    report.data[6] = 0;
    report.data[7] = 0;
    report.data[8] = 0;

    report.length = 9;

    if (!send(&report)) {
        _mutex.unlock();
        return false;
    }

    report.data[1] = 0;
    report.data[3] = 0;

    if (!send(&report)) {
        _mutex.unlock();
        return false;
    }

    _mutex.unlock();
    return true;
}

int USBKeyboardGamepad::_putc(int c) {
    return SendKeyCode(c, keymap[c].modifier);
}

bool USBKeyboardGamepad::media_control(MEDIA_KEY key) {
    _mutex.lock();

    HID_REPORT report;

    report.data[0] = REPORT_ID_VOLUME;
    report.data[1] = (1 << key) & 0x7f;

    report.length = 2;

    if (!send(&report)) {
        _mutex.unlock();
        return false;
    }

    report.data[0] = REPORT_ID_VOLUME;
    report.data[1] = 0;

    report.length = 2;

    if (!send(&report)) {
        _mutex.unlock();
        return false;
    }

    _mutex.unlock();
    return true;
}

void USBKeyboardGamepad::report_rx() {
    assert_locked();

    HID_REPORT report;
    read_nb(&report);

    // we take [1] because [0] is the report ID
    _lock_status = report.data[1] & 0x07;
}

uint8_t USBKeyboardGamepad::lock_status() {
    return _lock_status;
}

