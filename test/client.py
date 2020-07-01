#!/usr/bin/env python3
import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("0.0.0.0", 9999))
closed = 0
while (closed == 0):
    message = input("Enter message you want to send : ")
    if (message == "XYZ"): closed = 1
    else: 
        try:
            sock.send(bytes(message * 1000, 'ascii'))
        except:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.connect(("0.0.0.0", 9999))
            sock.send(bytes(message * 1000, 'ascii'))
sock.close()