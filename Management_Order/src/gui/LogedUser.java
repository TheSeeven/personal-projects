package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LogedUser extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	public JFrame frmOrderManagement;

	public LogedUser() 
	{
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.getContentPane().setFont(new Font("Courier New", Font.BOLD, 14));
		frmOrderManagement.setBounds(100, 100, 460, 380);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel username = new JLabel(Data.username);
		username.setFont(new Font("Courier New", Font.BOLD, 14));
		username.setHorizontalAlignment(SwingConstants.CENTER);
		username.setLabelFor(frmOrderManagement);
		username.setBounds(10, 23, 184, 50);
		frmOrderManagement.getContentPane().add(username);
		
		JLabel label = new JLabel("-----");
		label.setFont(new Font("Courier New", Font.BOLD, 14));
		label.setBounds(204, 23, 25, 50);
		frmOrderManagement.getContentPane().add(label);
		
		JLabel functie = new JLabel(Data.functie);
		functie.setHorizontalAlignment(SwingConstants.CENTER);
		functie.setFont(new Font("Courier New", Font.BOLD, 14));
		functie.setBounds(239, 23, 195, 50);
		frmOrderManagement.getContentPane().add(functie);
		
		JButton addorder = new JButton("Add order");
		addorder.setFont(new Font("Courier New", Font.BOLD, 14));
		addorder.setBounds(10, 84, 424, 41);
		frmOrderManagement.getContentPane().add(addorder);
		addorder.addActionListener(this);
		
		JButton completeorder = new JButton("Complete order");
		completeorder.setFont(new Font("Courier New", Font.BOLD, 14));
		completeorder.setBounds(10, 136, 424, 41);
		frmOrderManagement.getContentPane().add(completeorder);
		completeorder.addActionListener(this);
		
		JButton vieworder = new JButton("View Orders");
		vieworder.setFont(new Font("Courier New", Font.BOLD, 14));
		vieworder.setBounds(10, 188, 424, 41);
		frmOrderManagement.getContentPane().add(vieworder);
		vieworder.addActionListener(this);
		
		JButton viewhistory = new JButton("View History (current user)");
		viewhistory.setFont(new Font("Courier New", Font.BOLD, 14));
		viewhistory.setBounds(10, 240, 424, 41);
		frmOrderManagement.getContentPane().add(viewhistory);
		viewhistory.addActionListener(this);
		
		JButton signout = new JButton("Sign out");
		signout.setForeground(Color.RED);
		signout.setFont(new Font("Courier New", Font.BOLD, 14));
		signout.setBounds(10, 290, 424, 41);
		frmOrderManagement.getContentPane().add(signout);
		signout.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand() == "Sign out") // ok
		{
			login x = new login();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Complete order") // ok
		{
			CompleteOrder x = new CompleteOrder();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "Add order") // ok
		{
			AddOrder x = new AddOrder();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "View Orders")
		{
			ModifyBuffer x = new ModifyBuffer();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
		else if(e.getActionCommand() == "View History (current user)")
		{
			History x = new History();
			x.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}
	}
}
