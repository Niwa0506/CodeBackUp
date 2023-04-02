import javax.swing.JFrame;
public class NewFrame2 extends JFrame{
	public NewFrame2(){
	      this.setTitle("NewFrame");
	      this.setSize(300,200);
	      this.setVisible(true);
	}
	
	public static void main(String argv[]) {
	      new NewFrame2();  // NewFrameオブジェクトを生成します．生成すると，
	                       // コンストラクタ内の処理が自動的に実行されます．
	}
}
