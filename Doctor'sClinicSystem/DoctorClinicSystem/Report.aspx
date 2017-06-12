<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Report.aspx.cs" Inherits="Report" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <link rel="shortcut icon" href="~/Images/report.jpg" type="image/x-icon"/>
    <title></title>
    <style type="text/css">

         table{
             width:100% ;
             border:solid 1px black;
             font-size:20px;
             margin-left:150px;
            
         }
         
          tr{
              
             background-color:#fc0a4d;
             border-collapse: collapse;
         }
        td {
            width="17%"
        }
        </style>
</head>
<body style="background-color:#00ffff">
    <form id="form1" runat="server">
    <div>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:399px; margin:auto; height: 36px;">
            Search About Report of Patient</h2>
        <br/>
    
    </div>
    
    </div>
        <p style="text-align: center">
        <asp:Label ID="lblpatname" runat="server" Height="20px" style="margin-left:0px; font-size:22px; text-align: center;" Text="ID" Width="80px"></asp:Label>
        <asp:TextBox ID="txtpatid1" runat="server" Width="164px" min="0" Height="33px" style="margin-left: 19px; text-align: center;" TextMode="Number"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator20" runat="server" ControlToValidate="txtpatid1" ErrorMessage="You Forget The ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
            </span>
        </p>
        <p style="text-align: center">
                <asp:Button ID="btpatsubmit7" runat="server" Text="Search"   style="margin-left: 62px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="a" OnClick="btpatsubmit7_Click"/>
            
        <asp:Label ID="lblstatus4" runat="server" Height="26px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert4" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest5" runat="server" Text="Reset"   style="margin-left: 15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest5_Click"/>
                
        </p>
        <p style="text-align: center">
            &nbsp;<p style="text-align: center">
            <span>
      
            <asp:ValidationSummary ID="ValidationSummary7" runat="server" Font-Size="X-Large" ForeColor="Black" ValidationGroup="a" style="text-align: center" />
            <p>
                </span>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:325px; margin:auto; height: 36px;">
            Add Report About Patient</h2>
        <br/>
    
    </div>
        <p style="text-align: center">
                <asp:Button ID="btpatsubmit" runat="server" Text="AddReport"  s style="margin-left: 0px;font-size:18px;margin-right:20px;" Width="151px" Height="40px" OnClick="btpatsubmit_Click"/>
            
        </p>
        <p style="text-align: center">
            
        <asp:Label ID="lblsepr" runat="server" Height="10px"  style="margin-left:2px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
    </form>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:325px; margin:auto; height: 36px;">
            Result of Search</h2>
        <br/>
    
    </div>
    <p style="text-align: center">
        &nbsp;</p>
    <div runat="server" id="divresult" style="width: 1100px; height: 200px;" >
    </div>
</body>
</html>
