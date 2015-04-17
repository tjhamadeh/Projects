import java.io.*;
import java.net.*;
import java.sql.*;

public class client {
    public static void main(String argv[]) throws Exception {
	String id = "0";
        String responseId;
	String host = "afsconnect2.njit.edu";
	int port = 51331;
	int cost = 7;
	int router = 0;

        String url = "jdbc:mysql://sql.njit.edu:3306/";
        String dbName = "tjh24";
        String driver = "com.mysql.jdbc.Driver";
        String userName = "tjh24";
        String password = "senorita3";

        BufferedReader inUser = new BufferedReader(new InputStreamReader(System.in));
        Socket clientSocket = new Socket(host, port);
        DataOutputStream outServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

	System.out.println("I am Router "+id+"...\n");
	outServer.writeBytes(id + '\n');

        try {
            Class.forName(driver).newInstance();
            Connection conn = DriverManager.getConnection(url+dbName, userName, password);
            Statement st = conn.createStatement();
            String query = "SELECT * FROM socket WHERE fromNode = '"+id+"'";
            ResultSet rs = st.executeQuery(query);

            while (rs.next()) {
		String distance;
                distance = "Link cost from Router "+id+" to Router "+rs.getString("toNode")+" is: "+rs.getString("linkCost")+".";
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

	System.out.println();
        String send = "SENT FROM ROUTER 0: Router "+id+"'s lowest link cost is Router "+router+". Link cost: "+cost+".";
	outServer.writeBytes(send + '\n');
	responseId = inServer.readLine();
	System.out.println(responseId);
	System.out.println("Closing connection...");
        clientSocket.close();
    }
}
