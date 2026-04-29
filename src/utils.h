#ifndef __UTILS_H__
#define __UTILS_H__

#if defined __SDCC
#   include <gb/gb.h>
#   include <gb/hardware.h>
#else /* __SDCC */
#   error "Not implemented."
#endif /* __SDCC */

#include <stdint.h>

#ifndef MUL2
#   define MUL2(A)            ((A) << 1)
#endif /* MUL2 */
#ifndef DIV2
#   define DIV2(A)            ((A) >> 1)
#endif /* DIV2 */
#ifndef DIV4
#   define DIV4(A)            ((A) >> 2)
#endif /* DIV4 */
#ifndef DIV128
#   define DIV128(A)          ((A) >> 7)
#endif /* DIV128 */
#ifndef MIN
#   define MIN(A, B)          (((A) < (B)) ? (A) : (B))
#endif /* MIN */
#ifndef MAX
#   define MAX(A, B)          (((A) > (B)) ? (A) : (B))
#endif /* MAX */
#ifndef CLAMP
#   define CLAMP(A, LO, HI)   (((A) < (LO)) ? (LO) : (((A) > (HI)) ? (HI) : (A)))
#endif /* CLAMP */

#define SWITCH_ROM_BANK(B)    SWITCH_ROM(B)

UINT8 get_uint8(UINT8 bank, UINT8 * ptr) NONBANKED;

void get_chunk(UINT8 * dst, UINT8 bank, UINT8 * ptr, UINT8 size) NONBANKED;

#endif /* __UTILS_H__ */
