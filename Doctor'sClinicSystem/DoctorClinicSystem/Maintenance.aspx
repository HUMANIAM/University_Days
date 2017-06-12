<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Maintenance.aspx.cs" Inherits="Maintenance" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link rel="shortcut icon" href="~/Images/worker.jpg" type="image/x-icon"/>
    <style type="text/css">

        #lblpataddress{
            margin-left:10px;
        }
        #form1 {
            text-align: center;
        }
    </style>
</head>
<body style="background-color:#86e6ef">
    <form id="form1" runat="server">
    <div style="text-align: center">
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:198px; margin:auto;">
            Add Worker</h2><br/>
    
    </div>
    
    </div>
         <p>
        <asp:Label ID="lblpatname" runat="server" Height="20px" style="margin-left:290px;font-size:22px; text-align: center;" Text="Name" Width="80px"></asp:Label>
        <asp:TextBox ID="txtworkname" runat="server" autocomplete="off" Width="192px" Height="26px" style="margin-left: 19px; text-align: center;" MaxLength="50"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator21" runat="server" ControlToValidate="txtworkname" ErrorMessage="You Forget The Worker Name" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
                </span>
        <asp:Label ID="lblpataddress" runat="server" Height="20px" style="text-align: center;font-size:22px;margin-left:150px;" Text="Address" Width="74px"></asp:Label>
        <asp:TextBox ID="txtworkaddress" runat="server" autocomplete="off" Width="191px" Height="26px" style="text-align: center; margin-left: 13px;" MaxLength="50"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator25" runat="server" ControlToValidate="txtworkaddress" ErrorMessage="You Forget The Worker Address" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
                </span>
        </p>
        <p>
        <asp:Label ID="lblpatphone" runat="server" Height="20px" style="text-align: left;margin-left:290px;font-size:22px;" Text="PhoneNo" Width="89px"></asp:Label>
        <asp:TextBox ID="txtworkphone" runat="server" autocomplete="off" Width="192px" Height="26px" style="margin-left: 7px; text-align: center;" MaxLength="11"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator26" runat="server" ControlToValidate="txtworkphone" ErrorMessage="You Forget The Worker PhoneNUmber" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
                </span>
        <asp:Label ID="lblpatemail" runat="server" Height="20px" style="text-align: center;margin-left:142px; font-size:22px;" Text="Working" Width="74px"></asp:Label>
        &nbsp;
        <asp:TextBox ID="txtworking" runat="server" autocomplete="off" Width="191px" Height="26px" style="text-align: center; margin-left: 16px;" MaxLength="20"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator27" runat="server" ControlToValidate="txtworking" ErrorMessage="You Forget The Worker Working" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="a">*</asp:RequiredFieldValidator>
    
                </span>
   </p>
        <p>
            &nbsp;</p>
        <p style="text-align: center">
                <asp:Button ID="btpatsubmit" runat="server" Text="Submit"  s style="margin-left: 0px;font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="a" OnClick="btpatsubmit_Click"/>
            
        <asp:Label ID="lblstatus" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtworkinsert" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>
    
               &nbsp;&nbsp;
                <asp:Button ID="btpatsubmit9" runat="server" Text="Rest"  s style="margin-left: 0px;font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="a" OnClick="btpatsubmit9_Click"/>
            
               </p>
        <p style="text-align: center">
            &nbsp;</p>
        <p style="text-align: center">
         
                <asp:Button ID="btngetid" runat="server" Text="GetId"  s style="margin-left: 0px;font-size:18px;" Width="94px" Height="29px"/>
                
                <asp:Button ID="btnid" runat="server" Text="ID"  s style="margin-left: 0px;font-size:18px;margin-right:20px;" Width="97px" Enabled="False" Height="28px"/>

         </p>
        <p style="text-align: center">
         
            <span>

            <asp:ValidationSummary ID="ValidationSummary6" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="a" />
      
        <p>
            </span>

         </p>
        <p style="text-align: center">
            
        <asp:Label ID="lblsepr" runat="server" Height="10px"  style="margin-left:2px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:220px; margin:auto;">
            Add Maintenance</h2>
        <br />
        <br/>
    
    </div>
    
        <p style="text-align: left;width:1320px">
            
        <asp:Label ID="lblpatidentityno" runat="server" Height="20px" style="text-align: center;margin-left:285px; font-size:22px;" Text="WorkerId" Width="99px"></asp:Label>
        <asp:TextBox ID="txtworkerid" runat="server"  min="0" autocomplete="off" Width="123px" style="margin-left: 10px; text-align: center;" Height="26px"></asp:TextBox>
            
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator28" runat="server" ControlToValidate="txtworkerid" ErrorMessage="You Forget The Worker Id" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="b">*</asp:RequiredFieldValidator>
    
                </span>
            
        <asp:Label ID="lblsid" runat="server" Height="20px" style="text-align: center;margin-left:70px; font-size:22px;" Text="SecretaryId" Width="113px"></asp:Label>
        <asp:TextBox ID="txtserid" runat="server" min="0" autocomplete="off" Width="118px" style="margin-left: 10px; text-align: center;" Height="26px"></asp:TextBox>
            
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator29" runat="server" ControlToValidate="txtcost" ErrorMessage="You Forget The Cost" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="b">*</asp:RequiredFieldValidator>
    
        <asp:Label ID="lbldate" runat="server" Height="20px" style="text-align: center;margin-left:70px; font-size:22px;" Text="Date" Width="69px"></asp:Label>
        <asp:TextBox ID="txtdate" runat="server" autocomplete="off" Width="118px" style="margin-left: 10px; text-align: center;" Height="26px" TextMode="Date"></asp:TextBox>
            
            <asp:RequiredFieldValidator ID="RequiredFieldValidator31" runat="server" ControlToValidate="txtdate" ErrorMessage="You Forget The Maintenance Date" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="b">*</asp:RequiredFieldValidator>
    
                </span>
            
        </p>
        <p style="text-align: left;width:1320px">
            
            &nbsp;</p>
             <p style="text-align: left; width: 1320px">
            
        <asp:Label ID="lblpatidentityno2" runat="server" Height="20px" style="text-align: center;margin-left:300px; font-size:22px;" Text="Cost" Width="69px"></asp:Label>
        <asp:TextBox ID="txtcost" runat="server" min="0" autocomplete="off" Width="118px" style="margin-left: 10px; text-align: center;" Height="26px"></asp:TextBox>
            
        <asp:Label ID="lblpatidentityno1" runat="server" Height="20px" style="text-align: center;margin-left:108px; font-size:22px;" Text="Maintenance" Width="136px"></asp:Label>
        <asp:TextBox ID="txtmain" runat="server" autocomplete="off" Width="319px" style="margin-left: 10px; text-align: left;" Height="77px" TextMode="MultiLine"></asp:TextBox>
            
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator30" runat="server" ControlToValidate="txtmain" ErrorMessage="You Forget The Maintenance" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="b">*</asp:RequiredFieldValidator>
    
                 </span>
            
        </p>
        <p style="text-align: left; width: 1320px">
            &nbsp;</p>
        <p>
                <asp:Button ID="btpatsubmit6" runat="server" Text="Submit"   style="margin-left: 410px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="b" OnClick="btpatsubmit6_Click"/>
            
        <asp:Label ID="lblstatus3" runat="server" Height="26px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtmaininser" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest4" runat="server" Text="Reset"   style="margin-left: 15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest4_Click"/>
                
        </p>
        <p style="text-align: center">
            <span>

            <asp:ValidationSummary ID="ValidationSummary7" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="b" />
      
        <p>
            </span>
                
        </p>
        <p style="text-align: center">
            
        <asp:Label ID="lblsepr0" runat="server" Height="10px"  style="margin-left:2px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:273px; margin:auto; height: 42px;">
            Search About Worker</h2>
    
    </div>
        <p>
            &nbsp;</p>
&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblpateintid0" runat="server" Height="26px" style="text-align: center;font-size:22px;margin-left:0px;" Text="Employment" Width="112px"></asp:Label>
        <asp:TextBox ID="txtname" runat="server" autocomplete="off" Height="26px" style="margin-left: 11px; text-align: center;" Width="213px"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator20" runat="server" ControlToValidate="txtname" ErrorMessage="You Forget The Worker Employment" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="c">*</asp:RequiredFieldValidator>
    
                </span>
             <br />
        <p style="text-align: left">
                <asp:Button ID="btpatsubmit7" runat="server" Text="Submit"   style="margin-left: 410px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="c"/>
            
        <asp:Label ID="lblstatus4" runat="server" Height="26px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert4" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest5" runat="server" Text="Reset"   style="margin-left: 15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest5_Click"/>
                
        </p>
        <p style="text-align: center">
            <span>

            <asp:ValidationSummary ID="ValidationSummary5" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="c" />
      
        <p>
            </span>
                
        </p>
        <p style="text-align: left">
            
        <asp:Label ID="lblsepr1" runat="server" Height="10px" style="margin-left:180px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:339px; margin:auto; height: 42px;">
            Search About Maintenance</h2>
    
    </div>
        <p style="text-align: left">
            &nbsp;</p>
        <p style="text-align: center">
            <asp:Label ID="lblmanfrom" runat="server" Height="20px" style="text-align: center;font-size:30px;" Text="From" Width="92px" ></asp:Label>
            <asp:TextBox ID="txtfrom" runat="server" Height="22px" style="margin-left: 22px" Width="182px" TextMode="Date"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator17" runat="server" ControlToValidate="txtfrom" ErrorMessage="You Forget The From Date" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="d">*</asp:RequiredFieldValidator>
    
                </span>
            <asp:Label ID="lblmanto" runat="server" Height="20px" style="text-align: center;font-size:30px; margin-left: 87px;" Text="To" Width="60px"></asp:Label>
            <asp:TextBox ID="txtto" runat="server" Height="22px" style="margin-left: 22px" Width="184px" TextMode="Date"></asp:TextBox>
            <span>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator18" runat="server" ControlToValidate="txtto" ErrorMessage="You Forget The To date" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="d">*</asp:RequiredFieldValidator>
    
                </span>
            </p>
        <p style="text-align: center">
            &nbsp;</p>
             <p>
                <asp:Button ID="btpatsubmit8" runat="server" Text="Submit"   style="margin-left: 410px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" ValidationGroup="d"/>
            
        <asp:Label ID="lblstatus5" runat="server" Height="26px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert5" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest6" runat="server" Text="Reset"   style="margin-left: 15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest6_Click"/>
                
        </p>
        <p style="text-align: center">
            <span>

            <asp:ValidationSummary ID="ValidationSummary4" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="d" />
      
        <p>
            </span>
                
        </p>
        <p>
            
        <asp:Label ID="lblsepr2" runat="server" Height="10px" style="margin-left:180px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
             </form>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:404px; margin:auto; height: 32px;">
            Result Of Search about Worker</h2>
    
        <div style="width: 1000px; height: 99px;" runat="server" id="divresult0">
        </div>
    
    </div>
    
    <div style="text-align: center">
    
        <h2 style="border:1px solid black;width:466px; margin:auto; height: 32px;">
            Result Of Search about Maintenance</h2>
    
        <div style="width: 1000px; height: 99px;" runat="server" id="divresult1">
        </div>
    
    </div>
        <p style="text-align: center">
            &nbsp;</p>
        </body>
</html>
