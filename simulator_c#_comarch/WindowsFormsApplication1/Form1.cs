using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
namespace WindowsFormsApplication1
{
     
    public partial class Form1 : Form
    {
        char s;//dertermine number is float or integer
        string checkOP = null;
        char BinaryOrDecimal;
        
        int i;
        public Form1()
        {
            InitializeComponent();
            initialize();
        }
        void initialize()
        {

            addcom.DropDownStyle = ComboBoxStyle.DropDownList;
            subcom.DropDownStyle = ComboBoxStyle.DropDownList;
            mulcom.DropDownStyle = ComboBoxStyle.DropDownList;
            divcom.DropDownStyle = ComboBoxStyle.DropDownList;
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void addcom_SelectedIndexChanged(object sender, EventArgs e)
        {
            checkOP = addcom.Text;
        }

        private void subcom_SelectedIndexChanged(object sender, EventArgs e)
        {

            checkOP = subcom.Text;
        }

        private void mulcom_SelectedIndexChanged(object sender, EventArgs e)
        {
            checkOP = mulcom.Text;
        }

        private void divcom_SelectedIndexChanged(object sender, EventArgs e)
        {
            checkOP = divcom.Text;
        }

        private void binradio_CheckedChanged(object sender, EventArgs e)
        {

            string Number1, Number2 = null;
            int x = 0;
            decradio.Checked = false;
            

            Number1 = n1.Text;
            Number2 = n2.Text;

            if (binradio.Checked == true)
            {


                bool test3 = testinputisalreadybinary(Number1);

                bool test4 = testinputisalreadybinary(Number2);


                if (test3 == false)
                {
                    MessageBox.Show("here is a wrong in input numbers", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    x = 1;
                    binradio.Checked = false;
                }
                else if (test4 == false)
                {
                    MessageBox.Show("There is a wrong in input numbers", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    x = 1;
                    binradio.Checked = false;
                }
            }


            if (x == 0)
            {
                if (Number1.Count(c => c == '.') == 0 && Number2.Count(c => c == '.') == 0)
                {
                    //BinaryFill();
                    BinaryOrDecimal = 'b'; s = 'i';

                }
                else  //else here represent the float addition or substraction of decimal naumbers
                {
                    BinaryOrDecimal = 'b'; s = 'f';


                }
            }
        }
                   
        private void decradio_CheckedChanged(object sender, EventArgs e)
        {
            string Number1, Number2 = null;
            int x = 0;
            Number1 = n1.Text;
               Number2 = n2.Text;
            binradio.Checked = false;
            
              
                 if (decradio.Checked == true)
                 {
                    

                     bool test3 = testinputisalreadydecimal(Number1);

                     bool test4 = testinputisalreadydecimal(Number2);


                     if (test3 == false)
                     {
                         MessageBox.Show("here is a wrong in input numbers", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                         x = 1;
                         decradio.Checked = false;
                     }
                     else if (test4 == false)
                     {
                         MessageBox.Show("There is a wrong in input numbers", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                         x = 1;
                         decradio.Checked = false;
                     }
                 }
             
            
            if (x == 0)
            {
                if (Number1.Count(c => c == '.') == 0 && Number2.Count(c => c == '.') == 0)
                {
                    //BinaryFill();
                    BinaryOrDecimal = 'd';s='i';

                }
                else  //else here represent the float addition or substraction of decimal naumbers
                {
                    BinaryOrDecimal = 'd'; s = 'f';


                }
            }
            }
        private void comp_Click(object sender, EventArgs e)
        {
            string Number1, Number2 = null;
            Number1 = n1.Text;
            Number2 = n2.Text;
            if (string.IsNullOrWhiteSpace(r.Text))
            {
                if (!string.IsNullOrEmpty(n1.Text) && !string.IsNullOrEmpty(n2.Text))
                {
                    //if (binradio.Checked == false && decradio.Checked == false)
                    //{
                        if (checkOP == "Addition")
                        {
                            if (s == 'i')
                            { Display_Add_Sub_IntDecimal_Numbers(Number1, Number2, BinaryOrDecimal); op.Text = " Operation : Addition"; me.Text = "Method : Normal"; }
                            else if (s == 'f')
                            { Display_Add_Sub_float_Numbers(Number1, Number2, BinaryOrDecimal); op.Text = " Operation : Addition"; me.Text = "Method : Normal"; }
                        }

                        else if (checkOP == "Substraction")
                        {
                            if (BinaryOrDecimal == 'b')
                            {
                                if (Number2[0] == '0')
                                {
                                    StringBuilder sb = new StringBuilder(Number2);
                                    sb[0] = '1';
                                    Number2 = sb.ToString();
                                }
                                else
                                {
                                    StringBuilder sb = new StringBuilder(Number2);
                                    sb[0] = '0';
                                    Number2 = sb.ToString();
                                }
                            }
                            else
                            {
                                if (Number2[0] == '-')
                                    Number2 = Number2.Remove(0, 1);
                                else Number2 = "-" + Number2;

                            }
                            if (s == 'i')
                            {
                                Display_Add_Sub_IntDecimal_Numbers(Number1, Number2, BinaryOrDecimal);
                                op.Text = " Operation : Substraction"; me.Text = "Method : Normal";
                            }
                            else if (s == 'f')
                            {
                                Display_Add_Sub_float_Numbers(Number1, Number2, BinaryOrDecimal);
                                op.Text = " Operation : Substraction"; me.Text = "Method : Normal";
                            }
                        }

                        else if (checkOP == "Bit_Paire_Multiplication")
                        {
                            MUL_Bit_Pair(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Multiplication"; me.Text = "Method : Bit-Pair Algorithm";
                        }
                        else if (checkOP == "Booth _Multiplication")
                        {
                            MUL_Booth_Alogorithm(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Multiplication"; me.Text = "Method : Booth Algorithm";

                        }
                        else if (checkOP == "Sign_Extension_Multiplication")    
                        {
                            MUL_Sign_Extension(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Multiplication"; me.Text = "Method : Sign Extension Algorithm";
                        }
                        else if (checkOP == "NonRestoting_Division")
                        {
                            Non_Restoring_Division(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Division"; me.Text = "Method : Non-Restoring Algorithm";
                        }
                        else if (checkOP == "    Restoting_Division")
                        {
                            Restoring_Division(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Division"; me.Text = "Restoring Algorithm";
                        }
                        else if (checkOP == "Sequential_Multiplication")
                        {
                            MUL_Sequential(Number1, Number2, BinaryOrDecimal);
                            op.Text = " Operation : Division"; me.Text = "MUL_Sequential Algorithm";
                        }

                        else { MessageBox.Show("determine the operation firestly", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error); }
                    }
                //    else { MessageBox.Show("dertermine the data type firestly", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error); }
                //}
            
         else { MessageBox.Show("input numbers firestly", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error); }
        }
            else { MessageBox.Show("Reset the program firestly", "Message", MessageBoxButtons.OK, MessageBoxIcon.Error); }
            
        }
          private void resert_Click(object sender, EventArgs e)
          {
              r.Clear();
              binradio.Checked = false;
              decradio.Checked = false;
              op.Text = " Operation : "; me.Text = "Method : ";
          }
          void Display_Add_Sub_IntDecimal_Numbers(string number1, string number2, char c)
          {

              int res = 0;
              string carry = "";
              string result = "";
              char f = '0';
              Make_Qulified_numbers(ref number1, ref number2, c, ref res, 'A');
              r.AppendText("Number1 = " + number1 + Environment.NewLine);
              r.AppendText("Number2 = " + number2 + Environment.NewLine);
              r.AppendText("____________________" + Environment.NewLine + Environment.NewLine);
              Make_Twos_Equal(ref number1, ref number2);
              carry = Function_Add_Two_Decimal_Numbers(number1, number2, ref result, ref f);          
            
              r.AppendText("Carry  ".PadRight(13) + carry + Environment.NewLine + Environment.NewLine);
              r.AppendText("Number1  ".PadRight(10) + number1 + Environment.NewLine + Environment.NewLine);
              r.AppendText("Number2  ".PadRight(10) + number2 + Environment.NewLine) ;
              r.AppendText("____________________" + Environment.NewLine );
              r.AppendText("result  ".PadRight(14) + result + Environment.NewLine + Environment.NewLine);

              r.AppendText("result = " +res+ Environment.NewLine);


          }
          string fromdfloatdecimaltosingleprecision(string s)
          {
              float argument = (float)Convert.ToDouble(s);
              byte[] byteArray = BitConverter.GetBytes(argument);
              string ss = string.Join("",
                 byteArray.Reverse().Select(y => Convert.ToString(y, 2).PadLeft(8, '0')));
              return ss;


          }
          string frombnaryfloattosigleprecision(string s, ref float resul)
          {
              string high = s.Substring(0, s.IndexOf("."));
              string low = s.Substring(s.IndexOf(".") + 1);
              high = high.Remove(0, 1);
              int highi = Convert.ToInt32(high, 2);
              float sum = 0f;
              for (int j = 0; j <= low.Length - 1; j++)
              {
                  if (low[j] == '1')
                      sum += Convert.ToSingle(Math.Pow(2, -1 * (j + 1)));
              }
              float highf = (float)highi;

              if (s[0] == '1') { resul = -1 * (highf + sum); return fromdfloatdecimaltosingleprecision(resul.ToString()); }

              else { resul = (highf + sum); return fromdfloatdecimaltosingleprecision(resul.ToString()); }



          }
          bool testinputisalreadydecimal(string s)
          {
              int occurence_of_point = 0;
              foreach (char c in s) { if (c == '.') occurence_of_point++; }
              int h = 1;
              for (int j = 0; j < s.Length - 1; j++)
              {
                  if (!(char.IsDigit(s[j])) && s[j] != '.' && s[j] != '-')
                  { h = 0; break; }
              }
              if (h == 1 && s.Count(c => c == '.') <= 1 && s.Count(c => c == '-') <= 1)
                  return true;
              else
                  return false;
          }
          bool testinputisalreadybinary(string s)
          {

              int h = 1;

              foreach (char c in s)
              {
                  if (c != '0' && c != '1' && c != '.')
                      h = 0;
              }
              if (h == 1 && (s.Count(c => c == '.')) <= 1)
                  return true;
              else
                  return false;
          }
          string twoscomtobinaryinbinary(string H)
          {
              Stack<char> s = new Stack<char>();
              Boolean exit = false;
              StringBuilder res = new StringBuilder();
              for (int j = H.Length - 1; j >= 0; j--)
              {
                  if (exit == false)
                  {
                      if (H[j] == '1')
                      {
                          s.Push(H[j]);
                          exit = true;
                      }
                      else
                          s.Push(H[j]);
                  }
                  else
                  {
                      if (H[j] == '0')
                          s.Push('1');
                      else
                          s.Push('0');
                  }
              }

              foreach (char c in s) { res.Append(c); }
              return res.ToString();

          }
          string twoscomtobinary(string H)
          {

              if ((Int32.Parse(H)) < 0)
              {

                  int num = -1 * (Int32.Parse(H));
                  H = Convert.ToString(num, 2);
                  H = "0" + H;
                  string res = twoscomtobinaryinbinary(H);
                  return res;
              }
              else
              {
                  int n1 = (Int32.Parse(H));
                  H = Convert.ToString(n1, 2);
                  H = "0" + H;
                  return H;
              }
          }
          void Make_Twos_Equal(ref string num1, ref string num2)
          {
              if (num1.Length > num2.Length)
                  num2 = string.Join("", Enumerable.Repeat(num2[0], num1.Length - num2.Length)) + num2;

              else if (num1.Length < num2.Length)
                  num1 = string.Join("", Enumerable.Repeat(num1[0], num2.Length - num1.Length)) + num1;

          }
          string Function_Add_Two_Decimal_Numbers(string num1, string num2, ref string result, ref char d)
          {
              Stack<char> res = new Stack<char>();
              Stack<char> carr = new Stack<char>();
              StringBuilder carb = new StringBuilder();
              StringBuilder resb = new StringBuilder();
              char c = '0';
              carr.Push('0');
              for (int j = num1.Length - 1; j >= 0; j--)
              {
                  if (num1[j] == '0' && num2[j] == '0') { res.Push(c); c = '0'; carr.Push(c); }
                  else if (num1[j] == '1' && num2[j] == '1')
                  {
                      if (c == '0') { res.Push('0'); c = '1'; carr.Push(c); }
                      else { res.Push('1'); carr.Push(c); }
                  }
                  else
                  {
                      if (c == '0') { res.Push('1'); carr.Push(c); }
                      else { res.Push('0'); carr.Push(c); }
                  }

              }

              foreach (char ch in res) { resb.Append(ch); }
              foreach (char ch in carr) { carb.Append(ch); }

              if (d == '0') { d = c; }
              result = resb.ToString();
              return ((carb.ToString()).Remove(0, 1));
          }
          void function_convert_decimal_tobinary(ref string number1, ref string number2)
          {
              if (Int32.Parse(number1) >= 0)
              { number1 = "0" + (Convert.ToString(Int32.Parse(number1), 2)); }
              else
              { number1 = twoscomtobinary(number1); }


              if (Int32.Parse(number2) >= 0)
              { number2 = "0" + (Convert.ToString(Int32.Parse(number2), 2)); }
              else
              { number2 = twoscomtobinary(number2); }
          }
       
          void Display_Add_Sub_float_Numbers(string number1, string number2, char c)
          {
              string mentis1, mentis2, exp1, exp2;
              float resul = 0.0f;
              int e1, e2, m1, m2, diffe, addmentis;
              string resultsign, resexp, resultmentissa, result;
              char s1, s2;
              if (c == 'd')
              {
                  resul = (float)Convert.ToDouble(number1) + (float)Convert.ToDouble(number2);
                  number1 = fromdfloatdecimaltosingleprecision(number1);
                  number2 = fromdfloatdecimaltosingleprecision(number2);

              }
              else
              {
                  float res1 = 0.0f, res2 = 0.0f;
                  number1 = frombnaryfloattosigleprecision(number1, ref res1);
                  number2 = frombnaryfloattosigleprecision(number2, ref res2);
                  resul = res1 + res2;
              }
              exp1 = number1.Substring(1, 8);
              exp2 = number2.Substring(1, 8);
              mentis1 = "1" + number1.Substring(9, 23);
              mentis2 = "1" + number2.Substring(9, 23);
              s1 = number1[0];
              s2 = number2[0];
              r.AppendText("number1 in single precision =   " + number1+Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
              r.AppendText("number2 in single precision =   " + number2 + Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
              r.AppendText( "exponent of number1   =   " + exp1 + "         " + Convert.ToInt32(exp1, 2) + Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
              r.AppendText( "exponent of number2   =   " + exp2 + "           " + Convert.ToInt32(exp2, 2) + Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
              r.AppendText("significant of number1 =  " + mentis1.Insert(1, ".") + Environment.NewLine);
              r.AppendText("significant of number2 =  " + mentis2.Insert(1, ".") + Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
              r.AppendText("sign of number1   =   " + s1 + Environment.NewLine);
              r.AppendText(" ________________________________  " + Environment.NewLine);
               r.AppendText("sign of number2   =   " + s2 + Environment.NewLine);
               r.AppendText(" ________________________________  " + Environment.NewLine);
              
               e1 = Convert.ToInt32(exp1, 2);
               
               e2 = Convert.ToInt32(exp2, 2);
            
               if (e1 > e2)
               {
                  
                   r.AppendText("we can note that exponent of number1 is greater than of number2" + Environment.NewLine);
                   r.AppendText("so we modify the exponent of number2 to make them are equal" + Environment.NewLine);
                   resexp = exp1;
                   diffe = e1 - e2;
                   r.AppendText("difference between two exponents= " + diffe + Environment.NewLine);
                   mentis2 = (new string('0', diffe)) + mentis2;
                   r.AppendText("new mentissa of number2= " + mentis2.Insert(1, ".") + Environment.NewLine);
                   r.AppendText("we neglect bits out 23 of mentissa part " + Environment.NewLine);
                   mentis2 = mentis2.Substring(0, 24);
                   r.AppendText("mentissa2  =" + mentis2.Insert(1, ".") + Environment.NewLine);
               }
               else if (e1 < e2)
               {
                   r.AppendText("we can note that exponent of number1 is greater than of number2" + Environment.NewLine);
                   r.AppendText("so we modify the exponent of number2 to make them are equal" + Environment.NewLine);
                   resexp = exp2;
                   diffe = e2 - e1;
                   r.AppendText("difference between two exponents= " + diffe + Environment.NewLine);

                   mentis1 = (new string('0', diffe)) + mentis1;
                   r.AppendText("new mentissa of number1= " + mentis1.Insert(1, ".") + Environment.NewLine);
                   r.AppendText(r.Text = mentis1 = mentis1.Substring(0, 24));
                   r.AppendText("mentissa2  = " + mentis2.Insert(1, ".") + Environment.NewLine);
               }
               else
               { resexp = exp1; r.AppendText("exponents of numbers are equal so we add mentissa of numbers directely" + Environment.NewLine); }
               r.AppendText("now we add the two mentissa two each other" + Environment.NewLine);
               r.AppendText(mentis1.Insert(1, ".") + Environment.NewLine);
               r.AppendText ( mentis2.Insert(1, ".") + Environment.NewLine);
               r.AppendText("_____________________" + Environment.NewLine);
               if (s1 == '1') { m1 = -1 * (Convert.ToInt32(mentis1, 2)); } else { m1 = (Convert.ToInt32(mentis1, 2)); }
               if (s2 == '1') { m2 = -1 * (Convert.ToInt32(mentis2, 2)); } else { m2 = (Convert.ToInt32(mentis2, 2)); }
               addmentis = m1 + m2;
               r.AppendText("addition of mentissa" + addmentis + Environment.NewLine);
               if (addmentis < 0)
               {
                   resultsign = "1"; resultmentissa = Convert.ToString(-1 * addmentis, 2);

               }
               else if (addmentis == 0) { resultsign = "0"; resultmentissa = new string('0', 23); }
               else
               {
                   resultsign = "0"; resultmentissa = Convert.ToString(addmentis, 2);
               }
               if (resultmentissa.Length == 25)
               {
                   r.AppendText(resultmentissa.Insert(1, ".") + Environment.NewLine);

                   resultmentissa = resultmentissa.Substring(0, 24);
                   r.AppendText("we neglect the first bit and shift the point to left" + Environment.NewLine);
                   r.AppendText(resultmentissa.Insert(1, ".") + Environment.NewLine);
                   r.AppendText(Convert.ToString((Convert.ToInt32(resexp, 2) + 1), 2));
                   r.AppendText("we add one to the exponent of the result because of shifting point to left" + Environment.NewLine);
                   r.AppendText("new exponent of result= {" + resexp + Environment.NewLine);

               }
               else { r.AppendText( resultmentissa.Insert(1, ".") + Environment.NewLine); }
               result = resultsign + resexp + resultmentissa.Remove(0, 1);
               r.AppendText("the final result in single precision = " + result + Environment.NewLine);
              
              
             r.AppendText( "result = " + resul + Environment.NewLine);
          }
          void Make_Qulified_numbers(ref string number1, ref string number2, char c, ref int res, char op)
          {
              int n1 = 0; int n2 = 0;
              if (c == 'd')
              {
                  if (op == 'A') { res = Int32.Parse(number1) + Int32.Parse(number2); }
                  else if (op == 'M') { res = Int32.Parse(number1) * Int32.Parse(number2); }
                  else { res = Int32.Parse(number1) / Int32.Parse(number2); }

                  function_convert_decimal_tobinary(ref  number1, ref  number2);
              }
              else
              {

                  if (number1[0] == '1')
                  {
                      n1 = -1 * (Convert.ToInt32(number1.Remove(0, 1), 2));
                      StringBuilder sb = new StringBuilder(number1);
                      sb[0] = '0';
                      number1 = sb.ToString();
                      number1 = twoscomtobinaryinbinary(number1);

                  }
                  else n1 = Convert.ToInt32(number1, 2);

                  if (number2[0] == '1')
                  {
                      n2 = -1 * (Convert.ToInt32(number2.Remove(0, 1), 2));
                      StringBuilder sb = new StringBuilder(number2);
                      sb[0] = '0';
                      number2 = sb.ToString();

                      number2 = twoscomtobinaryinbinary(number2);
                  }
                  else n2 = Convert.ToInt32(number2, 2);
                  if (op == 'A') { res = n1 + n2; } else if (op == 'M') { res = n1 * n2; } else { res = n1 / n2; }
              }
          }
          void Determine_M_Q(ref string number1, ref string number2, ref string multipleir, ref string multiplicant, ref string zeros, ref string tempresult, ref string result)
          {
              if (number1.Length < number2.Length)
              {

                  result = zeros = new string('0', 2 * number2.Length);
                  tempresult = new string(number2[0], number2.Length) + number2;
                  multipleir = number1; multiplicant = number2;
                  r.AppendText("multiplicant       ".PadRight(5) + number2+Environment.NewLine);
                  r.AppendText("multipleir         ".PadRight(5) + number1 + Environment.NewLine);
                  r.AppendText("_________________________________________" + Environment.NewLine);
              }
              else if ((number2.Length < number1.Length) || (number2.Length == number1.Length))
              {

                  result = zeros = new string('0', 2 * number1.Length);
                  tempresult = new string(number1[0], number1.Length) + number1;
                  multipleir = number2; multiplicant = number1;
                  r.AppendText("multiplicant           ".PadRight(5) + number1 + Environment.NewLine);
                  r.AppendText("multipleir             ".PadRight(5) + number2 + Environment.NewLine);
                  r.AppendText("_________________________________________" + Environment.NewLine);
              }
              else { }
          }
          void MUL_Sign_Extension(string number1, string number2, char c)
          {

              string zeros = ""; string tempresult = "";
              string multipleir = "";
              string multiplicant = "";
              string result = "";
              int res = 0;


              Make_Qulified_numbers(ref number1, ref number2, c, ref res, 'M');
              r.AppendText("number1 = " + number1 + Environment.NewLine);
              r.AppendText("number2 = " + number2 + Environment.NewLine);
              r.AppendText("________________________________" + Environment.NewLine);
              Determine_M_Q(ref number1, ref number2, ref multipleir, ref multiplicant, ref zeros, ref tempresult, ref  result);
              result = "";
              for (int j = multipleir.Length - 1; j >= 0; j--)
              {
                  if (multipleir[j] == '0') { r.AppendText("".PadRight(18) + zeros + Environment.NewLine); }
                  else
                  {

                      int k = multipleir.Length - 1 - j;
                      string dis = tempresult.Substring(k, tempresult.Length - k) + new string('0', k);
                      r.AppendText("".PadRight(18) + dis + Environment.NewLine);


                  }
              }
              r.AppendText("________________________________" + Environment.NewLine);

              if (res >= 0) { result = Convert.ToString(res, 2); result = new string('0', tempresult.Length - result.Length) + result; }
              if (res < 0) { result = twoscomtobinary(res.ToString()); result = new string('1', tempresult.Length - result.Length) + result; }
              r.AppendText("".PadRight(18) + result + "               result= " + res + Environment.NewLine);



          }
          void MUL_Booth_Alogorithm(string number1, string number2, char c)
          {

              int res = 0;
              string multibooth = "";
              
              string zeros = ""; string tempresult = "";
              string multipleir = "";
              string multiplicant = "";
              string result = "";

              Make_Qulified_numbers(ref number1, ref number2, c, ref res, 'M');
              r.AppendText("number1 = " + number1+Environment.NewLine);
              r.AppendText("number2 = " + number2 + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine);
              Determine_M_Q(ref number1, ref number2, ref multipleir, ref multiplicant, ref zeros, ref tempresult, ref  result);
              
              multipleir = multipleir + "0";
              
              string[] boothmultip = new string[multipleir.Length - 1];
              for (int l = multipleir.Length-1; l >= 1; l--)
              {
                  int j = multipleir.Length - 1 - l;
                  if (multipleir[l] == '0' && multipleir[l - 1] == '1') {  boothmultip[j]="-1"; }
                  else if (multipleir[l] == '1' && multipleir[l - 1] == '0') { boothmultip[j] = "+1";  }
                  else { boothmultip[j] = "0"; }
              }
              
              for (int j = boothmultip.Length - 1; j>=0; j--)
              { multibooth +=" "+ boothmultip[j]; }
              r.AppendText("multiplicant".PadRight(23) + multiplicant + Environment.NewLine);
              r.AppendText("multiplier in booth".PadRight(20) + multibooth + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine);
              string distwos = twoscomtobinaryinbinary(tempresult);
              for (int j = 0; j <= boothmultip.Length - 1; j++)
              {

                  string s = boothmultip.ElementAt(j);
                  if (s == "0") { r.AppendText("".PadRight(20) + zeros + Environment.NewLine); }
                  else if (s == "+1")    
                  {
                      string dis = tempresult.Substring(j, tempresult.Length - j) + new string('0', j);
                      r.AppendText("".PadRight(20) + dis + Environment.NewLine);
                  }
                  else
                  {

                      int k = multipleir.Length - 1 - j;
                      distwos = distwos.Substring(j, tempresult.Length - j) + new string('0', j);//shifting
                      r.AppendText("".PadRight(20) + distwos + Environment.NewLine);

                  }
              }
               r.AppendText("________________________________________" + Environment.NewLine);
              if (res >= 0) { result = Convert.ToString(res, 2); result = new string('0', tempresult.Length - result.Length) + result; }
              if (res < 0) { result = twoscomtobinary(res.ToString()); result = new string('1', tempresult.Length - result.Length) + result; }
              r.AppendText("".PadRight(20) + result + Environment.NewLine + Environment.NewLine);
              r.AppendText("".PadRight(20)+" result= " + res + Environment.NewLine);
          }
          void MUL_Sequential(string number1, string number2, char c)
          {
              string zeros = ""; string tempresult = "";
              string multipleir = "";
              string multiplicant = "";
              string result = "";
              int res = 0;
              char C = '0';
              char d = '0';
              Make_Qulified_numbers(ref number1, ref number2, c, ref res, 'M');
              r.AppendText("number1 = " + number1 + Environment.NewLine);
              r.AppendText("number2 = " + number2 + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine);
              Determine_M_Q(ref number1, ref number2, ref multipleir, ref multiplicant, ref zeros, ref tempresult, ref  result);
             
              result = new string('0', multiplicant.Length);
              r.AppendText("".PadRight(12) + "M" + Environment.NewLine);

              r.AppendText("".PadRight(10) + multiplicant.PadRight(15) + Environment.NewLine);
              r.AppendText("0".PadRight(10) + result.PadRight(10) + multipleir + Environment.NewLine);
              r.AppendText("C".PadRight(13) + "A".PadRight(14) + "Q" + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine );

              for (int p = multipleir.Length - 1; p >= 0; p--)
              {
                  r.AppendText("".PadRight(13)+"cycle number " + (multipleir.Length +(- 1-p) )+ Environment.NewLine);
                  r.AppendText("_________________________________________" + Environment.NewLine);
                  if (multipleir[multipleir.Length - 1] == '1')
                  {
                      string rp = result;
                      string h = Function_Add_Two_Decimal_Numbers(rp, multiplicant, ref result, ref d);

                      
                      r.AppendText(d.ToString().PadRight(10) + result.PadRight(10) + multipleir.PadRight(10) + "add".PadRight(10) + Environment.NewLine);
                      multipleir = result[result.Length-1] + multipleir.Substring(0, multipleir.Length - 1); result = C + result.Substring(0, result.Length - 1);
                      r.AppendText("0".ToString().PadRight(10) + result.PadRight(10) + multipleir.PadRight(10) + "Shift".PadRight(10) + Environment.NewLine);
                  }
                  else
                  {
                      r.AppendText(d.ToString().PadRight(10) + result.PadRight(10) + multipleir.PadRight(10) + "No add".PadRight(10) + Environment.NewLine);
                      multipleir = result[result.Length - 1] + multipleir.Substring(0, multipleir.Length - 1); result = C + result.Substring(0, result.Length - 1);
                      r.AppendText("0".PadRight(10) + result.PadRight(10) + multipleir.PadRight(10) + "Shift".PadRight(10) + Environment.NewLine);
                  }
                  r.AppendText("_________________________________________" + Environment.NewLine);
              }
              r.AppendText("".PadRight(5)+"result = "+result+multipleir+Environment.NewLine);
              r.AppendText("".PadRight(5) + "result = " + res + Environment.NewLine);
          }
          void MUL_Bit_Pair(string number1, string number2, char c)
          {

              int res = 0;
              string multibooth = "";
              Stack<string> boothmultip = new Stack<string>();
              string zeros = ""; string tempresult = "";
              string multipleir = "";
              string multiplicant = "";
              string result = "";
              StringBuilder ui = new StringBuilder();
              Make_Qulified_numbers(ref number1, ref number2, c, ref res, 'M');
              r.AppendText("number1 = " + number1 + Environment.NewLine);
              r.AppendText("number2 = " + number2 + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine);
              Determine_M_Q(ref number1, ref number2, ref multipleir, ref multiplicant, ref zeros, ref tempresult, ref  result);

              Make_Twos_Equal(ref multipleir, ref multiplicant);
             

              multipleir = multipleir + "0";
             

              if ((multipleir.Length % 2) == 0) { multipleir = multipleir[0] + multipleir; }
              Stack<string> mb = new Stack<string>();
              for (i = multipleir.Length - 1; i >= 2; i -= 2)
              {

                  string m = multipleir;
                  if (m[i] == '0' && m[i - 1] == '0' && m[i - 2] == '0') { boothmultip.Push("0"); mb.Push(" " + "0"); }
                  if (m[i] == '1' && m[i - 1] == '0' && m[i - 2] == '0') { boothmultip.Push("+1"); mb.Push(" " + "+1"); }
                  if (m[i] == '0' && m[i - 1] == '1' && m[i - 2] == '0') { boothmultip.Push("+1"); mb.Push(" " + "+1"); }
                  if (m[i] == '1' && m[i - 1] == '1' && m[i - 2] == '0') { boothmultip.Push("+2"); mb.Push(" " + "+2"); }
                  if (m[i] == '0' && m[i - 1] == '0' && m[i - 2] == '1') { boothmultip.Push("-2"); mb.Push(" " + "-2"); }
                  if (m[i] == '1' && m[i - 1] == '0' && m[i - 2] == '1') { boothmultip.Push("-1"); mb.Push(" " + "-1"); }
                  if (m[i] == '0' && m[i - 1] == '1' && m[i - 2] == '1') { boothmultip.Push("-1"); mb.Push(" " + "-1"); }
                  if (m[i] == '1' && m[i - 1] == '1' && m[i - 2] == '1') { boothmultip.Push("0"); mb.Push(" " + "0"); }
              }

              foreach (string g in mb) { ui.Append(g); }
              multibooth = ui.ToString();

              r.AppendText("multiplicant".PadRight(23) + multiplicant + Environment.NewLine);
              r.AppendText("multiplier in booth".PadRight(20) + multibooth + Environment.NewLine);
              r.AppendText("_________________________________________" + Environment.NewLine);
              string distwos = twoscomtobinaryinbinary(tempresult);

              for (i = boothmultip.Count - 1; i >= 0; i--)
              {
                  int k = (boothmultip.Count - 1) - i;

                  string s = boothmultip.ElementAt(i);
                  if (s == "0") { Console.WriteLine("".PadRight(20) + zeros); }
                  else if (s == "+1")
                  {
                      string dis = tempresult.Substring(2 * k, tempresult.Length - 2 * k) + new string('0', 2 * k);
                      r.AppendText("".PadRight(20) + dis + Environment.NewLine);
                  }
                  else if (s == "-1")
                  {


                      distwos = distwos.Substring(2 * k, tempresult.Length - 2 * k) + new string('0', 2 * k);//shifting
                      r.AppendText("".PadRight(20) + distwos + Environment.NewLine);

                  }
                  else if (s == "+2")
                  {

                      string dis = tempresult.Substring(2 * k + 1, tempresult.Length - (2 * k + 1)) + new string('0', (2 * k + 1));
                      r.AppendText("".PadRight(20) + dis + Environment.NewLine);
                  }
                  else
                  {

                      string dist;
                      dist = distwos.Substring(2 * k + 1, distwos.Length - (2 * k + 1)) + new string('0', (2 * k + 1));
                      r.AppendText("".PadRight(20) + dist + Environment.NewLine);
                  }

              }
              r.AppendText("_________________________________________" + Environment.NewLine);
              if (res >= 0) { result = Convert.ToString(res, 2); result = new string('0', tempresult.Length - result.Length) + result; }
              if (res < 0) { result = twoscomtobinary(res.ToString()); result = new string('1', tempresult.Length - result.Length) + result; }
              r.AppendText("".PadRight(20)+ result  + Environment.NewLine+ Environment.NewLine);;

              r.AppendText("".PadRight(20)+"Result = "+res+  Environment.NewLine);
          }
          void Restoring_Division(string number1, string number2, char c)
          {
              string result = ""; int res = 0;
              char d = '0';
              Make_Qulified_numbers(ref  number1, ref  number2, c, ref res, 'D');
              Make_Twos_Equal(ref  number1, ref  number2);
              number1 = number1.Remove(0, 1);



              string M = number2; string A = new string('0', number2.Length); result = new string('0', number2.Length);
              string mtwos = twoscomtobinaryinbinary(number2);
              r.AppendText(("A".PadLeft(15)) + "Q".PadLeft(25) + Environment.NewLine);
              r.AppendText(("Intially").PadRight(12) + A.PadRight(15) + number1 + Environment.NewLine);
              r.AppendText("".PadRight(3) + ("M").PadRight(9) + number2 + Environment.NewLine);
              r.AppendText("____________________________________"+Environment.NewLine);
              for (int j = 0; j < number1.Length; j++)
              {
                  r.AppendText("".PadLeft(10) + "cycle number " + (j + 1) + Environment.NewLine);
                  r.AppendText("____________________________________" + Environment.NewLine);

                  A = A.Substring(1, A.Length - 1) + number1[0];
                  number1 = number1.Substring(1, number1.Length - 1) + "-";
                  StringBuilder num1 = new StringBuilder(number1);
                  r.AppendText(("shifting").PadRight(13) + A.PadRight(15) + number1 + Environment.NewLine);
                  r.AppendText(("substract").PadRight(12) + mtwos + Environment.NewLine);
                  string h = Function_Add_Two_Decimal_Numbers(A, mtwos, ref result, ref d);
                  r.AppendText("".PadRight(15) + new string('-', result.Length+3) + Environment.NewLine);



                  if (result[0] == '1')
                  {
                      num1[number1.Length - 1] = '0';
                      number1 = num1.ToString();

                      r.AppendText(("Set Q0").PadRight(12) + result + Environment.NewLine);
                      r.AppendText(("Restore").PadRight(12) + M + Environment.NewLine);
                      r.AppendText("".PadRight(15) + new string('-', result.Length+3) + Environment.NewLine);
                      r.AppendText(("").PadRight(15) + A.PadRight(18) + number1 + Environment.NewLine);
                  }
                  else
                  {
                      num1[number1.Length - 1] = '1';
                      number1 = num1.ToString();
                      r.AppendText(("Set Q0").PadRight(12) + result.PadRight(15) + number1+ Environment.NewLine);
                      A = result;
                  }
                  r.AppendText("____________________________________"+ Environment.NewLine);
              }
              if (result[0] == '1')
              {
                  r.AppendText("".PadRight(6) + "the last bit of A is 1 so we restore A" + Environment.NewLine + Environment.NewLine);
                  string k = "";
                  string h = Function_Add_Two_Decimal_Numbers(result, M, ref k, ref d);
                  r.AppendText("A = " + result + " + " + M + " = " + k + Environment.NewLine);
                  r.AppendText("".PadRight(8) + "reminder = " + k + Environment.NewLine);
                  r.AppendText("".PadRight(8) + " remider = " + Convert.ToInt32(k, 2) + Environment.NewLine);
              }
              else
              {
                  r.AppendText("".PadRight(8) + "reminder = " + result + Environment.NewLine);
                  r.AppendText("".PadRight(8) + "remider = " + Convert.ToInt32(result, 2) + Environment.NewLine);
              }
              r.AppendText("".PadRight(8) + "Quotient = " + number1 + Environment.NewLine);
              r.AppendText("".PadRight(8) + "Quotient = " + res + Environment.NewLine + Environment.NewLine);
          }
          void Non_Restoring_Division(string number1, string number2, char c)
          {
              string result = " "; int res = 0;
              char d = '0';
              Make_Qulified_numbers(ref  number1, ref  number2, c, ref res, 'D');
              Make_Twos_Equal(ref  number1, ref  number2);
              number1 = number1.Remove(0, 1);


              number2 = number2[0] + number2;

              string M = number2; string A = new string('0', number2.Length); result = new string('0', number2.Length);
              string mtwos = twoscomtobinaryinbinary(number2);
              r.AppendText("A".PadLeft(15) + "Q".PadLeft(25)+Environment.NewLine);
              r.AppendText(("Intially").PadRight(12) + A.PadRight(15) + number1 + Environment.NewLine);
              r.AppendText("".PadRight(3) + ("M").PadRight(9) + number2 + Environment.NewLine);
              r.AppendText("____________________________________" + Environment.NewLine);
              for (int j = 0; j < number1.Length; j++)
              {
                  r.AppendText("".PadLeft(10) + "cycle number " + (j + 1 )+ Environment.NewLine);
                  r.AppendText("____________________________________" + Environment.NewLine);

                  result = result.Substring(1, result.Length - 1) + number1[0];
                  number1 = number1.Substring(1, number1.Length - 1) + "-";
                  StringBuilder num1 = new StringBuilder(number1);
                  r.AppendText(("shifting").PadRight(13) + result.PadRight(15) + number1 + Environment.NewLine);

                  if (result[0] == '0' || j == 0)
                  {
                      r.AppendText(("substract").PadRight(13) + mtwos + Environment.NewLine);
                      string h = Function_Add_Two_Decimal_Numbers(result, mtwos, ref result, ref c);
                      if (result[0] == '0')
                      {
                          num1[number1.Length - 1] = '1';
                          number1 = num1.ToString();
                      }
                      else
                      {
                          num1[number1.Length - 1] = '0';
                          number1 = num1.ToString();
                      }
                  }
                  else
                  {
                      r.AppendText(("Add").PadRight(12) + M + Environment.NewLine);
                      string h = Function_Add_Two_Decimal_Numbers(result, M, ref result, ref d);
                      if (result[0] == '0')
                      {
                          num1[number1.Length - 1] = '1';
                          number1 = num1.ToString();
                      }
                      else
                      {
                          num1[number1.Length - 1] = '0';
                          number1 = num1.ToString();
                      }

                  }

                  r.AppendText("".PadRight(15) + new string('-', result.Length+5) + Environment.NewLine);
                  r.AppendText(("Set Q0").PadRight(12) + result.PadRight(15) + number1 + Environment.NewLine);
                  r.AppendText("____________________________________" + Environment.NewLine);
              }
              if (result[0] == '1')
              {
                  r.AppendText("".PadRight(6) + "the last bit of A is 1 so we restore A" + Environment.NewLine + Environment.NewLine);
                  string k = "";
                  string h = Function_Add_Two_Decimal_Numbers(result, M, ref k, ref d);
                  r.AppendText("A = " + result + " + " + M + " = " + k + Environment.NewLine );
                  r.AppendText("".PadRight(8) + "reminder = " + k + Environment.NewLine);
                  r.AppendText("".PadRight(8) +" remider = " + Convert.ToInt32(k, 2) + Environment.NewLine);
              }
              else { r.AppendText("".PadRight(8)+"reminder = " + result + Environment.NewLine);
              r.AppendText("".PadRight(8) + "remider = " + Convert.ToInt32(result, 2) + Environment.NewLine);
              }
              r.AppendText("".PadRight(8) + "Quotient = " + number1 +  Environment.NewLine );
             r.AppendText("".PadRight(8) + "Quotient = " + res+ Environment.NewLine + Environment.NewLine);

          }

          private void n1_TextChanged(object sender, EventArgs e)
          {
              
          }

          private void n2_TextChanged(object sender, EventArgs e)
          {

          }

          private void label4_Click(object sender, EventArgs e)
          {

          }

          private void label3_Click(object sender, EventArgs e)
          {

          }

          private void me_Click(object sender, EventArgs e)
          {

          }

          private void saveToolStripMenuItem_Click(object sender, EventArgs e)
          {
              saveFileDialog1.Filter="textfile | * .TXT";
              saveFileDialog1.InitialDirectory = "D:\\";
              if(saveFileDialog1.ShowDialog()==DialogResult.OK)
              {
                  File.WriteAllText(saveFileDialog1.FileName,r.Text);

              }
          }

          private void exitToolStripMenuItem_Click(object sender, EventArgs e)
          {
              this.Close();
          }

          private void aboutProgramToolStripMenuItem_Click(object sender, EventArgs e)
          {
              MessageBox.Show("this program very simple simulation of arthimatic operation "+Environment.NewLine+"in the computer and its purpose is learining"
                 ,"About the program",MessageBoxButtons.OK,MessageBoxIcon.Information );
          }

          
    }
}
          

