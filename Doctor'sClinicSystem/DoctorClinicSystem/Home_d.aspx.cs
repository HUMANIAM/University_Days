using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Home_d : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        { }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        //Server.Transfer(".aspx");
    }
    protected void btnacheivements_Click(object sender, EventArgs e)
    {

    }
    protected void btnLogin_Click(object sender, EventArgs e)
    {
        Server.Transfer("Login.aspx");
    }
    protected void btnacheivements_Click1(object sender, EventArgs e)
    {
        //Server.Transfer("");
    }
}