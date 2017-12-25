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

    public partial class AddImage : UserControl
    {

        ImageTag lastSelected;
        ImageRecord record;
        SystemBase parent;

        public AddImage(SystemBase _parent, ImageRecord _record)//null if new image, not if editing pre-existing. 
        {
            InitializeComponent();
            parent = _parent;
            record = _record;
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {
            //delete this
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            lastSelected = (ImageTag)ListSuggestions.SelectedItem;
            UpdateSuggestion();
        }

        private void UpdateSuggestion()
        {
            //update suggestion list

            ListSuggestions.Items.Clear();
            ListSuggestions.Items.Add(new ImageTag(TagSearch.Text, true));
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

        private void button4_Click(object sender, EventArgs e)//add photo
        {
            //add photo to database
            if(record == null)
            {
                //check for file name collisons
                int nameStart = ImageSelect.Text.LastIndexOf(@"\");
                String name = ImageSelect.Text.Substring(nameStart + 1);
                record = new ImageRecord(name, DescriptionBox.Text, new DateTime());//figure out how to convert back and fourth between dateTimePicker/DateTime and plaintext
                record.AddToDatabase(ImageSelect.Text);
                parent.EnterGridView();
                //reload the entire database???
            }
            else
            {
                //update current
            }


        }

        private void button5_Click(object sender, EventArgs e)//Select Image file dialog
        {
            openFileDialog1.ShowDialog();
            ImageSelect.Text = openFileDialog1.FileName;
            SelectedImage.Image = ImageRecord.ResizeImage(Image.FromFile(ImageSelect.Text), SelectedImage.Width, SelectedImage.Height);
        }

        private void ButtAddTag_Click(object sender, EventArgs e)
        {
            //listsuggestions to list tags
            ListTags.Items.Add(ListSuggestions.SelectedItem);
        }

        private void ButtRemoveTag_Click(object sender, EventArgs e)
        {
            ListTags.Items.RemoveAt(ListTags.SelectedIndex);
        }

        private void ButtDelete_Click(object sender, EventArgs e)
        {
            //if its a new record just get rid of the data 

            //if it was a preexisting record the record need to be purged from the database.
        }
    }
}
