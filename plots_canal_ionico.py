import numpy as np
import matplotlib.pyplot as plt

dataCI= np.loadtxt("canal_ionico.txt")
dataCI1= np.loadtxt("canal_ionico1.txt")
CanalIonicoDat = np.loadtxt("CID.txt")
CanalIonico1Dat = np.loadtxt("CID1.txt")
CanalIonico1DatBuenos = np.loadtxt("datosci1.txt")



x = dataCI[:,0]
y = dataCI[:,1]
xi = CanalIonico1Dat[:,0]
yi = CanalIonico1Dat[:,1]
r = CanalIonicoDat[:,2]

radioMaximo = np.amax(r)
posRadMax = np.argmax(r)

xo, yo = xi[posRadMax], yi[posRadMax]

fig, ax = plt.subplots()
plt.scatter(x,y)
plt.title("x = "+ str(round(xo,5)) + "y = " + str(round(yo,5)) +  "r = " + str(round(radioMaximo,5)))
circulo1 = plt.Circle((xo,yo), radioMaximo, color='r')
ax.add_artist(circulo1)
plt.savefig("CI.png")
plt.close()

x1 = dataCI1[:,0]
y1 = dataCI1[:,1]
xi1 = CanalIonico1Dat[:,0]
yi1 = CanalIonico1Dat[:,1]
r1 = CanalIonico1Dat[:,2]


radioMaximo2 = np.amax(r1)
posRadMax1 = np.argmax(r1)

xo1, yo1 = xi1[posRadMax1], yi1[posRadMax1]

fig, ax = plt.subplots()
plt.scatter(x1,y1)
plt.title("x = "+ str(round(xo1,5)) + "y = " + str(round(yo1,5)) +  "r = " + str(round(radioMaximo2,5)))
circulo2 = plt.Circle((xo1,yo1), radioMaximo2, color='r')
ax.add_artist(circulo2)
plt.savefig("CI1.png")
plt.close()

x1 = dataCI1[:,0]
y1 = dataCI1[:,1]
xi1B = CanalIonico1DatBuenos[:,0]
yi1B = CanalIonico1DatBuenos[:,1]
r1B = CanalIonico1DatBuenos[:,2]

radioMaximo2B = np.amax(r1B)
posRadMax1B = np.argmax(r1B)

xo1B, yo1B = xi1B[posRadMax1B], yi1B[posRadMax1B]

fig, ax = plt.subplots()
plt.title("x = "+ str(round(xo1B,5)) + "y = " + str(round(yo1B,5)) +  "r = " + str(round(radioMaximo2B,5)))
plt.scatter(x1,y1)
circulo2B= plt.Circle((xo1B,yo1B), radioMaximo2B, color='r')
ax.add_artist(circulo2B)
plt.savefig("CI1B.png")
plt.close()

