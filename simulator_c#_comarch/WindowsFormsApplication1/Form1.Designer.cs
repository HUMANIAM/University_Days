namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.comp = new System.Windows.Forms.Button();
            this.addcom = new System.Windows.Forms.ComboBox();
            this.binradio = new System.Windows.Forms.RadioButton();
            this.r = new System.Windows.Forms.RichTextBox();
            this.me = new System.Windows.Forms.Label();
            this.n1 = new System.Windows.Forms.TextBox();
            this.n2 = new System.Windows.Forms.TextBox();
            this.divcom = new System.Windows.Forms.ComboBox();
            this.subcom = new System.Windows.Forms.ComboBox();
            this.mulcom = new System.Windows.Forms.ComboBox();
            this.resert = new System.Windows.Forms.Button();
            this.decradio = new System.Windows.Forms.RadioButton();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.savetext = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutProgramToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.op = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // comp
            // 
            this.comp.Location = new System.Drawing.Point(73, 454);
            this.comp.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.comp.Name = "comp";
            this.comp.Size = new System.Drawing.Size(87, 28);
            this.comp.TabIndex = 0;
            this.comp.Text = "Compute";
            this.comp.UseVisualStyleBackColor = true;
            this.comp.Click += new System.EventHandler(this.comp_Click);
            // 
            // addcom
            // 
            this.addcom.Font = new System.Drawing.Font("Tahoma", 10F);
            this.addcom.FormattingEnabled = true;
            this.addcom.Items.AddRange(new object[] {
            "Addition"});
            this.addcom.Location = new System.Drawing.Point(48, 319);
            this.addcom.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.addcom.Name = "addcom";
            this.addcom.Size = new System.Drawing.Size(112, 24);
            this.addcom.TabIndex = 1;
            this.addcom.Text = "Addition";
            this.addcom.SelectedIndexChanged += new System.EventHandler(this.addcom_SelectedIndexChanged);
            // 
            // binradio
            // 
            this.binradio.AutoSize = true;
            this.binradio.Font = new System.Drawing.Font("Tahoma", 10F);
            this.binradio.Location = new System.Drawing.Point(128, 233);
            this.binradio.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.binradio.Name = "binradio";
            this.binradio.Size = new System.Drawing.Size(64, 21);
            this.binradio.TabIndex = 4;
            this.binradio.TabStop = true;
            this.binradio.Text = "Binary";
            this.binradio.UseVisualStyleBackColor = true;
            this.binradio.CheckedChanged += new System.EventHandler(this.binradio_CheckedChanged);
            // 
            // r
            // 
            this.r.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.r.Font = new System.Drawing.Font("Tahoma", 12F);
            this.r.Location = new System.Drawing.Point(460, 136);
            this.r.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.r.Name = "r";
            this.r.ReadOnly = true;
            this.r.Size = new System.Drawing.Size(424, 492);
            this.r.TabIndex = 5;
            this.r.Text = "";
            // 
            // me
            // 
            this.me.AutoSize = true;
            this.me.Font = new System.Drawing.Font("Tahoma", 15F);
            this.me.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.me.Location = new System.Drawing.Point(594, 101);
            this.me.Name = "me";
            this.me.Size = new System.Drawing.Size(101, 24);
            this.me.TabIndex = 7;
            this.me.Text = "Method :  ";
            this.me.Click += new System.EventHandler(this.me_Click);
            // 
            // n1
            // 
            this.n1.Font = new System.Drawing.Font("Tahoma", 10F);
            this.n1.Location = new System.Drawing.Point(128, 142);
            this.n1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.n1.Name = "n1";
            this.n1.Size = new System.Drawing.Size(206, 24);
            this.n1.TabIndex = 11;
            this.n1.TextChanged += new System.EventHandler(this.n1_TextChanged);
            // 
            // n2
            // 
            this.n2.Font = new System.Drawing.Font("Tahoma", 10F);
            this.n2.Location = new System.Drawing.Point(128, 181);
            this.n2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.n2.Name = "n2";
            this.n2.Size = new System.Drawing.Size(206, 24);
            this.n2.TabIndex = 12;
            this.n2.TextChanged += new System.EventHandler(this.n2_TextChanged);
            // 
            // divcom
            // 
            this.divcom.Font = new System.Drawing.Font("Tahoma", 10F);
            this.divcom.FormattingEnabled = true;
            this.divcom.Items.AddRange(new object[] {
            "Division",
            "    Restoting_Division",
            "NonRestoting_Division"});
            this.divcom.Location = new System.Drawing.Point(234, 366);
            this.divcom.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.divcom.Name = "divcom";
            this.divcom.Size = new System.Drawing.Size(155, 24);
            this.divcom.TabIndex = 13;
            this.divcom.Text = "Division";
            this.divcom.SelectedIndexChanged += new System.EventHandler(this.divcom_SelectedIndexChanged);
            // 
            // subcom
            // 
            this.subcom.Font = new System.Drawing.Font("Tahoma", 10F);
            this.subcom.FormattingEnabled = true;
            this.subcom.Items.AddRange(new object[] {
            "Substraction"});
            this.subcom.Location = new System.Drawing.Point(48, 366);
            this.subcom.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.subcom.Name = "subcom";
            this.subcom.Size = new System.Drawing.Size(112, 24);
            this.subcom.TabIndex = 14;
            this.subcom.Text = "Substraction";
            this.subcom.SelectedIndexChanged += new System.EventHandler(this.subcom_SelectedIndexChanged);
            // 
            // mulcom
            // 
            this.mulcom.Font = new System.Drawing.Font("Tahoma", 10F);
            this.mulcom.FormattingEnabled = true;
            this.mulcom.Items.AddRange(new object[] {
            "Multiplication",
            "Bit_Paire_Multiplication",
            "Booth _Multiplication",
            "Sequential_Multiplication",
            "Sign_Extension_Multiplication"});
            this.mulcom.Location = new System.Drawing.Point(234, 319);
            this.mulcom.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.mulcom.Name = "mulcom";
            this.mulcom.Size = new System.Drawing.Size(155, 24);
            this.mulcom.TabIndex = 15;
            this.mulcom.Text = "Multiplication";
            this.mulcom.SelectedIndexChanged += new System.EventHandler(this.mulcom_SelectedIndexChanged);
            // 
            // resert
            // 
            this.resert.Location = new System.Drawing.Point(234, 454);
            this.resert.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.resert.Name = "resert";
            this.resert.Size = new System.Drawing.Size(87, 28);
            this.resert.TabIndex = 16;
            this.resert.Text = "Reset";
            this.resert.UseVisualStyleBackColor = true;
            this.resert.Click += new System.EventHandler(this.resert_Click);
            // 
            // decradio
            // 
            this.decradio.AutoSize = true;
            this.decradio.Font = new System.Drawing.Font("Tahoma", 10F);
            this.decradio.Location = new System.Drawing.Point(261, 233);
            this.decradio.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.decradio.Name = "decradio";
            this.decradio.Size = new System.Drawing.Size(73, 21);
            this.decradio.TabIndex = 17;
            this.decradio.TabStop = true;
            this.decradio.Text = "Decimal";
            this.decradio.UseVisualStyleBackColor = true;
            this.decradio.CheckedChanged += new System.EventHandler(this.decradio_CheckedChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackgroundImage = global::WindowsFormsApplication1.Properties.Resources.images__67_1;
            this.menuStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(10, 44);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(120, 29);
            this.menuStrip1.TabIndex = 20;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.savetext,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 12F);
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(54, 25);
            this.fileToolStripMenuItem.Text = " FILE";
            // 
            // savetext
            // 
            this.savetext.Name = "savetext";
            this.savetext.Size = new System.Drawing.Size(138, 26);
            this.savetext.Text = "Save file";
            this.savetext.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(138, 26);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutProgramToolStripMenuItem});
            this.helpToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 12F);
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(58, 25);
            this.helpToolStripMenuItem.Text = "HELP";
            // 
            // aboutProgramToolStripMenuItem
            // 
            this.aboutProgramToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 8F);
            this.aboutProgramToolStripMenuItem.Name = "aboutProgramToolStripMenuItem";
            this.aboutProgramToolStripMenuItem.Size = new System.Drawing.Size(156, 22);
            this.aboutProgramToolStripMenuItem.Text = "About program";
            this.aboutProgramToolStripMenuItem.Click += new System.EventHandler(this.aboutProgramToolStripMenuItem_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(109, 522);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(196, 23);
            this.button1.TabIndex = 21;
            this.button1.Text = "Know More About The Method";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(47, 143);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 22;
            this.button2.Text = "Number1";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(47, 181);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 23;
            this.button3.Text = "Number2";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(129, 102);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(176, 23);
            this.button4.TabIndex = 24;
            this.button4.Text = "Input Numbers";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(129, 289);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(176, 23);
            this.button5.TabIndex = 25;
            this.button5.Text = "Choose An Operation";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // op
            // 
            this.op.AutoSize = true;
            this.op.Font = new System.Drawing.Font("Tahoma", 15F);
            this.op.ForeColor = System.Drawing.Color.Blue;
            this.op.Location = new System.Drawing.Point(594, 69);
            this.op.Name = "op";
            this.op.Size = new System.Drawing.Size(111, 24);
            this.op.TabIndex = 3;
            this.op.Text = "Operation :";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::WindowsFormsApplication1.Properties.Resources.images__67_;
            this.ClientSize = new System.Drawing.Size(884, 662);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.decradio);
            this.Controls.Add(this.resert);
            this.Controls.Add(this.mulcom);
            this.Controls.Add(this.subcom);
            this.Controls.Add(this.divcom);
            this.Controls.Add(this.n2);
            this.Controls.Add(this.n1);
            this.Controls.Add(this.me);
            this.Controls.Add(this.r);
            this.Controls.Add(this.binradio);
            this.Controls.Add(this.op);
            this.Controls.Add(this.addcom);
            this.Controls.Add(this.comp);
            this.Controls.Add(this.menuStrip1);
            this.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Padding = new System.Windows.Forms.Padding(10, 20, 0, 0);
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = " ";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button comp;
        private System.Windows.Forms.ComboBox addcom;
        private System.Windows.Forms.RadioButton binradio;
        private System.Windows.Forms.RichTextBox r;
        private System.Windows.Forms.Label me;
        private System.Windows.Forms.TextBox n1;
        private System.Windows.Forms.TextBox n2;
        private System.Windows.Forms.ComboBox divcom;
        private System.Windows.Forms.ComboBox subcom;
        private System.Windows.Forms.ComboBox mulcom;
        private System.Windows.Forms.Button resert;
        private System.Windows.Forms.RadioButton decradio;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem savetext;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutProgramToolStripMenuItem;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label op;
    }
}

