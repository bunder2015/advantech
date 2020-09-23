# MSDOS watchdog TSRs for Advantech CPU boards


### Backstory and description:

I recently came into possession of an Advantech industrial computer running
MSDOS.  One unfortunate feature of the system is that it does not have a
convenient-to-press reset button (it has a pinhole reset button on the front of
the chassis).  If the CPU hangs, the only reasonable way to recover is to power
off the entire chassis and power it back on.  The watchdog timer on some
Advantech CPU boards have the ability to reset the CPU if it stops receiving
ticks from software.  This software runs in the background providing those
ticks.

### Build and installation notes:

Software is written in x86 assembly, assembled with Borland Turbo Assembler.

- Copy the directory for your particular watchdog to your device, along with a
copy of Borland Turbo Assembler (Don't forget to add the `bin` directory to
your `PATH` environment variable).
- Change directory to the source directory and run `BUILD.BAT`.
- Edit `C:\AUTOEXEC.BAT` to add the watchdog TSR,
eg: `LH C:\PCA6155V\WDTSR.COM`
- Optional: Add the controller to run the watchdog,
eg: `C:\PCA6155V\WDCTRL.COM 5`
- Reboot.
