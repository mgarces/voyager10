QMK_HOME ?= $(HOME)/qmk_firmware
KEYBOARD := handwired/voyager10

.PHONY: install build flash check

check:
	@test -d "$(QMK_HOME)/keyboards" || (echo "QMK firmware not found at $(QMK_HOME)"; exit 1)
	@command -v qmk >/dev/null || (echo "QMK CLI missing; see https://docs.qmk.fm/newbs_getting_started"; exit 1)

install: check
	mkdir -p "$(QMK_HOME)/keyboards/handwired/voyager10"
	cp -R firmware/keyboards/handwired/voyager10/. "$(QMK_HOME)/keyboards/handwired/voyager10/"
	@echo "Installed $(KEYBOARD) in $(QMK_HOME)"

build: install
	cd "$(QMK_HOME)" && qmk compile -kb "$(KEYBOARD)" -km default

flash:
	@test -d /Volumes/RPI-RP2 || (echo "Bootloader drive missing. Hold B while connecting USB, or keys 1+4 at boot."; exit 1)
	cp "$(QMK_HOME)/handwired_voyager10_default.uf2" /Volumes/RPI-RP2/
