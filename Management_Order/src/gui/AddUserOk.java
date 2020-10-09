package gui;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddUserOk implements ActionListener
{

	public JFrame frmOrderManagement;
	public AddUserOk(String user, String functia) 
	{
		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 277, 175);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel username = new JLabel(user);
		username.setFont(new Font("Courier New", Font.BOLD, 14));
		username.setHorizontalAlignment(SwingConstants.LEFT);
		username.setBounds(100, 11, 302, 17);
		frmOrderManagement.getContentPane().add(username);
		
		JLabel functie = new JLabel(functia);
		functie.setFont(new Font("Courier New", Font.BOLD, 14));
		functie.setHorizontalAlignment(SwingConstants.LEFT);
		functie.setBounds(100, 39, 302, 17);
		frmOrderManagement.getContentPane().add(functie);
		
		JLabel lblAFostAdaugat = new JLabel("Username: ");
		lblAFostAdaugat.setFont(new Font("Courier New", Font.BOLD, 14));
		lblAFostAdaugat.setHorizontalAlignment(SwingConstants.LEFT);
		lblAFostAdaugat.setBounds(10, 11, 80, 17);
		frmOrderManagement.getContentPane().add(lblAFostAdaugat);
		
		JButton ok = new JButton("OK");
		ok.setFont(new Font("Courier New", Font.BOLD, 13));
		ok.setBounds(10, 95, 80, 34);
		frmOrderManagement.getContentPane().add(ok);
		ok.addActionListener(this);
		
		JLabel lblFunction = new JLabel("Function:");
		lblFunction.setHorizontalAlignment(SwingConstants.LEFT);
		lblFunction.setFont(new Font("Courier New", Font.BOLD, 14));
		lblFunction.setBounds(10, 40, 80, 17);
		frmOrderManagement.getContentPane().add(lblFunction);
		
		JLabel lblSuccesfullyAdded = new JLabel("Succesfully added!");
		lblSuccesfullyAdded.setForeground(new Color(0, 153, 0));
		lblSuccesfullyAdded.setFocusTraversalPolicyProvider(true);
		lblSuccesfullyAdded.setHorizontalAlignment(SwingConstants.LEFT);
		lblSuccesfullyAdded.setFont(new Font("Courier New", Font.BOLD, 14));
		lblSuccesfullyAdded.setBounds(10, 67, 392, 17);
		frmOrderManagement.getContentPane().add(lblSuccesfullyAdded);
	}


	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand()=="OK")
		{
			gui.LogedManager window = new gui.LogedManager(); 
			window.frmOrderManagement.setVisible(true);

			this.frmOrderManagement.dispose();
		}	
	}
}
