<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
     <link rel="stylesheet" type="text/css" href="clinicstyle.css">
    <link rel="shortcut icon" href="~/Images/login.jpg" type="image/x-icon"/>
    <title>Login</title>

    <style type="text/css">


        .auto-style1 {
            text-align: center;
            
            
            
        }
    </style>
</head>
<body  style="background-color:#83a9f7">
    <form id="form1" runat="server">
    <div class="auto-style1" style="margin-top:70px;">
        
        
    &nbsp;<h1>Welocome So Much Our Guest</h1>
        
        
        <asp:Label ID="lblusrname" runat="server" Text="UserName" Height="25px"></asp:Label>
        <asp:TextBox ID="txtusrname" runat="server" Height="25px" Width="217px" autocomplete="off" style="margin-left: 5px; text-align: center;" MaxLength="40"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="txtusrname" ErrorMessage="UserName is required" Font-Size="X-Large" ForeColor="#FF0066">^</asp:RequiredFieldValidator>
        <br />
        <br />
        <br />
        <br />
        
        <asp:Label ID="lblpassword" runat="server" Text="Password" Height="25px"></asp:Label>
        <asp:TextBox ID="txtpassword" runat="server" Height="25px" autocomplete="off" Width="218px"  style="margin-left: 16px; text-align: center;" TextMode="Password" MaxLength="40"></asp:TextBox>
       
            <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="txtpassword" ErrorMessage="Password is required" Font-Size="X-Large" ForeColor="#FF0066">^</asp:RequiredFieldValidator>
        <br />
        <br />
        <br />
        <br />
        <asp:Button ID="Button1" runat="server" style="font-size: x-large;  margin-left: 102px" Text="Login" Width="189px" OnClick="Button1_Click" />
       
            <br />
        <br />
       
            <br />
        <asp:Label ID="lbllogin" runat="server"></asp:Label>
        <br />
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" Font-Size="X-Large" ForeColor="Blue" />
       
            <br />
        <br />
    </div>
       
    </form>
</body>
</html>
