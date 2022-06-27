
# Dragon Warrior Monsters 2
A disassembly of Dragon Warrior Monsters 2.

## Progress
NOTE: Numbers are based on a direct comparison between the outputted file and the original. Actual documentation is a different story.

[2,846 / 2,060,211] | ~[.0014%] Similarity as of 2022/06/25.

TODO:

## Building
NOTE: A step in the build script is comparing the output ROM to a backup copy of the released game, and that file is not included for obvious reasons. While I *currently* have no plans to switch over to a special build system, I will be working on improving this as I go forward.

### Building on Windows
Using a cli in the main folder type in the command:

`.\build.bat`

No fancy build system, It just simply creates a directory named /target/debug/%CurrentDate%, copies the src files into it.

It then runs, in this order:
- rgbasm
- rgblink
- rgbfix

Finally it compares the output ROM with an original *backup* located at \ROM\Cobi.gbc and outputs the result into compared.txt.

### Building on Linux
TODO:

### Building on Mac
I'm going to need someone else for this. I don't have any apple products to test on and I don't plan on getting any.