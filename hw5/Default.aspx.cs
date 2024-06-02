using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Web;
using System.Web.Services;

public partial class Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    [WebMethod]
    public static List<Student> GetStudents()
    {
        string filePath = HttpContext.Current.Server.MapPath("~/jsondata.txt");
        string jsonData = File.ReadAllText(filePath);
        List<Student> students = JsonConvert.DeserializeObject<List<Student>>(jsonData);
        return students;
    }

    public class Student
    {
        public string StudentID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
        public string Gender { get; set; }
        public int Salary { get; set; }
        public DateTime BirthDay { get; set; }
    }
}
