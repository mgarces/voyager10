# Wiring and build notes

## Controller and switches

- **Controller:** Seeed Studio XIAO RP2040 (USB-C)
- **Switches:** 10 × Kailh Choc V1
- **Wiring:** one GPIO per switch, shared GND, no diodes
- **Firmware:** QMK, direct-pin matrix

```text
Top/left/right physical key numbering:
       [4] [3] [2] [1]
       [5]         [7]
          [6]   [8][9][10]
```

| Key | Controller pad | RP2040 pin |
|---:|---|---|
| 1 | D0 | GP26 |
| 2 | D1 | GP27 |
| 3 | D2 | GP28 |
| 4 | D3 | GP29 |
| 5 | D4 | GP6 |
| 6 | D5 | GP7 |
| 7 | D6 | GP0 |
| 8 | D9 | GP4 |
| 9 | D8 | GP2 |
| 10 | D7 | GP1 |

**Each switch:** connect one terminal to the specified controller pad, the other to GND. Chain GND across all ten switches. The switch itself is not polarized. Keep USB disconnected while soldering. Verify with continuity mode before powering.

## Plate dimensions

The original Choc V1 fit coupon physically tested on the Bambu Lab X1 Carbon worked perfectly with:

- Switch cutouts **13.7 × 13.7 mm** (square)
- Plate thickness **1.3 mm**
- Gap between neighbouring cutout edges **5 mm** (where applicable)

Do not assume all keycaps clear one another solely from the square cutout spacing. Check the angled keys with the actual keycaps.

## Notes

- Keys 8 (Left) and 10 (Right) are intentionally crossed relative to the first wiring plan; the firmware corrects this.
- D10 / GP3 is currently unused.
- Existing Karabiner-Elements setup on macOS modifies events from both the Voyager and Voyager10, allowing cross-device modifiers.
- On a new computer or after a USB identity change, recheck Karabiner-Elements → Devices → **Modify events**.
