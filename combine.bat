@rem ** WARNING:: DEMQ has patched DSRLNK that does not DSRLNK!

\work\setbinsize\release\setbinsize.exe header.bin 64
\work\setbinsize\release\setbinsize.exe unpack.bin 512
\work\setbinsize\release\setbinsize.exe robo1.pack 5888
\work\setbinsize\release\setbinsize.exe robo2.pack 4918
\work\setbinsize\release\setbinsize.exe robo3.pack 1650
\work\setbinsize\release\setbinsize.exe murder_p.pack 3058
\work\setbinsize\release\setbinsize.exe robotf_p.pack 2702
\work\setbinsize\release\setbinsize.exe dash.tiac.pack 2510
\work\setbinsize\release\setbinsize.exe dash.tiap.pack 2974
\work\setbinsize\release\setbinsize.exe PATCH.BIN 96

@rem those are the only files that are stacked
@rem using tiobj2bin on unpack will leave a big header you need to manually delete
@rem remember to take the c99 E/A startup code out of the executable, it loads in
@rem at startup and we need to delete the E/A copy code. At >A00C you should see
@rem bytes 0201 20FA 0202 02C2 - these load R1 with the destination address, and R2
@rem with the length. Change 20FA to 0000 (write to ROM) and 02C2 to 0002 (two bytes)
@rem some work was also needed to allow the dash pic to load color ;)

copy /y /b header.bin + /b unpack.bin + /b robo1.pack + /b robo3.pack /b bank0.bin
copy /y /b header.bin + /b robo2.pack + /b demq.pack /b bank1.bin
copy /y /b header.bin + /b robotf_p.pack + /b murder_p.pack /b bank2.bin
copy /y /b header.bin + /b dash.tiac.pack + /b dash.tiap.pack + /B PATCH.BIN /b bank3.bin

\work\setbinsize\release\setbinsize.exe bank0.bin 8192
\work\setbinsize\release\setbinsize.exe bank1.bin 8192
\work\setbinsize\release\setbinsize.exe bank2.bin 8192
\work\setbinsize\release\setbinsize.exe bank3.bin 8192

copy /y /b bank0.bin + /b bank1.bin + /b bank2.bin + /b bank3.bin /b RobotFighter32KB8.bin
