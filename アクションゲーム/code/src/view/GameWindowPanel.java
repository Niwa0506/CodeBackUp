package view;

import java.awt.Dimension;

import javax.swing.JPanel;

import controller.GameController;

public class GameWindowPanel extends JPanel{
	public GameWindowPanel(BasePanel basePanel) {
		this.setPreferredSize(new Dimension(1000, 800));
		this.add(new GamePanel(basePanel));

		GameController controller = new GameController();
		this.addKeyListener(controller);
	}
}
