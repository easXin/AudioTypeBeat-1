from os import path
from pydub import AudioSegment
import sys
from playButton import play
wavefile=""
mp3file=""
newwav=''
newmp3=''
# we will be using sys class for now, later we will have to find a way to let the users do it from a web or app
if len(sys.argv) < 2:
    print("input an audio file.\n\nUsage: %s filename.wav or filename.mp3" % sys.argv[0])
    sys.exit(-1)

elif sys.argv[1].find("wav")!=-1: #if the file inputed is a wav file convert to mp3 @author: Moulid Ahmed
    wavefile=sys.argv[1]
    exchange=AudioSegment.from_wav(wavefile)
    newmp3=wavefile[:len(wavefile)-4]+".mp3"
    exchange.export(newmp3,format="mp3")

elif sys.argv[1].find("mp3")!=-1: #if the file inputed is a mp3 file convert to mp3 @author: Moulid Ahmed
    mp3file=sys.argv[1]
    exchange=AudioSegment.from_mp3(mp3file)
    newwav=mp3file[:len(mp3file)-4]+".wav"
    exchange.export(newwav,format="wav")
    play(newwav)
    #do stuff with mp3file
