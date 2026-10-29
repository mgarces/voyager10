# Voyager10 — project notes

## Goal

Make a reliable, low-profile, standalone ten-key companion for the ZSA Voyager that fits comfortably between its halves. Keep the code and CAD reproducible.

## Current hardware

- Seeed XIAO RP2040, USB-C, QMK
- 10 Kailh Choc V1 switches, hand-wired directly to GPIO
- 3D-printed case and separate plate in Shapr3D
- Mac shortcuts and QMK combos; Karabiner-Elements handles cross-device modifiers

## Near-term work

- [ ] Compile and confirm the latest `:` and `€` mapping on the Mac
- [ ] Photograph finished build with caps and check keycap rubbing
- [ ] Add actual Shapr3D source and STEP/STL exports for the ten-key case
- [ ] Revise cable exit, controller positioning and internal clearance
- [ ] Test repeated bootloader entry and recovery
- [ ] Add assembly and wiring photos

## Future exploration (not current scope)

- [ ] Mechanically connect to Voyager using removable mounts
- [ ] Dedicated PCB (optional hot-swap sockets)
- [ ] Wireless version, small display, rotary encoders

## Design choices

- Preserve the physically tested switch cutout: 13.7 mm square in a 1.3 mm plate.
- Direct GPIO wiring remains intentional; switch to a diode matrix only when additional GPIO is needed.
- Avoid committing a full copy of `qmk_firmware`; keep the custom keyboard definition here.
- Initial GitHub repository should be private until visibility/license are decided.
