<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Doctor.aspx.cs" Inherits="Doctor" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link rel="shortcut icon" href="~/Images/doctor.jpg" type="image/x-icon"/>
    <style type="text/css">

        .auto-style1 {
            text-align: center;
        }
    .auto-style1 {
        }
        #btnaddpatient{
           
               margin:auto;
          display:block;
          color:blue;
          font-size:20px;
          }
        
        #btnaddmain{
               margin:auto;
          display:block;
          color:blue;
          font-size:20px;
          }
        </style>
</head>
<body style="background-color:#66d0ed">
    <form id="form1" runat="server">
    <div style="margin-top:80px;">
    
        <h1 class="auto-style1">Welcome to the system </h1>
        <p class="auto-style1">&nbsp;</p>
        <p class="auto-style1">
            <asp:Button ID="btnnursemission" runat="server" Height="66px" Text="NurseMissions" Width="182px" Font-Size="Large" ForeColor="#0000CC" OnClick="btnnursemission_Click"   />
        </p>
        <p class="auto-style1">&nbsp;</p>
        <p class="auto-style1">&nbsp;</p>
        <p class="auto-style1">
            <asp:Button ID="btnsecretarymission" runat="server" Height="65px" Text="SecretaryMission" Width="182px" Font-Size="Large" ForeColor="#0000CC" OnClick="btnsecretarymission_Click"   />
    
        </p>
        <br />
        <br />
        <br />
    
    </div>
    </form>
</body>
</html>
