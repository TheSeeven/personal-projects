package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import app.User;

import java.awt.Font;


import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ModifyuserOk implements ActionListener
{
	public JFrame frmOrderManagement;
	private JTextField textField;
	private JPasswordField passwordField_1;
	private JPasswordField passwordField_2;
	private JTextField textField_1;
	private static String name2;

	public ModifyuserOk(String name) 
	{	
		name2=name;
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 515, 273);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Modify User");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(159, 11, 160, 48);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel(name);
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(10, 67, 120, 20);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewPass = new JLabel("New Password: ");
		lblNewPass.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewPass.setBounds(10, 98, 120, 20);
		frmOrderManagement.getContentPane().add(lblNewPass);
		
		JLabel lblNewLabel_2 = new JLabel("---------------------->");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2.setBounds(140, 70, 107, 14);
		frmOrderManagement.getContentPane().add(lblNewLabel_2);
		
		JLabel label_2 = new JLabel("---------------------->");
		label_2.setHorizontalAlignment(SwingConstants.CENTER);
		label_2.setBounds(140, 101, 107, 14);
		frmOrderManagement.getContentPane().add(label_2);
		
		textField = new JTextField();
		textField.setBounds(257, 68, 227, 17);
		frmOrderManagement.getContentPane().add(textField);
		textField.setColumns(10);
		
		JLabel lblRetypeNewPass = new JLabel("Re-type password: ");
		lblRetypeNewPass.setHorizontalAlignment(SwingConstants.CENTER);
		lblRetypeNewPass.setBounds(10, 129, 120, 20);
		frmOrderManagement.getContentPane().add(lblRetypeNewPass);
		
		JLabel label = new JLabel("---------------------->");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setBounds(140, 132, 107, 14);
		frmOrderManagement.getContentPane().add(label);
		
		passwordField_1 = new JPasswordField();
		passwordField_1.setBounds(257, 99, 227, 17);
		frmOrderManagement.getContentPane().add(passwordField_1);
		
		passwordField_2 = new JPasswordField();
		passwordField_2.setBounds(257, 130, 227, 17);
		frmOrderManagement.getContentPane().add(passwordField_2);
		
		JLabel label_3 = new JLabel("---------------------->");
		label_3.setHorizontalAlignment(SwingConstants.CENTER);
		label_3.setBounds(140, 163, 107, 14);
		frmOrderManagement.getContentPane().add(label_3);
		
		JLabel lblFunction = new JLabel(User.get_functie(name));
		lblFunction.setHorizontalAlignment(SwingConstants.CENTER);
		lblFunction.setBounds(10, 160, 120, 20);
		frmOrderManagement.getContentPane().add(lblFunction);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(257, 161, 227, 17);
		frmOrderManagement.getContentPane().add(textField_1);
		
		JButton modify = new JButton("Modify");
		modify.setBounds(10, 191, 120, 42);
		modify.setFont(new Font("Courier New", Font.BOLD, 14));
		frmOrderManagement.getContentPane().add(modify);
		modify.addActionListener(this);
		
		JButton menu = new JButton("Menu");
		menu.setFont(new Font("Courier New", Font.BOLD, 14));
		menu.setBounds(364, 189, 120, 42);
		frmOrderManagement.getContentPane().add(menu);
		menu.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand()=="Modify")
		{
			if (app.Functions.get_String(passwordField_1.getPassword()).equals(app.Functions.get_String(passwordField_2.getPassword()))) 
			{
				if (app.Functions.get_String(passwordField_1.getPassword()).equals(app.Functions.get_String(passwordField_2.getPassword()))
						&& app.Functions.good_password(passwordField_1.getPassword())) 		
				{
					app.User x = new app.User(textField.getText(),textField_1.getText(),app.Functions.get_String(passwordField_1.getPassword()));
					User.remove(name2);
					x.add();
					MessageBox pMessageBox = new MessageBox("Utilizatorul a fost modificat cu succes!");
					pMessageBox.frmOrderManagement.setVisible(true);
				}

				else
				{
					MessageBox pMessageBox = new MessageBox("Parola nu corespunde cerintelor!");
					pMessageBox.frmOrderManagement.setVisible(true);
				}
			}
			else
			{
				MessageBox pMessageBox = new MessageBox("Parolele nu sunt identice!");
				pMessageBox.frmOrderManagement.setVisible(true);
			}
		}

		else if(e.getActionCommand()=="Menu")
		{
			LogedManager window = new LogedManager();
			window.frmOrderManagement.setVisible(true);
				
			this.frmOrderManagement.dispose();
		}

	}
}
