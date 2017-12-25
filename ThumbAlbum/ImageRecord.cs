using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThumbAlbum
{
    public class ImageRecord
    {
        static String filePath = "../../../Data\\DemoImages\\";//everything must be in this folder
        static String dbFile = "../../../Data\\Database.txt";//wherever I put the data file

        //String fileName = "";
        String imageName = "";
        public String description = "";
        DateTime taken;

        //is tag a class or just a string?
        public List<ImageTag> imgTags = new List<ImageTag>();

        Image image;//may not even use this

        public ImageRecord(String _imageName, String _description, DateTime _taken)
        {
            imageName = _imageName;
            description = _description;
            taken = _taken;
        }
        
        public Image GetImage()
        {
            Console.WriteLine(filePath + imageName);
            Image i = Image.FromFile(filePath + imageName);
            Console.WriteLine(i.Width);
            return i;//I should error check this
        }

        public Image GetImageFit(int maxWidth, int maxHeight)
        {
            return ResizeImage(GetImage(), maxWidth, maxHeight);
        }

        public void AddToDatabase(String _filePath)//make this sorted by date taken? that would be good. LATER
        {
            StreamWriter sw = new StreamWriter(dbFile, true);
            sw.WriteLine(imageName);
            sw.WriteLine(description);
            sw.WriteLine(taken);

            String comma = "";
            foreach(ImageTag tag in imgTags)
            {

                sw.Write(comma + tag.tag);
                comma = ",";
            }
            sw.Close();
            File.Copy(_filePath, filePath + imageName);//source, destinatoin 
        }

        public void RemoveFromDatabase()
        {

        }

        public static ImageRecord[] LoadDatabase()
        {
            ImageRecord[] list = null;
            StreamReader sr = new StreamReader(dbFile);
            //if (sr.ReadToEnd() != "")//if the database is not empty
            //{
                
                int images = int.Parse(sr.ReadLine());
                Console.WriteLine("number of images is: " + images);
                list = new ImageRecord[images];

                for (int i = 0; i < images; i++)
                {
                    list[i] = ReadRecord(sr);
                }
           // }
            sr.Close();
            return list;
        }

        private static ImageRecord ReadRecord(StreamReader sr)
        {
            String name = "";
            String desc = "";
            String date = "";
            //read and parse
            name = sr.ReadLine();
            Console.WriteLine("the name that was read in was: " + name);
            desc = sr.ReadLine();
            date = sr.ReadLine();

            ImageRecord record = new ImageRecord(name, desc, DateTime.Now);//date time is a dummy value because I don't know how I want to handel it yet.

            String[] tags = sr.ReadLine().Split(',');//spit at ','
            foreach(String tag in tags)
            {
                ImageTag.attachTag(record, tag);
            }

            return record;
        }

        public static Image ResizeImage(Image image, int maxWidth, int maxHeight)
        {
            
            var destImage = new Bitmap(maxWidth, maxHeight);

            int scaleWidth = 0;
            int scaleHeight = 0;
            double aspectRatio = image.Height / (float)image.Width;
            double newRatio = maxHeight / (float)maxWidth;
            if(aspectRatio >= newRatio)
            {
                scaleHeight = maxHeight;
                scaleWidth = (int)Math.Round(maxHeight * (1 / aspectRatio) );
            }
            else
            {
                scaleWidth = maxWidth;
                scaleHeight = (int)Math.Round(maxWidth * aspectRatio);
            }
            int centeredX = (int)((maxWidth / 2.0f) - (scaleWidth / 2.0f));
            int centeredY = (int)((maxHeight / 2.0f) - (scaleHeight / 2.0f));
            var destRect = new Rectangle(centeredX, centeredY, scaleWidth, scaleHeight);
            

            destImage.SetResolution(image.HorizontalResolution, image.VerticalResolution);

            using (var graphics = Graphics.FromImage(destImage))
            {
                graphics.CompositingMode = CompositingMode.SourceCopy;
                graphics.CompositingQuality = CompositingQuality.HighQuality;
                graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
                graphics.SmoothingMode = SmoothingMode.HighQuality;
                graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;

                using (var wrapMode = new ImageAttributes())
                {
                    wrapMode.SetWrapMode(WrapMode.TileFlipXY);
                    graphics.DrawImage(image, destRect, 0, 0, image.Width, image.Height, GraphicsUnit.Pixel, wrapMode);
                }
            }

            return (Image)destImage;
        }

        public void ImportImage(String filePath)
        {
            
        }
    }
}
