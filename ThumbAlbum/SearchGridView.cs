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
    public partial class SearchGridView : UserControl
    {
        SystemBase parent;
        public SearchGridView(SystemBase _parent)
        {
            parent = _parent;
            InitializeComponent();
            
        }

        private void ButtAddTag_Click(object sender, EventArgs e)
        {

        }

        private void ButtExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void label2_Click(object sender, EventArgs e)
        {
            //delete this
        }

        private void ImageUL_Click(object sender, EventArgs e)
        {
            parent.EnterSingleView(0);
        }

        private void ImageUR_Click(object sender, EventArgs e)
        {
            parent.EnterSingleView(1);
        }

        private void SearchGridView_Load(object sender, EventArgs e)
        {
            ImageRecord[] imgs = parent.GetImageSelection();
            Console.WriteLine("there are this many images: " + imgs.Length);
            ImageUL.Image = imgs[0].GetImageFit(ImageUL.Width, ImageUR.Height);
            LabelUL.Text = imgs[0].description;
            ImageUR.Image = imgs[1].GetImageFit(ImageUL.Width, ImageUR.Height);
            LabelUR.Text = imgs[1].description;
        }

        
    }
}
