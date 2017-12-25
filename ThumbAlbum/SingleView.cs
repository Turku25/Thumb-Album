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
        ImageRecord image;
        public SingleView(SystemBase _parent)
        {
            parent = _parent;
            InitializeComponent();  
        }

        private void ButtReturnToGrid_Click(object sender, EventArgs e)
        {
            parent.EnterGridView();
        }

        public void EnterImage(ImageRecord i)//int startImage)
        {
            //imageIndex = startImage;
            UpdateImage(i);
        }

        private void UpdateImage(ImageRecord image)
        {
            //image = parent.GetRecord(imageIndex);
            BigImage.Image = image.GetImageFit(BigImage.Width, BigImage.Height);
            ListTags.Items.Clear();
            foreach (ImageTag t in image.imgTags)
            {
                ListTags.Items.Add(t.tag);
            }
        }
    }
}
