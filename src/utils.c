#include "utils.h"

UINT8 get_uint8(UINT8 bank, UINT8 * ptr) NONBANKED {
    UINT8 _save = CURRENT_BANK;
    SWITCH_ROM_BANK(bank);
    UINT8 result = *ptr;
    SWITCH_ROM_BANK(_save);

    return result;
}

void get_chunk(UINT8 * dst, UINT8 bank, UINT8 * ptr, UINT8 size) NONBANKED {
    UINT8 _save = CURRENT_BANK;
    SWITCH_ROM_BANK(bank);
    while (size--)
        *dst++ = *ptr++;
    SWITCH_ROM_BANK(_save);
}
