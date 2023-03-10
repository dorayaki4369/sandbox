import wave
from pylab import *

if __name__ == '__main__':
    wf = wave.open("2U.wav", "rb")
    data = wf.readframes(wf.getnframes())
    data = frombuffer(data, dtype="int16")
    length = float(wf.getnframes()) / wf.getframerate()  # 波形長さ(秒)

    # FFTのサンプル数
    N = 512

    # FFTで用いるハミング窓
    hammingWindow = np.hamming(N)

    # スペクトログラムを描画
    pxx, freqs, bins, im = specgram(data, NFFT=N, Fs=wf.getframerate(), noverlap=0, window=hammingWindow)
    axis([0, length, 0, wf.getframerate() / 2])
    xlabel("time [second]")
    ylabel("frequency [Hz]")

    show()
