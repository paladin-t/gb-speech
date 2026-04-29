#include <gbdk/console.h>

#include <stdio.h>
#include <string.h>

#include "speech.h"
#include "utils.h"

static const char * text_hello   = "Hello World.";
static const char * text_how     = "How are you?";
static const char * text_nice    = "Nice to meet you";
static const char * text_welcome = "Welcome to the game!";
static const char * text_thank   = "Thank you very much!";
static const char * text_exclaim = "Amazing!";

static const UINT16 pitch_presets[] = { 100, 120, 150, 180, 280 };
static const char * pitch_names[] = { "Low", "Male", "Medium", "Female", "High" };

static void update_display(UINT8 state, UINT8 pitch_idx) {
    gotoxy(0, 12);
    printf("Pitch: %s    ", pitch_names[pitch_idx]);

    gotoxy(0, 13);
    printf("                    ");
    gotoxy(0, 13);
    switch (state) {
    case 0:
        printf("Status: Ready");

        break;
    case 1:
        printf("Status: Playing...");

        break;
    case 2:
        printf("Status: Complete!");

        break;
    }
}

void main(void) {
    UINT8 keys;
    UINT8 prev_keys = 0;
    UINT8 pitch_idx = 1;
    BOOLEAN busy = FALSE;

    speech_init(TRUE);
    speech_set_pitch(pitch_presets[pitch_idx]);
    speech_set_speed(7);

    printf("Speech Synthesizer\n");
    printf("Realtime//Gibberish\n");
    printf("\n");
    printf("A: Hello World.\n");
    printf("B: How are you?\n");
    printf("UP: Nice to meet you");
    printf("DOWN: Welcome...!\n");
    printf("LEFT: Thank you...!\n");
    printf("RIGHT: Amazing!\n");
    printf("\n");
    printf("START: Stop\n");
    printf("SELECT: Pitch\n");
    gotoxy(0, 15);
    printf("https://github.com/\npaladin-t/gb-speech/");

    update_display(0, pitch_idx);

    for (; ; ) {
        speech_update();

        keys = joypad();
        if (keys != prev_keys) {
            if ((keys & J_A) && !(prev_keys & J_A)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_hello, strlen(text_hello));
                    update_display(1, pitch_idx);
                }
            }
            if ((keys & J_B) && !(prev_keys & J_B)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_how, strlen(text_how));
                    update_display(1, pitch_idx);
                }
            }
            if ((keys & J_UP) && !(prev_keys & J_UP)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_nice, strlen(text_nice));
                    update_display(1, pitch_idx);
                }
            }
            if ((keys & J_DOWN) && !(prev_keys & J_DOWN)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_welcome, strlen(text_welcome));
                    update_display(1, pitch_idx);
                }
            }
            if ((keys & J_LEFT) && !(prev_keys & J_LEFT)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_thank, strlen(text_thank));
                    update_display(1, pitch_idx);
                }
            }
            if ((keys & J_RIGHT) && !(prev_keys & J_RIGHT)) {
                if (!speech_is_playing()) {
                    speech_play(0, text_exclaim, strlen(text_exclaim));
                    update_display(1, pitch_idx);
                }
            }

            if ((keys & J_START) && !(prev_keys & J_START)) {
                speech_stop();
                update_display(0, pitch_idx);
            }
            if ((keys & J_SELECT) && !(prev_keys & J_SELECT)) {
                ++pitch_idx;
                if (pitch_idx >= 5) pitch_idx = 0;
                speech_set_pitch(pitch_presets[pitch_idx]);
                update_display(speech_is_playing() ? 1 : 0, pitch_idx);
            }

            prev_keys = keys;
        }

        if (!speech_is_playing()) {
            if (busy) {
                update_display(2, pitch_idx);
                busy = FALSE;
            }
        } else {
            if (!busy)
                busy = TRUE;
        }

        wait_vbl_done();
    }
}
