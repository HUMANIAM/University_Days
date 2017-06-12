using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class SecretaryPage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnaddmain_Click(object sender, EventArgs e)
    {
        Server.Transfer("Maintenance.aspx");
    }
    protected void btnaddpatient_Click(object sender, EventArgs e)
    {
        Server.Transfer("NewAddition.aspx");
    }
}