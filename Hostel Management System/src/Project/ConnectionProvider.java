
package Project;
import java.sql.*;
/**
 *
 * @author DELL
 */
public class ConnectionProvider {
    public static Connection getCon()
    {
        try
        {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/hostel_management","root","root");
            return con;
        }
        catch(Exception e)
        {
            return null;
        }
        
    }
}
