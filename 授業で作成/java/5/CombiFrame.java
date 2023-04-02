import java.awt.*;
import javax.swing.*;

class CombiFrame extends JFrame {
  public CombiFrame(){
    JPanel  p1=new JPanel(),p2=new JPanel();
    JButton b1=new JButton("1"),b2=new JButton("2");
    JButton b3=new JButton("3"),b4=new JButton("4");
    JButton b5=new JButton("5"),b6=new JButton("6");
    JButton b7=new JButton("7"),b8=new JButton("8");
    JButton b9=new JButton("9"),b10=new JButton("10");
    JButton b11=new JButton("11"),b12=new JButton("12");
    JButton b13=new JButton("13"),b14=new JButton("14");
    JButton b15=new JButton("15");
    JTextArea t=new JTextArea(10,20);
    this.setTitle("Panel Combination");
    p1.setLayout(new GridLayout(1,10));
    p2.setLayout(new GridLayout(5,1));
    p1.add(b1); p1.add(b2); p1.add(b3);p1.add(b4);p1.add(b5);
    p1.add(b6);p1.add(b7);p1.add(b8);p1.add(b9);p1.add(b10);
    p2.add(b11); p2.add(b12);p2.add(b13);p2.add(b14);p2.add(b15);
    this.add(p1,BorderLayout.NORTH);
    this.add(p2,BorderLayout.WEST);
    this.add(t,BorderLayout.CENTER);
    this.pack(); 
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    this.setVisible(true);
  }
  public static void main(String argv[]) {
    new CombiFrame();
  }
}
