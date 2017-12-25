namespace ThumbAlbum
{
    partial class SingleView
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
            this.BigImage = new System.Windows.Forms.PictureBox();
            this.ButtReturnToGrid = new System.Windows.Forms.Button();
            this.ListTags = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.BigImage)).BeginInit();
            this.SuspendLayout();
            // 
            // BigImage
            // 
            this.BigImage.BackColor = System.Drawing.Color.Black;
            this.BigImage.Location = new System.Drawing.Point(0, 0);
            this.BigImage.Name = "BigImage";
            this.BigImage.Size = new System.Drawing.Size(1620, 1080);
            this.BigImage.TabIndex = 0;
            this.BigImage.TabStop = false;
            // 
            // ButtReturnToGrid
            // 
            this.ButtReturnToGrid.Location = new System.Drawing.Point(1626, 3);
            this.ButtReturnToGrid.Name = "ButtReturnToGrid";
            this.ButtReturnToGrid.Size = new System.Drawing.Size(291, 77);
            this.ButtReturnToGrid.TabIndex = 1;
            this.ButtReturnToGrid.Text = "Return to grid view";
            this.ButtReturnToGrid.UseVisualStyleBackColor = true;
            this.ButtReturnToGrid.Click += new System.EventHandler(this.ButtReturnToGrid_Click);
            // 
            // ListTags
            // 
            this.ListTags.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListTags.FormattingEnabled = true;
            this.ListTags.ItemHeight = 24;
            this.ListTags.Location = new System.Drawing.Point(1626, 761);
            this.ListTags.Name = "ListTags";
            this.ListTags.Size = new System.Drawing.Size(291, 316);
            this.ListTags.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(1626, 726);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "Tags";
            // 
            // SingleView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ListTags);
            this.Controls.Add(this.ButtReturnToGrid);
            this.Controls.Add(this.BigImage);
            this.Name = "SingleView";
            this.Size = new System.Drawing.Size(1920, 1080);
            ((System.ComponentModel.ISupportInitialize)(this.BigImage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox BigImage;
        private System.Windows.Forms.Button ButtReturnToGrid;
        private System.Windows.Forms.ListBox ListTags;
        private System.Windows.Forms.Label label1;
    }
}
