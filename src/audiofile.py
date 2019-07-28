import scipy.io
import scipy.io.wavfile
import random
import sys
import numpy as np

if len(sys.argv) < 2:
    print("input a wav file.\n\nUsage: %s filename.wav" % sys.argv[0])
    sys.exit(-1)
else:
    filename=sys.argv[1]
    rate, data = scipy.io.wavfile.read(filename)
    # print(len(data))
    print(len(data))
    #I Want to make a random number array into a wav file and see what it Plays
    # for i in range(len(data)-10000):
    #     # index=random.randrange(10,int(len(data)))
    #     # print(index)
    # while 0 in data:
    #     data=np.delete(data,0,0)
    # for i in range(0,len(data)-1):
    #     if data[i]!=0:
    #         ran=random.randrange(-90,10000)
    #         data[i]=ran
    # data=data.tolist()
    # print(data)
    # # while 0 in data:
    # #     data.remove(0)
    # # data[0]=0
    # data=np.asarray(data)
    # print(data)

    print((data))
    scipy.io.wavfile.write('random.wav',rate,data)
    print((data[110]))
