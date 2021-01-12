library("rgl") # install.packages("rgl") # se nao tiver instalado
source("matrizes-funcoes.R")

# desenha um bbox com os rotulos das coordenadas x,y,z
desenharExemploOrto()

# cria um vetor para um vertice com coordenadas homogeneas (x,y,z,w=1)
v <- rbind(x=50,y=100,z=0,w=1)  
print(v)

# desenha o vertice dentro do bbox em formato de 'cubo 3d'. Note que o R espera um vetor 'linha',
# por isso foi feita a transposicao
desenharPonto3D(v, color="red", size=10) 


# Ex: aplique outras transformacoes
#Mt = matrizTranslacao(100, 0, 0)
#vt = Mt %*% v
#print(vt)
#desenharPonto3D(vt, color="orange", size=10) 


# O que o OpenGL faz: aplica transformacao de projecao no ponto
MPo = matrizProjOrto()
vt = MPo %*% v # operador %*% multiplicacao de matriz
print(vt)

# dividindo por w
print("Dividindo por w pra ver onde ele apareceria na tela: ")
print(vt/vt[4,1])

# plotando tela 2D simulada pra conferir
desenharTelaSimulada()
desenharPontosTelaSimulada(vt, col="red")



