class Tsample2 {
   public static void main(String[] args){
      TurtleFrame f;             // TurtleFrame型の変数 f の宣言
      f =  new TurtleFrame();    // TurtleFrame(表示フレーム)を生成しfに代入
      Turtle m = new Turtle();   // Turtle(亀)を生成し，m の初期値として代入
      int i=0;
      f.add(m); 
      m.up();
      m.rt(90);
      m.fd(40);
      m.rt(90);
      m.down();                 // 亀を下に向けます．(標準状態では上を向いています．
      while(i++<=10){ 
        int k = 0;m.rt(18*3);
         while(k++<=20){
      m.down();
      m.fd(40);                  // 前に 10 進め
      m.lt(18);                 // 左に 18 度回り
      m.fd(20);
      m.up();
      m.rt(72);
      m.fd(40);       
      }         // 前に 5 進め
     }   
   }
 }