<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Home_d.aspx.cs" Inherits="Home_d" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <link rel="stylesheet" type="text/css" href="clinicstyle.css">
    <link rel="shortcut icon" href="~/Images/home.png" type="image/x-icon"/>
    <title>Home Page</title>
   
</head>
<body style="background-color:#2872e8">
  
    <form id="form1" runat="server" style="margin-top:120px;">
  
        <h1 class="wrapper">Doctor&#39;s Clinic System</h1>
        <br />

        <asp:Button ID="btnLogin" styel="padding-left:10px" runat="server" Text="Login" Height="45px" style="text-align: center" Width="200px" OnClick="btnLogin_Click"/>
        
              <br> <br> 
        <asp:Button ID="btnacheivements" runat="server" Height="47px" Text="Acheivements" style="text-align: center" Width="200px" OnClick="btnacheivements_Click1" />
                 <br> <br> 
         <asp:Button ID="btnaboutus" runat="server" OnClick="Button2_Click" Text="About Us" style="text-align: center" Height="48px" Width="200px" />
               
          <br> <br> 
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
