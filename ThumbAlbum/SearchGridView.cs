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
        ImageTag lastSelected = null;

        public SearchGridView(SystemBase _parent)
        {
            parent = _parent;
            InitializeComponent();
            UpdateSuggestion();
            
        }

        private void ButtAddTag_Click(object sender, EventArgs e)
        {
            //add a tag to the list
            ListSuggestions.Items.Add(new ImageRecord("", "", new DateTime()));
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
            parent.EnterSingleView(imgs[0]);//0);
        }
        private void ImageUR_Click(object sender, EventArgs e)
        {
            parent.EnterSingleView(imgs[1]);
        }
        private void ImageBL_Click(object sender, EventArgs e)
        {
            parent.EnterSingleView(imgs[2]);
        }
        private void ImageBR_Click(object sender, EventArgs e)
        {
            parent.EnterSingleView(imgs[3]);
        }

        private void SearchGridView_Load(object sender, EventArgs e)//HEY YOU NEED TO FIX THIS
        {
            imgs = parent.GetImageSelection();
            UpdateImages();
        }

        ImageRecord[] imgs;//THIS IS A DIRTY HACK

        private void UpdateImages()
        {
            if (imgs != null)
            {
                ImageUL.Image = null;
                LabelUL.Text = "";
                ImageUR.Image = null;
                LabelUR.Text = "";
                ImageBL.Image = null;
                LabelBL.Text = "";
                ImageBR.Image = null;
                LabelBR.Text = "";
                switch (imgs.Length)
                {
                    case 4:
                        ImageBR.Image = imgs[3].GetImageFit(ImageUL.Width, ImageUR.Height);
                        LabelBR.Text = imgs[3].description;
                        goto case 3;
                    case 3:
                        ImageBL.Image = imgs[2].GetImageFit(ImageUL.Width, ImageUR.Height);
                        LabelBL.Text = imgs[2].description;
                        goto case 2;
                    case 2:
                        ImageUR.Image = imgs[1].GetImageFit(ImageUL.Width, ImageUR.Height);
                        LabelUR.Text = imgs[1].description;
                        goto case 1;
                    case 1:
                        ImageUL.Image = imgs[0].GetImageFit(ImageUL.Width, ImageUR.Height);
                        LabelUL.Text = imgs[0].description;
                        break;
                }
            }
        }

        private void TextTag_TextChanged(object sender, EventArgs e)
        {
            lastSelected = (ImageTag)ListSuggestions.SelectedItem;
            UpdateSuggestion();
        }

        private void UpdateSuggestion()
        {
            //update suggestion list
            
            ListSuggestions.Items.Clear();
            ListSuggestions.Items.Add(new ImageTag("None", true));
            foreach (ImageTag tag in ImageTag.tagList)
            {
                if (tag.tag.ToLower().StartsWith(TagSearch.Text.ToLower()))
                {
                    ListSuggestions.Items.Add(tag);
                }
            }

            if (lastSelected != null && ListSuggestions.Items.Contains(lastSelected))
            {
                ListSuggestions.SetSelected(ListSuggestions.Items.IndexOf(lastSelected), true);
            }
            else
            {
                ListSuggestions.SetSelected(0, true);
            }
        }

        private void ListSuggestions_SelectedIndexChanged(object sender, EventArgs e)
        {
            //first check if it's actually the same object
            if(ListSuggestions.SelectedItem != lastSelected)//else there is no change
            {
                //Filter Images
                //ImageRecord[] imgs;
                if (((ImageTag)ListSuggestions.SelectedItem).isTemp)
                    imgs = parent.GetImageSelection();
                else
                    imgs = parent.QuereyWithTag((ImageTag)ListSuggestions.SelectedItem);
                UpdateImages();
            }
        }

        private void ButtAddPhoto_Click(object sender, EventArgs e)
        {
            parent.EnterAddImage(null);
        }

        
    }
}
