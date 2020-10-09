package gui;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import java.awt.Font;
import javax.swing.JPasswordField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class login implements ActionListener 
{
	public JFrame frmOrderManagement;

	private JTextField usernameField;
	private JPasswordField passwordField;

	public login() {
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 390, 244);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);

		JButton login_button = new JButton("Login");
		login_button.setFont(new Font("Courier New", Font.BOLD, 14));
		login_button.setBounds(10, 147, 115, 46);
		frmOrderManagement.getContentPane().add(login_button);
		login_button.addActionListener(this);
		login_button.setActionCommand("login");

		JButton exit_button = new JButton("Exit");
		exit_button.setFont(new Font("Courier New", Font.BOLD, 14));
		exit_button.setBounds(227, 147, 115, 46);
		frmOrderManagement.getContentPane().add(exit_button);
		exit_button.addActionListener(this);
		exit_button.setActionCommand("exit");

		JLabel lblNewLabel = new JLabel("Login");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(63, 11, 222, 52);
		frmOrderManagement.getContentPane().add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("Username: ");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblNewLabel_1.setBounds(29, 74, 91, 30);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);

		JLabel lblPassword = new JLabel("Password: ");
		lblPassword.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblPassword.setBounds(29, 106, 91, 30);
		frmOrderManagement.getContentPane().add(lblPassword);

		usernameField = new JTextField();
		usernameField.setBounds(130, 80, 222, 20);
		frmOrderManagement.getContentPane().add(usernameField);
		usernameField.setColumns(10);

		passwordField = new JPasswordField();
		passwordField.setBounds(130, 112, 222, 20);
		frmOrderManagement.getContentPane().add(passwordField);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if (usernameField.getText() != "" && passwordField.getPassword().length != 0
			&& e.getActionCommand() == "login") {
			if (app.Functions.find_user_credentials(usernameField.getText(),
				app.Functions.get_String(passwordField.getPassword())) == 2) {
				Data.username = usernameField.getText();
				Data.functie = "MANAGER";
				gui.LogedManager window = new gui.LogedManager(); // Loged as Manager
				window.frmOrderManagement.setVisible(true);
				this.frmOrderManagement.dispose();}
			else if (app.Functions.find_user_credentials(usernameField.getText(),
				app.Functions.get_String(passwordField.getPassword())) == 1) {
				Data.username = usernameField.getText();
				gui.LogedUser window = new gui.LogedUser(); // Loged as user
				window.frmOrderManagement.setVisible(true);
				this.frmOrderManagement.dispose();}
			else 
			{MessageBox x = new MessageBox("Utilizatorul nu a fost gasit!"); // The User/Manager was not found ->
			x.frmOrderManagement.setVisible(true);}}
		else if(e.getActionCommand()=="exit")
		{System.exit(0);}
	}

}
