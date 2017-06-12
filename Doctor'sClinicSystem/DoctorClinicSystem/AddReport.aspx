<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AddReport.aspx.cs" Inherits="AddReport" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
    
<head runat="server">
    <title></title>
    <link rel="shortcut icon" href="~/Images/report1.jpg" type="image/x-icon"/>
</head>
<body style="background-color:#00ffff">
    <form id="form1" runat="server">
    
        <h2 style="border:1px solid black;width:327px; margin-left:510px; text-align: center;">
            Add Report About Patient</h2>
    
        <h3 style="border:1px solid black;width:201px; margin-left:590px; text-align: center;">
            Patient Id</h3>
    
    <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid" runat="server" min="1" autocomplete="off" Width="92px" style="margin-left: 51px; text-align: center;" Height="26px" MaxLength="5" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator20" runat="server" ControlToValidate="txtpatid" ErrorMessage="You Forget The ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
            </span></p>
        <p style="text-align: center">
            <span>
      
            <asp:ValidationSummary ID="ValidationSummary7" runat="server" Font-Size="X-Large" ForeColor="Black" ValidationGroup="a" />
            <p>
                </span></p>
        <h3 style="border:1px solid black;width:201px; margin-left:590px; text-align: center;">Patient Asymptoms</h3>
        <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid0" runat="server" autocomplete="off" Width="509px" style="margin-left: 51px; " Height="122px" TextMode="MultiLine"></asp:TextBox>
    
            </span>
        </p>
        <h3 style="border:1px solid black;width:201px; margin-left:590px; text-align: center;">Patient Diseases</h3>
        <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid1" runat="server" autocomplete="off" Width="509px" style="margin-left: 51px; text-align: left;" Height="122px" TextMode="MultiLine"></asp:TextBox>
    
            </span>
        </p>
        <h3 style="border:1px solid black;width:202px; margin-left:590px; text-align: center;">Patient Tests</h3>
        <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid2" runat="server" autocomplete="off" Width="509px" style="margin-left: 51px; text-align: left;" Height="122px" TextMode="MultiLine"></asp:TextBox>
    
            </span>
        </p>
        <h3 style="border:1px solid black;width:202px; margin-left:590px; text-align: center;">Patient Medicine</h3>
        <p style="text-align: center">
            &nbsp;</p>
        <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid3" runat="server" autocomplete="off" Width="509px" style="margin-left: 51px; text-align: left;" Height="122px" TextMode="MultiLine"></asp:TextBox>
    
            </span>
        </p>
        <h3 style="border:1px solid black;width:202px; margin-left:590px; text-align: center;">Comments</h3>
        <p style="text-align: center">
            <span>
        <asp:TextBox ID="txtpatid4" runat="server" autocomplete="off" Width="509px" style="margin-left: 51px; text-align: left;" Height="122px" TextMode="MultiLine"></asp:TextBox>
    
            </span>
        </p>
        <h3 style="text-align: center">
            <asp:Button ID="btnsubmit" runat="server" Font-Size="20px" Text="Submit" ValidationGroup="a" Width="93px" OnClick="btnsubmit_Click" />
            <asp:Label ID="lblstatus" runat="server" style="margin-left:50px;margin-right:50px; border:1px black solid" Text="Insertion Success Or Not"></asp:Label>
            <asp:Button ID="btnrest" runat="server" Font-Size="20px" Text="Reset" Width="90px" OnClick="btnrest_Click" />
        </h3>
    </form>
    
        </body>
</html>
