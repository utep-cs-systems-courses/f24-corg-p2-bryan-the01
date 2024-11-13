Compilation first! In the project directory, run "make all" in order to get
started. Navigate towards the "buzzer_toy" subdirectory. Execute "make load"
with an msp430 connected to compile all the files.

Now that we have compiled everything, a brief description of the controls. If
we press S1 on the expansion board, we get an alarm system that switches pitch
from high to low, and alternates the red and green LEDs. Pressing S2 puts the
system on green alarm mode, where the green LED will be on, and a slow, normal
pitch rhythm will play (pressing the S2 button again will make the LED
disappear for as long as it is held, but the tone will remain the
same). Pressing S3 puts the system in red alarm mode, in which
the red LED will be on and a fast, high pitch rhythm will play (pressing the
S3 button will make the LED disappear for as long as it is held, but the tone
will remain the same). Finally, our S4 button simply turns off EVERYTHING, any
tone or leds on will turn off. The system can freely switch between all these
modes, unless you press it really fast (250ths of a second fast)
