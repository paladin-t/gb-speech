#include "utils.h"
#include "speech.h"

UINT8 get_uint8(UINT8 bank, UINT8 * ptr) NONBANKED {
#if SPEECH_BANKED
    const UINT8 _save = CURRENT_BANK;
    SWITCH_ROM_BANK(bank);
    const UINT8 result = *ptr;
    SWITCH_ROM_BANK(_save);

    return result;
#else /* SPEECH_BANKED */
    (void)bank;

    const UINT8 result = *ptr;

    return result;
#endif /* SPEECH_BANKED */
}

void get_chunk(UINT8 * dst, UINT8 bank, UINT8 * ptr, UINT8 size) NONBANKED {
#if SPEECH_BANKED
    const UINT8 _save = CURRENT_BANK;
    SWITCH_ROM_BANK(bank);
    while (size--)
        *dst++ = *ptr++;
    SWITCH_ROM_BANK(_save);
#else /* SPEECH_BANKED */
    (void)bank;

    while (size--)
        *dst++ = *ptr++;
#endif /* SPEECH_BANKED */
}
