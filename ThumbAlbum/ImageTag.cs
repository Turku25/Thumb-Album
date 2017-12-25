using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThumbAlbum
{
    public class ImageTag
    {
        public static List<ImageTag> tagList = new List<ImageTag>();

        public String tag = "";
        public List<ImageRecord> taggedImages = new List<ImageRecord>();
        public bool isTemp = false;

        public ImageTag(String _tag)
        {
            tag = _tag;
            tagList.Add(this);
        }

        public ImageTag(String _tag, bool nul)//use this for tags that are not part of the tag list
        {
            tag = _tag;
            isTemp = true;
        }

        public static void attachTag(ImageRecord _img, String _tag)
        {
            ImageTag imgTag = tagExists(_tag);
            if (imgTag == null)
                imgTag = new ImageTag(_tag);
            imgTag.taggedImages.Add(_img);
            _img.imgTags.Add(imgTag);

        }

        private static ImageTag tagExists(String _tag)
        {
            foreach(ImageTag t in tagList)
            {
                if(t.tag == _tag)
                {
                    return t;
                }
            }
            return null;
        }

        public override String ToString()
        {
            return tag;
        }

    }
}
