package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JRadioButton;
import javax.swing.JComboBox;
import javax.swing.ButtonGroup;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JPasswordField;
import javax.swing.JButton;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddUser extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;

	public JFrame frmOrderManagement;
	private JTextField username;
	private JPasswordField pass2;
	private JPasswordField pass1;
	private JRadioButton male;
	private JRadioButton female;
	private ButtonGroup bg = new ButtonGroup();
	private JComboBox<String> comboBox;

	public AddUser() {
		frmOrderManagement = new JFrame();
		frmOrderManagement.getContentPane().setFont(new Font("Courier New", Font.PLAIN, 12));
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 280, 455);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Add user");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(10, 11, 247, 55);
		frmOrderManagement.getContentPane().add(lblNewLabel);

		username = new JTextField();
		username.setBounds(10, 102, 247, 20);
		frmOrderManagement.getContentPane().add(username);
		username.setColumns(10);

		JLabel lblNewLabel_1 = new JLabel("Username:");
		lblNewLabel_1.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_1.setBounds(10, 77, 247, 14);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);

		JLabel lblJob = new JLabel("Function:");
		lblJob.setHorizontalAlignment(SwingConstants.LEFT);
		lblJob.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblJob.setBounds(10, 133, 247, 14);
		frmOrderManagement.getContentPane().add(lblJob);

		JLabel lblPassword = new JLabel("Password:");
		lblPassword.setHorizontalAlignment(SwingConstants.LEFT);
		lblPassword.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblPassword.setBounds(10, 260, 247, 14);
		frmOrderManagement.getContentPane().add(lblPassword);

		JLabel lblRetypePassword = new JLabel("Re-type Password:");
		lblRetypePassword.setHorizontalAlignment(SwingConstants.LEFT);
		lblRetypePassword.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblRetypePassword.setBounds(10, 316, 247, 14);
		frmOrderManagement.getContentPane().add(lblRetypePassword);

		JLabel lblGender = new JLabel("Gender:");
		lblGender.setHorizontalAlignment(SwingConstants.LEFT);
		lblGender.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblGender.setBounds(10, 189, 247, 14);
		frmOrderManagement.getContentPane().add(lblGender);

		male = new JRadioButton("Male", true);
		male.setBounds(10, 210, 115, 23);
		frmOrderManagement.getContentPane().add(male);
		male.addActionListener(this);

		female = new JRadioButton("Female", true);
		female.setBounds(127, 210, 130, 23);
		frmOrderManagement.getContentPane().add(female);
		female.addActionListener(this);

		comboBox = new JComboBox<String>();
		comboBox.setModel(new DefaultComboBoxModel<String>(new String[] { "User", "Manager" }));
		comboBox.setMaximumRowCount(2);
		comboBox.setBounds(10, 158, 247, 20);
		frmOrderManagement.getContentPane().add(comboBox);

		bg.add(male);
		bg.add(female);

		pass2 = new JPasswordField();
		pass2.setBounds(10, 341, 244, 20);
		frmOrderManagement.getContentPane().add(pass2);

		pass1 = new JPasswordField();
		pass1.setBounds(10, 285, 244, 20);
		frmOrderManagement.getContentPane().add(pass1);

		JButton btnNewButton = new JButton("Add user");
		btnNewButton.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnNewButton.setBounds(10, 372, 115, 41);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);

		JButton btnMenu = new JButton("Menu");
		btnMenu.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnMenu.setBounds(135, 372, 122, 41);
		frmOrderManagement.getContentPane().add(btnMenu);
		btnMenu.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand() == "Add user") {
			if (app.Functions.get_String(pass1.getPassword()).equals(app.Functions.get_String(pass2.getPassword()))) {
				if (app.Functions.get_String(pass1.getPassword()).equals(app.Functions.get_String(pass2.getPassword()))
						&& app.Functions.good_password(pass1.getPassword())) {
					if (username.getText().equals("")) {
						MessageBox pMessageBox = new MessageBox("Campul username este gol!");
						pMessageBox.frmOrderManagement.setVisible(true);
					} else {
						if (male.isSelected()) {
								if (!app.User.find(username.getText())) {
									app.User x = new app.User(username.getText(),comboBox.getSelectedItem().toString(),app.Functions.get_String(pass1.getPassword()));
									x.add();
									AddUserOk windows = new AddUserOk(username.getText(),
											comboBox.getSelectedItem().toString());
									windows.frmOrderManagement.setVisible(true);

									this.frmOrderManagement.dispose();
								} else {
									MessageBox pMessageBox = new MessageBox("Utilizatorul exista deja!");
									pMessageBox.frmOrderManagement.setVisible(true);
								} 
							}
							else if(female.isSelected())
							{
								if (!app.User.find(username.getText())) {
									app.User x = new app.User(username.getText(),comboBox.getSelectedItem().toString(),app.Functions.get_String(pass1.getPassword()));
									x.add();
									AddUserOk windows = new AddUserOk(username.getText(),
									comboBox.getSelectedItem().toString());
									windows.frmOrderManagement.setVisible(true);

									this.frmOrderManagement.dispose();
								} else {
									MessageBox pMessageBox = new MessageBox("Utilizatorul exista deja!");
									pMessageBox.frmOrderManagement.setVisible(true);
								}}
							else
							{
								MessageBox pMessageBox = new MessageBox("Utilizatorul " + username.getText() + " a fost adaugat!");
								pMessageBox.frmOrderManagement.setVisible(true);
							}	
						}
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
		else if(e.getActionCommand() == "Menu")
		{
			LogedManager window = new LogedManager();
			window.frmOrderManagement.setVisible(true);
				
			this.frmOrderManagement.dispose();
		}

	}
}
