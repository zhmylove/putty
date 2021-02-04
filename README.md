# A few words on this project

I have tried a lot of SSH clients on Windows and the PuTTY stays the best one for me for different reasons.
In spite of some problems with PuTTY which made me sad sometimes I still prefer to use it.
The most disturbing PuTTY problem for me was that after Windows wakeup or after a night when my connections are being closed automatically, I do find all PuTTY windows with poped out modal error message says: "Software caused connection abort".
The big deal is that I can't simply close the whole bunch of my PuTTY instances as I am obligued to firstly manually close all the error messages.
Obviously, I have used taskkill.exe to work around this problem but it was not so handy.

So it all have started with a little patch for PuTTY to avoid such messages.
I have used a hex editor to substitute a couple of bytes in the version I used, and the whole patch is:

```
address: 0x140074c9b
old: 48 8d 05 7d a6 03 00
new: e9 97 80 ff ff 90 90
```

Right after that I have discovered that PuTTY has it's source code open and I decided to make all required changes right in there.

I'll try to keep all my changes in a separate branch named "korg" which will help me with rebasing it on top of newer version of master branch.

# New features I have implemented so far

1. Removed annoying MessageBox invocation in case of "Software caused connection abort" error.  This makes all inactive PuTTY windows to be closed just with regular WM\_CLOSE event.
2. Changed plain "(Inactive)" window caption to more meaningful variant: "(Inactive: reason)".
3. Implemented keyword based highlighting using PCRE(!) regular expressions.  Although, the patterns are currently hard-coded...  I don't have too much time to implement the configuration part here.
4. Implemented border highlighting by default.  Windows 10 with it's useless thin borders makes a reall hell with overlapping PuTTY windows, so I've added an explicit border.
5. Implemented checkboxes for "Keywords highlight" and "Contrast border" features in PuTTY menu to support their toggle on the fly.
