import speech_recognition as sr
import sys
r=sr.Recognizer()

input = sr.AudioFile("StarWar3.wav")

with input as source:
    audio = r.record(source)

    print(r.recognize_google(audio, key="AIzaSyBB9BDWov9yhJ9x7rvarrCBrC6ajqhaXNY"))
