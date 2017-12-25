namespace ThumbAlbum
{
    partial class AddImage
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.SelectedImage = new System.Windows.Forms.PictureBox();
            this.DescriptionBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.TagSearch = new System.Windows.Forms.TextBox();
            this.ListSuggestions = new System.Windows.Forms.ListBox();
            this.ListTags = new System.Windows.Forms.ListBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.ButtAddTag = new System.Windows.Forms.Button();
            this.ButtRemoveTag = new System.Windows.Forms.Button();
            this.DateTaken = new System.Windows.Forms.DateTimePicker();
            this.label6 = new System.Windows.Forms.Label();
            this.ButtDelete = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.ImageSelect = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.SelectedImage)).BeginInit();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // SelectedImage
            // 
            this.SelectedImage.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.SelectedImage.Location = new System.Drawing.Point(0, 0);
            this.SelectedImage.Name = "SelectedImage";
            this.SelectedImage.Size = new System.Drawing.Size(1316, 1080);
            this.SelectedImage.TabIndex = 0;
            this.SelectedImage.TabStop = false;
            // 
            // DescriptionBox
            // 
            this.DescriptionBox.Location = new System.Drawing.Point(7, 222);
            this.DescriptionBox.Name = "DescriptionBox";
            this.DescriptionBox.Size = new System.Drawing.Size(591, 20);
            this.DescriptionBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(3, 195);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 24);
            this.label1.TabIndex = 2;
            this.label1.Text = "Description";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(4, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Tags";
            // 
            // TagSearch
            // 
            this.TagSearch.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TagSearch.Location = new System.Drawing.Point(3, 77);
            this.TagSearch.Name = "TagSearch";
            this.TagSearch.Size = new System.Drawing.Size(264, 29);
            this.TagSearch.TabIndex = 4;
            this.TagSearch.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // ListSuggestions
            // 
            this.ListSuggestions.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListSuggestions.FormattingEnabled = true;
            this.ListSuggestions.ItemHeight = 24;
            this.ListSuggestions.Location = new System.Drawing.Point(3, 153);
            this.ListSuggestions.Name = "ListSuggestions";
            this.ListSuggestions.Size = new System.Drawing.Size(264, 172);
            this.ListSuggestions.TabIndex = 5;
            // 
            // ListTags
            // 
            this.ListTags.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListTags.FormattingEnabled = true;
            this.ListTags.ItemHeight = 24;
            this.ListTags.Location = new System.Drawing.Point(386, 81);
            this.ListTags.Name = "ListTags";
            this.ListTags.Size = new System.Drawing.Size(202, 244);
            this.ListTags.TabIndex = 6;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panel1.Controls.Add(this.ButtRemoveTag);
            this.panel1.Controls.Add(this.ButtAddTag);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.ListTags);
            this.panel1.Controls.Add(this.TagSearch);
            this.panel1.Controls.Add(this.ListSuggestions);
            this.panel1.Location = new System.Drawing.Point(7, 363);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(591, 329);
            this.panel1.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(4, 54);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(60, 20);
            this.label3.TabIndex = 7;
            this.label3.Text = "Search";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(4, 130);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(98, 20);
            this.label4.TabIndex = 8;
            this.label4.Text = "Suggestions";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(382, 54);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(113, 20);
            this.label5.TabIndex = 9;
            this.label5.Text = "Attached Tags";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panel2.Controls.Add(this.ImageSelect);
            this.panel2.Controls.Add(this.button4);
            this.panel2.Controls.Add(this.ButtDelete);
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.DateTaken);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.panel1);
            this.panel2.Controls.Add(this.DescriptionBox);
            this.panel2.Location = new System.Drawing.Point(1316, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(604, 1080);
            this.panel2.TabIndex = 8;
            // 
            // ButtAddTag
            // 
            this.ButtAddTag.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtAddTag.Location = new System.Drawing.Point(273, 153);
            this.ButtAddTag.Name = "ButtAddTag";
            this.ButtAddTag.Size = new System.Drawing.Size(93, 68);
            this.ButtAddTag.TabIndex = 10;
            this.ButtAddTag.Text = "Add\r\nTag";
            this.ButtAddTag.UseVisualStyleBackColor = true;
            this.ButtAddTag.Click += new System.EventHandler(this.ButtAddTag_Click);
            // 
            // ButtRemoveTag
            // 
            this.ButtRemoveTag.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtRemoveTag.Location = new System.Drawing.Point(287, 242);
            this.ButtRemoveTag.Name = "ButtRemoveTag";
            this.ButtRemoveTag.Size = new System.Drawing.Size(93, 68);
            this.ButtRemoveTag.TabIndex = 11;
            this.ButtRemoveTag.Text = "Remove Tag";
            this.ButtRemoveTag.UseVisualStyleBackColor = true;
            this.ButtRemoveTag.Click += new System.EventHandler(this.ButtRemoveTag_Click);
            // 
            // DateTaken
            // 
            this.DateTaken.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DateTaken.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DateTaken.Location = new System.Drawing.Point(10, 296);
            this.DateTaken.Name = "DateTaken";
            this.DateTaken.Size = new System.Drawing.Size(320, 29);
            this.DateTaken.TabIndex = 8;
            this.DateTaken.ValueChanged += new System.EventHandler(this.dateTimePicker1_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(6, 269);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(106, 24);
            this.label6.TabIndex = 9;
            this.label6.Text = "Date Taken";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // ButtDelete
            // 
            this.ButtDelete.BackColor = System.Drawing.Color.Firebrick;
            this.ButtDelete.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ButtDelete.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtDelete.Location = new System.Drawing.Point(3, 992);
            this.ButtDelete.Name = "ButtDelete";
            this.ButtDelete.Size = new System.Drawing.Size(258, 85);
            this.ButtDelete.TabIndex = 10;
            this.ButtDelete.Text = "Delete";
            this.ButtDelete.UseVisualStyleBackColor = false;
            this.ButtDelete.Click += new System.EventHandler(this.ButtDelete_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.PaleGreen;
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(343, 992);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(258, 85);
            this.button4.TabIndex = 11;
            this.button4.Text = "Add Photo";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // ImageSelect
            // 
            this.ImageSelect.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ImageSelect.Location = new System.Drawing.Point(3, 3);
            this.ImageSelect.Name = "ImageSelect";
            this.ImageSelect.Size = new System.Drawing.Size(592, 68);
            this.ImageSelect.TabIndex = 12;
            this.ImageSelect.Text = "Select Image";
            this.ImageSelect.UseVisualStyleBackColor = true;
            this.ImageSelect.Click += new System.EventHandler(this.button5_Click);
            // 
            // AddImage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.SelectedImage);
            this.Name = "AddImage";
            this.Size = new System.Drawing.Size(1920, 1080);
            ((System.ComponentModel.ISupportInitialize)(this.SelectedImage)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox SelectedImage;
        private System.Windows.Forms.TextBox DescriptionBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TagSearch;
        private System.Windows.Forms.ListBox ListSuggestions;
        private System.Windows.Forms.ListBox ListTags;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button ButtRemoveTag;
        private System.Windows.Forms.Button ButtAddTag;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.DateTimePicker DateTaken;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button ButtDelete;
        private System.Windows.Forms.Button ImageSelect;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
    }
}
