#!/bin/bash

# Architettura degli Elaboratori mod. 2
# ==============================================
#  VM ARM Cortex-A57 con Linux Debian
# 
#	Dopo il boot connettersi alla VM con:
#		$ ssh vm@localhost -p 2222
#	password: vm
#
#  Per info: filippo.bergamasco@unive.it
#

qemu-system-aarch64 -smp 2 -M virt -cpu cortex-a57 -m 1G \
    -initrd debian_arm64/initrd.img-5.10.0-8-arm64 \
    -kernel debian_arm64/vmlinuz-5.10.0-8-arm64 \
    -append "root=/dev/sda1 console=ttyAMA0" \
    -global virtio-blk-device.scsi=off \
    -device virtio-scsi-device,id=scsi \
    -drive file=arm64vm_fb_disk.qcow2,id=rootimg,cache=unsafe,if=none \
    -device scsi-hd,drive=rootimg \
    -netdev user,hostfwd=tcp::2222-:22,id=unet -device virtio-net-device,netdev=unet \
    -net user
#    -serial stdio

