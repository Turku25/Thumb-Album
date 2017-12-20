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
            // SingleView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.Controls.Add(this.ButtReturnToGrid);
            this.Controls.Add(this.BigImage);
            this.Name = "SingleView";
            this.Size = new System.Drawing.Size(1920, 1080);
            ((System.ComponentModel.ISupportInitialize)(this.BigImage)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox BigImage;
        private System.Windows.Forms.Button ButtReturnToGrid;
    }
}
