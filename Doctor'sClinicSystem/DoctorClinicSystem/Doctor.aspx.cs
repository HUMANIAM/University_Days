using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Doctor : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if(!IsPostBack)
        {}
    }

  
   
    protected void btnnursemission_Click(object sender, EventArgs e)
    {
        Server.Transfer("Report.aspx");
    }
    protected void btnsecretarymission_Click(object sender, EventArgs e)
    {
        Server.Transfer("SecretaryPage.aspx");
    }
}