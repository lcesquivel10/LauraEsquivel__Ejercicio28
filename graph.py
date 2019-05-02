import matplotlib
import matplotlib.pyplot as plt
from matplotlib.colors import BoundaryNorm
from matplotlib.ticker import MaxNLocator
import numpy as np
f=open("datos.dat","r")
steps=200
x=np.array(list(map(float,f.readline().strip().split())))
t=np.array(list(map(float,f.readline().strip().split())))
T=[]
for i in range(steps):
    T.append(np.array(list(map(float,f.readline().strip().split()))))
T=np.array(T)


levels = MaxNLocator(nbins=15).tick_values(200, 500)



cmap = plt.get_cmap('inferno')
norm = BoundaryNorm(levels, ncolors=cmap.N, clip=True)

fig, ax0 = plt.subplots(nrows=1)

im = ax0.pcolormesh(x,t, T, cmap=cmap, norm=norm)
fig.colorbar(im, ax=ax0)
ax0.set_title('Temperatura')

ax0.set_ylabel("tiempo")
ax0.set_xlabel("Largo de la barra")


fig.tight_layout()
plt.savefig("Temperatura1.pdf")

fig, ax0 = plt.subplots(nrows=1)

T1=[[0 for i in range(steps)] for j in range(steps)]
for i in range(steps):
    for j in range(steps):
        T1[i][j]=T[j][i]
for i in range(steps):
    T1[i]=np.array(T1[i])
T1=np.array(T1)
ax0.plot(x,t,T1)

ax0.set_ylim(200,600)

fig.tight_layout()
ax0.set_ylabel("tempertura")
ax0.set_xlabel("tiempo")

plt.savefig("Temperatura2.pdf")
