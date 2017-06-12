using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
public partial class Report : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        { }
    }
    protected void btpatsubmit_Click(object sender, EventArgs e)
    {
        Server.Transfer("AddReport.aspx");
    }
    protected void btpatrest5_Click(object sender, EventArgs e)
    {
        txtpatid1.Text = "";
        divresult.InnerHtml = "";
    }
    protected void btpatsubmit7_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
        try
        {
            int id = Int32.Parse(txtpatid1.Text);
            string table = "<table >{0}</table>";
            string Pid, Symptoms, Disease, Tests, medicine, Comment, rows;
            Pid = Symptoms = Disease = Tests = medicine = Comment =rows = "";

            rows += "<tr><th>{0}</th><th>{1}</th><th>{2}</th><th>{3}</th><th>{4}</th><th>{5}</th></tr>";
            rows = String.Format(rows, "Pid", "Symptoms", "Disease", "Tests", "medicine", "Comment");

            string fromreport = String.Format("select * from Report where Report.Pid={0}", id);

            //read from the Report table

            conn.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = conn;
            command.CommandText = fromreport;
            SqlDataReader res = command.ExecuteReader();

            if (res.HasRows)
            {
                while (res.Read())
                {
                    Pid = res[0].ToString();
                    Symptoms = res[1].ToString();
                    Disease = res[2].ToString();
                    Tests = res[3].ToString();
                    medicine = res[4].ToString();
                    Comment = res[5].ToString();
                  
                }

            }
            conn.Close();

            rows += "<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td></tr>";
            rows = String.Format(rows, Pid, Symptoms, Disease, Tests, medicine, Comment);
            table = String.Format(table, rows);

            divresult.InnerHtml = table;
            // Response.Write(table);

            txtpatinsert4.Text = "Search success";
        }
        catch
        {
            conn.Close();
            txtpatinsert4.Text = "Search not success";
        }
    }
}