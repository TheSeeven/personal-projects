package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import app.User;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ModifyUser implements ActionListener {

	public JFrame frmOrderManagement;
	private JTextField textField;

	public ModifyUser() {

		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 400, 190);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Modify User");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(100, 11, 165, 52);
		frmOrderManagement.getContentPane().add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("Name: ");
		lblNewLabel_1.setFont(new Font("Courier New", Font.BOLD, 12));
		lblNewLabel_1.setBounds(10, 84, 55, 14);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);

		textField = new JTextField();
		textField.setBounds(75, 80, 293, 20);
		frmOrderManagement.getContentPane().add(textField);
		textField.setColumns(10);

		JButton btnNewButton = new JButton("Modify");
		btnNewButton.setBounds(10, 123, 89, 23);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);

		JButton btnNewButton_1 = new JButton("Menu");
		btnNewButton_1.setBounds(281, 123, 89, 23);
		frmOrderManagement.getContentPane().add(btnNewButton_1);
		btnNewButton_1.addActionListener(this);

		JButton btnRemove = new JButton("Remove");
		btnRemove.setBounds(147, 123, 89, 23);
		frmOrderManagement.getContentPane().add(btnRemove);
		btnRemove.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "Modify") 
		{
				if (User.find(textField.getText())) 
				{
					ModifyuserOk modifyuserOk = new ModifyuserOk(textField.getText());
					modifyuserOk.frmOrderManagement.setVisible(true);

					this.frmOrderManagement.dispose();
				}
				else if(!User.find(textField.getText()))
				{	
					MessageBox x = new MessageBox(textField.getText() + " Nu exista!");
					x.frmOrderManagement.setVisible(true);
				}
		} 
		else if (e.getActionCommand() == "Menu") 
			{
				if(Data.functie.toUpperCase() == "MANAGER")
				{
					LogedManager logedManager = new LogedManager();
					logedManager.frmOrderManagement.setVisible(true);

					this.frmOrderManagement.dispose();
				}
				else
				{
					LogedUser logedUser = new LogedUser();
					logedUser.frmOrderManagement.setVisible(true);

					this.frmOrderManagement.dispose();
				}
			} 
		else if (e.getActionCommand() == "Remove") 
		{	
			if(!User.find(textField.getText()))
			{
				MessageBox x = new MessageBox(textField.getText() + " Nu exista!");
				x.frmOrderManagement.setVisible(true);	
			}

			if(User.find(textField.getText()))
			{
				User.remove(textField.getText());
				MessageBox x = new MessageBox(textField.getText() + " A fost eliminat!");
				x.frmOrderManagement.setVisible(true);
			}

			
		}
	}
}
