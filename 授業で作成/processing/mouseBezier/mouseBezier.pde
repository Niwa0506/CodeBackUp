int npoints = 100,n = 0;
int[] x = new int[npoints],y = new int[npoints];
void setup(){
  size(600,600);
  background(255);
  fill(0);
  smooth();
}

void draw(){}

void mouseClicked(){
  update(mouseX, mouseY);
}

void update(int p,int q){
  if(mouseButton == LEFT){
    if(n == npoints){
      n = 0;
      background(255);
    }
    if(n%3==1&&n>3){x[n]=x[n-1]+(x[n-1]-x[n-2]);y[n]=y[n-1]+(y[n-1]-y[n-2]);}
    else{x[n] = p;y[n] = q;}
      noStroke();
      fill(255,0,0);
      ellipse(x[n],y[n],5,5);
      if(n!=0){
        stroke(200);
        line(x[n-1],y[n-1],x[n],y[n]);
        if(n%3==0&&n>0){
          stroke(0,0,255);
          noFill();
          bezier(x[n-3],y[n-3],(x[n-2]+x[n-3])/2,
                  (y[n-2]+y[n-3])/2,(x[n-1]+x[n])/2,(y[n-1]+y[n])/2,x[n],y[n]);
        } 
      }
      n++;
  }
  else if(mouseButton == RIGHT){
    n=0;
    background(255);
  }
}
