# mumblePMRgateway
A Mumble Client for Raspberry PI with GPIO Pin activation for SQL and PTT signals for use with two-way radio transceivers (CB, PMR and others).

Based on official Mumble Client and MumbleRF 


## Warning:
This version currently only tested on Debian/Raspbian 10 (buster) on a Raspbery 3B+.
Quick and Dirty Code

### Features:
The software provides:

A squelch (SQL) output to be connected with the transceiver's PTT (push to talk) input in order to set the transceiver to transmit-mode when audio is received from the mumble server.
A PTT-input driven by the transceiver's SQL-output for sending audio to the mumble server when a radio frequency call is received.
The software is optimized for Raspberry Pi single board computers.
Digital I/O is available via Raspberry Pi GPIO-ports. These ports are defined in ExternalPTT.cpp

### Branches and versioning:
Branches are named according to the underlying Mumble release version.

(Select a branch from the github-menu! Otherwise you won't see the files!)

Mumble Build Guide:
https://wiki.mumble.info/wiki/BuildingLinux#1.3.x

### Preparations:
install WiringPi to use Raspberry Pi GPIO-ports.
Add unix user to the groups "audio" (for ALSA support) and "gpio" (for GPIO without root privileges).

### Build
-> Run ./build.sh as a normal (non-root) user. See inside the file for build options.
