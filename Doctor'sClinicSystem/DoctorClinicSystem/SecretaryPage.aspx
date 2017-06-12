<%@ Page Language="C#" AutoEventWireup="true" CodeFile="SecretaryPage.aspx.cs" Inherits="SecretaryPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <link rel="stylesheet" type="text/css" href="clinicstyle.css"/>
    <link rel="shortcut icon" href="~/Images/secretary.png" type="image/x-icon"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            text-align: center;
        }
    </style>
</head>
<body style="background-color:#61ace5">
    <form id="form1" runat="server">
    <div style="margin-top:80;width=200px;">
    
        <h1 class="auto-style1">Welcome to the system </h1>
        <p class="auto-style1">&nbsp;</p>
          <p>
            <asp:Button ID="btnaddpatient" runat="server" Height="66px" Text="AddPatient" Width="182px" OnClick="btnaddpatient_Click" />
        </p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            <asp:Button ID="btnaddmain" runat="server" Height="65px" Text="AddMaintenance" Width="182px" OnClick="btnaddmain_Click" />
        </p>
        <p>
        </p>
        <p>
            &nbsp;</p>
    
    </div>
      
    </form>
</body>
</html>
