import numpy as np
import matplotlib.pyplot as plt

dataCRC = np.loadtxt("CircuitoRC.txt")
t = dataCRC[:,0]
Q = dataCRC[:,1]

varianzQ = np.var(Q)
print varianzQ #Se saca la varianza para modificar el likelihood y que funcione adecuadamente, segun la formula que esta en el notebook.



def likelihood(Q, Qmodel):
    chi_squared = (1.0/2.0)*sum(((Q-Qmodel)/varianzQ)**2)
    return np.exp(-chi_squared)

def funcionCarga(t, R, C):
    return (10*C)*(1 - np.exp(-t/(R*C)))

Rwalk = np.empty((0))
Cwalk = np.empty((0))
lwalk = np.empty((0))

Rwalk = np.append(Rwalk, np.random.random())
Cwalk = np.append(Cwalk, np.random.random())

Qinit = funcionCarga(t, Rwalk[0], Cwalk[0])
lwalk = np.append(lwalk, likelihood(Q, Qinit))


it = 20000
#this is the number of iterations I want to make
for i in range(it):
    Rprime = np.random.normal(Rwalk[i], 0.1) 
    Cprime = np.random.normal(Cwalk[i], 0.1)

    Qinit = funcionCarga(t, Rwalk[i], Cwalk[i])
    Qprime = funcionCarga(t, Rprime, Cprime)
    
    lprime = likelihood(Q, Qprime)
    linit = likelihood(Q, Qinit)
    
    alpha = lprime/linit
    if(alpha>=1.0):
        Rwalk  = np.append(Rwalk,Rprime)
        Cwalk  = np.append(Cwalk,Cprime)
        lwalk = np.append(lwalk, lprime)
    else:
        beta = np.random.random()
        if(beta<=alpha):
            Rwalk = np.append(Rwalk,Rprime)
            Cwalk = np.append(Cwalk,Cprime)
            lwalk = np.append(lwalk, lprime)
        else:
            Rwalk = np.append(Rwalk,Rwalk[i])
            Cwalk = np.append(Cwalk,Cwalk[i])
            lwalk = np.append(lwalk, linit)
            
#Guardar figura de resistecia vs capacitancia
plt.scatter(Rwalk, Cwalk)
plt.xlabel("$Resistencia$")
plt.ylabel("$Capacitancia$")
plt.savefig("RC1.png")
plt.close()

#Guardar figura de verosimilutd
plt.scatter(Rwalk, -np.log(lwalk))
plt.xlabel("$Resistencia$")
plt.ylabel("$Likehood$")
plt.savefig("RC2.png")
plt.close()

#Guardar figura de verosimilutd
plt.scatter(Cwalk, -np.log(lwalk))
plt.xlabel("$Capacitancia$")
plt.ylabel("$Likehood$")
plt.savefig("RC3.png")
plt.close()

#guardar grafica de variacion de los parametros
minR = np.amin(Rwalk)
maxR = np.amax(Rwalk)
minC = np.amin(Cwalk)
maxC = np.amax(Cwalk)
gridR, gridC = np.mgrid[minR:maxC:200j, minR:maxC:200j]
from scipy.interpolate import griddata
n_points = np.size(Rwalk)
points = np.ones((n_points,2))
print np.shape(points)
points[:,0] = Rwalk
points[:,1] = Cwalk
grid_l = griddata(points, -np.log(lwalk), (gridR, gridC), method='cubic')
plt.imshow(grid_l.T, extent=(minR,maxR,minC,maxC), aspect='auto',origin='lower')
plt.colorbar()
plt.savefig("RC4.png")
plt.close()

#guardar histograma resistencia
count, bins, ignored =plt.hist(Rwalk, 20, normed=True)
plt.xlabel("Resistencia")
plt.savefig("RC5.png")
plt.close()

#guardar histograma de capacitancia
count, bins, ignored =plt.hist(Cwalk, 20, normed=True)
plt.xlabel("Capacitancia")
plt.savefig("RC6.png")

