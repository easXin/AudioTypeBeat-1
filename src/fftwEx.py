import pyfftw
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np

a = pyfftw.empty_aligned(128, dtype='complex128')
b = pyfftw.empty_aligned(128, dtype='complex128')
f = pyfftw.empty_aligned(4, dtype='complex128')


rate, data = wav.read('voice.wav')
fft_out = fft(data)

# %matplotlib inline
plt.plot(data, np.abs(fft_out))
plt.show()
