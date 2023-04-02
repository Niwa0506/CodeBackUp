package view;

import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class BaseFrame extends JFrame{
	public static final int FRAME_WIDTH = 1000;
	public static final int FRAME_HEIGHT = 800;

	public BaseFrame() {
		JPanel base = new BasePanel();
		this.setBackground(Color.black);
	    this.setTitle("Social Distance");
	    this.setSize(FRAME_WIDTH, FRAME_HEIGHT);
	    this.setResizable(false);
	    this.add(base);
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    this.setVisible(true);
	}
}
