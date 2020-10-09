package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;

import app.Order;

import javax.swing.JList;
import javax.swing.JScrollBar;
import javax.swing.ListSelectionModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class View implements ActionListener 
{
	public JFrame frmOrderManagement;
	private JList<Object> list;
	private DefaultListModel<Object> model = new DefaultListModel<Object>();
	private ArrayList<Order> dbdata;

	public View(String view,String username,app.Order x) 
	{
		dbdata = new ArrayList<Order>();

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
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 880, 557);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel(view);
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(107, 0, 193, 88);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JLabel label = new JLabel("----------");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setFont(new Font("Courier New", Font.BOLD, 24));
		label.setBounds(310, 0, 193, 88);
		frmOrderManagement.getContentPane().add(label);
		
		JLabel lblMihailCeva = new JLabel(username);
		lblMihailCeva.setHorizontalAlignment(SwingConstants.CENTER);
		lblMihailCeva.setFont(new Font("Courier New", Font.BOLD, 24));
		lblMihailCeva.setBounds(529, 0, 308, 88);
		frmOrderManagement.getContentPane().add(lblMihailCeva);
		
		JList<String> list = new JList<String>();
		list.setBounds(10, 87, 839, 396);
		frmOrderManagement.getContentPane().add(list);
		
		JScrollBar scrollBar = new JScrollBar();
		scrollBar.setBounds(847, 87, 17, 396);
		frmOrderManagement.getContentPane().add(scrollBar);
		
		JButton btnNewButton = new JButton("Menu");
		btnNewButton.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnNewButton.setBounds(377, 494, 126, 23);
		frmOrderManagement.getContentPane().add(btnNewButton);
		
		JButton btnRemove = new JButton("Remove");
		btnRemove.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnRemove.setBounds(10, 494, 126, 23);
		frmOrderManagement.getContentPane().add(btnRemove);
		
		JButton btnModify = new JButton("Modify");
		btnModify.setFont(new Font("Courier New", Font.PLAIN, 12));
		btnModify.setBounds(723, 494, 126, 23);
		frmOrderManagement.getContentPane().add(btnModify);
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getActionCommand()=="Menu")
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
		
		else if(e.getActionCommand()=="Remove")
		{}
		
		else if(e.getActionCommand()=="Modify")
		{}
	
	}

}
