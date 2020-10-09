package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.ComponentOrientation;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ViewOrders implements ActionListener
{
	public JFrame frmOrderManagement;

	public ViewOrders(String text,String title) 
	{
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.getContentPane().setFont(new Font("Courier New", Font.BOLD, 14));
		frmOrderManagement.setBounds(100, 100, 450, 500);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JTextArea txtrLoremIpsumIs = new JTextArea();
		txtrLoremIpsumIs.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
		txtrLoremIpsumIs.setWrapStyleWord(true);
		txtrLoremIpsumIs.setText(text);
		txtrLoremIpsumIs.setEditable(false);
		txtrLoremIpsumIs.setRequestFocusEnabled(false);
		txtrLoremIpsumIs.setLineWrap(true);
		txtrLoremIpsumIs.setBounds(10, 65, 424, 335);
		frmOrderManagement.getContentPane().add(txtrLoremIpsumIs);
		
		JLabel lblNewLabel = new JLabel(title);
		lblNewLabel.setForeground(Color.GREEN);
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(10, 11, 424, 54);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JButton btnNewButton = new JButton("OK");
		btnNewButton.setBounds(168, 400, 119, 44);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand()=="OK")
		{
			if(Data.functie.toUpperCase().equals("MANAGER"))
			{
				LogedManager x = new LogedManager();
				x.frmOrderManagement.setVisible(true);

				this.frmOrderManagement.dispose();
			}
			else
			{
				LogedUser x = new LogedUser();
				x.frmOrderManagement.setVisible(true);

				this.frmOrderManagement.dispose();
			}
		}
	}
}
