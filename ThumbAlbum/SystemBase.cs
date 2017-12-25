using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThumbAlbum
{
    public partial class SystemBase : Form
    {
        SearchGridView sgv;
        SingleView singleView;
        AddImage addImage;

        ImageRecord[] imageList;
        List<ImageRecord> filteredList = new List<ImageRecord>();
        public int selectionStart = 0;
        public int selectionEnd = 3;
        

        public SystemBase()
        {
            InitializeComponent();
            FormBorderStyle = FormBorderStyle.None;
            WindowState = FormWindowState.Maximized;
            imageList = ImageRecord.LoadDatabase();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            sgv = new SearchGridView(this);
            singleView = new SingleView(this);
            this.Controls.Add(sgv);
            this.Bounds = sgv.Bounds;
        }

        public ImageRecord[] GetImageSelection()
        {
            if (imageList != null)
            {
                int size = selectionEnd - selectionStart + 1;
                size = Math.Min(size, imageList.Length);//make sure you dont go out of bounds!
                ImageRecord[] selection = new ImageRecord[size];
                for (int i = 0; i < size; i++)
                {
                    selection[i] = imageList[selectionStart + i];
                }
                return selection;
            }
            return null;
        }

        public ImageRecord GetRecord(int index)
        {
            //I can error check to see if ined is greater than the current selection
            return imageList[index];
        }

        public void EnterSingleView(ImageRecord i)//int index)//index of the image within current selection
        {
            this.Controls.Remove(sgv);
            singleView.EnterImage(i);// index);
            this.Controls.Add(singleView);
            
        }

        public void EnterGridView()
        {
            this.Controls.RemoveAt(0);
            this.Controls.Add(sgv);
        }

        public void EnterAddImage(ImageRecord edit)
        {
            this.Controls.RemoveAt(0);
            this.Controls.Add(addImage = new AddImage(this, edit));
        }

        public ImageRecord[] QuereyWithTag(ImageTag t)//this is awful programming
        {
            return t.taggedImages.ToArray();
        }
    }
}
