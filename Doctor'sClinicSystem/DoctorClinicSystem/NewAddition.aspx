<%@ Page Language="C#" AutoEventWireup="true" CodeFile="NewAddition.aspx.cs" Inherits="NewAddition" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
     
     <link rel="stylesheet" type="text/css" href="clinicstyle.css"/>
    <link rel="shortcut icon" href="~/Images/1.jpg" type="image/x-icon"/>
    
    <title>NewAddition</title>

    
     <style type="text/css">

         table{
             width:100% ;
             border:solid 1px black;
             font-size:20px;
             margin-left:150px;
             border-collapse: collapse;
         }
         
          tr{
              width:50px;
             background-color:#fc0a4d;
             border-collapse: collapse;
         }
         .auto-style3 {
         }
         #form1 {
             text-align: center;
             height: 2421px;
         }
     </style>
  
    
</head>
<body style="background-color:#657fe5; " >

    <form id="form1" runat="server">
        <div class="auto-style3">
    <div>
    
        <h2 style="border:1px solid black;width:200px;margin-left:710px;">
            Clinic Today</h2>
    
    </div>
            <p style="text-align: center">
        <asp:Label ID="lblpatname0" runat="server" Height="32px" style="margin-left:225px; font-size:22px;" Text="patients Today" Width="159px"></asp:Label>
                
                <asp:Button ID="btnunserviced" runat="server" Text="0"   style="margin-left: 0px;font-size:18px;" Width="102px" OnClick="btnupload_Click" ValidationGroup="B"/>
                <asp:HiddenField ID="hfsevice" runat="server"  />
            </p>
            <span>
            <p style="text-align: left">
        <asp:Label ID="lblpatname1" runat="server" Height="32px" style="margin-left:674px; font-size:22px; text-align: center;" Text="Date Of Reservation" Width="225px"></asp:Label>
                
            </p>
            <p>
            
        <asp:Label ID="lblpatid5" runat="server" Height="21px" style="text-align: left;font-size:22px;margin-left:229px;" Text="ID" Width="33px"></asp:Label>
        <asp:TextBox ID="txtpatid5" runat="server" autocomplete="off" Width="92px" style="margin-left: 5px; text-align: center;" min="1" Height="26px" MaxLength="5" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator20" runat="server" ControlToValidate="txtpatid5" ErrorMessage="You Forget The ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="w">*</asp:RequiredFieldValidator>
    
            &nbsp;
                <asp:Button ID="Button1" runat="server" Font-Size="20px" Height="31px" OnClick="Button1_Click" Text="When" ValidationGroup="w" Width="87px" />
            </p>
            <p style="text-align: left">
            
        <asp:Label ID="lblpatid6" runat="server" Height="21px" style="text-align: center; font-size:22px;margin-left:750px;" Text="Date" Width="130px"></asp:Label>
            
        <asp:Label ID="lblpatid7" runat="server" Height="21px" style="text-align: center; font-size:22px;margin-left:750px;" Width="126px"></asp:Label>
            </p>
            <p>
                <asp:Button ID="Button2" runat="server" Height="32px" OnClick="Button2_Click" style="margin-left: 280px" Text="Okey" Width="104px" Font-Size="Large" />
      
            <asp:ValidationSummary ID="ValidationSummary7" runat="server" Font-Size="X-Large" ForeColor="Black" ValidationGroup="w" />
            <p>
     
                
        <h2 style="border:1px solid black;width:200px;margin-left:710px;">
            Add Patient</h2>
    
            <p>

            </p>
        <asp:Label ID="lblpatname" runat="server" Height="20px" style="margin-left:187px; font-size:22px;" Text="Name" Width="73px"></asp:Label>
&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="txtpatname" runat="server" Width="193px" Height="26px" style="margin-left: 10px; text-align: center;" autocomplete="off" MaxLength="50"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator11" runat="server" ControlToValidate="txtpatname" ErrorMessage="You Forget The Name" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
            <asp:RegularExpressionValidator ID="RegularExpressionValidator4" runat="server" ControlToValidate="txtpatname" ErrorMessage="Invalid Patient Name" ValidationExpression="[a-zA-Z]+" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RegularExpressionValidator>
    
        <asp:Label ID="lblpataddress" runat="server" Height="20px" style="text-align: center;font-size:22px;margin-left:150px;" Text="Address" Width="74px"></asp:Label>
        <asp:TextBox ID="txtpataddress" runat="server" Width="192px" Height="26px" style="text-align: center" autocomplete="off" MaxLength="50"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator10" runat="server" ControlToValidate="txtpataddress" ErrorMessage="You Forget The Address" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
        <p style="direction: ltr">
        <asp:Label ID="lblpatphone" runat="server" Height="20px" style="text-align: left;margin-left:191px; font-size:22px;" Text="PhoneNo" Width="89px"></asp:Label>
&nbsp;&nbsp;
        <asp:TextBox ID="txtpatphone" runat="server" Width="192px" Height="26px" style="margin-left: 0px; text-align: center;" autocomplete="off" MaxLength="11"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator8" runat="server" ControlToValidate="txtpatphone" ErrorMessage="You Forget The PhoneNO" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
            <asp:RegularExpressionValidator ID="RegularExpressionValidator2" runat="server" ControlToValidate="txtpatphone" ErrorMessage="Invalid PhoneNo" ValidationExpression="\d{11}" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RegularExpressionValidator>
    
        <asp:Label ID="lblpatemail" runat="server" Height="20px" style="text-align: center;margin-left:141px; font-size:22px;" Text="Email" Width="74px"></asp:Label>
        <asp:TextBox ID="txtpatemail" runat="server" Width="191px" Height="26px" style="text-align: center; margin-left: 0px;" autocomplete="off" MaxLength="30">@gmail.com</asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" ControlToValidate="txtpatemail" ErrorMessage="You Forget The Email" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
             <br/>
    
        </p>
            <p style="direction: ltr">
            
        <asp:Label ID="lblpatidentityno" runat="server" Height="20px" style="margin-left:123px; font-size:22px;" Text="IdentityNo" Width="99px"></asp:Label>
        <asp:TextBox ID="txtpatidentityn" runat="server" Width="192px" style="margin-left: 10px; text-align: center;" Height="26px" autocomplete="off" MaxLength="14"></asp:TextBox>
            
            <asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" ControlToValidate="txtpatidentityn" ErrorMessage="You Forget The IdentityNO" Font-Size="X-Large"  ForeColor="#CC0000" style="text-align: center" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
            <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="txtpatidentityn" ErrorMessage="Invalid IndentityNO" ValidationExpression="\d{14}" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RegularExpressionValidator>
    
        <asp:Label ID="lblpatage" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:170px;" Text="Age" Width="63px"></asp:Label>
        <asp:TextBox ID="txtpatage" runat="server" Width="92px" style="margin-left: 0px; text-align: center;" Height="26px" MaxLength="4" min="1" autocomplete="off" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" ControlToValidate="txtpatage" ErrorMessage="You Forget The Age" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RequiredFieldValidator>
    
            <asp:RegularExpressionValidator ID="RegularExpressionValidator3" runat="server" ControlToValidate="txtpatage" ErrorMessage="Invalid AgeValue" ValidationExpression="\d+" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RegularExpressionValidator>
    
        </p>
     
      
            <p style="width: 1000px" id="patientimg">
                <asp:Image ID="Imagepatient" runat="server" Width="175px" Height="104px" style="text-align: center;margin-left:600px" BorderWidth="2px" ImageUrl="~/Images/smile.png" />
        </p>
     
      
            <p style="width: 1000px">
                <asp:FileUpload ID="fuimage" runat="server" Width="320px" style="margin-left:492px" Height="30px" />
                
                <asp:Button ID="btnupload" runat="server" Text="Upload"   style="margin-left: 0px;font-size:18px;" Width="79px" OnClick="btnupload_Click" ValidationGroup="B"/>
                <asp:HiddenField ID="hfimageurl" runat="server" />
                </p>
        <br/>
        <p style="text-align: center">
                <asp:Button ID="btpatsubmit" runat="server" Text="Submit"   style="margin-left: 197px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" OnClick="btpatsubmit_Click" ValidationGroup="A"/>
            
        <asp:Label ID="lblstatus" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert" runat="server" Width="236px" style="margin-left: 14px; text-align: center;" Height="29px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>
    
               </p></br>
     <p style="text-align: center">
         
        <asp:Label ID="lblstatus4" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:125px;" Text="ID" Width="28px"></asp:Label>
                
                <asp:Button ID="btnid" runat="server" Text="ID"   style="margin-left: 0px;font-size:18px;margin-right:20px;" Width="97px" Enabled="False" Height="28px"/>

                <asp:Button ID="btpatrest" runat="server" Text="Reset"   style="margin-left: 0px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest_Click" ValidationGroup="B"/>
                
         </p>
            <p style="text-align: center">
         
         </p>
      
            <asp:ValidationSummary ID="ValidationSummary1" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="A" />
      
            <p style="text-align: center">
            
        <asp:Label ID="lblsepr" runat="server" Height="10px"  style="margin-left:2px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
     <br/>
      
   <h2 style="border:1px solid black;width:250px;margin:auto; ">
        Financial information</h2>
            
        <asp:Label ID="lblpatid" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:125px;" Text="ID" Width="33px"></asp:Label>
        <asp:TextBox ID="txtpatid" runat="server" autocomplete="off" Width="92px" style="margin-left: 5px; text-align: center;" min="0" Height="26px" MaxLength="5" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator12" runat="server" ControlToValidate="txtpatid" ErrorMessage="You Forget The ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="c">*</asp:RequiredFieldValidator>
    
            <asp:RegularExpressionValidator ID="RegularExpressionValidator5" runat="server" ControlToValidate="txtpatid" ErrorMessage="Invalid ID" ValidationExpression="\d{}" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="A">*</asp:RegularExpressionValidator>
    
        <asp:Label ID="lblpatpaid" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:100px;" Text="Paid" Width="54px"></asp:Label>
        <asp:TextBox ID="txtpatpaid" runat="server" Width="92px" autocomplete="off"  min="0" style="margin-left: 5px; text-align: center;" Height="26px" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator13" runat="server" ControlToValidate="txtpatpaid" ErrorMessage="You Forget The Paid" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="c">*</asp:RequiredFieldValidator>
    
        <asp:Label ID="lblpatrest" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:100px;" Text="Rest" Width="50px"></asp:Label>
        <asp:TextBox ID="txtpatrest" runat="server" Width="92px" autocomplete="off" min="0" style="margin-left: 5px; text-align: center;" Height="26px" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator14" runat="server" ControlToValidate="txtpatrest" ErrorMessage="You Forget The Rest" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="c">*</asp:RequiredFieldValidator>
    
           </p>
            <p>
            
            <asp:ValidationSummary ID="ValidationSummary2" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="c" />
      
            <p>
      
            <br/>
        <p class="auto-style3">

            
                <asp:Button ID="btpatsubmit0" runat="server" Text="Submit"   style="margin-left: 48px; font-size:18px;margin-right:20px;" Width="94px" Height="29px" OnClick="btpatsubmit0_Click" ValidationGroup="c"/>
            
        <asp:Label ID="lblstatus0" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert0" runat="server" Width="232px" style="margin-left: 0px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>
    
                <asp:Button ID="btpatrest0" runat="server" Text="Reset"  style="margin-left:15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest0_Click"/>
                
        </p><br/>
        <p style="text-align: center">
            
        <asp:Label ID="lblsep" runat="server" Height="10px"  style="margin-left:2px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
      
   <h2 style="border:1px solid black;width:249px; margin:auto; text-align: center;">
        New A Medical</h2><br/>
      
    <p style="text-align: center">
            
        <asp:Label ID="lblpatid0" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:38px;" Text="ID" Width="33px"></asp:Label>
        <asp:TextBox ID="txtpatid0" runat="server" Width="92px" min="0" style="margin-left: 5px; text-align: center;" autocomplete="off" Height="26px" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator15" runat="server" ControlToValidate="txtpatid0" ErrorMessage="You Forget The ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="d">*</asp:RequiredFieldValidator>
    
        <asp:Label ID="lblpatid1" runat="server" Height="20px" style="text-align: center; font-size:22px;margin-left:38px;" Text="Date" Width="60px"></asp:Label>
        <asp:TextBox ID="txtmeddate" runat="server" Width="176px" style="margin-left: 0px; margin-bottom: 1px; text-align: center;" autocomplete="off"  Height="26px" TextMode="Date"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator16" runat="server" ControlToValidate="txtmeddate" ErrorMessage="You Forget The Date" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="d">*</asp:RequiredFieldValidator>
    
        </p><br/>
      
            <p class="wrapper">
                <asp:Button ID="btpatsubmit1" runat="server" Text="Submit"   style="margin-left: 38px;font-size:18px;margin-right:20px;" Width="94px" Height="29px" OnClick="btpatsubmit1_Click1" ValidationGroup="d"/>
            
        <asp:Label ID="lblstatus1" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert1" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest1" runat="server" Text="Reset"   style="margin-left: 15px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest1_Click"/>
                
            <p class="wrapper">
      
            <asp:ValidationSummary ID="ValidationSummary3" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="d" />
      
            <p>
      
            <br />
        </div>
      
        <asp:Label ID="lblsep2" runat="server" Height="10px"  style="margin-left:0px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        <br>
      
   <h2 style="border:1px solid black;width:249px; margin:auto; text-align: center;">
        Delete A Medical</h2>
    <br/>
    <pDelete A Medical </h2>
   
    <p style="text-align: center">

        <asp:Label ID="lblpatid2" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:100px;" Text="ID" Width="33px"></asp:Label>
        <asp:TextBox ID="txtpatid2" runat="server" Width="92px" min="0" style="margin-left: 5px; text-align: center;" Height="26px" autocomplete="off" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator17" runat="server" ControlToValidate="txtpatid2" ErrorMessage="You Forget The Patient ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="e">*</asp:RequiredFieldValidator>
    
                <asp:Button ID="btpatsubmit2" runat="server" Text="Submit"   style="margin-left: 38px;font-size:18px;margin-right:20px;" Width="94px" Height="29px" OnClick="btpatsubmit2_Click" ValidationGroup="e"/>
            
    </p>
        <p style="text-align: center">

        <asp:Label ID="lblstatus2" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert2" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btpatrest2" runat="server" Text="Reset"   style="margin-left: 10px;font-size:18px;" Width="94px" Height="29px" OnClick="btpatrest2_Click"/>
                
    </p>
        <p style="text-align: center">

            <asp:ValidationSummary ID="ValidationSummary4" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="e" />
      
        <p>
      
      <br/>
            <p style="text-align: center">
      
        <asp:Label ID="lblsep1" runat="server" Height="10px"  style="margin-left:0px;" Width="1000px" BackColor="#0000CC"></asp:Label>
        </p>
                        
        <p style="text-align: left">
            &nbsp;</p>
      
   <h2 style="border:1px solid black;width:249px; margin:auto; text-align: center;">
        Search About Patient</h2>
        <p style="text-align: left">
            &nbsp;</p>
        <p style="text-align: center">

        <asp:Label ID="lblpatid3" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:22px;" Text="ID" Width="33px"></asp:Label>
        <asp:TextBox ID="txtpatid3" runat="server" Width="92px" min="0" style="margin-left: 5px; text-align: center;" Height="26px" autocomplete="off" TextMode="Number"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator18" runat="server" ControlToValidate="txtpatid3" ErrorMessage="You Forget The Patient ID" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="g">*</asp:RequiredFieldValidator>
    
                <asp:Button ID="btnser" runat="server" Height="33px" Text="Search"  style="margin-left: 68px; font-size:18px;" ValidationGroup="g" Width="79px" OnClick="btnser_Click" />
    
                </p>
        <h3 style="text-align: center">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; OR</h3>
        <p style="text-align: left">

        <asp:Label ID="lblpatid4" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:440px;" Text="NationalId" Width="72px"></asp:Label>
        <asp:TextBox ID="txtpatid4" runat="server" Width="92px" style="margin-left: 39px; text-align: center;" Height="26px" autocomplete="off"></asp:TextBox>
    
            <asp:RequiredFieldValidator ID="RequiredFieldValidator19" runat="server" ControlToValidate="txtpatid4" ErrorMessage="You Forget The Patient Name" Font-Size="X-Large" ForeColor="#CC0000" ValidationGroup="f">*</asp:RequiredFieldValidator>
    
                <asp:Button ID="Button3" runat="server" Font-Size="Large" Height="34px" OnClick="Button3_Click" style="margin-left: 60px" Text="Search" ValidationGroup="f" Width="86px" />
    
        </p>
        <p style="text-align: center">

        <asp:Label ID="lblstatus5" runat="server" Height="20px" style="text-align: left;font-size:22px;margin-left:20px;" Text="Status" Width="65px"></asp:Label>
        <asp:TextBox ID="txtpatinsert3" runat="server" Width="209px" style="margin-left: 5px; text-align: center;" Height="26px" Enabled="False" Font-Size="Medium">Successed/not Successed</asp:TextBox>

                <asp:Button ID="btnserrest" runat="server" Height="33px" Text="Rest" style="margin-left: 10px;font-size:18px;" Width="88px" OnClick="btnserrest_Click" />
    
        </p>

            <asp:ValidationSummary ID="ValidationSummary5" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="f" Height="32px" />
      
            <asp:ValidationSummary ID="ValidationSummary6" runat="server" style="text-align: center" Font-Size="X-Large" ForeColor="Black" ValidationGroup="g" Height="32px" />
      
              </form>
      
   <h2 style="border:1px solid black;width:249px; margin:auto; text-align: center;">
        Result Of Search</h2>
    <p style="text-align: center">
        &nbsp;</p>

    <div style="width: 1000px; height: 99px;" runat="server" id="divresult">

    </div>


</html>
