package view;

import java.awt.Dimension;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JPanel;

import model.game.GameManager;

public class BasePanel extends JPanel implements Observer{
	public static final int TITLE_WINDOW_ID = 0;
	public static final int GAME_WINDOW_ID = 1;
	private JPanel currentPanel;
	private JPanel titleWindowPanel;
	private JPanel gameWindowPanel;

	public BasePanel() {
		this.setPreferredSize(new Dimension(BaseFrame.FRAME_WIDTH, BaseFrame.FRAME_HEIGHT));
		this.titleWindowPanel = new TitleWindowPanel(this);
		this.gameWindowPanel = new GameWindowPanel(this);
		switchWindow(TITLE_WINDOW_ID);

		//テスト用
		GameManager.getInstance().getGame().getScoreTime().addObserver(this);
		GameManager.getInstance().getGame().getCharacterManager().getHealthyNPCCount().addObserver(this);
	}

	public void switchWindow(int windowId) {
		switch(windowId) {
		case 0:
			currentPanel = this.titleWindowPanel;
			break;
		case 1:
			currentPanel = this.gameWindowPanel;
			break;
		default:
			return;
		}
		this.removeAll();
		this.add(currentPanel);
		currentPanel.setFocusable(true);
		currentPanel.requestFocusInWindow();
		validate();
		repaint();
	}

	//テスト用
	@Override
	public void update(Observable o, Object arg) {
		/*
		HealthyNPCCount count = GameManager.getInstance().getGame().getCharacterManager().getHealthyNPCCount();
		System.out.println("非感染者残り: " + count.getValue() + "人");

		ScoreTime scoreTime = GameManager.getInstance().getGame().getScoreTime();
		System.out.println(scoreTime.getMinute() + "分 " + scoreTime.getSecond() + "秒");
		*/

	}
}
