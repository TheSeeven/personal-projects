package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddOrder implements ActionListener {
	public JFrame frmOrderManagement;
	private JTextField nameField;
	private JTextField usernameField;
	private JTextField streetField1;
	private JTextField companyField1;
	private JTextField cityField1;
	private JTextField countryField1;
	private JTextField zipField1;
	private JTextField companyField2;
	private JTextField streetField2;
	private JTextField cityField2;
	private JTextField countryField2;
	private JTextField zipField2;
	private JTextField quantityField;
	JCheckBox checkBox;
	JCheckBox checkBox_1;
	JCheckBox checkBox_2;
	JCheckBox checkBox_3;

	JComboBox<String> comboBox;

	public AddOrder() {
		frmOrderManagement = new JFrame();
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 370, 660);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Add Order");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(95, 0, 136, 47);
		frmOrderManagement.getContentPane().add(lblNewLabel);

		JLabel lblName = new JLabel("Name: ");
		lblName.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblName.setBounds(10, 52, 112, 21);
		frmOrderManagement.getContentPane().add(lblName);

		JLabel label_1 = new JLabel("Destination");
		label_1.setFont(new Font("Courier New", Font.BOLD, 13));
		label_1.setBounds(10, 105, 112, 21);
		frmOrderManagement.getContentPane().add(label_1);

		JLabel label_2 = new JLabel("Company:");
		label_2.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_2.setBounds(10, 130, 68, 14);
		frmOrderManagement.getContentPane().add(label_2);

		JLabel label_3 = new JLabel("Street:");
		label_3.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_3.setBounds(10, 155, 58, 14);
		frmOrderManagement.getContentPane().add(label_3);

		JLabel label_4 = new JLabel("City:");
		label_4.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_4.setBounds(10, 178, 53, 14);
		frmOrderManagement.getContentPane().add(label_4);

		JLabel label_5 = new JLabel("Country:");
		label_5.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_5.setBounds(10, 203, 73, 14);
		frmOrderManagement.getContentPane().add(label_5);

		JLabel label_6 = new JLabel("Zip:");
		label_6.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_6.setBounds(10, 228, 53, 14);
		frmOrderManagement.getContentPane().add(label_6);

		JLabel label_7 = new JLabel("Provenience");
		label_7.setFont(new Font("Courier New", Font.BOLD, 13));
		label_7.setBounds(10, 253, 112, 21);
		frmOrderManagement.getContentPane().add(label_7);

		JLabel label_8 = new JLabel("Company:");
		label_8.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_8.setBounds(10, 285, 68, 14);
		frmOrderManagement.getContentPane().add(label_8);

		JLabel label_9 = new JLabel("Street:");
		label_9.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_9.setBounds(10, 310, 58, 14);
		frmOrderManagement.getContentPane().add(label_9);

		JLabel label_10 = new JLabel("City:");
		label_10.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_10.setBounds(10, 335, 53, 14);
		frmOrderManagement.getContentPane().add(label_10);

		JLabel label_11 = new JLabel("Country:");
		label_11.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_11.setBounds(10, 360, 73, 14);
		frmOrderManagement.getContentPane().add(label_11);

		JLabel label_12 = new JLabel("Zip:");
		label_12.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_12.setBounds(10, 385, 53, 14);
		frmOrderManagement.getContentPane().add(label_12);

		JLabel label_13 = new JLabel("Quantity Type:");
		label_13.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_13.setBounds(10, 409, 98, 14);
		frmOrderManagement.getContentPane().add(label_13);

		JLabel label_14 = new JLabel("Quantity:");
		label_14.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_14.setBounds(10, 434, 98, 14);
		frmOrderManagement.getContentPane().add(label_14);

		comboBox = new JComboBox<String>();
		comboBox.setFont(new Font("Courier New", Font.PLAIN, 12));
		comboBox.setBounds(118, 406, 211, 20);
		frmOrderManagement.getContentPane().add(comboBox);
		comboBox.addItem("palets");
		comboBox.addItem("packs");
		comboBox.addItem("kg");
		comboBox.addItem("t");

		checkBox = new JCheckBox("fragile");
		checkBox.setBounds(118, 457, 97, 23);
		frmOrderManagement.getContentPane().add(checkBox);

		checkBox_1 = new JCheckBox("alcohol");
		checkBox_1.setBounds(118, 483, 97, 23);
		frmOrderManagement.getContentPane().add(checkBox_1);

		checkBox_2 = new JCheckBox("electronic");
		checkBox_2.setBounds(118, 509, 97, 23);
		frmOrderManagement.getContentPane().add(checkBox_2);

		checkBox_3 = new JCheckBox("consumption");
		checkBox_3.setBounds(118, 535, 97, 23);
		frmOrderManagement.getContentPane().add(checkBox_3);

		JLabel lblUsername = new JLabel("Username: ");
		lblUsername.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblUsername.setBounds(10, 73, 112, 21);
		frmOrderManagement.getContentPane().add(lblUsername);

		nameField = new JTextField();
		nameField.setColumns(10);
		nameField.setBounds(118, 51, 211, 20);
		frmOrderManagement.getContentPane().add(nameField);

		usernameField = new JTextField(Data.username);
		usernameField.setColumns(10);
		usernameField.setBounds(118, 74, 211, 20);
		frmOrderManagement.getContentPane().add(usernameField);
		usernameField.setEditable(false);

		streetField1 = new JTextField();
		streetField1.setColumns(10);
		streetField1.setBounds(118, 151, 211, 20);
		frmOrderManagement.getContentPane().add(streetField1);

		companyField1 = new JTextField();
		companyField1.setColumns(10);
		companyField1.setBounds(118, 126, 211, 20);
		frmOrderManagement.getContentPane().add(companyField1);

		cityField1 = new JTextField();
		cityField1.setColumns(10);
		cityField1.setBounds(118, 174, 211, 20);
		frmOrderManagement.getContentPane().add(cityField1);

		countryField1 = new JTextField();
		countryField1.setColumns(10);
		countryField1.setBounds(118, 199, 211, 20);
		frmOrderManagement.getContentPane().add(countryField1);

		zipField1 = new JTextField();
		zipField1.setColumns(10);
		zipField1.setBounds(118, 224, 211, 20);
		frmOrderManagement.getContentPane().add(zipField1);

		companyField2 = new JTextField();
		companyField2.setColumns(10);
		companyField2.setBounds(118, 281, 211, 20);
		frmOrderManagement.getContentPane().add(companyField2);

		streetField2 = new JTextField();
		streetField2.setColumns(10);
		streetField2.setBounds(118, 306, 211, 20);
		frmOrderManagement.getContentPane().add(streetField2);

		cityField2 = new JTextField();
		cityField2.setColumns(10);
		cityField2.setBounds(118, 331, 211, 20);
		frmOrderManagement.getContentPane().add(cityField2);

		countryField2 = new JTextField();
		countryField2.setColumns(10);
		countryField2.setBounds(118, 356, 211, 20);
		frmOrderManagement.getContentPane().add(countryField2);

		zipField2 = new JTextField();
		zipField2.setColumns(10);
		zipField2.setBounds(118, 381, 211, 20);
		frmOrderManagement.getContentPane().add(zipField2);

		quantityField = new JTextField();
		quantityField.setColumns(10);
		quantityField.setBounds(118, 430, 211, 20);
		frmOrderManagement.getContentPane().add(quantityField);

		JButton btnadd = new JButton("Add");
		btnadd.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnadd.setBounds(10, 573, 112, 47);
		frmOrderManagement.getContentPane().add(btnadd);
		btnadd.addActionListener(this);

		JButton btnmenu = new JButton("Menu");
		btnmenu.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnmenu.setBounds(236, 573, 112, 47);
		frmOrderManagement.getContentPane().add(btnmenu);
		btnmenu.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e)
	{usernameField = new JTextField(Data.username);
		if (e.getActionCommand() == "Menu")
		{
			if (Data.functie.toUpperCase().equals("MANAGER")) 
			{LogedManager window = new LogedManager();
			window.frmOrderManagement.setVisible(true);
			this.frmOrderManagement.dispose();
			}else if (!Data.functie.toUpperCase().equals("MANAGER")){
			LogedUser window = new LogedUser();
			window.frmOrderManagement.setVisible(true);
			this.frmOrderManagement.dispose();}
		}
		else if (e.getActionCommand() == "Add") 
		{
			try{
			Integer.parseInt(quantityField.getText());}
			catch(Exception ex){ 
			MessageBox window = new MessageBox("Introduceti numai numere in campul quantity!", 500);
			window.frmOrderManagement.setVisible(true);}
			
			int quantity_type = 0;
			if (comboBox.getSelectedItem().toString().equals("palets")) {
				quantity_type = 0;
			} else if (comboBox.getSelectedItem().toString().equals("packs")) {
				quantity_type = 1;
			} else if (comboBox.getSelectedItem().toString().equals("kg")) {
				quantity_type = 2;
			} else if (comboBox.getSelectedItem().toString().equals("t")) {
				quantity_type = 3;
			}

			app.Order x;
			x = new app.Order(usernameField.getText(), nameField.getText(),new app.Adress(companyField1.getText(), countryField1.getText(), cityField1.getText(),streetField1.getText(), zipField1.getText()),new app.Adress(companyField2.getText(), countryField2.getText(), cityField2.getText(),streetField2.getText(), zipField2.getText()),quantity_type, Integer.parseInt(quantityField.getText()), checkBox.isSelected(),checkBox_1.isSelected(), checkBox_2.isSelected(), checkBox_3.isSelected());	
			x.add_buffer();

			nameField.setText("");
			streetField1.setText("");
			companyField1.setText("");
			cityField1.setText("");
			countryField1.setText("");
			zipField1.setText("");
			companyField2.setText("");
			streetField2.setText("");
			cityField2.setText("");
			countryField2.setText("");
			zipField2.setText("");
			quantityField.setText("");

			AddOrderOk added = new AddOrderOk(x.JFieldString());
			added.frmOrderManagement.setVisible(true);
			System.out.println(x.JLiString());
			}
		}
	}
