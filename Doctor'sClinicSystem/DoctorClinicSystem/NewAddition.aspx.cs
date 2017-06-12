using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

public partial class NewAddition : System.Web.UI.Page
{
    string patientname;
    string patientaddress;
    string patientemail;
    string patientidentity;
    string patientid;
    string imagename;
    string patientphone;
    long patientage;
    int id;


    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            patientname = patientaddress = patientemail = patientidentity = patientphone = "";
            patientage = id = 0;

            SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
            try
            {

                conn.Open();
                SqlCommand comm2 = new SqlCommand();
                comm2.Connection = conn;
                comm2.CommandText = String.Format("select count(Pid) from Amedical");
                SqlDataReader res2 = comm2.ExecuteReader();
                if (res2.HasRows)
                {

                    while (res2.Read())
                    {
                        hfsevice.Value = res2[0].ToString();
                        btnunserviced.Text = hfsevice.Value;
                    }
                }

                conn.Close();
            }
           
            catch{
                conn.Close();
            }
        }

    }
    protected void btnupload_Click(object sender, EventArgs e)
    {
        if (fuimage.HasFile)
        {
            string fullpath = Server.MapPath(".") + @"\Images\" + fuimage.FileName;
            fuimage.SaveAs(fullpath);
            Imagepatient.ImageUrl = @"~\Images\" + fuimage.FileName;
            hfimageurl.Value = fuimage.FileName;
        }

    }
    protected void btpatsubmit_Click(object sender, EventArgs e)
    {

        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");

        try
        {

            patientaddress = txtpataddress.Text;
            patientname = txtpatname.Text;
            patientemail = txtpatemail.Text;
            patientidentity = txtpatidentityn.Text;
            patientphone = txtpatphone.Text;
            imagename = hfimageurl.Value;

            patientage = Int64.Parse(txtpatage.Text);

            // This command to insert new person into the person table

            conn.Open();
            SqlCommand comm0 = new SqlCommand();
            comm0.Connection = conn;
            comm0.CommandText = String.Format("insert into Persons values('{0}','{1}','{2}','{3}')", patientname, patientemail, patientphone, patientaddress);
            int s = comm0.ExecuteNonQuery();
            conn.Close();

            // this command to get id of the inserted person

            SqlCommand comm1 = new SqlCommand();
            conn.Open();
            comm1.Connection = conn;
            comm1.CommandText = String.Format("select Id from Persons where PhoneNumber = {0}", Int64.Parse(txtpatphone.Text));
            SqlDataReader res = comm1.ExecuteReader();
          
            if (res.HasRows)
            {
                
                while (res.Read())
                {
                    id = Int32.Parse(res[0].ToString());
                    btnid.Text = id.ToString();

                }
            }
            conn.Close();

            //this command to insert new patient into the patient table

            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("insert into Pateint values('{0}','{1}','{2}','{3}')", id, patientidentity, patientage, imagename);
            comm2.ExecuteNonQuery();
            conn.Close();

            txtpatinsert.Text = "Insertion success";

        }
        catch
        {

            txtpatinsert.Text = "Insertion doesn't success";
            conn.Close();
        }


    }
    protected void btpatrest_Click(object sender, EventArgs e)
    {
        txtpataddress.Text = txtpatname.Text = "";
        txtpatemail.Text = txtpatidentityn.Text = "";
        txtpatphone.Text = txtpatage.Text = "";
        btnid.Text = "ID";
        txtpatinsert.Text = "Success/not Success";
        txtpatemail.Text = "@gmail.com";
        Imagepatient.ImageUrl = @"~/Images/smile.png";
        //fuimage.Attributes.Clear();

    }
    protected void btpatsubmit1_Click(object sender, EventArgs e)
    {
        int n;
        int id;
        if (!int.TryParse(txtpatid0.Text, out n))
        { txtpatinsert1.Text = "there is an error"; }
        else
        {
            id = Int32.Parse(txtpatid0.Text);
            txtpatinsert1.Text = "Success/not Success";
        }



    }

    protected void btpatsubmit0_Click(object sender, EventArgs e)
    {

        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
        try
        {
            patientid = txtpatid.Text;
            id = Int32.Parse(patientid);
            int paid = Int32.Parse(txtpatpaid.Text);
            int rest = Int32.Parse(txtpatrest.Text);
            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("insert into Financials values('{0}','{1}','{2}')", id, paid, rest);
            comm2.ExecuteNonQuery();
            conn.Close();
            txtpatinsert0.Text = "Insertion Success";
        }
        catch
        {
            txtpatinsert0.Text = "Insertion not Success";
            conn.Close();
        }
    }
    protected void btpatrest0_Click(object sender, EventArgs e)
    {
        txtpatid.Text = "";
        txtpatpaid.Text = "";
        txtpatrest.Text = "";
        txtpatinsert0.Text = "Success/Not Success";
    }
    protected void btpatrest1_Click(object sender, EventArgs e)
    {
        txtpatid0.Text = "";
        txtmeddate.Text = "";
        txtpatinsert1.Text = "Success/Not Success";

    }
    protected void btpatsubmit1_Click1(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");

        try
        {
            patientid = txtpatid0.Text;
            id = Int32.Parse(patientid);


            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("insert into Amedical values('{0}','{1}')", id, txtmeddate.Text);
            comm2.ExecuteNonQuery();
            conn.Close();

            txtpatinsert1.Text = "Insertion Success";

            int x = Int32.Parse(hfsevice.Value);
            x += 1;
            hfsevice.Value = x.ToString();
            btnunserviced.Text = hfsevice.Value;

        }
        catch
        {
            txtpatinsert1.Text = "Insertion not Success";
            conn.Close();
        }
    }


    protected void btpatrest2_Click(object sender, EventArgs e)
    {
        txtpatid2.Text = "";
        txtpatinsert2.Text = "Success/Not Success";
    }
    protected void btpatsubmit2_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True");
        try
        {
            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("delete from Amedical where Pid = {0}", Int32.Parse(txtpatid2.Text));
            int n = comm2.ExecuteNonQuery();
            conn.Close();

            txtpatinsert2.Text = "Deletion Success";

            int x = Int32.Parse(hfsevice.Value);
            x -= 1;
            hfsevice.Value = x.ToString();
            btnunserviced.Text = hfsevice.Value;
        }
        catch
        {
            txtpatinsert2.Text = "Not Success";
            conn.Close();
        }
        
    }

    protected void btnserrest_Click(object sender, EventArgs e)
    {
        txtpatid3.Text = txtpatid4.Text="";
        txtpatinsert3.Text = "Success/Not Success";
        divresult.InnerHtml = "";
    }
    //Here is the search part of the page
    //create new command function
   
    protected void btnser_Click(object sender, EventArgs e)
    {
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True"); 
        try
        {
            string table = "<table class=\"persontable\" >{0}</table>";
            string Id, Name, Email, PhoneNumber, Address, NationalId, Age, img, Amedical , rows ;
            Id = Name = Email = PhoneNumber = Address = NationalId = Age = img = Amedical = rows="";

            rows += "<tr><th>{0}</th><th>{1}</th><th>{2}</th><th>{3}</th><th>{4}</th><th>{5}</th><th>{6}</th><th>{7}</th><th></tr>";
             rows = String.Format(rows, "Id", "Name", "Email", "PhoneNumber", "Address","NationalId","Age","Image");

             string fromperson = String.Format("select * from Persons,Pateint where Pateint.Id={0} and Persons.Id={0}", Int32.Parse(txtpatid3.Text));

            //read from the person table

            conn.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = conn;
            command.CommandText = fromperson;
            SqlDataReader res = command.ExecuteReader();

            if(res.HasRows)
            {
                while (res.Read())
                {
                    Id = res[0].ToString();
                    Name = res[1].ToString();
                    Email = res[2].ToString();
                    PhoneNumber = res[3].ToString();
                    Address = res[4].ToString();
                    NationalId = res[6].ToString();
                    Age = res[7].ToString();
                    img = "Images\\" + res[8];
                }

            }
            conn.Close();

            string imag = String.Format("<img src=\"{0}\" width=\"60px;\" height=\"60px;\"></img>", img);
            rows += "<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td><td>{6}</td><td>{7}</td></tr>";
            rows = String.Format(rows, Id, Name, Email, PhoneNumber, Address,NationalId,Age,imag);
            table = String.Format(table, rows);

            divresult.InnerHtml = table;
           // Response.Write(table);
  
            txtpatinsert3.Text = "Search success";
        }
        catch
        {
            conn.Close();
            txtpatinsert3.Text = "Search not success";
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        lblpatid7.Text = "";
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True"); 
        try
        {
            conn.Open();
            SqlCommand comm2 = new SqlCommand();
            comm2.Connection = conn;
            comm2.CommandText = String.Format("select MedicalDate from Amedical where Pid = {0}",Int32.Parse(txtpatid5.Text));
            SqlDataReader res2 = comm2.ExecuteReader();
            if (res2.HasRows)
            {

                while (res2.Read())
                {
                    lblpatid6.Text = res2[0].ToString();
                }
            }
            else { lblpatid7.Text = "Not found"; }
            conn.Close();
        
        }
        catch
        {
            conn.Close();
            
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        txtpatid5.Text = "";
        lblpatid6.Text = "Date";
        lblpatid7.Text = "";
    }

    protected void Button3_Click(object sender, EventArgs e)
    {
    
        SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=DoctorClinic;Integrated Security=True"); 
        try
        {
            string table = "<table  >{0}</table>";
            string Id, NationalId, Age, img, rows ;
            Id  = NationalId = Age = img =  rows="";

            rows += "<tr><th>{0}</th><th>{1}</th><th>{2}</th><th>{3}</th></tr>";
             rows = String.Format(rows, "Id", "NationalId", "Age", "Image");

             string fromperson = String.Format("select * from Pateint where NationalId={0}", txtpatid4.Text);

            //read from the person table

            conn.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = conn;
            command.CommandText = fromperson;
            SqlDataReader res = command.ExecuteReader();

            if(res.HasRows)
            {
                while (res.Read())
                {
                    Id = res[0].ToString();
                    NationalId = res[1].ToString();
                    Age = res[2].ToString();
                    img = "Images\\" + res[3];
                }
                conn.Close();

                string imag = String.Format("<img src=\"{0}\" width=\"60px;\" height=\"60px;\"></img>", img);
                rows += "<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td></tr>";
                rows = String.Format(rows, Id, NationalId, Age, imag);
                table = String.Format(table, rows);

                divresult.InnerHtml = table;
                // Response.Write(table);

                txtpatinsert3.Text = "Search success";
            }
           
        }
        catch
        {
            conn.Close();
            txtpatinsert3.Text = "Search not success";
        }
    }
    
}
   

