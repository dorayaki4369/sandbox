import numpy as np
import librosa
import librosa.display as display

music = librosa.load("sm24084897_ラスボス神社４.mp4.mp3")
display.waveplot(music[0], sr=22050)
