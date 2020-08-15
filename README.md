# MSDOS watchdog TSRs for Advantech CPU boards

I recently came into possession of an Advantech industrial computer running
MSDOS.  One unfortunate feature of the system is that it does not have a reset
button.  If the CPU hangs, the only way to recover is to power off the entire
chassis and power it back on.  The watchdog timer on some Advantech CPU boards
have the ability to reset the CPU if it stops receiving ticks from software.
This software runs in the background providing those ticks.

Build notes:

Software is written in x86 assembly, assembled with Borland Turbo Assembler.
