using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThumbAlbum
{
    public partial class SingleView : UserControl
    {
        SystemBase parent;
        int imageIndex = 0;
        public SingleView(SystemBase _parent)
        {
            parent = _parent;
            InitializeComponent();  
        }

        private void ButtReturnToGrid_Click(object sender, EventArgs e)
        {
            parent.EnterGridView();
        }

        public void EnterImage(int startImage)
        {
            imageIndex = startImage;
            UpdateImage();
        }

        private void UpdateImage()
        {
            BigImage.Image = (parent.GetRecord(imageIndex)).GetImageFit(BigImage.Width, BigImage.Height);
        }
    }
}
