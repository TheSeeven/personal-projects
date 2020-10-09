package gui;

import javax.swing.JFrame;
import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class LogedManager extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	public JFrame frmOrderManagement;
	private JLabel label_3 = new JLabel();


	public LogedManager() 
	{
		label_3 = new JLabel(Data.username);
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 460, 500);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		label_3.setBounds(20, 23, 168, 50);
		frmOrderManagement.getContentPane().add(label_3);
		label_3.setHorizontalAlignment(SwingConstants.CENTER);
		label_3.setFont(new Font("Courier New", Font.BOLD, 14));
		
		JLabel label_4 = new JLabel("-----");
		label_4.setFont(new Font("Courier New", Font.BOLD, 14));
		label_4.setBounds(198, 23, 25, 50);
		frmOrderManagement.getContentPane().add(label_4);
		
		JLabel label_5 = new JLabel(Data.functie);
		label_5.setHorizontalAlignment(SwingConstants.CENTER);
		label_5.setFont(new Font("Courier New", Font.BOLD, 14));
		label_5.setBounds(233, 23, 201, 50);
		frmOrderManagement.getContentPane().add(label_5);
		
		JButton button_8 = new JButton("Add order");
		button_8.setFont(new Font("Courier New", Font.BOLD, 14));
		button_8.setBounds(10, 84, 424, 41);
		frmOrderManagement.getContentPane().add(button_8);
		button_8.addActionListener(this);
		
		JButton button_9 = new JButton("Complete order");
		button_9.setFont(new Font("Courier New", Font.BOLD, 14));
		button_9.setBounds(10, 136, 424, 41);
		frmOrderManagement.getContentPane().add(button_9);
		button_9.addActionListener(this);

		JButton button_11 = new JButton("View Orders");
		button_11.setFont(new Font("Courier New", Font.BOLD, 14));
		button_11.setBounds(10, 188, 424, 41);
		frmOrderManagement.getContentPane().add(button_11);
		button_11.addActionListener(this);
		
		JButton btnViewHistory = new JButton("View History");
		btnViewHistory.setFont(new Font("Courier New", Font.BOLD, 14));
		btnViewHistory.setBounds(10, 240, 424, 41);
		frmOrderManagement.getContentPane().add(btnViewHistory);
		btnViewHistory.addActionListener(this);
		
		JButton btnAddNewUser = new JButton("Add new user");
		btnAddNewUser.setFont(new Font("Courier New", Font.BOLD, 14));
		btnAddNewUser.setBounds(10, 292, 424, 41);
		frmOrderManagement.getContentPane().add(btnAddNewUser);
		btnAddNewUser.addActionListener(this);
		
		JButton btnModifyCurrentUser = new JButton("Modify user");
		btnModifyCurrentUser.setFont(new Font("Courier New", Font.BOLD, 14));
		btnModifyCurrentUser.setBounds(10, 344, 424, 41);
		frmOrderManagement.getContentPane().add(btnModifyCurrentUser);
		btnModifyCurrentUser.addActionListener(this);

		JButton button_7 = new JButton("Sign out");
		button_7.setForeground(Color.RED);
		button_7.setFont(new Font("Courier New", Font.BOLD, 14));
		button_7.setBounds(10, 396, 424, 41);
		frmOrderManagement.getContentPane().add(button_7);
		button_7.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand() == "Sign out")
		{
			login x = new login();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Complete order")
		{
			CompleteOrder x = new CompleteOrder();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Add new user")
		{
			AddUser x = new AddUser();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Add order")
		{
			AddOrder x = new AddOrder();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Modify user")
		{
			ModifyUser x = new ModifyUser();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "View Orders")
		{
			ModifyBuffer x = new ModifyBuffer();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "View History")
		{
			History x = new History();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
	}
}
