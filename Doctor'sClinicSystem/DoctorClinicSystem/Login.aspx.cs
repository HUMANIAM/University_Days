using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        { }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
        try
        {

            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("select Type from Users where Users.Username ='{0}' and Users.Password = '{1}'", txtusrname.Text, txtpassword.Text);
            SqlDataReader res2 = comm2.ExecuteReader();
            if (res2.HasRows)
            {

                while (res2.Read())
                {
                    string type = res2[0].ToString();
                    lbllogin.Text = type;
                    switch (type)
                    {
                        case "d":
                            Server.Transfer("Doctor.aspx");
                            break;

                        case "n":
                            Server.Transfer("Report.aspx");
                            break;

                        case "s":
                            Server.Transfer("SecretaryPage.aspx");
                            break;

                        default:
                            break;

                    }
                }
            }
            else {
                lbllogin.Text = "Check Again your password or Username";
            }
            conn.Close();
        }

        catch
        {
            conn.Close();
        }
    }
}