package gui;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JButton;

public class Validate {

	private JFrame frmOrderManagement;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Validate window = new Validate();
					window.frmOrderManagement.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Validate() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmOrderManagement = new JFrame();
		frmOrderManagement.setTitle("Order Management");
		frmOrderManagement.setResizable(false);
		frmOrderManagement.setBounds(100, 100, 405, 244);
		frmOrderManagement.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmOrderManagement.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Confirm");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 24));
		lblNewLabel.setBounds(131, 11, 123, 51);
		frmOrderManagement.getContentPane().add(lblNewLabel);
		
		JButton btnNewButton = new JButton("Yes");
		btnNewButton.setBounds(10, 153, 112, 51);
		frmOrderManagement.getContentPane().add(btnNewButton);
		
		JButton btnNu = new JButton("Nu");
		btnNu.setBounds(277, 153, 112, 51);
		frmOrderManagement.getContentPane().add(btnNu);
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		lblNewLabel_1.setFont(new Font("Courier New", Font.PLAIN, 12));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(10, 62, 379, 80);
		frmOrderManagement.getContentPane().add(lblNewLabel_1);
	}

}
