using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
        }

        private void Forward_Click(object sender, EventArgs e)
        {
            serialPort1.Write("F");
        }

        private void Start_Click(object sender, EventArgs e)
        {
            serialPort1.Write("S");
        }

        private void left90_Click(object sender, EventArgs e)
        {
            serialPort1.Write("Q");
        }

        private void Right90_Click(object sender, EventArgs e)
        {
            serialPort1.Write("E");

        }

        private void Left_Click(object sender, EventArgs e)
        {
            serialPort1.Write("L");
        }

        private void Backward_Click(object sender, EventArgs e)
        {
            serialPort1.Write("B");
        }

        private void Right_Click(object sender, EventArgs e)
        {
            serialPort1.Write("R");
        }

        private void Stop_Click(object sender, EventArgs e)
        {
            serialPort1.Write("St");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("I");
        }
    }
}
