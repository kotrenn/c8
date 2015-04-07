import os, sys

C7 = '.c7'
C8 = '.c8'

files = os.listdir('.')
files = filter(lambda x: x[-len(C7):] == C7, files)
files = map(lambda x: x[:-len(C7)], files)
for f in files:
    c7file = f + C7
    c8file = f + C8
    os.system('mv ' + c7file + ' ' + c8file)
