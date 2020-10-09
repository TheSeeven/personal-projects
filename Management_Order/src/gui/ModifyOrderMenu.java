package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;

import app.GroupAdress;
import app.Order;

import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JCheckBox;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;

public class ModifyOrderMenu implements ActionListener 
{
	public JFrame frmOrderManagement;
	private JTextField ordnamej;
	private JTextField companydestj;
	private JTextField streetdestj;
	private JTextField citydestj;
	private JTextField countrydestj;
	private JTextField zipdestj;
	private JTextField companyprovj;
	private JTextField streetprovj;
	private JTextField cityprovj;
	private JTextField countryprovj;
	private JTextField zipprovj;
	private JTextField quantityj;
	private Order org;
	private JComboBox<String> comboBox;
	JCheckBox chckbxfragile;
	JCheckBox chckbxAlcohol;
	JCheckBox chckbxElectronic;
	JCheckBox chckbxConsumption;


	public ModifyOrderMenu(String order_name,String code) 
	{
		org = new Order();
		GroupAdress gr = new GroupAdress();
		String SQL1 = "select * from order_buffer where code='"+code+"'";
		

		try
            {
                Connection con = DriverManager.getConnection(Data.url);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery(SQL1);
				rs.next();
				org = new Order(rs.getString("name"),rs.getString("code"),rs.getString("oname"),rs.getString("qtype"),rs.getInt("quantity"),rs.getBoolean("fragile"),rs.getBoolean("alcohol"),rs.getBoolean("electronic"),rs.getBoolean("consumption"));
				gr = GroupAdress.view_adress(code);
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }

		

		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 553, 667);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Modify");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(188, 0, 132, 52);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel(order_name);
		lblNewLabel_1.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_1.setBounds(10, 60, 112, 21);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);
		
		JLabel label = new JLabel("---------->");
		label.setFont(new Font("Courier New", Font.BOLD, 13));
		label.setBounds(216, 59, 93, 21);
		frmOrderManagement.getContentPane().add(label);
		
		JLabel lblDestination = new JLabel("Destination");
		lblDestination.setFont(new Font("Courier New", Font.BOLD, 13));
		lblDestination.setBounds(10, 92, 112, 21);
		frmOrderManagement.getContentPane().add(lblDestination);
		
		JLabel lblNewLabel_2 = new JLabel("companyprov:");
		lblNewLabel_2.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_2.setBounds(10, 124, 68, 14);
		frmOrderManagement.getContentPane().add(lblNewLabel_2);
		
		JLabel lblstreetprovl = new JLabel("streetprov:");
		lblstreetprovl.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblstreetprovl.setBounds(10, 149, 58, 14);
		frmOrderManagement.getContentPane().add(lblstreetprovl);
		
		JLabel lblcityprovl = new JLabel("cityprov:");
		lblcityprovl.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcityprovl.setBounds(10, 174, 53, 14);
		frmOrderManagement.getContentPane().add(lblcityprovl);
		
		JLabel lblcountryprovl = new JLabel("countryprov:");
		lblcountryprovl.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcountryprovl.setBounds(10, 199, 73, 14);
		frmOrderManagement.getContentPane().add(lblcountryprovl);
		
		JLabel lblZip = new JLabel("Zip:");
		lblZip.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblZip.setBounds(10, 224, 53, 14);
		frmOrderManagement.getContentPane().add(lblZip);
		
		JLabel label_1 = new JLabel("---------->");
		label_1.setFont(new Font("Courier New", Font.BOLD, 13));
		label_1.setBounds(216, 121, 93, 21);
		frmOrderManagement.getContentPane().add(label_1);
		
		JLabel label_2 = new JLabel("---------->");
		label_2.setFont(new Font("Courier New", Font.BOLD, 13));
		label_2.setBounds(216, 146, 93, 21);
		frmOrderManagement.getContentPane().add(label_2);
		
		JLabel label_3 = new JLabel("---------->");
		label_3.setFont(new Font("Courier New", Font.BOLD, 13));
		label_3.setBounds(216, 171, 93, 21);
		frmOrderManagement.getContentPane().add(label_3);
		
		JLabel label_4 = new JLabel("---------->");
		label_4.setFont(new Font("Courier New", Font.BOLD, 13));
		label_4.setBounds(216, 196, 93, 21);
		frmOrderManagement.getContentPane().add(label_4);
		
		JLabel label_5 = new JLabel("---------->");
		label_5.setFont(new Font("Courier New", Font.BOLD, 13));
		label_5.setBounds(216, 221, 93, 21);
		frmOrderManagement.getContentPane().add(label_5);
		
		JLabel lblcompanydest = new JLabel(gr.destinatie.getCompany());
		lblcompanydest.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcompanydest.setHorizontalAlignment(SwingConstants.CENTER);
		lblcompanydest.setBounds(98, 124, 108, 14);
		frmOrderManagement.getContentPane().add(lblcompanydest);
		
		JLabel lblstreetdest = new JLabel(gr.destinatie.getStreet());
		lblstreetdest.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblstreetdest.setHorizontalAlignment(SwingConstants.CENTER);
		lblstreetdest.setBounds(98, 149, 108, 14);
		frmOrderManagement.getContentPane().add(lblstreetdest);
		
		JLabel lblcitydest = new JLabel(gr.destinatie.getCity());
		lblcitydest.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcitydest.setHorizontalAlignment(SwingConstants.CENTER);
		lblcitydest.setBounds(98, 174, 108, 14);
		frmOrderManagement.getContentPane().add(lblcitydest);
		
		JLabel lblcountrydest = new JLabel(gr.destinatie.getCountry());
		lblcountrydest.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcountrydest.setHorizontalAlignment(SwingConstants.CENTER);
		lblcountrydest.setBounds(98, 199, 108, 14);
		frmOrderManagement.getContentPane().add(lblcountrydest);
		
		JLabel lblzipdest = new JLabel(gr.destinatie.getZip_code());
		lblzipdest.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblzipdest.setHorizontalAlignment(SwingConstants.CENTER);
		lblzipdest.setBounds(98, 224, 108, 14);
		frmOrderManagement.getContentPane().add(lblzipdest);
		
		JLabel lblProvenience = new JLabel("Provenience");
		lblProvenience.setFont(new Font("Courier New", Font.BOLD, 13));
		lblProvenience.setBounds(10, 249, 112, 21);
		frmOrderManagement.getContentPane().add(lblProvenience);
		
		JLabel label_10 = new JLabel("companyprov:");
		label_10.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_10.setBounds(10, 281, 68, 14);
		frmOrderManagement.getContentPane().add(label_10);
		
		JLabel label_11 = new JLabel("streetprov:");
		label_11.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_11.setBounds(10, 306, 58, 14);
		frmOrderManagement.getContentPane().add(label_11);
		
		JLabel label_12 = new JLabel("cityprov:");
		label_12.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_12.setBounds(10, 331, 53, 14);
		frmOrderManagement.getContentPane().add(label_12);
		
		JLabel label_13 = new JLabel("countryprov:");
		label_13.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_13.setBounds(10, 356, 73, 14);
		frmOrderManagement.getContentPane().add(label_13);
		
		JLabel label_14 = new JLabel("Zip:");
		label_14.setFont(new Font("Courier New", Font.PLAIN, 12));
		label_14.setBounds(10, 381, 53, 14);
		frmOrderManagement.getContentPane().add(label_14);
		
		JLabel lblcompanyprov = new JLabel(gr.provenienta.getCompany());
		lblcompanyprov.setHorizontalAlignment(SwingConstants.CENTER);
		lblcompanyprov.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcompanyprov.setBounds(98, 281, 108, 14);
		frmOrderManagement.getContentPane().add(lblcompanyprov);
		
		JLabel lblstreetprov = new JLabel(gr.provenienta.getStreet());
		lblstreetprov.setHorizontalAlignment(SwingConstants.CENTER);
		lblstreetprov.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblstreetprov.setBounds(98, 305, 108, 14);
		frmOrderManagement.getContentPane().add(lblstreetprov);
		
		JLabel lblcityprov = new JLabel(gr.provenienta.getCity());
		lblcityprov.setHorizontalAlignment(SwingConstants.CENTER);
		lblcityprov.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcityprov.setBounds(98, 330, 108, 14);
		frmOrderManagement.getContentPane().add(lblcityprov);
		
		JLabel lblcountryprov = new JLabel(gr.provenienta.getCountry());
		lblcountryprov.setHorizontalAlignment(SwingConstants.CENTER);
		lblcountryprov.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblcountryprov.setBounds(98, 355, 108, 14);
		frmOrderManagement.getContentPane().add(lblcountryprov);
		
		JLabel lblzipprov = new JLabel(gr.provenienta.getZip_code());
		lblzipprov.setHorizontalAlignment(SwingConstants.CENTER);
		lblzipprov.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblzipprov.setBounds(98, 380, 108, 14);
		frmOrderManagement.getContentPane().add(lblzipprov);
		
		JLabel label_20 = new JLabel("---------->");
		label_20.setFont(new Font("Courier New", Font.BOLD, 13));
		label_20.setBounds(216, 277, 93, 21);
		frmOrderManagement.getContentPane().add(label_20);
		
		JLabel label_21 = new JLabel("---------->");
		label_21.setFont(new Font("Courier New", Font.BOLD, 13));
		label_21.setBounds(216, 302, 93, 21);
		frmOrderManagement.getContentPane().add(label_21);
		
		JLabel label_22 = new JLabel("---------->");
		label_22.setFont(new Font("Courier New", Font.BOLD, 13));
		label_22.setBounds(216, 327, 93, 21);
		frmOrderManagement.getContentPane().add(label_22);
		
		JLabel label_23 = new JLabel("---------->");
		label_23.setFont(new Font("Courier New", Font.BOLD, 13));
		label_23.setBounds(216, 352, 93, 21);
		frmOrderManagement.getContentPane().add(label_23);
		
		JLabel label_24 = new JLabel("---------->");
		label_24.setFont(new Font("Courier New", Font.BOLD, 13));
		label_24.setBounds(216, 377, 93, 21);
		frmOrderManagement.getContentPane().add(label_24);

		companydestj = new JTextField();
		companydestj.setBounds(319, 120, 211, 20);
		frmOrderManagement.getContentPane().add(companydestj);
		companydestj.setColumns(10);
		
		
		streetdestj = new JTextField();
		streetdestj.setColumns(10);
		streetdestj.setBounds(319, 145, 211, 20);
		frmOrderManagement.getContentPane().add(streetdestj);
	
		
		citydestj = new JTextField();
		citydestj.setColumns(10);
		citydestj.setBounds(319, 170, 211, 20);
		frmOrderManagement.getContentPane().add(citydestj);
	
		
		countrydestj = new JTextField();
		countrydestj.setColumns(10);
		countrydestj.setBounds(319, 195, 211, 20);
		frmOrderManagement.getContentPane().add(countrydestj);

		
		zipdestj = new JTextField();
		zipdestj.setColumns(10);
		zipdestj.setBounds(319, 220, 211, 20);
		frmOrderManagement.getContentPane().add(zipdestj);
	
		
		companyprovj = new JTextField();
		companyprovj.setColumns(10);
		companyprovj.setBounds(319, 277, 211, 20);
		frmOrderManagement.getContentPane().add(companyprovj);
	
		
		streetprovj = new JTextField();
		streetprovj.setColumns(10);
		streetprovj.setBounds(319, 303, 211, 20);
		frmOrderManagement.getContentPane().add(streetprovj);
	

		cityprovj = new JTextField();
		cityprovj.setColumns(10);
		cityprovj.setBounds(319, 328, 211, 20);
		frmOrderManagement.getContentPane().add(cityprovj);

		
		countryprovj = new JTextField();
		countryprovj.setColumns(10);
		countryprovj.setBounds(319, 352, 211, 20);
		frmOrderManagement.getContentPane().add(countryprovj);

		
		zipprovj = new JTextField();
		zipprovj.setColumns(10);
		zipprovj.setBounds(319, 377, 211, 20);
		frmOrderManagement.getContentPane().add(zipprovj);
	
		
		ordnamej = new JTextField();
		ordnamej.setColumns(10);
		ordnamej.setBounds(319, 59, 211, 20);
		frmOrderManagement.getContentPane().add(ordnamej);


		quantityj = new JTextField();
		quantityj.setColumns(10);
		quantityj.setBounds(319, 444, 211, 20);
		frmOrderManagement.getContentPane().add(quantityj);
	
		JLabel lblQuantityType = new JLabel("Quantity Type:");
		lblQuantityType.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblQuantityType.setBounds(10, 423, 98, 14);
		frmOrderManagement.getContentPane().add(lblQuantityType);

		JLabel quantity = new JLabel(Integer.toString(org.getQuantity()));
		quantity.setHorizontalAlignment(SwingConstants.CENTER);
		quantity.setFont(new Font("Courier New", Font.PLAIN, 12));
		quantity.setBounds(98, 448, 108, 14);;
		frmOrderManagement.getContentPane().add(quantity);
		
		JLabel label_26 = new JLabel("---------->");
		label_26.setFont(new Font("Courier New", Font.BOLD, 13));
		label_26.setBounds(216, 419, 93, 21);
		frmOrderManagement.getContentPane().add(label_26);
		
		comboBox = new JComboBox<String>();
		comboBox.setModel(new DefaultComboBoxModel<String>(new String[] {"palets", "packs", "kg", "t"}));
		comboBox.setFont(new Font("Courier New", Font.PLAIN, 12));
		comboBox.setBounds(319, 419, 211, 20);
		frmOrderManagement.getContentPane().add(comboBox);
		
		JLabel lblQuantity = new JLabel("Quantity:");
		lblQuantity.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblQuantity.setBounds(10, 448, 98, 14);
		frmOrderManagement.getContentPane().add(lblQuantity);
		
		JLabel qtype = new JLabel(org.getQuantity_type());
		qtype.setHorizontalAlignment(SwingConstants.CENTER);
		qtype.setFont(new Font("Courier New", Font.PLAIN, 12));
		qtype.setBounds(98, 422, 108, 14);
		frmOrderManagement.getContentPane().add(qtype);
		
		JLabel label_28 = new JLabel("---------->");
		label_28.setFont(new Font("Courier New", Font.BOLD, 13));
		label_28.setBounds(216, 444, 93, 21);
		frmOrderManagement.getContentPane().add(label_28);
		
		chckbxfragile = new JCheckBox("fragile");
		chckbxfragile.setBounds(319, 474, 97, 23);
		frmOrderManagement.getContentPane().add(chckbxfragile);
		chckbxfragile.setEnabled(true);
		
		chckbxAlcohol = new JCheckBox("alcohol");
		chckbxAlcohol.setBounds(319, 500, 97, 23);
		frmOrderManagement.getContentPane().add(chckbxAlcohol);
		chckbxAlcohol.setEnabled(true);
		
		chckbxElectronic = new JCheckBox("electronic");
		chckbxElectronic.setBounds(319, 524, 97, 23);
		frmOrderManagement.getContentPane().add(chckbxElectronic);
		chckbxElectronic.setEnabled(true);
		
		chckbxConsumption = new JCheckBox("consumption");
		chckbxConsumption.setBounds(319, 550, 97, 23);
		frmOrderManagement.getContentPane().add(chckbxConsumption);
		chckbxConsumption.setEnabled(true);
		
		JLabel label_29 = new JLabel("---------->");
		label_29.setFont(new Font("Courier New", Font.BOLD, 13));
		label_29.setBounds(216, 476, 93, 21);
		frmOrderManagement.getContentPane().add(label_29);
		
		JLabel label_30 = new JLabel("---------->");
		label_30.setFont(new Font("Courier New", Font.BOLD, 13));
		label_30.setBounds(216, 501, 93, 21);
		frmOrderManagement.getContentPane().add(label_30);
		
		JLabel label_31 = new JLabel("---------->");
		label_31.setFont(new Font("Courier New", Font.BOLD, 13));
		label_31.setBounds(216, 525, 93, 21);
		frmOrderManagement.getContentPane().add(label_31);
		
		JLabel label_32 = new JLabel("---------->");
		label_32.setFont(new Font("Courier New", Font.BOLD, 13));
		label_32.setBounds(216, 551, 93, 21);
		frmOrderManagement.getContentPane().add(label_32);
		
		JCheckBox orgfragile = new JCheckBox("fragile");
		orgfragile.setEnabled(false);
		orgfragile.setBounds(109, 474, 97, 23);
		frmOrderManagement.getContentPane().add(orgfragile);
		orgfragile.setSelected(org.getFragile());
		
		JCheckBox orgalcohol = new JCheckBox("alcohol");
		orgalcohol.setEnabled(false);
		orgalcohol.setBounds(109, 500, 97, 23);
		frmOrderManagement.getContentPane().add(orgalcohol);
		orgalcohol.setSelected(org.getAlcohol());
		
		JCheckBox orgelectronic = new JCheckBox("electronic");
		orgelectronic.setEnabled(false);
		orgelectronic.setBounds(109, 524, 97, 23);
		frmOrderManagement.getContentPane().add(orgelectronic);
		orgelectronic.setSelected(org.getElectronic());
		
		
		JCheckBox orgconsumption = new JCheckBox("consumption");
		orgconsumption.setEnabled(false);
		orgconsumption.setBounds(109, 550, 97, 23);
		frmOrderManagement.getContentPane().add(orgconsumption);
		orgconsumption.setSelected(org.getConsumption());
		
		
		JButton btnNewButton = new JButton("Modify");
		btnNewButton.setBounds(10, 580, 98, 47);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);
		
		JButton btnMenu = new JButton("Menu");
		btnMenu.setBounds(432, 580, 98, 47);
		frmOrderManagement.getContentPane().add(btnMenu);
		btnMenu.addActionListener(this);
	}


	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand()=="Menu")
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
		else if(e.getActionCommand()=="Modify")
		{
			app.Adress dest = new app.Adress(companydestj.getText(),countrydestj.getText(),citydestj.getText(),streetdestj.getText(),zipdestj.getText());
			app.Adress prov = new app.Adress(companyprovj.getText(),countryprovj.getText(),cityprovj.getText(),streetprovj.getText(),zipprovj.getText());
			
			app.GroupAdress gr = new app.GroupAdress(prov,dest);
			Order add = new Order(org.getUsername(),org.getCode(),ordnamej.getText(),gr.destinatie,gr.provenienta,String.valueOf(comboBox.getSelectedItem()),Integer.parseInt(quantityj.getText()),chckbxfragile.isSelected(),chckbxAlcohol.isSelected(),chckbxElectronic.isSelected(),chckbxConsumption.isSelected());

			Order.remove_buffer_database(org.getCode());
			add.add_buffer();

			ViewOrders x = new ViewOrders(add.JFieldString(),"Succesfully modified");
			x.frmOrderManagement.setVisible(true);
		}

	}
}
