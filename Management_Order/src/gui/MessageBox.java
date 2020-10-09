package gui;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MessageBox extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;
	public JFrame frmOrderManagement;

	public MessageBox(String message) 
	{
		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 313, 206);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Error");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(83, 11, 150, 46);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel(message);
		lblNewLabel_1.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(10, 66, 292, 66);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);
		
		JButton btnNewButton = new JButton("Ok");
		btnNewButton.setBounds(114, 143, 89, 23);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);
		btnNewButton.setActionCommand("ok");

		frmOrderManagement.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

	}

	public MessageBox(String message,int length) 
	{
		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, length, 206);
		frmOrderManagement.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Error");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(83, 11, length/2+20, 46);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel(message);
		lblNewLabel_1.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(10, 66, length, 66);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);
		
		JButton btnNewButton = new JButton("Ok");
		btnNewButton.setBounds(114, 143, length/2+20, 23);
		frmOrderManagement.getContentPane().add(btnNewButton);
		btnNewButton.addActionListener(this);
		btnNewButton.setActionCommand("ok");

		frmOrderManagement.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand()=="ok")
		{
			this.frmOrderManagement.dispose();
		}
	}

}
