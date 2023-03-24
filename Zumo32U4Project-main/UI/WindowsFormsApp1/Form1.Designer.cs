namespace WindowsFormsApp1
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
            this.components = new System.ComponentModel.Container();
            this.Forward = new System.Windows.Forms.Button();
            this.Stop = new System.Windows.Forms.Button();
            this.Backward = new System.Windows.Forms.Button();
            this.Left = new System.Windows.Forms.Button();
            this.Right = new System.Windows.Forms.Button();
            this.Right90 = new System.Windows.Forms.Button();
            this.Left90 = new System.Windows.Forms.Button();
            this.Start = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // Forward
            // 
            this.Forward.Location = new System.Drawing.Point(468, 219);
            this.Forward.Name = "Forward";
            this.Forward.Size = new System.Drawing.Size(244, 75);
            this.Forward.TabIndex = 0;
            this.Forward.Text = "Forward";
            this.Forward.UseVisualStyleBackColor = true;
            this.Forward.Click += new System.EventHandler(this.Forward_Click);
            // 
            // Stop
            // 
            this.Stop.Location = new System.Drawing.Point(718, 487);
            this.Stop.Name = "Stop";
            this.Stop.Size = new System.Drawing.Size(86, 75);
            this.Stop.TabIndex = 1;
            this.Stop.Text = "Stop";
            this.Stop.UseVisualStyleBackColor = true;
            this.Stop.Click += new System.EventHandler(this.Stop_Click);
            // 
            // Backward
            // 
            this.Backward.Location = new System.Drawing.Point(468, 334);
            this.Backward.Name = "Backward";
            this.Backward.Size = new System.Drawing.Size(244, 75);
            this.Backward.TabIndex = 2;
            this.Backward.Text = "Backward";
            this.Backward.UseVisualStyleBackColor = true;
            this.Backward.Click += new System.EventHandler(this.Backward_Click);
            // 
            // Left
            // 
            this.Left.Location = new System.Drawing.Point(214, 334);
            this.Left.Name = "Left";
            this.Left.Size = new System.Drawing.Size(244, 75);
            this.Left.TabIndex = 3;
            this.Left.Text = "Left";
            this.Left.UseVisualStyleBackColor = true;
            this.Left.Click += new System.EventHandler(this.Left_Click);
            // 
            // Right
            // 
            this.Right.Location = new System.Drawing.Point(718, 334);
            this.Right.Name = "Right";
            this.Right.Size = new System.Drawing.Size(244, 75);
            this.Right.TabIndex = 4;
            this.Right.Text = "Right";
            this.Right.UseVisualStyleBackColor = true;
            this.Right.Click += new System.EventHandler(this.Right_Click);
            // 
            // Right90
            // 
            this.Right90.Location = new System.Drawing.Point(718, 219);
            this.Right90.Name = "Right90";
            this.Right90.Size = new System.Drawing.Size(244, 75);
            this.Right90.TabIndex = 5;
            this.Right90.Text = "90 Right";
            this.Right90.UseVisualStyleBackColor = true;
            this.Right90.Click += new System.EventHandler(this.Right90_Click);
            // 
            // Left90
            // 
            this.Left90.Location = new System.Drawing.Point(214, 219);
            this.Left90.Name = "Left90";
            this.Left90.Size = new System.Drawing.Size(244, 75);
            this.Left90.TabIndex = 6;
            this.Left90.Text = "90 Left ";
            this.Left90.UseVisualStyleBackColor = true;
            this.Left90.Click += new System.EventHandler(this.left90_Click);
            // 
            // Start
            // 
            this.Start.Location = new System.Drawing.Point(369, 487);
            this.Start.Name = "Start";
            this.Start.Size = new System.Drawing.Size(89, 75);
            this.Start.TabIndex = 8;
            this.Start.Text = "Start";
            this.Start.UseVisualStyleBackColor = true;
            this.Start.Click += new System.EventHandler(this.Start_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM5";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(1180, 833);
            this.Controls.Add(this.Start);
            this.Controls.Add(this.Left90);
            this.Controls.Add(this.Right90);
            this.Controls.Add(this.Right);
            this.Controls.Add(this.Left);
            this.Controls.Add(this.Backward);
            this.Controls.Add(this.Stop);
            this.Controls.Add(this.Forward);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Forward;
        private System.Windows.Forms.Button Stop;
        private System.Windows.Forms.Button Backward;
        private System.Windows.Forms.Button Left;
        private System.Windows.Forms.Button Right;
        private System.Windows.Forms.Button Right90;
        private System.Windows.Forms.Button Left90;
        private System.Windows.Forms.Button Start;
        private System.IO.Ports.SerialPort serialPort1;
    }
}

