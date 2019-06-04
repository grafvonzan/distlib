import matplotlib.pyplot as plt
import numpy as np

#get input data
file_pipe = open("histScriptIn.dat", "r")

dataSet = []

for line in file_pipe:
	dataSet.append(float(line))
	
#straight outta an internet tutorial

n, bins, patches = plt.hist(x=dataSet, bins='auto', color = '#71eeb8', alpha = 0.7, rwidth = 0.85)

plt.grid(axis = 'y', alpha = 0.75)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Distribution Visualization')
plt.text(23, 45, r'$\mu=15, b=3$')
maxfreq = n.max()
plt.ylim(ymax=np.ceil(maxfreq / 10) * 10 if maxfreq % 10 else maxfreq + 10)
plt.xlim(-100, 100)

plt.savefig("histScriptOut.png")
