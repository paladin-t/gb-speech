# Speech Synthesizer for Game Boy

## About This Software

Try it [online](https://tonywang.itch.io/gb-speech) (itch.io)?

<p align="center">
  <a href="https://www.youtube.com/shorts/t7VPJj0dZ4M">
    <img src="https://img.youtube.com/vi/t7VPJj0dZ4M/maxresdefault.jpg" width="256px" />
  </a>
</p>

This project is a Game Boy realtime speech synthesizer that outputs gibberish voice. It is used as a sub module in a runtime [kernel](https://github.com/paladin-t/gbb/releases/latest) of the [GB BASIC](https://github.com/paladin-t/gbb) project.

It provides a stylized speech synthesis solution with decent realtime efficiency rather than realistic human voice synthesis. The idea is similar to the mumbled speech of characters in _Tomodachi Life_, _Animal Crossing_, and many other games. You can use it to give every line of conversation in your Game Boy game a unique auditory experience. Using this approach offers the following benefits:

1. Globalization strategy: avoids recording voice-overs for dozens of languages while giving players across regions a unified audiovisual experience
2. Cost and performance: an extremely efficient solution considering budget and storage constraints
3. Artistic expression: pursues a unique aesthetic, avoids fatigue from repeated lines, and leaves infinite room for the player's imagination

## Technical Notes

Directory structure:

```
.
├── src/
│   ├── speech.c        # Speech synthesis implementation
│   ├── speech.h        # Public data structures and interface definitions
│   ├── utils.c         # Utilities implementation
│   ├── utils.h         # Interface of utilities
│   └── main.c          # Main program and demo
├── Makefile            # Build script
├── README.md           # This file
└── ...
```

This library is written in C and requires GBDK-2020 to compile. You can test it via the online link at the top of this page, or download the precompiled .gb file in the "build" directory.

The library uses the second square channel (the `NR2y` registers) for audio output. To integrate it into your own game, simply add "speech.c", "speech.h", "utils.c", "utils.h" to your project and define macros such as banking as needed. You may also want to modify "utils" according to your own situation.

This library was created primarily with English scenarios in mind. Thanks to its gibberish style, it also works well with non-English text, and you can write text for other languages based on English spelling-pronunciation rules.

## API Usage

### Initialization

```c
#include "speech.h"

speech_init();
```

### Updating

```c
for (; ; ) {
  speech_update(); // Called every frame.
  // ...
}
```

### Speaking

```c
const char * txt = "Hello World";
speech_play(0, txt, strlen(txt)); // Speak asynchronously.
```

### Getting Whether the Synthesizer Is Busy

```c
speech_is_playing();
```

## Controls (Demo)

| Button | Function                          |
|--------|-----------------------------------|
| A      | Synthesize "Hello World."         |
| B      | Synthesize "How are you?"         |
| UP     | Synthesize "Nice to meet you"     |
| DOWN   | Synthesize "Welcome to the game!" |
| LEFT   | Synthesize "Thank you very much!" |
| RIGHT  | Synthesize "Amazing!"             |
| START  | Stop playback                     |
| SELECT | Change pitch                      |
