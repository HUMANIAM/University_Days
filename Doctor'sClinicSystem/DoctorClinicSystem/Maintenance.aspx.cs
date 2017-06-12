using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class Maintenance : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        { }
    }
    protected void btpatsubmit_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");

        try
        {

            string Name = txtworkname.Text;
            string Working = txtworking.Text;
            string Address = txtworkaddress.Text;
            string PhoneNumber = txtworkphone.Text;


            // This command to insert new worker into the work table

            conn.Open();
            SqlCommand comm0 = new SqlCommand();
            comm0.Connection = conn;
            comm0.CommandText = String.Format("insert into Worker values('{0}','{1}','{2}','{3}')", Name, Working, Address, PhoneNumber);
            int s = comm0.ExecuteNonQuery();
            conn.Close();
            txtworkinsert.Text = "Insertion Success";

        }
        catch
        {

            txtworkinsert.Text = "Insertion Success";
            conn.Close();
        }
    }
    protected void btpatsubmit9_Click(object sender, EventArgs e)
    {
        txtworkname.Text = txtworking.Text = txtworkaddress.Text = txtworkphone.Text = "";
        txtworking.Text = "Success/Not Success";
    }
    protected void btpatrest4_Click(object sender, EventArgs e)
    {
        txtserid.Text = txtworkerid.Text = txtdate.Text = txtmain.Text = txtserid.Text = "";
        txtmaininser.Text = "Successed/not Successed";
    }
    protected void btpatsubmit6_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");

        try
        {
            int wid = Int32.Parse(txtworkerid.Text);
            int sid = Int32.Parse(txtserid.Text);
            int cost = Int32.Parse(txtcost.Text);
            string main = txtmain.Text;

            // This command to insert new Mainenance into the Maintenance table

            conn.Open();
            SqlCommand comm0 = new SqlCommand();
            comm0.Connection = conn;
            comm0.CommandText = String.Format("insert into Maintenance values('{0}','{1}','{2}','{3}','{4}')", wid, sid, main, cost, txtdate.Text);
            int s = comm0.ExecuteNonQuery();
            conn.Close();
            txtmaininser.Text = "Insertion Success";

        }
        catch
        {

            txtmaininser.Text = "Insertion not Success";
            conn.Close();
        }
    }
    protected void btpatrest6_Click(object sender, EventArgs e)
    {
        txtfrom.Text = txtto.Text = "";
        txtpatinsert5.Text = "Success / Not Success";
    }
    protected void btpatrest5_Click(object sender, EventArgs e)
    {
        txtname.Text = "";
        txtpatinsert4.Text = "Success/Not Success";

    }
    /* protected void btpatsubmit7_Click(object sender, EventArgs e)
   {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
        try
        {
            string table = "<table >{0}</table>";
            string Id, Name, Working, Address, PhoneNumber, rows;
            Id = Name = PhoneNumber = Address = PhoneNumber = rows = "";

            rows += "<tr><th>{0}</th><th>{1}</th><th>{2}</th><th>{3}</th><th>{4}</tr>";
            rows = String.Format(rows, "Id", "Name", "Working", "Address", "PhoneNumber");

            string fromperson = String.Format("select * from Worker where Working={0}", txtname.Text);

            //read from the Worker table

            conn.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = conn;
            command.CommandText = fromperson;
            SqlDataReader res = command.ExecuteReader();

            if (res.HasRows)
            {
                while (res.Read())
                {
                    Id = res[0].ToString();
                    Name = res[1].ToString();
                    Working = res[2].ToString();
                    Address = res[3].ToString();
                    PhoneNumber = res[4].ToString();

                }

            }
            conn.Close();

            rows += "<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td></tr>";
            rows = String.Format(rows, Id, Name, Working, Address, PhoneNumber);
            table = String.Format(table, rows);

            divresult0.InnerHtml = table;
            // Response.Write(table);

            txtpatinsert4.Text = "Search success";
        }
    }*/
}