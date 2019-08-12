#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


SDL_AudioSpec wav_spec;
Uint32 wav_length;
Uint8 *wav_buffer;
char* seconds_to_time(float raw_seconds);
// SDL_AudioFormat fmt;
int main(int argc, char *argv[])
{
  /* Load the audio format data if function is called successfully*/
  if (SDL_LoadWAV("kendrick.wav", &wav_spec, &wav_buffer, &wav_length) == NULL) {
      fprintf(stderr, "Could not open test.wav: %s\n", SDL_GetError());
  } else {
      /* Do stuff with the WAV data, and then... */
      printf("file size = %u\n",wav_length);
      printf("sample rate = %d\n",wav_spec.freq);
      printf("samples = %d\n",wav_spec.samples);
      printf("channels = %d\n",wav_spec.channels);
      // float seconds = 0.0;

      if (SDL_AUDIO_ISFLOAT(wav_spec.format)) {
        printf("floating point data\n");
      } else {
        printf("integer data\n");
      }

      int bitsize = (int) SDL_AUDIO_BITSIZE(wav_spec.format);
      int bitrate = (wav_spec.freq)*wav_spec.channels*bitsize;
      float byerate = bitrate/8;
      printf("ByteRate = %f\n",byerate);

      float seconds = wav_length/byerate;
      printf("seconds = %f\n", seconds);

      printf("%d bits per sample\n", bitsize);
      char *time = seconds_to_time(seconds);
      puts(time);
      SDL_FreeWAV(wav_buffer);
  }

  return 1;

}

char* seconds_to_time(float raw_seconds) {
 char *hms;
 int hours, hours_residue, minutes, seconds, milliseconds;
 hms = (char*) malloc(100);

 sprintf(hms, "%f", raw_seconds);

 hours = (int) raw_seconds/3600;
 hours_residue = (int) raw_seconds % 3600;
 minutes = hours_residue/60;
 seconds = hours_residue % 60;
 milliseconds = 0;

 // get the decimal part of raw_seconds to get milliseconds
 char *pos;
 pos = strchr(hms, '.');
 int ipos = (int) (pos - hms);
 char decimalpart[15];
 memset(decimalpart, ' ', sizeof(decimalpart));
 strncpy(decimalpart, &hms[ipos+1], 3);
 milliseconds = atoi(decimalpart);


 sprintf(hms, "%d:%d:%d.%d", hours, minutes, seconds, milliseconds);
 return hms;
}
