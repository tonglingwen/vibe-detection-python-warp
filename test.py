from vibe import *
import numpy as np
import cv2
import time




cap = cv2.VideoCapture("./sequence.mp4")
ret, frame = cap.read()
initializevibe(frame.shape[0],frame.shape[1])
frame=cv2.cvtColor(frame,cv2.COLOR_RGB2GRAY)
vibe(frame)

while ret:
    ret, frame = cap.read()
    frame=cv2.cvtColor(frame,cv2.COLOR_RGB2GRAY)
    res=vibe(frame)
    cv2.imshow("vibe",res)