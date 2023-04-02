package view;

import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JPanel;

import controller.TitleController;

public class TitleWindowPanel extends JPanel{
	BasePanel basePanel;
	public TitleWindowPanel(BasePanel basePanel) {
		this.basePanel = basePanel;
		this.setPreferredSize(new Dimension(1000, 800));
		this.setBackground(Color.black);
		this.setVisible(true);

		TitleController controller = new TitleController(basePanel);
		this.addKeyListener(controller);
	}
}
