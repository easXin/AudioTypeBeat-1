
#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

SDL_AudioSpec wav_spec;
Uint32 wav_length;
Uint8 *wav_buffer;
int main(int argc, char *argv[])
{
  /* Load the audio format data if function is called successfully*/
  if (SDL_LoadWAV("voice.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
      fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
  } else {
      /* Do stuff with the WAV data, and then... */
      SDL_FreeWAV(wav_buffer);
  }

}
