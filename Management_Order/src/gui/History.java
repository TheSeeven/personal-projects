package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.util.ArrayList;

import javax.swing.JList;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import app.Order;

public class History implements ActionListener

{
	public JFrame frmOrderManagement;
	private JList<Object> list;
	private DefaultListModel<Object> model = new DefaultListModel<Object>();
	private ArrayList<Order> dbdata;


	public History()  
	{	
		dbdata = new ArrayList<Order>();
		dbdata = Order.view_history_user(Data.username);

		Object[] values = new Object[dbdata.size()];

		for(int i=0;i<values.length;i++)
		{
			values[i]=dbdata.get(i);
		}

		list = new JList<Object>(model);
		list.setLayoutOrientation(JList.VERTICAL);
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

		for(Object i:values)
		{
			model.addElement(i);
		}

		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 800, 313);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("View Order");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(320, 11, 192, 49);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JScrollPane scrollBar = new JScrollPane(list);
		scrollBar.setVisible(true);
		scrollBar.setBounds(10, 63, 759, 154);
		frmOrderManagement.getContentPane().add(scrollBar);
		scrollBar.add(list);
		scrollBar.setViewportView(list);
		
		JButton btnMenu = new JButton("Menu");
		btnMenu.setBounds(670, 228, 97, 35);
		frmOrderManagement.getContentPane().add(btnMenu);
		btnMenu.addActionListener(this);

		JButton btnView = new JButton("Details");
		btnView.setBounds(10, 228, 97, 35);
		frmOrderManagement.getContentPane().add(btnView);
		btnView.addActionListener(this);
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
		else if(e.getActionCommand() == "Details")
		{
			int index = list.getSelectedIndex();
			String cod = dbdata.get(index).getCode(); 
			
			String x = Order.view_order_history(cod);

			AddOrderOk modifyorder = new AddOrderOk(x,"Details");
			modifyorder.frmOrderManagement.setVisible(true);

		}
	}
}
