import java.io.*;
import java.net.*;
import java.sql.*;

public class server {
    public static void main(String args[]) throws Exception {
	int port = 51331;
	int cost = 7;
	int router = 0;
	String id = "1";
	String lc = "";
	String host = "";

	String url = "jdbc:mysql://sql.njit.edu:3306/";
	String dbName = "tjh24";
	String driver = "com.mysql.jdbc.Driver";
	String userName = "tjh24";
	String password = "senorita3";

        String clientId;
        ServerSocket welcomeSocket = new ServerSocket(port);

	System.out.println("I am Router "+id+"...");
	System.out.println("Waiting for a connection...");
	Socket connectionSocket = welcomeSocket.accept();
	BufferedReader inClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
	DataOutputStream outClient = new DataOutputStream(connectionSocket.getOutputStream());
	clientId = inClient.readLine();

	System.out.println("Router "+clientId+" is currently connected...\n");

        try {
            Class.forName(driver).newInstance();
            Connection conn = DriverManager.getConnection(url+dbName, userName, password);
            Statement st = conn.createStatement();
            String query = "SELECT * FROM socket WHERE fromNode = '"+id+"'";
            ResultSet rs = st.executeQuery(query);

            while (rs.next()) {
                String distance;
                distance = "Link cost from Router "+id+" to Router "+rs.getString("toNode")+" is: "+rs.getString("linkCost");
                System.out.println(distance);
                if (Integer.parseInt(rs.getString("linkCost")) < cost) {
                    cost = Integer.parseInt(rs.getString("linkCost"));
                    router = Integer.parseInt(rs.getString("toNode"));
                }
            }
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
	
	clientId = inClient.readLine();
	System.out.println();
	String send = "SENT FROM ROUTER 1: Router "+id+"'s lowest link cost is Router "+router+". Link cost: "+cost+".";
	outClient.writeBytes(send + '\n');
	System.out.println(clientId);
	System.out.println("Connection closed.");
    }
}
