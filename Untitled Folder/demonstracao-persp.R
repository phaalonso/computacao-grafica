library("rgl")
source("matrizes-funcoes.R")

desenharExemploPersp()                  # desenha simulacao de viewing frustum da aula
v1 <- rbind(x=0,y=10,z=-80,w=1)           # coordenadas homogeneas (x,y,z,w=1)

desenharPonto3D(v1, color="red", size=10)

# O que o OpenGL faz:
MPp = matrizProjPersp()
vp1 = MPp %*% v1
print(vp1)


print("Onde apareceria: ")
print(vp1/vp1[4,1])

desenharTelaSimulada()
desenharPontosTelaSimulada(vp1/vp1[4,1], col="red")



