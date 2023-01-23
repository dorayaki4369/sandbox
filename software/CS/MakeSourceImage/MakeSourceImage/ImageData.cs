namespace MakeSourceImage {
    public enum Type {
        Color,
        Depth,
    } 
    public class ImageData {
        public Type ImageType { get; set; }
        public string Filename { get; set; }
        public bool Deletable { get; set; } = false;
    }
}