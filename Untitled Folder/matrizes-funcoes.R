# Dica: matriz inversa -> solve(M)

matrizTranslacao<-function(tx=0,ty=0,tz=0){
  Mt=diag(4)
  Mt[1,4]=tx
  Mt[4,4]=ty
  Mt[4,4]=tz
  print(Mt)
  return(Mt)
}

matrizEscala<-function(sx=1,sy=1,sz=1){
  Ms=diag(4)
  Ms[1,1]=sx
  Ms[2,2]=sy
  Ms[3,3]=sz
  print(Ms)
  return(Ms)
}


matrizProjOrto <- function(l=0, r=200, b=0, t=100, n=1, f=-1){
  Po=diag(4)
  
  Po[1,1] = 2 / (r-l)
  Po[2,2] = 2 / (t-b)
  Po[3,3]= -2 / (f-n)
  
  Po[1,4] = - ((r+l) / (r-l))
  Po[2,4] = - ((t+b) / (t-b))
  Po[3,4] = - ((f+n) / (f-n))
  
  
  print(Po) 
  return(Po)
}
 
matrizProjPersp <- function(l=-5, r=5, b=-5, t=5, n=5, f=100){
  Pp=diag(4)
  
  Pp[1,1] = 2*n / (r-l)
  Pp[1,3] = (r+l) / (r-l)
  
  Pp[2,2] = 2*n / (t-b)
  Pp[2,3] = (t+b) / (t-b)
  
  Pp[3,3] = - ((f+n) / (f-n))
  Pp[3,4] = - ((2*f*n) / (f-n))
  
  Pp[4,3] = -1
  Pp[4,4] =  0
  
  print(Pp) 
  return(Pp)
}  


# funcao para retornar transposta de um vertice ou matriz. 
# Obs: essa funcao foi criada apenas pra nao confundir t(v)-> transposto V com t(v)->transformacao(V)
transposto <-function(v){
  return (t(v))
}


desenharPonto3D<-function(v, color="red", size=10){
  shapelist3d(cube3d(), x=transposto(v), size =  size, color =color)
}


desenharExemploPersp <- function(l=-5, r=5, b=-5, t=5, n=5, f=100){
  rgl.open()
  rgl.points(0.0, 0.0, 0.0, col="black", size=5) # observador
  
  # entre o observador e o plano -near
  rgl.lines(c(0, l), c(0, t), c(0, -n), color = 'violetred2', lwd=3) # left, top, -near
  rgl.lines(c(0, l), c(0, b), c(0, -n), color = 'violetred2', lwd=3) # left, bottom, -near
  rgl.lines(c(0, r), c(0, t), c(0, -n), color = 'violetred2', lwd=3) # right, top, -near
  rgl.lines(c(0, r), c(0, b), c(0, -n), color = 'violetred2', lwd=3) # right, bottom, -near
  
  
  # entre plano -near e plano -far (ou seja, entre view face e back face)
  rgl.lines(c(l, f/n*l), c(t, f/n*t), c(-n, -f), color = 'cyan',lwd=2) # left, top, -near
  rgl.lines(c(l, f/n*l), c(b, f/n*b), c(-n, -f), color = 'cyan',lwd=2) # left, bottom, -near
  rgl.lines(c(r, f/n*r), c(t, f/n*t), c(-n, -f), color = 'cyan',lwd=2) # right, top, -near
  rgl.lines(c(r, f/n*r), c(b, f/n*b), c(-n, -f), color = 'cyan',lwd=2) # right, bottom, -near
  
  rgl.bbox(color=c('lightblue', 'lightblue'))
  
}



desenharExemploOrto <- function(){
  xlim=c(200,0)
  ylim=c(100,0)
  zlim=c(100,-100)
  
  rgl.open()
  rgl.lines(xlim, c(0, 0), c(0, 0), color = 'gray')
  rgl.lines(c(0, 0), ylim, c(0, 0), color = 'gray')
  rgl.lines(c(0, 0), c(0, 0), zlim, color = 'gray')
  rgl.bbox(color=c('lightblue', 'lightblue'),
           xat = seq(min(xlim),max(xlim),50))
  
}

desenharTelaSimulada <- function(){
  
  plot.new()
  plot(NA, xlim=c(-1,1), ylim=c(-1,1), xlab="x (ndc)", ylab="y (ndc)", bg="lightgray", 
       main="Simulação de Tela 2D")
  grid(nx=11, ny=11, col="gray")
  
}

desenharPontosTelaSimulada <-function(v, col="red", cex=5){
  
  points(v[1,1], v[2,1], pch=15, col=col, cex=5)  # x, y (z seria o resultado do z buffer)

}


