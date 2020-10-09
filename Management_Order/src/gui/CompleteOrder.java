package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import app.Order;
import java.awt.Font;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class CompleteOrder implements ActionListener
{
	public JFrame frmOrderManagement;

	private JList<Object> list;
	private DefaultListModel<Object> model = new DefaultListModel<Object>();
	private ArrayList<Order> dbdata;


	public CompleteOrder() 
	{
		
		dbdata = new ArrayList<Order>();
		dbdata = Order.view_buffer_user(Data.username);

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
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setBounds(100, 100, 635, 590);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Complete/View Order/s");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(140, 0, 331, 67);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		
		JScrollPane scrollBar = new JScrollPane(list);
		scrollBar.setVisible(true);
		scrollBar.setBounds(10, 81, 600, 400);
		frmOrderManagement.getContentPane().add(scrollBar);
		scrollBar.add(list);
		scrollBar.setViewportView(list);
		
		JButton btnNewButton = new JButton("Complete");
		btnNewButton.setBounds(10, 500, 109, 44);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);
		
		JButton btnMenu = new JButton("Menu");
		btnMenu.setBounds(500, 500, 109, 44);
		frmOrderManagement.getContentPane().add(btnMenu);
		btnMenu.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
			if(e.getActionCommand() == "Complete")
			{
				int index = list.getSelectedIndex();
				String cod = dbdata.get(index).getCode(); 
				AddOrderOk y = new AddOrderOk(Order.view_order(cod),"Completed");
				Order.completed(cod);
				dbdata.remove(index);
				model.remove(index);
				y.frmOrderManagement.setVisible(true);
			}
			
			else if(e.getActionCommand() == "Menu")
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
		
	}
}
