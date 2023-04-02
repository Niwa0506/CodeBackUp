void setup(){
  size(400, 300, P3D);
  noStroke();
  smooth();
  frameRate(60);
  textFont(createFont("Tempus Sans ITC",24));
}
void draw(){
  background(255);
  translate(width/2,height/2,0);
  rotateX(-PI/8.);
  rotateY(-PI/4.);
  drawAxis('X', color(255, 0, 0));//X-axis:red
  drawAxis('Y', color(0, 255, 0));//Y-axis:green
  drawAxis('Z', color(0, 0, 255));//Z-axis:blue1
}

void drawAxis(char s, color c){
  fill(c);
  pushMatrix();//draw axis
    switch(s){
      case'X': draw_line(200,1,1);break;
      case'Y': draw_line(1,200,1);break;
      case'Z': draw_line(1,1,200);break;
    }
  popMatrix();
  pushMatrix();
    switch(s){
      case'X': translate(100,0,0);break;
      case'Y': translate(0,100,0);break;
      case'Z': translate(0,0,100);break;
    }
    sphere(3);//draw positive axis
    text(s,5,0,0);
  popMatrix();
}

void draw_line(int l,int m,int n){
  for(int i=0;i<l;i++){
    for(int j=0;j<m;j++){
      for(int k = 0;k<n;k++){
         box(l,m,n);
      }
    }
  }
}
