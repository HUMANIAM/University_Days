using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class AddReport : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnrest_Click(object sender, EventArgs e)
    {
        txtpatid.Text = txtpatid0.Text = txtpatid1.Text = txtpatid2.Text = txtpatid3.Text = txtpatid4.Text="";
    }
    protected void btnsubmit_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");

        try
        {
            int id = Int32.Parse(txtpatid.Text);
            string asymps = txtpatid0.Text;
            string diseases = txtpatid1.Text;
            string tests = txtpatid2.Text;
            string medicines = txtpatid3.Text;
            string comments = txtpatid4.Text;

            // This command to insert new Report into the Report table

            conn.Open();
            SqlCommand comm0 = new SqlCommand();
            comm0.Connection = conn;
            comm0.CommandText = String.Format("insert into Report values('{0}','{1}','{2}','{3}','{4}','{5}')", id, asymps, diseases, tests,medicines,comments);
            int s = comm0.ExecuteNonQuery();
            conn.Close();
            lblstatus.Text = "Insertion Success";

        }
        catch
        {

            lblstatus.Text = "Insertion Success";
            conn.Close();
        }
    }
}